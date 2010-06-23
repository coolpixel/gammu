/* (c) 2002-2003 by Marcin Wiacek and Joergen Thomsen */

#include <string.h>
#include <signal.h>
#include <stdarg.h>
#include <time.h>

#include "smsdcore.h"
#include "../gammu.h"
#include "s_files.h"
#include "../../common/misc/coding/coding.h"

FILE 		 *smsd_log_file = NULL;
static GSM_Error SendingSMSStatus;

static void SMSSendingSMSStatus (char *Device, int status)
{
	dbgprintf("Incoming SMS device: \"%s\" status=%d\n",Device, status);
	if (status==0) {
		SendingSMSStatus = ERR_NONE;
	} else {
		SendingSMSStatus = ERR_UNKNOWN;
	}
}

void GSM_Terminate_SMSD(char *msg, int error, bool exitprogram, int rc)
{
	int ret = ERR_NONE;

	if (s.opened) {
		WriteSMSDLog("Terminating communication");
		ret=GSM_TerminateConnection(&s);
		if (ret!=ERR_NONE) {
			printf("%s\n",print_error(error,s.di.df,s.msg));
			if (s.opened) GSM_TerminateConnection(&s);
		}
	}
	if (error != 0) {
		WriteSMSDLog(msg, error, print_error(error,s.di.df,s.msg));
		fprintf(stderr, msg, error, print_error(error,s.di.df,s.msg));
		fprintf(stderr, "\n");
	}
	if (exitprogram) {
		if (smsd_log_file!=NULL) fclose(smsd_log_file);
		exit(rc);
	}
}

void WriteSMSDLog(unsigned char *format, ...)
{
	GSM_DateTime 	date_time;
	char 		Buffer[2000];
	va_list		argp;
	int 		result;

	if (smsd_log_file != NULL) {
		va_start(argp, format);
		result = vsprintf(Buffer,GetMsg(s.msg,format),argp);
		va_end(argp);

		GSM_GetCurrentDateTime(&date_time);

		fprintf(smsd_log_file,"%s %4d/%02d/%02d %02d:%02d:%02d : %s\n",
			DayOfWeek(date_time.Year, date_time.Month, date_time.Day),
			date_time.Year, date_time.Month, date_time.Day,
			date_time.Hour, date_time.Minute, date_time.Second,Buffer);
		fflush(smsd_log_file);
	}
}

void SMSD_ReadConfig(int argc, char *argv[], GSM_SMSDConfig *Config)
{
	INI_Section 		*smsdcfgfile = NULL;
	GSM_Config 		smsdcfg;
	unsigned char		*str;
	static unsigned char	emptyPath[1] = "\0";

	smsdcfgfile=INI_ReadFile(argv[3], false);
	if (smsdcfgfile==NULL) {
		fprintf(stderr,"Can't find file \"%s\"\n",argv[3]);
		exit(-1);
	}

	Config->logfilename=INI_GetValue(smsdcfgfile, "smsd", "logfile", false);
	if (Config->logfilename != NULL) {
		smsd_log_file=fopen(Config->logfilename,"ab");
		if (smsd_log_file == NULL) {
			fprintf(stderr,"Can't open file \"%s\"\n",Config->logfilename);
			exit(-1);
		}
		fprintf(stderr,"Log filename is \"%s\"\n",Config->logfilename);
	}
	WriteSMSDLog("Start GAMMU smsd");

	/* Include Numbers used, because we don't want create new variable */
	Config->IncludeNumbers=INI_FindLastSectionEntry(smsdcfgfile, "gammu", false);
	if (Config->IncludeNumbers) {
		GSM_ReadConfig(smsdcfgfile, &smsdcfg, 0);
		memcpy(&s.Config,&smsdcfg,sizeof(GSM_Config));
	}

	Config->PINCode=INI_GetValue(smsdcfgfile, "smsd", "PIN", false);
	if (Config->PINCode == NULL) {
		WriteSMSDLog("No PIN code in %s file",argv[3]);
		fprintf(stderr,"No PIN code in %s file\n",argv[3]);
		exit(-1);
	}
	WriteSMSDLog("PIN code is \"%s\"",Config->PINCode);

	str = INI_GetValue(smsdcfgfile, "smsd", "commtimeout", false);
	if (str) Config->commtimeout=atoi(str); else Config->commtimeout = 1;
	str = INI_GetValue(smsdcfgfile, "smsd", "sendtimeout", false);
	if (str) Config->sendtimeout=atoi(str); else Config->sendtimeout = 10;
	str = INI_GetValue(smsdcfgfile, "smsd", "receivefrequency", false);
	if (str) Config->receivefrequency=atoi(str); else Config->receivefrequency = 0;
	WriteSMSDLog("commtimeout=%i, sendtimeout=%i, receivefrequency=%i", Config->commtimeout, Config->sendtimeout, Config->receivefrequency);

	Config->deliveryreport = INI_GetValue(smsdcfgfile, "smsd", "deliveryreport", false);
	if (Config->deliveryreport == NULL || (!mystrncasecmp(Config->deliveryreport, "log", 3) && !mystrncasecmp(Config->deliveryreport, "sms", 3))) {
		Config->deliveryreport = "no";
	}
	WriteSMSDLog("deliveryreport = %s", Config->deliveryreport);

	Config->inboxpath=INI_GetValue(smsdcfgfile, "smsd", "inboxpath", false);
	if (Config->inboxpath == NULL) Config->inboxpath = emptyPath;

	Config->inboxformat=INI_GetValue(smsdcfgfile, "smsd", "inboxformat", false);
	if (Config->inboxformat == NULL || (!mystrncasecmp(Config->inboxformat, "detail", 6) && !mystrncasecmp(Config->inboxformat, "unicode", 7))) {
		Config->inboxformat = "standard";
	}
	WriteSMSDLog("Inbox is \"%s\" with format \"%s\"", Config->inboxpath, Config->inboxformat);

	Config->outboxpath=INI_GetValue(smsdcfgfile, "smsd", "outboxpath", false);
	if (Config->outboxpath == NULL) Config->outboxpath = emptyPath;

	Config->transmitformat=INI_GetValue(smsdcfgfile, "smsd", "transmitformat", false);
	if (Config->transmitformat == NULL || (!mystrncasecmp(Config->transmitformat, "auto", 4) && !mystrncasecmp(Config->transmitformat, "unicode", 7))) {
		Config->transmitformat = "7bit";
	}
	WriteSMSDLog("Outbox is \"%s\" with transmission format \"%s\"", Config->outboxpath, Config->transmitformat);

	Config->sentsmspath=INI_GetValue(smsdcfgfile, "smsd", "sentsmspath", false);
	if (Config->sentsmspath == NULL) Config->sentsmspath = Config->outboxpath;
	WriteSMSDLog("Sent SMS moved to \"%s\"",Config->sentsmspath);

	Config->errorsmspath=INI_GetValue(smsdcfgfile, "smsd", "errorsmspath", false);
	if (Config->errorsmspath == NULL) Config->errorsmspath = Config->sentsmspath;
	WriteSMSDLog("SMS with errors moved to \"%s\"",Config->errorsmspath);

	Config->IncludeNumbers=INI_FindLastSectionEntry(smsdcfgfile, "include_numbers", false);
	Config->ExcludeNumbers=INI_FindLastSectionEntry(smsdcfgfile, "exclude_numbers", false);
	if (Config->IncludeNumbers != NULL) {
		WriteSMSDLog("Include numbers available");
	}
	if (Config->ExcludeNumbers != NULL) {
		if (Config->IncludeNumbers == NULL) {
			WriteSMSDLog("Exclude numbers available");
		} else {
			WriteSMSDLog("Exclude numbers available, but IGNORED");
		}
	}

	Config->retries = 0;
	Config->prevSMSID[0] = 0;
}

bool SMSD_CheckSecurity(GSM_SMSDConfig *Config)
{
	GSM_SecurityCode 	SecurityCode;
	GSM_Error		error;

	/* Need PIN ? */
	error=Phone->GetSecurityStatus(&s,&SecurityCode.Type);
	/* Unknown error */
	if (error != ERR_NOTSUPPORTED && error != ERR_NONE) {
		WriteSMSDLog("Error getting security status (%i)", error);
		return false;
	}
	/* No supported - do not check more */
	if (error == ERR_NOTSUPPORTED) return true;
	/* If PIN, try to enter */
	switch (SecurityCode.Type) {
	case SEC_Pin:
		WriteSMSDLog("Trying to enter PIN");
		strcpy(SecurityCode.Code,Config->PINCode);
		error=Phone->EnterSecurityCode(&s,SecurityCode);
		if (error == ERR_SECURITYERROR) {
			GSM_Terminate_SMSD("ERROR: incorrect PIN", error, true, -1);
		}
		if (error != ERR_NONE) {
			WriteSMSDLog("Error entering PIN (%i)", error);
			return false;
	  	}
		break;
	case SEC_SecurityCode:
	case SEC_Pin2:
	case SEC_Puk:
	case SEC_Puk2:
		GSM_Terminate_SMSD("ERROR: phone requires not supported code type", 0, true, -1);
	case SEC_None:
		break;
	}
	return true;
}

bool SMSD_ReadDeleteSMS(GSM_SMSDConfig *Config, GSM_SMSDService *Service)
{
	bool			start,process;
	GSM_MultiSMSMessage 	sms;
	unsigned char 		buffer[100];
	GSM_Error		error=ERR_NONE;
	INI_Entry		*e;
	int			i;

	start=true;
	while (error == ERR_NONE && !gshutdown) {
		sms.SMS[0].Folder=0x00;
		error=Phone->GetNextSMS(&s, &sms, start);
		switch (error) {
		case ERR_EMPTY:
			break;
		case ERR_NONE:
			/* Not Inbox SMS - exit */
			if (!sms.SMS[0].InboxFolder) break;
			process=true;
			DecodeUnicode(sms.SMS[0].Number,buffer);
			if (Config->IncludeNumbers != NULL) {
				e=Config->IncludeNumbers;
				process=false;
				while (1) {
					if (e == NULL) break;
					if (strcmp(buffer,e->EntryValue)==0) {
						process=true;
						break;
					}
					e = e->Prev;
				}
			} else if (Config->ExcludeNumbers != NULL) {
				e=Config->ExcludeNumbers;
				process=true;
				while (1) {
					if (e == NULL) break;
					if (strcmp(buffer,e->EntryValue)==0) {
						process=false;
						break;
					}
					e = e->Prev;
				}
			}
			if (process) {
	 			Service->SaveInboxSMS(sms, Config);
			} else {
				WriteSMSDLog("Excluded %s", buffer);
			}
			break;
		default:
	 		WriteSMSDLog("Error getting SMS (%i)", error);
			return false;
		}
		if (error == ERR_NONE && sms.SMS[0].InboxFolder) {
			for (i=0;i<sms.Number;i++) {
				sms.SMS[i].Folder=0;
				error=Phone->DeleteSMS(&s,&sms.SMS[i]);
				switch (error) {
				case ERR_NONE:
				case ERR_EMPTY:
					break;
				default:
					WriteSMSDLog("Error deleting SMS (%i)", error);
					return false;
				}
			}
		}
		start=false;
	}
	return true;
}

bool SMSD_CheckSMSStatus(GSM_SMSDConfig *Config,GSM_SMSDService *Service)
{
	GSM_SMSMemoryStatus	SMSStatus;
	GSM_Error		error;

	/* Do we have any SMS in phone ? */
	error=Phone->GetSMSStatus(&s,&SMSStatus);
	if (error != ERR_NONE) {
		WriteSMSDLog("Error getting SMS status (%i)", error);
		return false;
	}
	/* Yes. We have SMS in phone */
	if (SMSStatus.SIMUsed+SMSStatus.PhoneUsed != 0) {
		return SMSD_ReadDeleteSMS(Config,Service);
	}
	return true;
}

bool SMSD_SendSMS(GSM_SMSDConfig *Config,GSM_SMSDService *Service)
{
	GSM_MultiSMSMessage  	sms;
	GSM_DateTime         	Date;
	GSM_Error            	error;
	unsigned int         	i, j, z;

	error = Service->FindOutboxSMS(&sms, Config, Config->SMSID);

	if (error == ERR_EMPTY) {
		/* No outbox sms - wait few seconds and escape */
		for (j=0;j<Config->commtimeout && !gshutdown;j++) {
			GSM_GetCurrentDateTime (&Date);
			i=Date.Second;
	 		while (i==Date.Second && !gshutdown) {
				my_sleep(10);
				GSM_GetCurrentDateTime(&Date);
			}
		}
		return true;
	}
	if (error != ERR_NONE) {
		/* Unknown error - escape */
		WriteSMSDLog("Error in outbox on %s", Config->SMSID);
		Service->MoveSMS(Config->outboxpath, Config->errorsmspath, Config->SMSID, true);
		return false;
	}
	if (!gshutdown) {
		if (strcmp(Config->prevSMSID, Config->SMSID) == 0) {
			Config->retries++;
			if (Config->retries > MAX_RETRIES) {
				Config->retries = 0;
				strcpy(Config->prevSMSID, "");
				WriteSMSDLog("Moved to errorbox: %s", Config->SMSID);
				Service->MoveSMS(Config->outboxpath, Config->errorsmspath, Config->SMSID, true);
				return false;
			}
		} else {
			Config->retries = 0;
			strcpy(Config->prevSMSID, Config->SMSID);
		}
		for (i=0;i<sms.Number;i++) {
			if (strcmp(Config->deliveryreport, "no") != 0) sms.SMS[i].PDU = SMS_Status_Report;
			error=Phone->SendSMS(&s, &sms.SMS[i]);
			if (error!=ERR_NONE) {
				WriteSMSDLog("Error sending SMS %s (%i): %s", Config->SMSID, error,print_error(error,s.di.df,s.msg));
				return false;
			}
			j=0;
			SendingSMSStatus = ERR_TIMEOUT;
			while (!gshutdown) {
				GSM_GetCurrentDateTime (&Date);
				z=Date.Second;
				while (z==Date.Second) {
					my_sleep(10);
					GSM_GetCurrentDateTime(&Date);
					GSM_ReadDevice(&s,true);
					if (SendingSMSStatus != ERR_TIMEOUT) break;
				}
				if (SendingSMSStatus != ERR_TIMEOUT) break;
				j++;
				if (j>Config->sendtimeout) break;
			}
			if (SendingSMSStatus != ERR_NONE) {
				WriteSMSDLog("Error getting send status of %s (%i): %s", Config->SMSID, SendingSMSStatus,print_error(SendingSMSStatus,s.di.df,s.msg));
				return false;
			}
			WriteSMSDLog("Transmitted %s (%s: %i) to %s", Config->SMSID, (i+1 == sms.Number?"total":"part"),i+1,DecodeUnicodeString(sms.SMS[0].Number));
		}
		strcpy(Config->prevSMSID, "");
		if (Service->MoveSMS(Config->outboxpath, Config->sentsmspath, Config->SMSID, false) != ERR_NONE)
			Service->MoveSMS(Config->outboxpath, Config->errorsmspath, Config->SMSID, true);
	}
	return true;
}

void SMSDaemon(int argc, char *argv[])
{
	int                     errors = 255, initerrors=0;
	GSM_SMSDService		*Service;
	GSM_Error		error;
 	time_t                  time1;
	GSM_SMSDConfig		Config;

	if (!strcmp(argv[2],"FILES")) {
		Service = &SMSDFiles;
	} else {
		fprintf(stderr,"Unknown service type (\"%s\")\n",argv[2]);
		exit(-1);
	}

	SMSD_ReadConfig(argc, argv, &Config);

	error = Service->Init();
	if (error!=ERR_NONE) {
		GSM_Terminate_SMSD("Stop GAMMU smsd (%i)", error, true, -1);
	}

	signal(SIGINT, interrupt);
	signal(SIGTERM, interrupt);
	fprintf(stderr,"Press Ctrl+C to stop the program ...\n");

	time1 			= time(NULL);
	SendingSMSStatus 	= ERR_UNKNOWN;

	while (!gshutdown) {
		/* There were errors in communication - try to recover */
		if (errors > 2) {
			if (errors != 255) {
				WriteSMSDLog("Terminating communication (%i,%i)", error, errors);
				error=GSM_TerminateConnection(&s);
			}
			if (initerrors++ > 3) my_sleep(30000);
			WriteSMSDLog("Starting communication");
			error=GSM_InitConnection(&s,2);
			switch (error) {
			case ERR_NONE:
				s.User.SendSMSStatus 	= SMSSendingSMSStatus;
				Phone			= s.Phone.Functions;
				errors 			= 0;
				/* Marcin Wiacek: FIXME. To check */
//				di 			= s.di;
				break;
			case ERR_DEVICEOPENERROR:
				GSM_Terminate_SMSD("Can't open device (%i)", error, true, -1);
			default:
				WriteSMSDLog("Error at init connection (%i)", error);
				errors = 250;
			}
			continue;
		}
		if ((difftime(time(NULL), time1) >= Config.receivefrequency) || (SendingSMSStatus != ERR_NONE)) {
	 		time1 = time(NULL);

			if (!SMSD_CheckSecurity(&Config))
			{
				errors++;
				initerrors++;
				continue;
			} else errors=0;

			initerrors = 0;

			if (!SMSD_CheckSMSStatus(&Config,Service))
			{
				errors++;
				continue;
			} else errors=0;
		}
		if (!SMSD_SendSMS(&Config,Service)) continue;
	}
	GSM_Terminate_SMSD("Stop GAMMU smsd", 0, false, 0);
}

/* How should editor hadle tabs in this file? Add editor commands here.
 * vim: noexpandtab sw=8 ts=8 sts=8:
 */