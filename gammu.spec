%define ver         0.96.9
%define name        gammu
%define bluetooth   1
%define relnum      1
 
%if %_vendor == "suse"
%define rel         %{relnum}suse
%else
%if %_vendor == "redhat"
%define rel         %{relnum}rh
%else
%define rel         %{relnum}
%endif
%endif
 
%if %bluetooth
%define configureparams ""
%else
%define configureparams "--disable-bluefbus --disable-blueobex --disable-bluephonet --disable-blueat"
%endif
  
Summary:            Mobile phones tools for Unix (Linux) and Win32
Name:               %name
Version:            %ver
Release:            %rel
License:            GPL
%if %_vendor == "suse"
Group:              Hardware/Mobile
%else
Group:              Applications/Communications
%endif
%if %bluetooth
%if %_vendor == "suse"
BuildRequires:      bluez-libs >= 2.0
%else
BuildRequires:      bluez-libs >= 2.0 bluez-libs-devel >= 2.0
%endif
%endif
Vendor:             Marcin Wiacek <marcin@mwiacek.com>
Source:             http://www.mwiacek.com/zips/gsm/%name/older/%{name}-%{ver}.tar.gz
URL:                http://www.mwiacek.com/gsm/gammu/gammu.html
Buildroot:          %{_tmppath}/%name-%version-root

%description
Gammu can do such things with cellular phones as making data calls,
updating the address book, changing calendar and ToDo entries, sending and
receiving SMS messages, loading and getting ring tones and pictures (different
types of logos), synchronizing time, enabling NetMonitor, managing WAP
settings and bookmarks and much more. Functions depend on the phone model.

%package devel
Summary:      Development files for Gammu
%if %_vendor == "suse"
Group:              Development/Libraries/C and C++
%else
Group:              Development/Libraries
%endif
Autoreqprov:  on
Requires:           %name = %ver-%rel

%description devel
Gammu can do such things with cellular phones as making data calls,
updating the address book, changing calendar and ToDo entries, sending and
receiving SMS messages, loading and getting ring tones and pictures (different
types of logos), synchronizing time, enabling NetMonitor, managing WAP
settings and bookmarks and much more. Functions depend on the phone model.

%prep
%setup -q

%build
%if %_vendor == "redhat"
%configure --with-docdir=%_docdir/%name-%ver/ %configureparams
%else
%configure --with-docdir=%_docdir/%name/ %configureparams
%endif
make shared

%install
rm -rf %buildroot
make installshared DESTDIR=%buildroot
install -m 755 -d %buildroot%_docdir/gammu/other/config
install -m 755 -d %buildroot%_docdir/gammu/other/basic
install -m 755 -d %buildroot%_docdir/gammu/other/smsdutil
install -m 755 other/config/gammu-config %buildroot%_docdir/gammu/other/config
install -m 644 other/basic/* %buildroot%_docdir/gammu/other/basic
install -m 644 other/smsdutil/* %buildroot%_docdir/gammu/other/smsdutil

%post
if test -f /etc/ld.so.conf ; then 
    /sbin/ldconfig
fi

%postun
if test -f /etc/ld.so.conf ; then 
    /sbin/ldconfig
fi

%files
%defattr(-,root,root)
%_bindir/*
%_libdir/*.so*
#localisations:
/usr/share/gammu
%doc %_mandir/man1/*
%if %_vendor == "redhat"
%doc %_docdir/%name-%ver
%else
%doc %_docdir/%name
%endif

%files devel
%defattr(-,root,root)
%_includedir/%name
%_libdir/pkgconfig/%name.pc
%_libdir/*.a

%clean
rm -rf %buildroot

%changelog
* Wed Nov 12 2003 Michal Cihar <michal@cihar.com>
- distiguish between packaging on SUSE and Redhat
- build depends on bluez if wanted

* Mon Nov 10 2003 Peter Soos <sp@osb.hu>
- using rpm macros where is possible
- added ldconfig to post/postun

* Mon Nov 03 2003 Michal Cihar <michal@cihar.com>
- split devel package

* Thu Jan 02 2003 Michal Cihar <michal@cihar.com>
- made it install in directories that are defined in rpm

* Sun Nov 10 2002 Marcin Wiacek <marcin@mwiacek.com>
- topnet.pl email no more available

* Sun Sep 30 2002 Marcin Wiacek <marcin-wiacek@topnet.pl>
- build system is now really working OK

* Sat Sep 15 2002 R P Herrold <herrold@owlriver.com>
- initial packaging