/* (c) 2001-2003 by Marcin Wiacek */

#include <string.h>

#include <gammu-info.h>

#include "gsmnet.h"
#include "../misc/coding/coding.h"

const char *GSM_Countries[] = {

	"202", "Greece",
	"204", "Netherlands",
	"206", "Belgium",
	"208", "France",
	"212", "Monaco",
	"213", "Andorra",
	"214", "Spain",
	"216", "Hungary",
	"218", "Bosnia and Herzegovina",
	"219", "Croatia",
	"220", "Serbia (Republic of)",
	"222", "Italy",
	"225", "Vatican City State",
	"226", "Romania",
	"228", "Switzerland",
	"230", "Czech Republic",
	"231", "Slovakia",
	"232", "Austria",
	"234", "United Kingdom",
	"235", "United Kingdom",
	"238", "Denmark",
	"240", "Sweden",
	"242", "Norway",
	"244", "Finland",
	"246", "Lithuania",
	"247", "Latvia",
	"248", "Estonia",
	"250", "Russian Federation",
	"255", "Ukraine",
	"257", "Belarus",
	"259", "Moldova",
	"260", "Poland",
	"262", "Germany",
	"266", "Gibraltar (UK)",
	"268", "Portugal",
	"270", "Luxembourg",
	"272", "Ireland",
	"274", "Iceland",
	"276", "Albania",
	"278", "Malta",
	"280", "Cyprus",
	"282", "Georgia",
	"283", "Armenia",
	"284", "Bulgaria",
	"286", "Turkey",
	"288", "Faroe Islands (Denmark)",
	"290", "Greenland (Denmark)",
	"292", "San Marino",
	"293", "Slovenia",
	"294", "Republic of Macedonia",
	"295", "Liechtenstein",
	"297", "Montenegro (Republic of)",

	"302", "Canada",
	"308", "Saint Pierre and Miquelon (France)",
	"310", "United States of America",
	"311", "United States of America",
	"312", "United States of America",
	"313", "United States of America",
	"314", "United States of America",
	"315", "United States of America",
	"316", "United States of America",
	"330", "Puerto Rico (US)",
	"332", "United States Virgin Islands (US)",
	"334", "Mexico",
	"338", "Jamaica",
	"340", "Guadeloupe (France)",
	"340", "Martinique (France)",
	"342", "Barbados",
	"344", "Antigua and Barbuda",
	"346", "Cayman Islands (UK)",
	"348", "British Virgin Islands (UK)",
	"350", "Bermuda (UK)",
	"352", "Grenada",
	"354", "Montserrat (UK)",
	"356", "Saint Kitts and Nevis",
	"358", "Saint Lucia",
	"360", "Saint Vincent and the Grenadines",
	"362", "Netherlands Antilles (Netherlands)",
	"363", "Aruba (Netherlands)",
	"364", "Bahamas",
	"365", "Anguilla",
	"366", "Dominica",
	"368", "Cuba",
	"370", "Dominican Republic",
	"372", "Haiti",
	"374", "Trinidad and Tobago",
	"376", "Turks and Caicos Islands (UK)",

	"400", "Azerbaijani Republic",
	"401", "Kazakhstan",
	"402", "Bhutan",
	"404", "India",
	"405", "India",
	"406", "India",
	"410", "Pakistan",
	"412", "Afghanistan",
	"413", "Sri Lanka",
	"414", "Myanmar",
	"415", "Lebanon",
	"416", "Jordan",
	"417", "Syria",
	"418", "Iraq",
	"419", "Kuwait",
	"420", "Saudi Arabia",
	"421", "Yemen",
	"422", "Oman",
	"423", "Palestine",
	"424", "United Arab Emirates",
	"425", "Israel",
	"426", "Bahrain",
	"427", "Qatar",
	"428", "Mongolia",
	"429", "Nepal",
	"430", "United Arab Emirates (Abu Dhabi)",
	"431", "United Arab Emirates (Dubai)",
	"432", "Iran",
	"434", "Uzbekistan",
	"436", "Tajikistan",
	"437", "Kyrgyz Republic",
	"438", "Turkmenistan",
	"440", "Japan",
	"441", "Japan",
	"450", "Korea, South",
	"452", "Viet Nam",
	"454", "Hong Kong (PRC)",
	"455", "Macau (PRC)",
	"456", "Cambodia",
	"457", "Laos",
	"460", "China",
	"461", "China",
	"466", "Taiwan",
	"467", "Korea, North",
	"470", "Bangladesh",
	"472", "Maldives",

	"502", "Malaysia",
	"505", "Australia",
	"510", "Indonesia",
	"514", "East Timor",
	"515", "Philippines",
	"520", "Thailand",
	"525", "Singapore",
	"528", "Brunei Darussalam",
	"530", "New Zealand",
	"534", "Northern Mariana Islands (US)",
	"535", "Guam (US)",
	"536", "Nauru",
	"537", "Papua New Guinea",
	"539", "Tonga",
	"540", "Solomon Islands",
	"541", "Vanuatu",
	"542", "Fiji",
	"543", "Wallis and Futuna (France)",
	"544", "American Samoa (US)",
	"545", "Kiribati",
	"546", "New Caledonia (France)",
	"547", "French Polynesia (France)",
	"548", "Cook Islands (NZ)",
	"549", "Samoa",
	"550", "Federated States of Micronesia",
	"551", "Marshall Islands",
	"552", "Palau",

	"602", "Egypt",
	"603", "Algeria",
	"604", "Morocco",
	"605", "Tunisia",
	"606", "Libya",
	"607", "Gambia",
	"608", "Senegal",
	"609", "Mauritania",
	"610", "Mali",
	"611", "Guinea",
	"612", "Cote d'Ivoire",
	"613", "Burkina Faso",
	"614", "Niger",
	"615", "Togolese Republic",
	"616", "Benin",
	"617", "Mauritius",
	"618", "Liberia",
	"619", "Sierra Leone",
	"620", "Ghana",
	"621", "Nigeria",
	"622", "Chad",
	"623", "Central African Republic",
	"624", "Cameroon",
	"625", "Cape Verde",
	"626", "Sao Tome and Principe",
	"627", "Equatorial Guinea",
	"628", "Gabonese Republic",
	"629", "Republic of the Congo",
	"630", "Democratic Republic of the Congo",
	"631", "Angola",
	"632", "Guinea-Bissau",
	"633", "Seychelles",
	"634", "Sudan",
	"635", "Rwandese Republic",
	"636", "Ethiopia",
	"637", "Somalia",
	"638", "Djibouti",
	"639", "Kenya",
	"640", "Tanzania",
	"641", "Uganda",
	"642", "Burundi",
	"643", "Mozambique",
	"645", "Zambia",
	"646", "Madagascar",
	"647", "Reunion (France)",
	"648", "Zimbabwe",
	"649", "Namibia",
	"650", "Malawi",
	"651", "Lesotho",
	"652", "Botswana",
	"653", "Swaziland",
	"654", "Comoros",
	"655", "South Africa",
	"657", "Eritrea",

	"702", "Belize",
	"704", "Guatemala",
	"706", "El Salvador",
	"708", "Honduras",
	"710", "Nicaragua",
	"712", "Costa Rica",
	"714", "Panama",
	"716", "Peru",
	"722", "Argentine Republic",
	"724", "Brazil",
	"730", "Chile",
	"732", "Colombia",
	"734", "Venezuela",
	"736", "Bolivia",
	"738", "Guyana",
	"740", "Ecuador",
	"742", "French Guiana (France)",
	"744", "Paraguay",
	"746", "Suriname",
	"748", "Uruguay",
	"750", "Falkland Islands (Malvinas)",

	"901", "International Shared Code",

	"999", "Dummy",

	NULL
};

const char *GSM_Networks[] = {

	"200 053", "",
	"200 054", "",
	"200 066", "",
	"202 01", "Cosmote",
	"202 05", "Vodafone",
	"202 09", "Wind",
	"202 10", "Wind",
	"204 01", "",
	"204 02", "Tele2",
	"204 04", "Vodafone",
	"204 05", "",
	"204 06", "",
	"204 07", "",
	"204 08", "KPN",
	"204 09", "Lycamobile",
	"204 10", "KPN",
	"204 12", "Telfort",
	"204 14", "6Gmobile",
	"204 16", "T-Mobile",
	"204 20", "T-Mobile",
	"204 21", "",
	"204 23", "ASPIDER Solutions",
	"204 69", "",
	"206 01", "Proximus",
	"206 05", "Telenet",
	"206 10", "Mobistar",
	"206 20", "BASE",
	"208 00", "Orange",
	"208 01", "Orange",
	"208 02", "Orange",
	"208 05", "",
	"208 06", "",
	"208 07", "",
	"208 10", "SFR",
	"208 11", "SFR",
	"208 13", "SFR",
	"208 20", "Bouygues",
	"208 21", "Bouygues",
	"208 22", "Transatel Mobile",
	"208 88", "Bouygues",
	"212 01", "Office des Telephones",
	"212 01", "Vala",
	"212 01", "Z Mobile",
	"213 03", "Mobiland",
	"214 01", "Vodafone",
	"214 03", "Orange",
	"214 04", "Yoigo",
	"214 05", "TME",
	"214 06", "Vodafone",
	"214 07", "movistar",
	"214 08", "Euskaltel",
	"214 09", "Orange",
	"214 15", "BT",
	"214 16", "TeleCable",
	"214 17", "Mobil R",
	"214 18", "ONO",
	"214 19", "Simyo",
	"214 20", "Fonyou",
	"214 21", "Jazztel",
	"214 22", "DigiMobil",
	"214 23", "Barablu",
	"214 24", "Eroski",
	"214 25", "LycaMobile",
	"216 01", "Telenor",
	"216 30", "T-Mobile",
	"216 70", "Vodafone",
	"218 03", "HT-ERONET",
	"218 05", "m:tel",
	"218 90", "BH Mobile",
	"219 01", "T-Mobile",
	"219 02", "Tele2",
	"219 10", "VIPnet",
	"220 01", "Telenor",
	"220 02", "Telenor",
	"220 03", "mt:s",
	"220 05", "VIP",
	"222 01", "TIM",
	"222 02", "Elsacom",
	"222 10", "Vodafone",
	"222 30", "RFI",
	"222 77", "IPSE 2000",
	"222 88", "Wind",
	"222 98", "Blu",
	"222 99", "3 Italia",
	"226 01", "Vodafone",
	"226 02", "Romtelecom",
	"226 03", "Cosmote",
	"226 04", "Cosmote",
	"226 05", "Digi.Mobil",
	"226 06", "Cosmote",
	"226 10", "Orange",
	"228 01", "Swisscom",
	"228 02", "Sunrise",
	"228 03", "Orange",
	"228 05", "",
	"228 06", "SBB-CFF-FFS",
	"228 07", "IN&Phone",
	"228 08", "Tele2",
	"228 50", "",
	"228 51", "",
	"230 01", "T-Mobile",
	"230 02", "O2",
	"230 03", "Vodafone",
	"230 04", "U:fon",
	"230 98", "",
	"230 99", "Vodafone",
	"231 01", "Orange",
	"231 02", "T-Mobile",
	"231 03", "",
	"231 04", "T-Mobile",
	"231 05", "",
	"231 06", "O2",
	"231 99", "ZSR",
	"232 01", "A1",
	"232 03", "T-Mobile",
	"232 05", "Orange",
	"232 07", "tele.ring",
	"232 09", "A1",
	"232 10", "3",
	"232 11", "bob",
	"232 12", "yesss",
	"232 14", "3",
	"232 15", "Barablu",
	"234 00", "BT",
	"234 01", "UK01",
	"234 02", "O2",
	"234 03", "Airtel Vodafone",
	"234 03", "Airtel Vodafone",
	"234 03", "Airtel-Vodafone",
	"234 04", "FMS Solutions Ltd",
	"234 07", "",
	"234 08", "",
	"234 09", "Sure Mobile",
	"234 10", "O2",
	"234 11", "O2",
	"234 12", "Railtrack",
	"234 14", "Hay Systems Ltd",
	"234 15", "Vodafone",
	"234 16", "Opal Telecom Ltd",
	"234 18", "Cloud9",
	"234 19", "Teleware",
	"234 20", "Three",
	"234 22", "RoutoMessaging",
	"234 25", "Truphone",
	"234 30", "T-Mobile",
	"234 31", "Virgin",
	"234 32", "Virgin",
	"234 33", "Orange",
	"234 34", "Orange",
	"234 50", "JT-Wave",
	"234 50", "JT-Wave",
	"234 50", "Wave Telecom",
	"234 55", "",
	"234 55", "Sure Mobile",
	"234 55", "Sure Mobile",
	"234 58", "",
	"234 58", "Pronto GSM",
	"234 75", "Inquam",
	"234 77", "BT",
	"234 78", "Airwave",
	"238 01", "TDC",
	"238 02", "Telenor",
	"238 03", "",
	"238 05", "",
	"238 06", "3",
	"238 07", "",
	"238 09", "",
	"238 10", "TDC",
	"238 11", "",
	"238 12", "",
	"238 20", "Telia",
	"238 30", "Telia",
	"238 40", "",
	"238 77", "Telenor",
	"240 01", "Telia",
	"240 02", "3",
	"240 03", "Ice.net",
	"240 04", "",
	"240 05", "Sweden 3G",
	"240 06", "Telenor",
	"240 07", "Tele2",
	"240 08", "Telenor",
	"240 09", "djuice",
	"240 10", "Spring Mobil",
	"240 11", "",
	"240 12", "",
	"240 13", "",
	"240 14", "",
	"240 15", "",
	"240 16", "",
	"240 17", "",
	"240 20", "",
	"240 21", "MobiSir",
	"240 25", "",
	"240 26", "",
	"242 01", "Telenor",
	"242 02", "NetCom",
	"242 03", "MTU",
	"242 04", "Tele2",
	"242 05", "Network Norway",
	"242 06", "Ice",
	"242 07", "Ventelo",
	"242 08", "TDC",
	"242 09", "Barablu",
	"242 11", "SystemNet",
	"242 20", "",
	"242 23", "Lyca",
	"244 03", "DNA",
	"244 05", "Elisa",
	"244 07", "Nokia",
	"244 08", "",
	"244 10", "",
	"244 11", "VIRVE",
	"244 12", "DNA",
	"244 14", "AMT",
	"244 15", "SAMK",
	"244 21", "Saunalahti",
	"244 29", "",
	"244 91", "Sonera",
	"246 01", "Omnitel",
	"246 02", "BITE",
	"246 03", "Tele 2",
	"247 01", "LMT",
	"247 02", "Tele2",
	"247 03", "TRIATEL",
	"247 05", "Bite",
	"247 06", "",
	"247 07", "MTS",
	"247 08", "IZZI",
	"247 09", "Camel Mobile",
	"248 01", "EMT",
	"248 02", "Elisa",
	"248 03", "Tele 2",
	"248 04", "",
	"248 05", "",
	"248 06", "",
	"250 01", "MTS",
	"250 02", "MegaFon",
	"250 03", "NCC",
	"250 04", "Sibchallenge",
	"250 05", "ETK",
	"250 06", "Skylink",
	"250 07", "SMARTS",
	"250 09", "Skylink",
	"250 10", "DTC",
	"250 11", "",
	"250 12", "Akos",
	"250 12", "Baykalwestcom",
	"250 13", "KUGSM",
	"250 15", "SMARTS",
	"250 16", "NTC",
	"250 17", "Utel",
	"250 19", "INDIGO",
	"250 20", "Tele2",
	"250 23", "Mobicom - Novosibirsk",
	"250 28", "Beeline",
	"250 30", "Megafon",
	"250 35", "MOTIV",
	"250 38", "Tambov GSM",
	"250 39", "Utel",
	"250 44", "",
	"250 92", "",
	"250 93", "",
	"250 99", "Beeline",
	"255 01", "MTS",
	"255 02", "Beeline",
	"255 03", "Kyivstar",
	"255 04", "IT",
	"255 05", "Golden Telecom",
	"255 06", "life:)",
	"255 07", "Ukrtelecom",
	"255 21", "PEOPLEnet",
	"255 23", "CDMA Ukraine",
	"257 01", "velcom",
	"257 02", "MTS",
	"257 03", "DIALLOG",
	"257 04", "life:)",
	"259 01", "Orange",
	"259 02", "Moldcell",
	"259 03", "IDC",
	"259 03", "Unite",
	"259 04", "Eventis",
	"259 05", "Unite",
	"260 01", "Plus",
	"260 02", "Era",
	"260 03", "Orange",
	"260 04", "",
	"260 05", "",
	"260 06", "Play",
	"260 07", "Netia",
	"260 08", "",
	"260 09", "",
	"260 10", "Sferia",
	"260 11", "Nordisk Polska",
	"260 12", "Cyfrowy Polsat",
	"260 13", "Sferia",
	"260 14", "Sferia",
	"260 15", "CenterNet",
	"260 16", "Mobyland",
	"260 17", "Aero2",
	"262 01", "T-Mobile",
	"262 02", "Vodafone",
	"262 03", "E-Plus",
	"262 04", "Vodafone",
	"262 05", "E-Plus",
	"262 06", "T-Mobile",
	"262 07", "O2",
	"262 08", "O2",
	"262 09", "Vodafone",
	"262 10", "",
	"262 11", "O2",
	"262 12", "",
	"262 13", "",
	"262 14", "",
	"262 15", "Airdata",
	"262 16", "Vistream",
	"262 42", "27C3",
	"262 43", "LYCA",
	"262 60", "",
	"262 76", "",
	"262 77", "E-Plus",
	"262 901", "Debitel",
	"262 92", "Nash Technologies",
	"266 01", "GibTel",
	"266 06", "CTS Mobile",
	"268 01", "Vodafone",
	"268 03", "Optimus",
	"268 06", "TMN",
	"268 21", "Zapp",
	"270 01", "LuxGSM",
	"270 77", "Tango",
	"270 99", "Orange",
	"272 01", "Vodafone",
	"272 02", "O2",
	"272 03", "Meteor",
	"272 04", "",
	"272 05", "3",
	"272 07", "Eircom",
	"272 09", "",
	"274 01", "Siminn",
	"274 02", "Vodafone",
	"274 03", "Vodafone",
	"274 04", "Viking",
	"274 06", "",
	"274 07", "IceCell",
	"274 08", "On-waves",
	"274 11", "Nova",
	"274 12", "Tal",
	"276 01", "AMC",
	"276 02", "Vodafone",
	"276 03", "Eagle Mobile",
	"276 04", "Plus Communication",
	"278 01", "Vodafone",
	"278 21", "GO",
	"278 77", "Melita",
	"280 01", "Cytamobile-Vodafone",
	"280 10", "MTN",
	"282 01", "Geocell",
	"282 02", "MagtiCom",
	"282 03", "Iberiatel",
	"282 04", "Beeline",
	"282 05", "SILKNET",
	"283 01", "Beeline",
	"283 04", "Karabakh Telecom",
	"283 05", "VivaCell-MTS",
	"283 10", "Orange",
	"284 01", "M-Tel",
	"284 03", "Vivacom",
	"284 04", "Undisclosed",
	"284 05", "GLOBUL",
	"286 01", "Turkcell",
	"286 02", "Vodafone",
	"286 03", "Avea",
	"286 04", "",
	"288 01", "Faroese Telecom",
	"288 02", "Vodafone",
	"289 67", "Aquafon",
	"289 88", "A-Mobile",
	"290 01", "",
	"292 01", "PRIMA",
	"293 40", "Si.mobil",
	"293 41", "D3 Mobile",
	"293 41", "IPKO",
	"293 41", "Mobitel",
	"293 64", "T-2",
	"293 70", "Tusmobil",
	"294 01", "T-Mobile MK",
	"294 02", "ONE",
	"294 03", "Vip MK",
	"295 01", "Swisscom",
	"295 02", "Orange",
	"295 05", "FL1",
	"295 77", "Tele 2",
	"297 01", "Telenor",
	"297 02", "T-Mobile",
	"297 03", "m:tel CG",

	"302 220", "Telus",
	"302 221", "Telus",
	"302 290", "",
	"302 320", "Mobilicity",
	"302 350", "FIRST",
	"302 360", "MiKe",
	"302 361", "Telus",
	"302 370", "Fido",
	"302 380", "DMTS",
	"302 490", "WIND Mobile",
	"302 500", "Videotron",
	"302 510", "Videotron",
	"302 610", "Bell",
	"302 610", "Bell",
	"302 620", "ICE Wireless",
	"302 640", "Bell",
	"302 651", "Bell",
	"302 652", "",
	"302 653", "Telus",
	"302 655", "MTS",
	"302 656", "TBay",
	"302 657", "Telus",
	"302 660", "MTS",
	"302 680", "SaskTel",
	"302 701", "",
	"302 702", "",
	"302 703", "",
	"302 710", "Globalstar",
	"302 720", "Rogers Wireless",
	"302 780", "SaskTel",
	"302 880", "Bell / Telus / SaskTel",
	"308 01", "Ameris",
	"310 000", "Mid-Tex Cellular",
	"310 004", "Verizon",
	"310 005", "Verizon",
	"310 010", "",
	"310 012", "Verizon",
	"310 013", "MobileTel",
	"310 014", "",
	"310 016", "",
	"310 017", "",
	"310 020", "",
	"310 026", "T-Mobile",
	"310 030", "Centennial",
	"310 032", "IT&E Wireless",
	"310 033", "",
	"310 034", "Airpeak",
	"310 040", "Concho",
	"310 046", "SIMMETRY",
	"310 060", "",
	"310 070", "",
	"310 080", "Corr",
	"310 090", "AT&T",
	"310 100", "Plateau Wireless",
	"310 110", "PTI Pacifica",
	"310 120", "Sprint",
	"310 140", "mPulse",
	"310 150", "AT&T",
	"310 160", "",
	"310 170", "",
	"310 180", "West Central",
	"310 190", "Dutch Harbor",
	"310 200", "",
	"310 210", "",
	"310 220", "",
	"310 230", "",
	"310 240", "",
	"310 250", "",
	"310 260", "",
	"310 270", "",
	"310 280", "",
	"310 290", "",
	"310 300", "iSmart Mobile",
	"310 310", "",
	"310 311", "",
	"310 320", "Cellular One",
	"310 330", "T-Mobile",
	"310 340", "Westlink",
	"310 350", "",
	"310 370", "Guamcell",
	"310 380", "AT&T",
	"310 390", "Cellular One of East Texas",
	"310 400", "i CAN_GSM",
	"310 410", "AT&T",
	"310 420", "Cincinnati Bell",
	"310 430", "",
	"310 440", "Cellular One",
	"310 450", "Viaero",
	"310 460", "Simmetry",
	"310 470", "nTelos",
	"310 480", "",
	"310 490", "T-Mobile",
	"310 500", "Alltel",
	"310 510", "Airtel",
	"310 520", "VeriSign",
	"310 530", "",
	"310 540", "Oklahoma Western",
	"310 560", "AT&T",
	"310 570", "Cellular One",
	"310 580", "T-Mobile",
	"310 590", "Alltel",
	"310 59", "Cellular One",
	"310 610", "Epic Touch",
	"310 620", "Coleman County Telecom",
	"310 630", "AmeriLink PCS",
	"310 640", "Airadigm",
	"310 650", "Jasper",
	"310 660", "T-Mobile",
	"310 670", "Northstar",
	"310 680", "AT&T",
	"310 690", "Conestoga",
	"310 730", "SeaMobile",
	"310 740", "Convey",
	"310 760", "Panhandle",
	"310 770", "i wireless",
	"310 780", "",
	"310 790", "PinPoint",
	"310 800", "",
	"310 830", "Caprock",
	"310 840", "telna Mobile",
	"310 850", "Aeris",
	"310 870", "PACE",
	"310 880", "Advantage",
	"310 890", "Unicel",
	"310 900", "Mid-Rivers Wireless",
	"310 910", "First Cellular",
	"310 940", "",
	"310 950", "XIT Wireless",
	"310 960", "Plateau Wireless",
	"310 970", "Globalstar",
	"310 980", "",
	"310 990", "",
	"311 000", "",
	"311 010", "Chariton Valley",
	"311 020", "",
	"311 030", "",
	"311 040", "",
	"311 050", "",
	"311 060", "Farmers Cellular",
	"311 070", "Easterbrooke",
	"311 080", "Pine Cellular",
	"311 090", "Long Lines Wireless",
	"311 100", "",
	"311 110", "",
	"311 120", "",
	"311 130", "",
	"311 140", "Sprocket",
	"311 150", "",
	"311 160", "",
	"311 170", "PetroCom",
	"311 180", "",
	"311 190", "",
	"311 210", "Farmers Cellular",
	"311 250", "i CAN_GSM",
	"311 330", "Bug Tussel Wireless",
	"311 480", "Verizon",
	"311 481", "Verizon",
	"311 482", "Verizon",
	"311 483", "Verizon",
	"311 484", "Verizon",
	"311 485", "Verizon",
	"311 486", "Verizon",
	"311 487", "Verizon",
	"311 488", "Verizon",
	"311 489", "Verizon",
	"316 010", "Nextel",
	"316 011", "",
	"330 11", "Claro",
	"334 01", "Nextel",
	"334 02", "Telcel",
	"334 03", "movistar",
	"334 04", "Iusacell / Unefon",
	"334 050", "Iusacell",
	"338 020", "LIME",
	"338 050", "Digicel",
	"338 050", "Digicel",
	"338 050", "Digicel",
	"338 050", "Digicel",
	"338 050", "Digicel Bermuda",
	"338 05", "Digicel",
	"338 070", "Claro",
	"338 180", "LIME",
	"340 01", "Orange",
	"340 01", "Orange",
	"340 02", "Outremer",
	"340 02", "Outremer",
	"340 03", "Telcell",
	"340 08", "MIO GSM",
	"340 20", "Digicel",
	"340 20", "Digicel",
	"342 600", "LIME",
	"342 750", "Digicel",
	"342 820", "",
	"344 030", "APUA",
	"344 920", "LIME",
	"346 140", "LIME",
	"348 170", "LIME",
	"348 570", "CCT Boatphone",
	"348 770", "Digicel",
	"350 01", "Digicel Bermuda",
	"350 02", "Mobility",
	"352 030", "Digicel",
	"352 110", "Cable & Wireless",
	"356 050", "Digicel",
	"356 110", "",
	"358 050", "Digicel",
	"358 110", "",
	"360 070", "Digicel",
	"360 100", "Cingular Wireless",
	"360 110", "Cable & Wireless",
	"362 51", "Telcell",
	"362 69", "Digicel",
	"362 91", "UTS",
	"362 94", "Bayos",
	"362 95", "MIO",
	"363 01", "SETAR",
	"363 02", "Digicel",
	"364 390", "BaTelCo",
	"365 010", "",
	"365 840", "",
	"366 020", "Digicel",
	"366 110", "",
	"368 01", "CUBACEL",
	"370 01", "Orange",
	"370 02", "Claro",
	"370 03", "Tricom",
	"370 04", "Viva",
	"372 01", "Voila",
	"374 12", "bmobile",
	"374 130", "Digicel",
	"376 350", "C&W",
	"376 352", "Islandcom",

	"400 01", "Azercell",
	"400 02", "Bakcell",
	"400 03", "FONEX",
	"400 04", "Nar Mobile",
	"401 01", "Beeline",
	"401 02", "Kcell",
	"401 07", "Dalacom",
	"401 08", "Kazakhtelecom",
	"401 77", "Mobile Telecom Service",
	"402 11", "B-Mobile",
	"402 77", "TashiCell",
	"404 01", "Vodafone IN",
	"404 02", "AirTel",
	"404 03", "AirTel",
	"404 04", "IDEA",
	"404 05", "Vodafone IN",
	"404 07", "IDEA",
	"404 09", "Reliance",
	"404 10", "AirTel",
	"404 11", "Vodafone IN",
	"404 12", "IDEA",
	"404 13", "Vodafone IN",
	"404 14", "IDEA",
	"404 15", "Vodafone IN",
	"404 17", "AIRCEL",
	"404 19", "IDEA",
	"404 20", "Vodafone IN",
	"404 21", "Loop Mobile",
	"404 22", "IDEA",
	"404 24", "IDEA",
	"404 27", "Vodafone IN",
	"404 28", "AIRCEL",
	"404 29", "AIRCEL",
	"404 30", "Vodafone IN",
	"404 31", "AirTel",
	"404 34", "CellOne",
	"404 36", "Reliance",
	"404 37", "Aircel",
	"404 38", "CellOne",
	"404 41", "Aircel",
	"404 42", "Aircel",
	"404 44", "IDEA",
	"404 45", "Airtel",
	"404 48", "Dishnet Wireless",
	"404 49", "Airtel",
	"404 51", "CellOne",
	"404 52", "Reliance",
	"404 53", "CellOne",
	"404 54", "CellOne",
	"404 55", "CellOne",
	"404 56", "IDEA",
	"404 57", "CellOne",
	"404 58", "CellOne",
	"404 59", "CellOne",
	"404 60", "Vodafone IN",
	"404 62", "CellOne",
	"404 64", "CellOne",
	"404 66", "CellOne",
	"404 67", "Reliance GSM",
	"404 68", "DOLPHIN",
	"404 69", "DOLPHIN",
	"404 72", "CellOne",
	"404 74", "CellOne",
	"404 76", "CellOne",
	"404 78", "Idea Cellular Ltd",
	"404 80", "BSNL MOBILE",
	"404 81", "CellOne",
	"404 82", "Idea",
	"404 83", "Reliance Smart GSM",
	"404 84", "Vodafone IN",
	"404 85", "Reliance",
	"404 86", "Vodafone IN",
	"404 87", "Idea",
	"404 88", "Vodafone IN",
	"404 89", "Idea",
	"404 90", "AirTel",
	"404 91", "AIRCEL",
	"404 92", "AirTel",
	"404 93", "AirTel",
	"404 96", "AirTel",
	"405 01", "Reliance",
	"405 025", "TATA DOCOMO",
	"405 026", "TATA DOCOMO",
	"405 027", "TATA DOCOMO",
	"405 029", "TATA DOCOMO",
	"405 030", "TATA DOCOMO",
	"405 031", "TATA DOCOMO",
	"405 032", "TATA DOCOMO",
	"405 033", "TATA DOCOMO",
	"405 034", "TATA DOCOMO",
	"405 035", "TATA DOCOMO",
	"405 036", "TATA DOCOMO",
	"405 037", "TATA DOCOMO",
	"405 038", "TATA DOCOMO",
	"405 039", "TATA DOCOMO",
	"405 03", "Reliance",
	"405 041", "TATA DOCOMO",
	"405 042", "TATA DOCOMO",
	"405 043", "TATA DOCOMO",
	"405 044", "TATA DOCOMO",
	"405 045", "TATA DOCOMO",
	"405 046", "TATA DOCOMO",
	"405 047", "TATA DOCOMO",
	"405 04", "Reliance",
	"405 05", "Reliance",
	"405 10", "Reliance",
	"405 13", "Reliance",
	"405 51", "AirTel",
	"405 52", "AirTel",
	"405 54", "AirTel",
	"405 56", "AirTel",
	"405 66", "Vodafone IN",
	"405 70", "IDEA",
	"405 750", "Vodafone IN",
	"405 751", "Vodafone IN",
	"405 752", "Vodafone IN",
	"405 753", "Vodafone IN",
	"405 754", "Vodafone IN",
	"405 755", "Vodafone IN",
	"405 756", "Vodafone IN",
	"405 799", "IDEA",
	"405 800", "AIRCEL",
	"405 801", "AIRCEL",
	"405 802", "AIRCEL",
	"405 803", "AIRCEL",
	"405 804", "AIRCEL",
	"405 805", "AIRCEL",
	"405 806", "AIRCEL",
	"405 807", "AIRCEL",
	"405 808", "AIRCEL",
	"405 809", "AIRCEL",
	"405 810", "AIRCEL",
	"405 811", "AIRCEL",
	"405 812", "AIRCEL",
	"405 818", "Uninor",
	"405 819", "Uninor",
	"405 820", "Uninor",
	"405 821", "Uninor",
	"405 822", "Uninor",
	"405 824", "Videocon Datacom",
	"405 827", "Videocon Datacom",
	"405 834", "Videocon Datacom",
	"405 844", "Uninor",
	"405 845", "IDEA",
	"405 848", "IDEA",
	"405 850", "IDEA",
	"405 855", "Loop Mobile",
	"405 864", "Loop Mobile",
	"405 865", "Loop Mobile",
	"405 875", "Uninor",
	"405 880", "Uninor",
	"405 881", "S Tel",
	"405 912", "Etisalat DB(cheers)",
	"405 913", "Etisalat DB(cheers)",
	"405 914", "Etisalat DB(cheers)",
	"405 917", "Etisalat DB(cheers)",
	"405 927", "Uninor",
	"405 929", "Uninor",
	"410 01", "Mobilink",
	"410 03", "Ufone",
	"410 04", "Zong",
	"410 06", "Telenor",
	"410 07", "Warid",
	"410 08", "Vodafone",
	"412 01", "AWCC",
	"412 20", "Roshan",
	"412 40", "MTN",
	"412 50", "Etisalat",
	"413 01", "Mobitel",
	"413 02", "Dialog",
	"413 03", "Etisalat",
	"413 05", "Airtel",
	"413 08", "Hutch",
	"414 01", "MPT",
	"415 01", "Alfa",
	"415 03", "mtc touch",
	"415 05", "Ogero Mobile",
	"416 01", "zain JO",
	"416 02", "XPress Telecom",
	"416 03", "Umniah",
	"416 77", "Orange",
	"417 01", "Syriatel",
	"417 02", "MTN",
	"418 05", "Asia Cell",
	"418 08", "SanaTel",
	"418 20", "Zain",
	"418 30", "Zain",
	"418 40", "Korek",
	"419 02", "zain KW",
	"419 03", "Wataniya",
	"419 04", "Viva",
	"420 01", "Al Jawal",
	"420 03", "Mobily",
	"420 04", "Zain SA",
	"421 01", "SabaFon",
	"421 02", "MTN",
	"421 03", "Yemen Mobile",
	"421 04", "HiTS-UNITEL",
	"422 02", "Oman Mobile",
	"422 03", "Nawras",
	"424 02", "Etisalat",
	"424 03", "du",
	"425 01", "Orange",
	"425 02", "Cellcom",
	"425 03", "Pelephone",
	"425 059", "Jawwal",
	"425 06", "Wataniya",
	"425 77", "Mirs",
	"426 01", "Batelco",
	"426 02", "zain BH",
	"426 04", "VIVA",
	"427 01", "Qtel",
	"427 02", "Vodafone",
	"428 88", "Unitel",
	"428 91", "Skytel",
	"428 98", "G.Mobile",
	"428 99", "MobiCom",
	"429 01", "Namaste / NT Mobile",
	"429 02", "Ncell",
	"429 03", "Sky/C-Phone",
	"429 04", "SmartCell",
	"432 11", "IR-MCI",
	"432 14", "TKC",
	"432 19", "MTCE",
	"432 32", "Taliya",
	"432 35", "Irancell",
	"432 70", "TCI",
	"434 01", "",
	"434 02", "",
	"434 04", "Beeline",
	"434 05", "Ucell",
	"434 06", "",
	"434 07", "MTS",
	"436 01", "Tcell",
	"436 02", "Tcell",
	"436 03", "MLT",
	"436 04", "Babilon-M",
	"436 05", "Beeline",
	"436 12", "Tcell",
	"437 01", "Beeline",
	"437 03", "Fonex",
	"437 05", "MegaCom",
	"437 09", "O!",
	"438 01", "MTS",
	"438 02", "TM-Cell",
	"440 00", "eMobile",
	"440 01", "NTT docomo",
	"440 02", "NTT docomo",
	"440 03", "NTT docomo",
	"440 04", "SoftBank",
	"440 06", "SoftBank",
	"440 07", "KDDI",
	"440 08", "KDDI",
	"440 09", "NTT docomo",
	"440 10", "NTT docomo",
	"440 11", "NTT docomo",
	"440 12", "NTT docomo",
	"440 13", "NTT docomo",
	"440 14", "NTT docomo",
	"440 15", "NTT docomo",
	"440 16", "NTT docomo",
	"440 17", "NTT docomo",
	"440 18", "NTT docomo",
	"440 19", "NTT docomo",
	"440 20", "SoftBank",
	"440 21", "NTT docomo",
	"440 22", "NTT docomo",
	"440 23", "DoCoMo",
	"440 24", "DoCoMo",
	"440 25", "DoCoMo",
	"440 26", "DoCoMo",
	"440 27", "DoCoMo",
	"440 28", "DoCoMo",
	"440 29", "DoCoMo",
	"440 30", "DoCoMo",
	"440 31", "DoCoMo",
	"440 32", "DoCoMo",
	"440 33", "DoCoMo",
	"440 34", "DoCoMo",
	"440 35", "DoCoMo",
	"440 36", "DoCoMo",
	"440 37", "DoCoMo",
	"440 38", "DoCoMo",
	"440 39", "DoCoMo",
	"440 40", "SoftBank",
	"440 41", "SoftBank",
	"440 42", "SoftBank",
	"440 43", "SoftBank",
	"440 44", "SoftBank",
	"440 45", "SoftBank",
	"440 46", "SoftBank",
	"440 47", "SoftBank",
	"440 48", "SoftBank",
	"440 49", "DoCoMo",
	"440 50", "KDDI",
	"440 51", "KDDI",
	"440 52", "KDDI",
	"440 53", "KDDI",
	"440 54", "KDDI",
	"440 55", "KDDI",
	"440 56", "KDDI",
	"440 58", "DoCoMo",
	"440 60", "DoCoMo",
	"440 61", "DoCoMo",
	"440 62", "DoCoMo",
	"440 63", "DoCoMo",
	"440 64", "DoCoMo",
	"440 65", "DoCoMo",
	"440 66", "DoCoMo",
	"440 67", "DoCoMo",
	"440 68", "DoCoMo",
	"440 69", "DoCoMo",
	"440 70", "au",
	"440 71", "KDDI",
	"440 72", "KDDI",
	"440 73", "KDDI",
	"440 74", "KDDI",
	"440 75", "KDDI",
	"440 76", "KDDI",
	"440 77", "KDDI",
	"440 78", "",
	"440 79", "KDDI",
	"440 80", "TU-KA",
	"440 81", "TU-KA",
	"440 82", "TU-KA",
	"440 83", "TU-KA",
	"440 84", "TU-KA",
	"440 85", "TU-KA",
	"440 86", "TU-KA",
	"440 87", "DoCoMo",
	"440 88", "KDDI",
	"440 89", "KDDI",
	"440 90", "SoftBank",
	"440 92", "SoftBank",
	"440 93", "SoftBank",
	"440 94", "SoftBank",
	"440 95", "SoftBank",
	"440 96", "SoftBank",
	"440 97", "SoftBank",
	"440 98", "SoftBank",
	"440 99", "DoCoMo",
	"450 02", "KT",
	"450 03", "Power 017",
	"450 04", "KT",
	"450 05", "SKT",
	"450 06", "LGT",
	"450 08", "olleh",
	"452 01", "MobiFone",
	"452 02", "Vinaphone",
	"452 03", "S-Fone",
	"452 04", "Viettel Mobile",
	"452 05", "Vietnamobile",
	"452 06", "EVNTelecom",
	"452 07", "Beeline VN",
	"452 08", "3G EVNTelecom",
	"454 00", "1O1O / One2Free",
	"454 01", "",
	"454 02", "",
	"454 03", "3 (3G)",
	"454 04", "3 (2G)",
	"454 05", "3 (CDMA)",
	"454 06", "SmarTone-Vodafone",
	"454 07", "",
	"454 08", "",
	"454 09", "",
	"454 10", "New World Mobility",
	"454 11", "",
	"454 12", "CMCC HK",
	"454 14", "",
	"454 15", "",
	"454 16", "PCCW Mobile (2G)",
	"454 17", "",
	"454 18", "",
	"454 19", "PCCW Mobile (3G)",
	"454 29", "PCCW Mobile (CDMA)",
	"455 00", "SmarTone",
	"455 01", "CTM",
	"455 02", "China Telecom",
	"455 03", "3",
	"455 04", "CTM",
	"455 05", "3",
	"456 01", "Mobitel",
	"456 02", "hello",
	"456 03", "",
	"456 04", "qb",
	"456 05", "Star-Cell",
	"456 06", "Smart Mobile",
	"456 08", "Metfone",
	"456 09", "Beeline",
	"456 11", "Excell",
	"456 18", "Mfone",
	"457 01", "LaoTel",
	"457 02", "ETL",
	"457 03", "Unitel",
	"457 08", "Tigo",
	"460 00", "China Mobile",
	"460 01", "China Unicom",
	"460 02", "China Mobile",
	"460 03", "China Telecom",
	"460 05", "China Telecom",
	"460 06", "China Unicom",
	"460 07", "China Mobile",
	"460 20", "China Tietong",
	"466 01", "FarEasTone",
	"466 02", "APTG",
	"466 06", "Tuntex",
	"466 11", "Chunghwa LDM",
	"466 88", "KG Telecom",
	"466 89", "VIBO",
	"466 92", "Chungwa",
	"466 93", "MobiTai",
	"466 97", "Taiwan Mobile",
	"466 99", "TransAsia",
	"467 193", "SUN NET",
	"470 01", "Grameenphone",
	"470 02", "Robi",
	"470 03", "Banglalink",
	"470 04", "TeleTalk",
	"470 05", "Citycell",
	"470 06", "Airtel",
	"470 07", "Warid Telecom International Ltd",
	"472 01", "Dhiraagu",
	"472 02", "Wataniya",

	"502 01", "TM CDMA",
	"502 12", "Maxis",
	"502 13", "Celcom",
	"502 16", "DiGi",
	"502 17", "Maxis",
	"502 18", "TM CDMA",
	"502 18", "U Mobile",
	"502 19", "Celcom",
	"505 01", "Telstra",
	"505 02", "Optus",
	"505 03", "Vodafone",
	"505 04", "",
	"505 05", "Ozitel",
	"505 06", "3",
	"505 08", "One.Tel",
	"505 09", "Airnet",
	"505 12", "3",
	"505 13", "Railcorp",
	"505 14", "AAPT",
	"505 15", "3GIS",
	"505 16", "Victorian Rail Track",
	"505 21", "SOUL",
	"505 24", "Advanced Communications Technologies Pty. Ltd.",
	"505 38", "Crazy John's",
	"505 71", "Telstra",
	"505 72", "Telstra",
	"505 88", "Localstar Holding Pty. Ltd.",
	"505 90", "Optus",
	"505 99", "One.Tel",
	"510 00", "PSN",
	"510 01", "INDOSAT",
	"510 03", "StarOne",
	"510 07", "TelkomFlexi",
	"510 08", "AXIS",
	"510 09", "SMART",
	"510 10", "Telkomsel",
	"510 11", "XL",
	"510 20", "TELKOMMobile",
	"510 21", "IM3",
	"510 27", "Ceria",
	"510 28", "Fren/Hepi",
	"510 89", "3",
	"510 99", "Esia",
	"514 02", "",
	"515 01", "Islacom",
	"515 02", "Globe",
	"515 03", "Smart",
	"515 05", "Sun",
	"515 11", "",
	"515 18", "Cure",
	"515 88", "",
	"520 00", "Hutch",
	"520 01", "AIS",
	"520 02", "CAT CDMA",
	"520 10", "",
	"520 15", "TOT 3G",
	"520 18", "dtac",
	"520 23", "AIS GSM 1800",
	"520 88", "Real Move",
	"520 99", "True Move",
	"525 01", "SingTel",
	"525 02", "SingTel-G18",
	"525 03", "M1",
	"525 05", "StarHub",
	"525 12", "",
	"528 01", "",
	"528 02", "B-Mobile",
	"528 11", "DSTCom",
	"530 00", "Telecom",
	"530 01", "Vodafone",
	"530 02", "Telecom",
	"530 03", "Woosh",
	"530 04", "TelstraClear",
	"530 05", "XT Mobile Network",
	"530 24", "2degrees",
	"537 01", "B-Mobile",
	"537 03", "Digicel",
	"539 01", "",
	"539 43", "",
	"539 88", "Digicel",
	"540 1", "BREEZE",
	"541 01", "SMILE",
	"542 01", "Vodafone",
	"542 02", "Digicel",
	"545 09", "Kiribati Frigate",
	"546 01", "Mobilis",
	"547 20", "Vini",
	"548 01", "",
	"549 01", "Digicel",
	"549 27", "SamoaTel",
	"550 01", "",
	"552 01", "PNCC",
	"552 80", "Palau Mobile",
	"553 01", "TTC",

	"602 01", "Mobinil",
	"602 02", "Vodafone",
	"602 03", "Etisalat",
	"603 01", "Mobilis",
	"603 02", "Djezzy",
	"603 03", "Nedjma",
	"604 00", "Meditel",
	"604 01", "IAM",
	"604 02", "INWI",
	"605 01", "Orange",
	"605 02", "Tunicell",
	"605 03", "Tunisiana",
	"606 00", "Libyana",
	"606 01", "Madar",
	"606 02", "Al-Jeel Phone",
	"606 03", "Libya Phone",
	"606 06", "Hatef Libya",
	"607 01", "Gamcel",
	"607 02", "Africel",
	"607 03", "Comium",
	"607 04", "QCell",
	"608 01", "Orange (telecommunications)",
	"608 02", "Tigo",
	"608 03", "Expresso",
	"609 01", "Mattel",
	"609 10", "Mauritel",
	"610 01", "Malitel",
	"610 02", "Orange",
	"611 01", "Orange S.A.",
	"611 02", "Sotelgui",
	"611 03", "Telecel Guinee",
	"611 04", "MTN",
	"611 05", "Cellcom",
	"612 01", "",
	"612 02", "Moov",
	"612 03", "Orange",
	"612 04", "KoZ",
	"612 05", "MTN",
	"612 06", "ORICEL",
	"613 01", "Telmob",
	"613 02", "Zain",
	"613 03", "Telecel Faso",
	"614 01", "SahelCom",
	"614 02", "Zain",
	"614 03", "Telecel",
	"614 04", "Orange",
	"615 01", "Togo Cell",
	"615 03", "Moov",
	"616 01", "Libercom",
	"616 02", "Moov",
	"616 03", "MTN",
	"616 04", "BBCOM",
	"616 05", "Glo",
	"617 01", "Orange",
	"617 02", "MTML",
	"617 10", "Emtel",
	"618 01", "Lonestar Cell",
	"618 02", "Libercell",
	"618 04", "Comium",
	"618 07", "Cellcom",
	"618 20", "LIBTELCO",
	"619 01", "Zain",
	"619 02", "Millicom",
	"619 03", "Datatel",
	"619 04", "Comium",
	"619 05", "Africell",
	"619 25", "Mobitel",
	"620 01", "MTN",
	"620 02", "Vodafone",
	"620 03", "tiGO",
	"620 04", "",
	"620 06", "Zain",
	"621 20", "Zain",
	"621 30", "MTN",
	"621 40", "M-Tel",
	"621 50", "Glo",
	"621 60", "Etisalat",
	"622 01", "Airtel",
	"622 02", "",
	"622 02", "TAWALI",
	"622 03", "",
	"622 04", "Salam",
	"623 01", "CTP",
	"623 02", "TC",
	"623 03", "Orange",
	"623 04", "Nationlink",
	"624 01", "MTN Cameroon",
	"624 02", "Orange",
	"625 01", "CVMOVEL",
	"625 02", "T+",
	"626 01", "CSTmovel",
	"627 01", "Orange GQ",
	"627 03", "Hits GQ",
	"628 01", "Libertis",
	"628 02", "",
	"628 03", "Zain",
	"628 04", "Azur",
	"629 01", "Zain",
	"629 07", "",
	"629 10", "Libertis Telecom",
	"630 01", "Vodacom",
	"630 02", "Zain",
	"630 04", "",
	"630 05", "Supercell",
	"630 86", "CCT",
	"630 89", "SAIT Telecom",
	"631 02", "UNITEL",
	"632 02", "Areeba",
	"632 03", "Orange",
	"633 01", "Cable & Wireless",
	"633 02", "Mediatech International",
	"633 10", "Airtel",
	"634 01", "Zain SD",
	"634 02", "MTN",
	"634 05", "Vivacell",
	"634 07", "Sudani One",
	"635 10", "MTN",
	"635 13", "Tigo",
	"636 01", "ETHMTN",
	"637 01", "Telesom",
	"637 04", "Somafone",
	"637 10", "Nationlink",
	"637 25", "Hormuud",
	"637 30", "Golis",
	"637 82", "Telcom",
	"638 01", "Evatis",
	"639 02", "Safaricom",
	"639 03", "Zain",
	"639 05", "yu",
	"639 07", "Orange Kenya",
	"640 02", "tiGO",
	"640 03", "Zantel",
	"640 04", "Vodacom",
	"640 05", "Zain",
	"640 06", "SasaTel",
	"640 07", "Life",
	"641 01", "Zain",
	"641 10", "MTN",
	"641 11", "",
	"641 14", "Orange",
	"641 22", "Warid Telecom",
	"642 01", "Spacetel",
	"642 02", "Africell",
	"642 03", "Onatel",
	"642 07", "Smart Mobile",
	"642 08", "HiTs Telecom",
	"642 82", "U-COM Burundi",
	"643 01", "mCel",
	"643 04", "Vodacom",
	"645 01", "Zain",
	"645 02", "MTN",
	"645 03", "ZAMTEL",
	"646 01", "Zain",
	"646 02", "Orange",
	"646 03", "Sacel",
	"646 04", "Telma",
	"647 00", "Orange",
	"647 02", "Outremer",
	"647 10", "SFR Reunion",
	"648 01", "Net*One",
	"648 03", "Telecel",
	"648 04", "Econet",
	"649 01", "MTC",
	"649 02", "switch",
	"649 03", "Leo",
	"650 01", "TNM",
	"650 10", "Airtel",
	"651 01", "Vodacom",
	"651 02", "",
	"652 01", "Mascom",
	"652 02", "Orange",
	"652 04", "BTC Mobile",
	"653 10", "",
	"654 01", "",
	"655 01", "Vodacom",
	"655 02", "Telkom Mobile / 8.ta",
	"655 06", "Sentech",
	"655 07", "Cell C",
	"655 10", "MTN",
	"655 11", "",
	"655 13", "Neotel",
	"655 21", "",
	"655 30", "",
	"655 31", "",
	"655 32", "",
	"655 33", "",
	"657 01", "Eritel",

	"702 67", "DigiCell",
	"702 99", "Smart",
	"704 01", "Claro",
	"704 02", "Comcel / Tigo",
	"704 03", "movistar",
	"706 01", "CTE Telecom Personal",
	"706 02", "digicel",
	"706 03", "Tigo",
	"706 04", "movistar",
	"706 11", "Claro",
	"708 01", "Claro",
	"708 02", "",
	"708 30", "Hondutel",
	"708 40", "DIGICEL",
	"710 21", "Claro",
	"710 30", "movistar",
	"710 73", "SERCOM",
	"712 01", "ICE",
	"712 02", "ICE",
	"712 03", "ICE",
	"714 01", "Cable & Wireless",
	"714 02", "movistar",
	"714 03", "Claro",
	"714 04", "Digicel",
	"716 06", "movistar",
	"716 10", "Claro",
	"716 17", "NEXTEL",
	"722 010", "Movistar",
	"722 020", "Nextel",
	"722 070", "Movistar",
	"722 310", "Claro",
	"722 320", "Claro",
	"722 330", "Claro",
	"722 341", "Personal",
	"722 34", "Personal",
	"722 350", "",
	"722 36", "Personal",
	"724 00", "Nextel",
	"724 02", "TIM",
	"724 03", "TIM",
	"724 04", "TIM",
	"724 05", "Claro",
	"724 06", "Vivo",
	"724 07", "Sercomtel",
	"724 08", "TIM",
	"724 10", "Vivo",
	"724 11", "Vivo",
	"724 15", "CTBC Celular",
	"724 16", "Oi / Brasil Telecom",
	"724 23", "Vivo",
	"724 24", "Oi / Amazonia Celular",
	"724 31", "Oi",
	"724 32", "CTBC Celular",
	"724 33", "CTBC Celular",
	"724 34", "CTBC Celular",
	"724 37", "aeiou",
	"730 01", "entel",
	"730 02", "movistar",
	"730 03", "Claro",
	"730 04", "Nextel",
	"730 05", "VTR Movil",
	"730 09", "Nextel",
	"730 10", "entel",
	"730 99", "Will",
	"732 001", "",
	"732 002", "Edatel",
	"732 101", "Comcel",
	"732 102", "movistar",
	"732 103", "Tigo",
	"732 111", "Tigo",
	"732 123", "movistar",
	"734 01", "Digitel",
	"734 02", "Digitel",
	"734 03", "Digitel",
	"734 04", "movistar",
	"734 06", "Movilnet",
	"736 01", "Nuevatel",
	"736 02", "Entel",
	"736 03", "Tigo",
	"738 01", "Digicel",
	"738 02", "GT&T Cellink Plus",
	"740 00", "Movistar",
	"740 01", "Porta",
	"740 02", "Alegro",
	"744 02", "Claro",
	"744 04", "Tigo",
	"744 05", "Personal",
	"744 06", "VOX",
	"746 02", "Telesur (GSM)",
	"748 00", "Ancel",
	"748 01", "Ancel",
	"748 07", "Movistar",
	"748 10", "Claro",

	"901 01", "ICO",
	"901 02", "",
	"901 03", "Iridium",
	"901 04", "Globalstar",
	"901 05", "",
	"901 06", "",
	"901 07", "Ellipso",
	"901 08", "",
	"901 09", "",
	"901 10", "ACeS",
	"901 11", "Inmarsat",
	"901 12", "MCP",
	"901 13", "GSM.AQ",
	"901 14", "",
	"901 15", "",
	"901 16", "",
	"901 17", "Navitas",
	"901 18", "Cellular @Sea",
	"901 19", "",
	"901 21", "Seanet",
	"901 23", "",
	"901 24", "iNum",
	"901 26", "TIM",
	"901 29", "Telenor",

	"999 99", "GammuTel",

	NULL
};

const unsigned char *GSM_GetNetworkName(const char *NetworkCode)
{
	int i = 0;
	static char retval[200];
	char NetworkCodeFull[8];
	const char *pos;

	EncodeUnicode(retval, "unknown", 7);

	/* Too long string */
	if (strlen(NetworkCode) > 7 || strlen(NetworkCode) < 5) {
		return retval;
	}
	pos = strchr(NetworkCode, ' ');
	if (pos == NULL) {
		pos = NetworkCode + 3;
	} else {
		pos += 1;
	}

	sprintf(NetworkCodeFull, "%c%c%c %s", NetworkCode[0], NetworkCode[1], NetworkCode[2], pos);

	for (i = 0; GSM_Networks[i * 2] != NULL; i++) {
		if (strcmp(GSM_Networks[i * 2], NetworkCodeFull) == 0) {
			EncodeUnicode(retval, GSM_Networks[i * 2 + 1], strlen(GSM_Networks[i * 2 + 1]));
			break;
		}
	}

	return retval;
}

const unsigned char *GSM_GetCountryName(const char *CountryCode)
{
	int		i = 0;
	static char	retval[200];

	EncodeUnicode(retval,"unknown",7);
	while (GSM_Countries[i*2] != NULL) {
		if (!strncmp(GSM_Countries[i*2],CountryCode,3)) {
			EncodeUnicode(retval, GSM_Countries[i*2+1], strlen(GSM_Countries[i*2+1]));
			break;
		}
		i++;
	}
	return retval;
}

void NOKIA_EncodeNetworkCode(unsigned char* buffer, const char* input)
{
	EncodeBCD(buffer, input, 6, FALSE);
	buffer[1] = buffer[1] | 0xf0;
}

void NOKIA_DecodeNetworkCode(const unsigned char* buffer, char* output)
{
	DecodeBCD(output, buffer, 3);
	output[6] = output[5];
	output[5] = output[4];
	output[4] = output[3];
	output[3] = ' ';
}

/* How should editor hadle tabs in this file? Add editor commands here.
 * vim: noexpandtab sw=8 ts=8 sts=8:
 */
