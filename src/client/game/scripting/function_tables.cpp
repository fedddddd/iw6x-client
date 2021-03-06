#include <std_include.hpp>

// This file has been generated.
// Do not touch!

namespace scripting
{
	std::unordered_map<std::string, unsigned> function_map =
	{
		{"abs", 177},
		{"acos", 173},
		{"activateclientexploder", 529},
		{"addagent", 353},
		{"addbot", 597},
		{"addstruct", 395},
		{"addtestclient", 352},
		{"allclientsprint", 355},
		{"ambientplay", 280},
		{"ambientstop", 312},
		{"angleclamp180", 221},
		{"angleclamp360", 220},
		{"anglesdelta", 269},
		{"anglestoaxis", 548},
		{"anglestoforward", 268},
		{"anglestoright", 267},
		{"anglestoup", 266},
		{"animhasnotetrack", 96},
		{"announcement", 332},
		{"asin", 172},
		{"assertexcmd", 42},
		{"assertmsgcmd", 584},
		{"atan", 174},
		{"averagenormal", 433},
		{"averagepoint", 432},
		{"axistoangles", 234},
		{"badplacearc", 32},
		{"badplacebrush", 33},
		{"badplacecylinder", 31},
		{"badplacedelete", 30},
		{"badplaceglobal", 508},
		{"blockteamradar", 285},
		{"botautoconnectenabled", 479},
		{"botflagmemoryevents", 484},
		{"botgetclosestnavigablepoint", 491},
		{"botgetmemoryevents", 478},
		{"botgetteamdifficulty", 587},
		{"botgetteamlimit", 585},
		{"botmemoryflags", 483},
		{"botsentientswap", 486},
		{"botzonegetcount", 480},
		{"botzonegetindoorpercent", 485},
		{"botzonenearestcount", 482},
		{"botzonesetteam", 481},
		{"bullettrace", 101},
		{"bullettracepassed", 129},
		{"calccsplinecorridor", 568},
		{"calccsplineposition", 566},
		{"calccsplinetangent", 567},
		{"calculatestartorientation", 555},
		{"canspawn", 344},
		{"canspawnturret", 24},
		{"capsuletracepassed", 604},
		{"castfloat", 176},
		{"castint", 175},
		{"ceil", 214},
		{"clamp", 219},
		{"clearfog", 545},
		{"clearmatchdata", 292},
		{"clientannouncement", 333},
		{"clientprint", 356},
		{"closer", 231},
		{"combineangles", 270},
		{"connectnodepair", 512},
		{"cos", 170},
		{"createthreatbiasgroup", 249},
		{"deleteglass", 454},
		{"destroyglass", 453},
		{"disconnectnodepair", 511},
		{"distance", 224},
		{"distance2d", 225},
		{"distance2dsquared", 527},
		{"distancesquared", 226},
		{"earthquake", 376},
		{"exitlevel", 351},
		{"exp", 215},
		{"findentrances", 507},
		{"floor", 213},
		{"getactiveclientcount", 593},
		{"getactivecount", 473},
		{"getallnodes", 184},
		{"getallvehiclenodes", 472},
		{"getangledelta", 135},
		{"getangledelta3d", 528},
		{"getanimlength", 95},
		{"getarray", 476},
		{"getarraykeys", 447},
		{"getbuildnumber", 301},
		{"getbuildversion", 300},
		{"getclientmatchdata", 297},
		{"getclosestnodeinsight", 187},
		{"getcountertotal", 242},
		{"getcsplinecount", 556},
		{"getcsplinelength", 558},
		{"getcsplinepointcorridordims", 563},
		{"getcsplinepointcount", 557},
		{"getcsplinepointdisttonextpoint", 565},
		{"getcsplinepointid", 559},
		{"getcsplinepointlabel", 560},
		{"getcsplinepointposition", 562},
		{"getcsplinepointtangent", 564},
		{"getcsplinepointtension", 561},
		{"getdvar", 54},
		{"getdvarfloat", 56},
		{"getdvarint", 55},
		{"getdvarvector", 57},
		{"getenemysquaddata", 542},
		{"getenemysquaddogtype", 603},
		{"getent", 391},
		{"getentarray", 392},
		{"getentbynum", 59},
		{"getentchannelname", 456},
		{"getfirstarraykey", 448},
		{"getglass", 449},
		{"getglassarray", 450},
		{"getglassorigin", 451},
		{"getgroundposition", 133},
		{"getindexforluincstring", 195},
		{"getlinkednodes", 510},
		{"getmapcustomfield", 239},
		{"getmatchdata", 290},
		{"getmatchrulesdata", 303},
		{"getmaxagents", 489},
		{"getmissileowner", 429},
		{"getmovedelta", 134},
		{"getnextarraykey", 421},
		{"getnode", 182},
		{"getnodearray", 183},
		{"getnodesinradius", 185},
		{"getnodesinradiussorted", 186},
		{"getnodesintrigger", 492},
		{"getnodesonpath", 494},
		{"getnodezone", 500},
		{"getnorthyaw", 136},
		{"getnotetracktimes", 97},
		{"getnumparts", 377},
		{"getomnvar", 48},
		{"getpartname", 411},
		{"getpathdist", 509},
		{"getplaylistid", 592},
		{"getplaylistversion", 591},
		{"getpredictedentityposition", 571},
		{"getscriptablearray", 544},
		{"getspawnarray", 393},
		{"getspawnerarray", 434},
		{"getsquadassaultelo", 588},
		{"getsquadassaultenemyprestige", 599},
		{"getsquadassaultsquadindex", 595},
		{"getstartangles", 106},
		{"getstartorigin", 105},
		{"getstarttime", 345},
		{"getsubstr", 276},
		{"getsystemtime", 302},
		{"getteamplayersalive", 339},
		{"getteamradar", 363},
		{"getteamradarstrength", 365},
		{"getteamscore", 335},
		{"getthreatbias", 251},
		{"gettime", 58},
		{"getuavstrengthlevelneutral", 598},
		{"getuavstrengthlevelshowenemyfastsweep", 283},
		{"getuavstrengthmax", 284},
		{"getuavstrengthmin", 366},
		{"getvehiclenode", 470},
		{"getvehiclenodearray", 471},
		{"getweaponarray", 1},
		{"getweaponattachmentdisplaynames", 91},
		{"getweaponattachments", 90},
		{"getweaponbasename", 89},
		{"getweaponcamoname", 92},
		{"getweapondisplayname", 88},
		{"getweaponexplosionradius", 503},
		{"getweaponflashtagname", 431},
		{"getweaponhidetags", 94},
		{"getweaponmodel", 60},
		{"getweaponreticlename", 93},
		{"getzonecount", 495},
		{"getzonenearest", 496},
		{"getzonenodeforindex", 502},
		{"getzonenodes", 497},
		{"getzonenodesbydist", 501},
		{"getzoneorigin", 499},
		{"getzonepath", 498},
		{"glassradiusdamage", 375},
		{"incrementcounter", 241},
		{"invertangles", 553},
		{"iprintln", 388},
		{"iprintlnbold", 389},
		{"isagent", 488},
		{"isai", 194},
		{"isalive", 397},
		{"isarray", 193},
		{"isbot", 487},
		{"isdedicatedserver", 590},
		{"isdefined", 44},
		{"isendstr", 275},
		{"isenemyteam", 255},
		{"isexplosivedamagemod", 372},
		{"isglassdestroyed", 452},
		{"isplayer", 409},
		{"isplayernumber", 410},
		{"ispointinvolume", 537},
		{"issentient", 196},
		{"isspawner", 398},
		{"issquadsmode", 594},
		{"isstring", 46},
		{"issubstr", 274},
		{"isteamradarblocked", 287},
		{"isusingmatchrulesdata", 304},
		{"isvalidgametype", 358},
		{"isvalidmissile", 45},
		{"isweaponcliponly", 467},
		{"isweapondetonationtimed", 468},
		{"kickplayer", 305},
		{"killfxontag", 326},
		{"length", 227},
		{"length2d", 228},
		{"length2dsquared", 230},
		{"lengthsquared", 229},
		{"loadfx", 322},
		{"loadluifile", 589},
		{"log", 216},
		{"lookupsoundlength", 543},
		{"magicbullet", 430},
		{"mapexists", 357},
		{"maprestart", 350},
		{"markdangerousnodes", 504},
		{"markdangerousnodesintrigger", 505},
		{"max", 212},
		{"min", 178},
		{"missilecreateattractorent", 399},
		{"missilecreateattractororigin", 400},
		{"missilecreaterepulsorent", 401},
		{"missilecreaterepulsororigin", 402},
		{"missiledeleteattractor", 403},
		{"newclienthudelem", 406},
		{"newhudelem", 405},
		{"newteamhudelem", 407},
		{"nodeexposedtosky", 506},
		{"nodesvisible", 493},
		{"obituary", 342},
		{"objectiveadd", 457},
		{"objectivecurrent", 462},
		{"objectivedelete", 458},
		{"objectiveicon", 460},
		{"objectiveonentity", 378},
		{"objectiveonentitywithrotation", 379},
		{"objectiveplayer", 381},
		{"objectiveplayerenemyteam", 383},
		{"objectiveplayermaskhidefrom", 385},
		{"objectiveplayermaskhidefromall", 384},
		{"objectiveplayermaskshowto", 387},
		{"objectiveplayermaskshowtoall", 386},
		{"objectiveplayerteam", 382},
		{"objectiveposition", 461},
		{"objectivestate", 459},
		{"objectiveteam", 380},
		{"physicsexplosioncylinder", 368},
		{"physicsexplosionsphere", 367},
		{"physicsradiusjitter", 370},
		{"physicsradiusjolt", 369},
		{"physicstrace", 131},
		{"playcinematicforall", 600},
		{"playerphysicstrace", 132},
		{"playfx", 323},
		{"playfxontag", 324},
		{"playfxontagforclients", 330},
		{"playloopedfx", 327},
		{"playrumblelooponposition", 436},
		{"playrumbleonposition", 435},
		{"playsoundatpos", 404},
		{"pointonsegmentnearesttopoint", 223},
		{"positionwouldtelefrag", 343},
		{"pow", 477},
		{"precache", 474},
		{"precacheheadicon", 347},
		{"precacheitem", 315},
		{"precacheleaderboards", 321},
		{"precachelocationselector", 320},
		{"precachematerial", 316},
		{"precachemenu", 318},
		{"precacheminimapicon", 348},
		{"precachemodel", 313},
		{"precachempanim", 349},
		{"precacherumble", 319},
		{"precacheshellshock", 314},
		{"precachesound", 518},
		{"precachestatusicon", 346},
		{"precachestring", 317},
		{"precacheturret", 0},
		{"preloadcinematicforall", 601},
		{"print", 15},
		{"println", 16},
		{"queuedialog", 578},
		{"radiusdamage", 373},
		{"randomfloat", 166},
		{"randomfloatrange", 168},
		{"randomint", 165},
		{"randomintrange", 167},
		{"resetsunlight", 65},
		{"resettimeout", 408},
		{"rotatepointaroundvector", 273},
		{"rotatevector", 272},
		{"rotatevectorinverted", 554},
		{"sendclientmatchdata", 299},
		{"sendmatchdata", 291},
		{"setac130ambience", 238},
		{"setclientmatchdata", 296},
		{"setclientmatchdatadef", 298},
		{"setclientnamemode", 337},
		{"setdvar", 52},
		{"setdvarifuninitialized", 53},
		{"setdynamicdvar", 50},
		{"setexponentialfog", 371},
		{"setgameendtime", 308},
		{"setignoremegroup", 254},
		{"setleveldopplerpreset", 546},
		{"setmapcenter", 307},
		{"setmatchclientip", 294},
		{"setmatchdata", 289},
		{"setmatchdatadef", 293},
		{"setmatchdataid", 295},
		{"setminimap", 445},
		{"setnojipscore", 569},
		{"setnojiptime", 570},
		{"setnorthyaw", 163},
		{"setomnvar", 47},
		{"setplayerignoreradiusdamage", 374},
		{"setplayerteamrank", 360},
		{"setslowmotion", 164},
		{"setsunlight", 64},
		{"setteammode", 334},
		{"setteamradar", 362},
		{"setteamradarstrength", 364},
		{"setteamscore", 336},
		{"setthermalbodymaterial", 446},
		{"setthreatbias", 252},
		{"setthreatbiasagainstall", 253},
		{"setwinningteam", 331},
		{"sighttracepassed", 130},
		{"sin", 169},
		{"sortbydistance", 422},
		{"soundexists", 438},
		{"spawn", 99},
		{"spawnfx", 328},
		{"spawnfxforclient", 586},
		{"spawnhelicopter", 396},
		{"spawnplane", 394},
		{"spawnsighttrace", 240},
		{"spawnturret", 23},
		{"spawnvehicle", 475},
		{"sqrt", 217},
		{"squared", 218},
		{"stopallrumbles", 437},
		{"stopcinematicforall", 602},
		{"stopfxontag", 325},
		{"stricmp", 279},
		{"strtok", 278},
		{"tableexists", 428},
		{"tablelookup", 423},
		{"tablelookupbyrow", 426},
		{"tablelookupistring", 425},
		{"tablelookuprownum", 427},
		{"tan", 171},
		{"threatbiasgroupexists", 250},
		{"tolower", 277},
		{"trajectorycalculateexitangle", 532},
		{"trajectorycalculateinitialvelocity", 530},
		{"trajectorycalculateminimumvelocity", 531},
		{"trajectorycanattemptaccuratejump", 535},
		{"trajectorycomputedeltaheightattime", 534},
		{"trajectoryestimatedesiredinairtime", 533},
		{"transformmove", 271},
		{"triggerfx", 329},
		{"triggerportableradarping", 583},
		{"unblockteamradar", 286},
		{"updateclientnames", 338},
		{"vectorcross", 233},
		{"vectordot", 232},
		{"vectorfromlinetopoint", 222},
		{"vectorlerp", 265},
		{"vectornormalize", 262},
		{"vectortoangles", 263},
		{"vectortoyaw", 264},
		{"visionsetmissilecam", 311},
		{"visionsetnaked", 309},
		{"visionsetnight", 310},
		{"visionsetpain", 236},
		{"visionsetpostapply", 596},
		{"visionsetthermal", 235},
		{"weaponaltweaponname", 466},
		{"weaponburstcount", 418},
		{"weaponclass", 420},
		{"weaponclipsize", 413},
		{"weaponfiretime", 412},
		{"weaponhasthermalscope", 469},
		{"weaponinheritsperks", 417},
		{"weaponinventorytype", 463},
		{"weaponisauto", 414},
		{"weaponisboltaction", 416},
		{"weaponissemiauto", 415},
		{"weaponmaxammo", 465},
		{"weaponstartammo", 464},
		{"weapontype", 419},
		{"worldentnumber", 341},
	};

	std::unordered_map<std::string, unsigned> method_map =
	{
		{"addpitch", 33454},
		{"addroll", 33456},
		{"addyaw", 33455},
		{"adsbuttonpressed", 33586},
		{"agentcanseesentient", 33663},
		{"aiphysicstrace", 33713},
		{"aiphysicstracepassed", 33714},
		{"alienscheckisitempurchased", 33833},
		{"alienscheckisrelicenabled", 33836},
		{"alienscheckisupgradeenabled", 33835},
		{"alienssethascrafteditem", 33834},
		{"allowads", 33526},
		{"allowjump", 33527},
		{"allowspectateteam", 33385},
		{"allowsprint", 33528},
		{"anyammoforweaponmodes", 33520},
		{"attach", 32792},
		{"attachpath", 33394},
		{"attachshieldmodel", 32793},
		{"attackbuttonpressed", 33585},
		{"autoboltmissileeffects", 33811},
		{"autospotoverlayoff", 32949},
		{"autospotoverlayon", 32948},
		{"beginlocationselection", 33550},
		{"beginmelee", 33677},
		{"botcanseeentity", 33631},
		{"botclearbutton", 33647},
		{"botclearscriptenemy", 33608},
		{"botclearscriptgoal", 33606},
		{"botfindnoderandom", 33617},
		{"botfirstavailablegrenade", 33743},
		{"botgetdifficulty", 33627},
		{"botgetdifficultysetting", 33643},
		{"botgetfovdot", 33635},
		{"botgetimperfectenemyinfo", 33639},
		{"botgetnodesonpath", 33632},
		{"botgetpathdist", 33644},
		{"botgetpersonality", 33622},
		{"botgetscriptgoal", 33610},
		{"botgetscriptgoalnode", 33638},
		{"botgetscriptgoalradius", 33611},
		{"botgetscriptgoaltype", 33613},
		{"botgetscriptgoalyaw", 33612},
		{"botgetworldclosestedge", 33628},
		{"botgetworldsize", 33615},
		{"bothasscriptgoal", 33621},
		{"botisrandomized", 33645},
		{"botlookatpoint", 33629},
		{"botmemoryevent", 33618},
		{"botnodeavailable", 33616},
		{"botnodepick", 33620},
		{"botnodepickmultiple", 33633},
		{"botnodescoremultiple", 33648},
		{"botpredictenemycampspots", 33795},
		{"botpredictseepoint", 33630},
		{"botpressbutton", 33646},
		{"botpursuingscriptgoal", 33637},
		{"botsetattacker", 33609},
		{"botsetawareness", 33636},
		{"botsetdifficulty", 33626},
		{"botsetdifficultysetting", 33642},
		{"botsetflag", 33601},
		{"botsetpathingstyle", 33641},
		{"botsetpersonality", 33625},
		{"botsetscriptenemy", 33607},
		{"botsetscriptgoal", 33604},
		{"botsetscriptgoalnode", 33605},
		{"botsetscriptmove", 33603},
		{"botsetstance", 33602},
		{"botthrowgrenade", 33623},
		{"buttonpresseddevonly", 33346},
		{"cameralinkto", 33245},
		{"cameraunlink", 33246},
		{"cancelmantle", 33797},
		{"canmantle", 33490},
		{"canplayerplacesentry", 33478},
		{"canplayerplacetank", 33479},
		{"canspawntestclient", 33766},
		{"canturrettargetpoint", 33370},
		{"changefontscaleovertime", 32904},
		{"claimnode", 33682},
		{"cleargoalyaw", 33363},
		{"clearlookatent", 33372},
		{"clearperks", 33437},
		{"clearportableradar", 32780},
		{"clearscrambler", 32779},
		{"cleartargetent", 32965},
		{"cleartargetentity", 33022},
		{"cleartargetyaw", 33365},
		{"clearturrettargetent", 33369},
		{"clientclaimtrigger", 32783},
		{"clientreleasetrigger", 32784},
		{"clientspawnsighttracepassed", 33525},
		{"cloneagent", 33662},
		{"clonebrushmodeltoscriptmodel", 33389},
		{"cloneplayer", 33383},
		{"closeingamemenu", 33378},
		{"closemenu", 33562},
		{"closepopupmenu", 33560},
		{"connectnode", 32857},
		{"connectpaths", 32855},
		{"controlslinkto", 33275},
		{"controlsunlink", 33276},
		{"crash", 33317},
		{"damageconetrace", 33234},
		{"deactivatechannelvolumes", 33513},
		{"delete", 32937},
		{"destroy", 32901},
		{"detach", 32806},
		{"detachall", 32809},
		{"detachshieldmodel", 32807},
		{"detonate", 33233},
		{"disableaimassist", 33231},
		{"disableautoreload", 33791},
		{"disablecrashing", 33319},
		{"disableforcethirdpersonwhenfollowing", 33600},
		{"disablegrenadetouchdamage", 33199},
		{"disablemissileboosting", 33764},
		{"disablemissilestick", 33812},
		{"disableoffhandweapons", 33554},
		{"disableplayeruse", 32776},
		{"disableusability", 33565},
		{"disableweaponpickup", 33471},
		{"disableweapons", 33552},
		{"disableweaponswitch", 33556},
		{"disconnectnode", 32856},
		{"disconnectpaths", 32854},
		{"doanimlerp", 33680},
		{"doanimrelative", 33780},
		{"dodamage", 32846},
		{"doesnodeallowstance", 32818},
		{"dontinterpolate", 32911},
		{"dospawn", 33315},
		{"dotrajectory", 33679},
		{"drivevehicleandcontrolturret", 33286},
		{"drivevehicleandcontrolturretoff", 33287},
		{"dropitem", 33350},
		{"dropscavengerbag", 33351},
		{"emissiveblend", 33749},
		{"enableaimassist", 33200},
		{"enableanimstate", 33693},
		{"enableautoreload", 33792},
		{"enablecrashing", 33320},
		{"enablegrenadetouchdamage", 33198},
		{"enablelinkto", 32872},
		{"enablemissileboosting", 33765},
		{"enablemissilestick", 33813},
		{"enableoffhandweapons", 33555},
		{"enableplayeruse", 32775},
		{"enableusability", 33566},
		{"enableweaponpickup", 33472},
		{"enableweapons", 33553},
		{"enableweaponswitch", 33557},
		{"endlocationselection", 33551},
		{"entityradiusdamage", 33232},
		{"entitywillneverchange", 32983},
		{"fadeoutshellshock", 33152},
		{"fadeovertime", 32897},
		{"finishagentdamage", 33660},
		{"finishdamage", 33399},
		{"finishplayerdamage", 33376},
		{"fireweapon", 33374},
		{"forcemantle", 33491},
		{"forcethirdpersonwhenfollowing", 33599},
		{"forceusehintoff", 32980},
		{"forceusehinton", 32979},
		{"fragbuttonpressed", 33506},
		{"freeentitysentient", 33075},
		{"freevehicle", 33355},
		{"freezecontrols", 33564},
		{"getammocount", 33146},
		{"getangles", 33583},
		{"getanimentry", 33695},
		{"getanimentryalias", 33697},
		{"getanimentrycount", 33698},
		{"getanimentryname", 33696},
		{"getattachignorecollision", 32836},
		{"getattachmodelname", 32811},
		{"getattachpos", 33395},
		{"getattachsize", 32810},
		{"getattachtagname", 32812},
		{"getbarrelspinrate", 32989},
		{"getbodyvelocity", 33405},
		{"getcacplayerdata", 33343},
		{"getclanidhigh", 33423},
		{"getclanidlow", 33424},
		{"getclanwarsbonusforcurrentplaylist", 33821},
		{"getclosestenemysqdist", 33137},
		{"getcommonplayerdata", 33311},
		{"getcommonplayerdatareservedint", 33828},
		{"getcoopplayerdata", 33310},
		{"getcoopplayerdatareservedint", 33829},
		{"getcorpseanim", 32790},
		{"getcorpseentity", 33784},
		{"getcurrentoffhand", 33543},
		{"getcurrentprimaryweapon", 33542},
		{"getcurrentweapon", 33541},
		{"getcurrentweaponclipammo", 33508},
		{"getcustomizationbody", 33752},
		{"getcustomizationhead", 33753},
		{"getcustomizationviewmodel", 33754},
		{"getenemyinfo", 33118},
		{"getenemysqdist", 33136},
		{"getentitynumber", 33196},
		{"getentityvelocity", 33197},
		{"geteye", 32929},
		{"getfireteammembers", 33440},
		{"getfractionmaxammo", 33576},
		{"getfractionstartammo", 33575},
		{"getgoalpos", 33666},
		{"getgoalspeedmph", 33411},
		{"getguid", 33386},
		{"gethighestnodestance", 32817},
		{"gethybridscopestate", 33804},
		{"getistouchingentities", 32931},
		{"getjointype", 33831},
		{"getlightintensity", 33241},
		{"getlinkedchildren", 33794},
		{"getlinkedparent", 33720},
		{"getlocalplayerprofiledata", 33289},
		{"getlookaheaddir", 33708},
		{"getmaxturnspeed", 33676},
		{"getmlgspectatorteam", 33827},
		{"getmode", 32869},
		{"getmovingplatformparent", 33721},
		{"getnearestnode", 33656},
		{"getnegotiationendnode", 33177},
		{"getnegotiationnextnode", 33178},
		{"getnegotiationstartnode", 33176},
		{"getnodenumber", 33649},
		{"getnormalhealth", 32888},
		{"getnormalizedcameramovement", 33537},
		{"getnormalizedmovement", 33511},
		{"getoffhandprimaryclass", 33593},
		{"getoffhandsecondaryclass", 33549},
		{"getorigin", 32914},
		{"getpathgoalpos", 33709},
		{"getplayerdata", 33307},
		{"getplayerknifemodel", 33487},
		{"getplayerssightingme", 33504},
		{"getpointinbounds", 33297},
		{"getprivateplayerdata", 33309},
		{"getrankedplayerdata", 33308},
		{"getrankedplayerdatareservedint", 33822},
		{"getrestedtime", 32787},
		{"getsightedplayers", 33503},
		{"getspectatingplayer", 33426},
		{"getspeed", 33403},
		{"getstance", 33143},
		{"getsteering", 33406},
		{"gettagangles", 33148},
		{"gettagorigin", 33147},
		{"getthirdpersoncrosshairoffset", 33470},
		{"getthreatbiasgroup", 33139},
		{"getthrottle", 33407},
		{"getturretowner", 32993},
		{"getturrettarget", 33023},
		{"getucdidlow", 33422},
		{"getvehicleowner", 33357},
		{"getvehvelocity", 33404},
		{"getvelocity", 33581},
		{"getviewheight", 33510},
		{"getviewkickscale", 33534},
		{"getviewmodel", 33505},
		{"getvieworigin", 33806},
		{"getweaponammoclip", 33518},
		{"getweaponammostock", 33519},
		{"getweaponhudiconoverride", 33303},
		{"getweaponslist", 33477},
		{"getweaponslistall", 33535},
		{"getweaponslistexclusives", 33476},
		{"getweaponslistitems", 33475},
		{"getweaponslistoffhands", 33474},
		{"getweaponslistprimaries", 33536},
		{"getwheelsurface", 33356},
		{"getxuid", 33420},
		{"givemaxammo", 33574},
		{"givestartammo", 33573},
		{"giveweapon", 33538},
		{"gravitymove", 33447},
		{"hasfemalecustomizationmodel", 33798},
		{"hasloadedcustomizationplayerview", 33777},
		{"hasperk", 33436},
		{"hasweapon", 33544},
		{"helisetdamagestage", 32770},
		{"helisetgoal", 33366},
		{"hide", 32849},
		{"hideallparts", 32839},
		{"hidepart", 32837},
		{"hidepartallinstances", 32838},
		{"hudoutlinedisable", 33735},
		{"hudoutlinedisableforclient", 33773},
		{"hudoutlinedisableforclients", 33775},
		{"hudoutlineenable", 33734},
		{"hudoutlineenableforclient", 33772},
		{"hudoutlineenableforclients", 33774},
		{"iclientprintln", 33379},
		{"iclientprintlnbold", 33380},
		{"isdualwielding", 33577},
		{"isfiringturret", 32986},
		{"isfiringvehicleturret", 33283},
		{"ishost", 33425},
		{"isitemunlocked", 33306},
		{"isleaning", 33816},
		{"islinked", 32871},
		{"ismantling", 33492},
		{"ismeleeing", 33063},
		{"ismlgspectator", 33790},
		{"isoffhandweaponreadytothrow", 33815},
		{"isonground", 33589},
		{"isonladder", 32789},
		{"isphysveh", 33316},
		{"isragdoll", 33243},
		{"isreloading", 33578},
		{"issighted", 33502},
		{"issplitscreenplayer", 33473},
		{"issplitscreenplayerprimary", 33500},
		{"issprinting", 33700},
		{"isswitchingweapon", 33579},
		{"istalking", 33384},
		{"isthrowinggrenade", 33061},
		{"istouching", 32930},
		{"isturretready", 33313},
		{"isusingonlinedataoffline", 32786},
		{"isusingturret", 33590},
		{"itemweaponsetammo", 33145},
		{"joltbody", 33354},
		{"jumpbuttonpressed", 33706},
		{"kcregweaponforfxremoval", 33467},
		{"laseraltviewoff", 32942},
		{"laseraltviewon", 32941},
		{"laseroff", 32940},
		{"laseron", 32939},
		{"lastknownpos", 33212},
		{"lastknowntime", 33211},
		{"laststandrevive", 33468},
		{"launch", 33318},
		{"lerpviewangleclamp", 32923},
		{"linkto", 32842},
		{"linktoblendtotag", 32843},
		{"linkwaypointtotargetwithoffset", 33719},
		{"loadcustomizationplayerview", 33768},
		{"localtoworldcoords", 33195},
		{"logmatchdatadeath", 33787},
		{"logmatchdatalife", 33786},
		{"makecollidewithitemclip", 33817},
		{"makeentitynomeleetarget", 33657},
		{"makeentitysentient", 33074},
		{"makehard", 32982},
		{"makeportableradar", 32778},
		{"makescrambler", 32777},
		{"makesoft", 32981},
		{"maketurretinoperable", 33073},
		{"maketurretoperable", 33072},
		{"maketurretsolid", 33071},
		{"makeunusable", 32953},
		{"makeusable", 32952},
		{"makevehiclenotcollidewithplayers", 33727},
		{"makevehiclesolidcapsule", 33277},
		{"makevehiclesolidsphere", 33279},
		{"markforeyeson", 33501},
		{"meleebuttonpressed", 33587},
		{"missilecleartarget", 33238},
		{"missilesetflightmodedirect", 33239},
		{"missilesetflightmodetop", 33240},
		{"missilesettargetent", 33236},
		{"missilesettargetpos", 33237},
		{"motionblurhqdisable", 33737},
		{"motionblurhqenable", 33736},
		{"moveovertime", 32899},
		{"moveshieldmodel", 32808},
		{"moveslide", 33448},
		{"moveto", 33443},
		{"movex", 33444},
		{"movey", 33445},
		{"movez", 33446},
		{"neargoalnotifydist", 33360},
		{"nodeisdisconnected", 33655},
		{"notifyonplayercommand", 33489},
		{"notsolid", 33460},
		{"openmenu", 33561},
		{"openpopupmenu", 33558},
		{"openpopupmenunomouse", 33559},
		{"physicsgetangspeed", 33763},
		{"physicsgetangvel", 33762},
		{"physicsgetlinspeed", 33761},
		{"physicsgetlinvel", 33760},
		{"physicslaunchclient", 33463},
		{"physicslaunchserver", 33387},
		{"physicslaunchserveritem", 33388},
		{"physicssetmaxangvel", 33759},
		{"physicssetmaxlinvel", 33758},
		{"pingplayer", 33345},
		{"playerads", 33588},
		{"playerchoke", 33837},
		{"playercommandbot", 33652},
		{"playerforcedeathanim", 32791},
		{"playerhide", 32773},
		{"playerlinkedoffsetdisable", 32920},
		{"playerlinkedoffsetenable", 32894},
		{"playerlinkedsetusebaseangleforviewclamp", 32922},
		{"playerlinkedsetviewznear", 32921},
		{"playerlinkto", 32889},
		{"playerlinktoabsolute", 32892},
		{"playerlinktoblend", 32893},
		{"playerlinktodelta", 32890},
		{"playerlinkweaponviewtodelta", 32891},
		{"playerrecoilscaleoff", 33495},
		{"playerrecoilscaleon", 33494},
		{"playersetexponentialfog", 33305},
		{"playersetgroundreferenceent", 32910},
		{"playfx", 33493},
		{"playlocalsound", 33514},
		{"playloopsound", 32883},
		{"playrumblelooponentity", 32935},
		{"playrumbleonentity", 32934},
		{"playsound", 32919},
		{"playsoundonmovingent", 33796},
		{"playsoundtoplayer", 32772},
		{"playsoundtoteam", 32771},
		{"predictstreampos", 33427},
		{"queuedialogforplayer", 33788},
		{"registerparty", 33439},
		{"releaseclaimedtrigger", 32785},
		{"relinquishclaimednode", 33683},
		{"remotecamerasoundscapeoff", 33292},
		{"remotecamerasoundscapeon", 33291},
		{"remotecontrolturret", 32990},
		{"remotecontrolturretoff", 32991},
		{"remotecontrolvehicle", 33281},
		{"remotecontrolvehicleoff", 33282},
		{"remotecontrolvehicletarget", 33284},
		{"remotecontrolvehicletargetoff", 33285},
		{"reset", 32900},
		{"resetspreadoverride", 33530},
		{"restoredefaultdroppitch", 33108},
		{"resumespeed", 33414},
		{"ridevehicle", 33808},
		{"rotateby", 33707},
		{"rotatepitch", 33451},
		{"rotateroll", 33453},
		{"rotateto", 33450},
		{"rotatevehyaw", 33402},
		{"rotatevelocity", 33458},
		{"rotateyaw", 33452},
		{"sayall", 33347},
		{"sayteam", 33348},
		{"scaleovertime", 32898},
		{"scriptmodelclearanim", 33391},
		{"scriptmodelplayanim", 33390},
		{"scriptmodelplayanimdeltamotion", 33392},
		{"secondaryoffhandbuttonpressed", 33507},
		{"setacceleration", 33412},
		{"setactionslot", 33532},
		{"setagentattacker", 33661},
		{"setagentwaypoint", 33664},
		{"setaimspreadmovementscale", 33531},
		{"setairresitance", 33418},
		{"setaisightlinevisible", 33653},
		{"setangles", 33582},
		{"setanimclass", 33692},
		{"setanimmode", 33672},
		{"setanimscale", 33670},
		{"setanimstate", 33694},
		{"setautorotationdelay", 33106},
		{"setblurforplayer", 33485},
		{"setbottomarc", 33105},
		{"setcandamage", 33461},
		{"setcanradiusdamage", 33462},
		{"setcarddisplayslot", 33466},
		{"setchannelvolume", 33572},
		{"setchannelvolumes", 33512},
		{"setclientdvar", 33522},
		{"setclientdvars", 33523},
		{"setclientomnvar", 33521},
		{"setclientowner", 33650},
		{"setclientspawnsighttraces", 33524},
		{"setclipmode", 33674},
		{"setclock", 32972},
		{"setclockup", 32973},
		{"setclothtype", 33703},
		{"setcommonplayerdata", 33342},
		{"setcommonplayerdatareservedint", 33820},
		{"setcontents", 32951},
		{"setconvergenceheightpercent", 33069},
		{"setconvergencetime", 33068},
		{"setconveyorbelt", 33322},
		{"setcoopplayerdata", 33341},
		{"setcoopplayerdatareservedint", 33830},
		{"setcorpsefalling", 33711},
		{"setcursorhint", 32977},
		{"setdeceleration", 33413},
		{"setdefaultdroppitch", 33107},
		{"setdepthoffield", 33153},
		{"setdronegoalpos", 33733},
		{"setempjammed", 33304},
		{"setentertime", 33382},
		{"setentityowner", 33654},
		{"seteyesonuplinkenabled", 32950},
		{"setfxkilldefondelete", 33800},
		{"setgoalentity", 33668},
		{"setgoalnode", 33667},
		{"setgoalpos", 33665},
		{"setgoalradius", 33669},
		{"setgoalyaw", 33362},
		{"setgrenadecookscale", 33770},
		{"setgrenadethrowscale", 33769},
		{"sethintstring", 32978},
		{"sethoverparams", 33353},
		{"sethybridscopestate", 33805},
		{"setignorefoliagesightingme", 33824},
		{"setjitterparams", 33352},
		{"setleftarc", 33103},
		{"setlightintensity", 33242},
		{"setlookatent", 33371},
		{"setmaterial", 32963},
		{"setmaxpitchroll", 33417},
		{"setmaxturnspeed", 33675},
		{"setmissileminimapvisible", 33814},
		{"setmlgcameradefaults", 33789},
		{"setmlgspectator", 33826},
		{"setmode", 32868},
		{"setmodel", 32938},
		{"setmovespeedscale", 33244},
		{"setnameplatematerial", 33722},
		{"setnormalhealth", 32845},
		{"setoffhandprimaryclass", 33592},
		{"setoffhandsecondaryclass", 33548},
		{"setorientmode", 33671},
		{"setorigin", 33580},
		{"setotherent", 33651},
		{"setperk", 33435},
		{"setphysicsmode", 33673},
		{"setphysvehspeed", 33321},
		{"setplanesplineid", 33771},
		{"setplayerdata", 33338},
		{"setplayernamestring", 32903},
		{"setplayerspread", 33024},
		{"setprivateplayerdata", 33340},
		{"setpulsefx", 32902},
		{"setrank", 33430},
		{"setrankedplayerdata", 33339},
		{"setrankedplayerdatareservedint", 33823},
		{"setrightarc", 33102},
		{"setrocketcorpse", 33732},
		{"setscriptabledamageowner", 33799},
		{"setscriptablepartstate", 33730},
		{"setscripted", 33678},
		{"setscriptmoverkillcam", 33597},
		{"setsentrycarrier", 33018},
		{"setsentryowner", 33017},
		{"setspawnweapon", 33349},
		{"setspectatedefaults", 33469},
		{"setspeed", 33400},
		{"setspeedimmediate", 33401},
		{"setspreadoverride", 33529},
		{"setstance", 33144},
		{"setsurfacetype", 33712},
		{"setswitchnode", 33397},
		{"settargetent", 32964},
		{"settargetentity", 33020},
		{"settargetyaw", 33364},
		{"setteamfortrigger", 32782},
		{"settenthstimer", 32969},
		{"settenthstimerstatic", 32971},
		{"settenthstimerup", 32970},
		{"settext", 32961},
		{"setthreatbiasgroup", 33138},
		{"settimer", 32966},
		{"settimerstatic", 32968},
		{"settimerup", 32967},
		{"settoparc", 33104},
		{"setturningability", 33419},
		{"setturretminimapvisible", 33019},
		{"setturretmodechangewait", 33141},
		{"setturrettargetent", 33368},
		{"setturrettargetvec", 33367},
		{"setturretteam", 33070},
		{"setvalue", 32974},
		{"setvehgoalpos", 33361},
		{"setvehiclelookattext", 33358},
		{"setvehicleteam", 33359},
		{"setvelocity", 33509},
		{"setviewheight", 33681},
		{"setviewkickscale", 33533},
		{"setviewmodel", 33591},
		{"setviewmodeldepthoffield", 33154},
		{"setvolmod", 33571},
		{"setwaitspeed", 33398},
		{"setwallruncost", 33832},
		{"setwatersheeting", 33299},
		{"setwaypoint", 32975},
		{"setwaypointedgestylerotatingicon", 32976},
		{"setwaypointedgestylesecondaryarrow", 32895},
		{"setwaypointiconoffscreenonly", 32896},
		{"setweapon", 33373},
		{"setweaponammoclip", 33516},
		{"setweaponammostock", 33517},
		{"setweaponhudiconoverride", 33302},
		{"setweaponmodelvariant", 33807},
		{"setwhizbyradii", 33568},
		{"setwhizbyspreads", 33567},
		{"setyawspeed", 33415},
		{"setyawspeedbyname", 33416},
		{"shellshock", 33149},
		{"shootturret", 32992},
		{"show", 32848},
		{"showallparts", 32841},
		{"showhudsplash", 33434},
		{"showpart", 32840},
		{"showtoplayer", 32774},
		{"sightconetrace", 33235},
		{"snaptotargetentity", 33021},
		{"solid", 33459},
		{"spawn", 33381},
		{"spawnagent", 33659},
		{"spawntestclient", 33767},
		{"startac130", 33595},
		{"startbarrelspin", 32987},
		{"startfiring", 32984},
		{"startpath", 33396},
		{"startragdoll", 32799},
		{"stopbarrelspin", 32988},
		{"stopfiring", 32985},
		{"stoplocalsound", 33515},
		{"stoploopsound", 32932},
		{"stopmoveslide", 33449},
		{"stopridingvehicle", 33809},
		{"stoprumble", 32936},
		{"stopshellshock", 33151},
		{"stopsliding", 33731},
		{"stopsounds", 32933},
		{"stunplayer", 33150},
		{"suicide", 33377},
		{"switchtooffhand", 33547},
		{"switchtoweapon", 33545},
		{"switchtoweaponimmediate", 33546},
		{"takeallweapons", 33540},
		{"takeweapon", 33539},
		{"teleport", 33393},
		{"thermaldrawdisable", 32768},
		{"thermaldrawenable", 32805},
		{"thermalvisionfofoverlayoff", 32947},
		{"thermalvisionfofoverlayon", 32946},
		{"thermalvisionoff", 32945},
		{"thermalvisionon", 32943},
		{"thermalvisiononshadowoff", 32944},
		{"trackerupdate", 33344},
		{"transfermarkstonewscriptmodel", 33298},
		{"turnengineoff", 33408},
		{"turnengineon", 33409},
		{"turretfiredisable", 33109},
		{"turretfireenable", 33140},
		{"turretsetbarrelspinenabled", 33776},
		{"unlink", 32844},
		{"unsetperk", 33438},
		{"usebuttonpressed", 33584},
		{"useby", 32918},
		{"usemodelcollisionbounds", 33825},
		{"usetriggerrequirelookat", 33142},
		{"usinggamepad", 33598},
		{"vehicledriveto", 33314},
		{"vehicleturretcontroloff", 33312},
		{"vehicleturretcontrolon", 33375},
		{"vibrate", 33457},
		{"viewkick", 33194},
		{"visionsetmissilecamforplayer", 33482},
		{"visionsetnakedforplayer", 33480},
		{"visionsetnightforplayer", 33481},
		{"visionsetpainforplayer", 33484},
		{"visionsetpostapplyforplayer", 33819},
		{"visionsetstage", 33718},
		{"visionsetthermalforplayer", 33483},
		{"visionsyncwithplayer", 33433},
		{"weaponlockfinalize", 33497},
		{"weaponlockfree", 33498},
		{"weaponlocknoclearance", 33432},
		{"weaponlockstart", 33496},
		{"weaponlocktargettooclose", 33499},
		{"worldpointinreticlecircle", 33295},
		{"worldpointinreticlerect", 33296},
		{"worldpointtoscreenpos", 33740},
	};
}
