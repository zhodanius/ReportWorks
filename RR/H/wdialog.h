////////////////////////////////////////////
// WDIALOG.H - Defines for dialog controls

// mjs 12/29/93  	Bring in these 600 symbols only ONCE!
#ifndef _WDIALOG_H_
#define _WDIALOG_H_

// special values
#define DIALOGHELP		300		// common help id
#define IDD_FIELD_NAME	310		// common field name indication
#define DRAGDROP_FIRST	400		// drag/drop enabled >= 400

// text field property page
#define DTEXTOLD		200
#define DTEXTNEW		201

// customized common dialog (no master table checkbox)
#define DNOMASTER		200

#define DMTEXT			200
#define DMICON			201
#define DMFRAME			202

#ifndef IDC_STATIC
#define IDC_STATIC	-1  // already defined in WIN32?
#endif

// File Print
#define DPRTWHAT		200
#define DCOPIES			201
#define DCOPYSPIN		202
#define DPRINTALL		203
#define DPRINTPAGES		204
#define DSTART_PAGE		205
#define DSPGSPIN		206
#define DEND_PAGE		207
#define DEPGSPIN		208
#define DBIN			209
#define DPRPREV			210
#define DPSETUP			211
#define DPOPTIONS		212
#define DPRDEST			213
#define DPRFILE			214
#define DPRPATH			215
#define DCOLLATE		216
#define DPRCLOSE		217

/* Export constants */
#define DEXPDEST		200
#define DEXPTYPE		201
#define DTXTGRP			202
#define DDOSCS			203
#define DWINCS			204
#define DEVERYCR		205
#define DONCECR			206
#define DEXPORT			207
#define DEXPCLOSE		208
#define DEXPHELP		209
#define DEXPBAND     	210
#define DDBXGRP			211
#define DEXPMAPI		212
#define DEXPMAPITEXT	213
#define DCOMMASV	   214
#define DTABSV			215
#define DFIXEDSV		216
#define DUSERSV		217
#define DFIELDNAMES  218
#define DPCCS			219
#define IDC_EDIT_SEP 220
#define DSEPLABEL		221

#define DTOTFIELD		200
#define DTOTRESET		201
#define DTOTACCUM		202
#define DTOTRUN			203
#define DTOTPREP		204
#define DTOTNAME		205
#define DTOTOPTS		206
#define DTOTCNT			207
#define DTOTSUM			208
#define DTOTAVG			209
#define DTOTMIN			210
#define DTOTMAX			211
#define DTOTSTD			212
#define DTOTVAR			213
#define DINFOACCUM		214
#define DTOTCOND		215
#define DTOTCONDEXPR	216
// Calculations Auto Total
#define DTOTNAMETEXT	217

#define DLINKFLD		200
#define DEXACT			201
#define DAPPROX			202
#define DSCAN			203
#define DFULL			204
#define DPARTIAL		205
#define DFBLANK			206
#define DFSKIP			207
#define DFTERM			208
#define DRELFILE		209
#define DRALIAS			210
#define DPARTLEN		211
#define DRIND			212
#define DUSERINDEX		213
#define DRECNO			214
#define DINDFILE		215
#define DRHELP			216
#define DGETREL			217
#define DGETIND			218

//#ifndef RSW
#define DRELINDTAGS		219
#define DRELTAGTX		220
#define DRELINDGRP		221
#define DRELKEYEXP		222
#define DRELINDKEYTX	223
#define DRELINDFILELAB	224
#define DCONTROLTAB		225
#define DRELOPTS		226
//#endif

#define DQFIELD			200
#define DQFUNC			201
#define DQEXP			202
// #define DQOP			203
#define DQCHECK			204
#define DQRESET			205
#define DQINSERT		206
#define DQFILE			207
#define DCALCNAME		208
#define DCALCEXP		209
#define DKEYEXP			210
#define DUDFFORM		211
#define DQNAMETX		212
#define DQFLDTX			213
#define DQT				214
#define DQF				215
#define DPASTEARGS		216
#define DFUNCHELP		217
#define DCALCHELP		218
//#ifdef RSW
#define DQVALUE			219
//#endif
#define DQOP1			221
#define DQOP2			222
#define DQOP3			223
#define DQOP4			224
#define DQOP5			225
#define DQOP6			226
#define DQOP7			227
#define DQOP8			228
#define DQOP9			229
#define DQOP10			220
#define DQOP11			231
#define DQOP12			232
#define DQOP13			233
#define DQOP14			234
#define DQOP15			235
#define DQOP16			236

#define DSKEY1			200
#define DSKEY2			201
#define DSKEY3			202
#define DSKEY4			203
#define DSKEY5			204
#define DSKEY6			205
#define DSKEY7			206
#define DSKEY8			207
#define DSASC1			208
#define DSASC2			209
#define DSASC3			210
#define DSASC4			211
#define DSASC5			212
#define DSASC6			213
#define DSASC7			214
#define DSASC8			215
#define DSTX1			216
#define DSTX2			217
#define DSTX3			218
#define DSTX4			219
#define DSTX5			220
#define DSTX6			221
#define DSTX7			222
#define DSTX8			223
#define DSRESET			224
#define DSINSERT		225
#define DSDELETE		226
#define DSGROUP			227
#define DSSORT			228
#define DGPR1			229
#define DGPR2			230
#define DGPR3			231
#define DGPR4			232
#define DGPR5			233
#define DGPR6			234
#define DGPR7			235
#define DGPR8			236
#define DGRES1			237
#define DGRES2			238
#define DGRES3			239
#define DGRES4			240
#define DGRES5			241
#define DGRES6			242
#define DGRES7			243
#define DGRES8			244
#define DGSWH1			245
#define DGSWH2			246
#define DGSWH3			247
#define DGSWH4			248
#define DGSWH5			249
#define DGSWH6			250
#define DGSWH7			251
#define DGSWH8			252
#define DGSWF1			253
#define DGSWF2			254
#define DGSWF3			255
#define DGSWF4			256
#define DGSWF5			257
#define DGSWF6			258
#define DGSWF7			259
#define DGSWF8			260
#define DGRPH1			261
#define DGRPH2			262
#define DGRPH3			263
#define DGRPH4			264
#define DGRPH5			265
#define DGRPH6			266
#define DGRPH7			267
#define DGRPH8			268

#define DRONONDEL		200
#define DRODEL			201
#define DROALL			202

#define DROACROSS		203
#define DROSPINACROSS	204

#define DROWIDTH		205
#define DROSPINWID		206

#define DROHITE			207
#define DROSPINHITE		208

#define DROCOPIES		209
#define DROCOMP			210
#define DROSUPP			211
#define DRONLSEMI		212
#define DROHFSUM		213
#define DROBRKBOD		214
#define DRODIMEN		215
#define DROCOPYNUM		216
#define DROCOPYFLD		217

#define DROCOPYEDIT		218
#define DROSPINCOPIES	219
#define DROLABEL		220
#define DROORDERA		221
#define DROORDERD		222

#define DGPCALC			200
#define DGPTOTAL    	201

#define DBRFROM			200
#define DBRTO			201
#define DBRHELP			202

#define DOPMLEN			200

#define DOPMTOPMAR		201
#define DOPMTOPSPIN		202

#define DOPMBOTMAR		203
#define DOPMBOTSPIN		204

#define DOPMLEFMAR		205
#define DOPMLEFSPIN		206

#define DOPMRITMAR		207
#define DOPMRITSPIN		208

#define DOPMPORT		209
#define DOPMLAND		210
#define DOPMMARGRP  	211
#define DOPMSIZETX   	212
#define DOPMLEADING		213

#define DRULEDIT		200
#define DHORZGROUP		201
#define DVRULEDIT		202
#define DVERTGROUP		203
#define DRULHELP		204

#define DFCWIDTH		200
#define DFCSPIN			201
#define DFCINCH			202
#define DFCCOLS			203
#define DFHELPTEXT		204

#define DFNINT			200
#define DFNISPIN		201
#define DFNDEC			202
#define DFNDSPIN		203
#define DFNLEADZ		204
#define DFNSHOWZ		205
#define DFNNAME			206
#define DFNFORMAT		207
#define DFNSAMPLE   	208
#ifdef RRPACE
#define DPACECHR		211
#endif

// date
#define DFDFORMAT		200
#define DFDSAMPLE   	201
// time
#define DFDTIME			202
// date/time
#define DFDSHOWDATE		203
#define DFDSHOWTIME		204

#define DINSLAYOUTFLDS	DRAGDROP_FIRST
#define DIFIELDS		200
#define DICLOSEDLG		201

#define DPSLIST     	200
#define DPSSETUP    	201
#define DPSDEFAULT		202

#define DPREPNAME   	200
#define DPRPRINTER  	201
#define DPRRECORDS  	202
#define DPRPAGE     	203
#define DPRRECSLAB		204
#define DPRPAGELAB		205
#define DPRCOPYOF		206

#define DLNTYPE      	200
#define DLNCNT	     	201
#define DLNCNTSPIN     	202
#define DLNABOVE		203
#define DLNBELOW		204
#define DLNNEW			205
#define DLNPAGE			206

#define DLHTBOX     	200
#define DLAUTOHT    	201
#define DLFREEFORM		202
#define DLINCHES    	203
#define DLPOINTS    	204
#define DLHEIGHT    	205
#define DLINEHTSPIN		206
#define DLLOGFLD    	207
#define DLSCANFLD   	208
#define DLINENUM		209
#define DLINETYPE		210
#define DLLOGTRUE		211
#define DLLOGFALSE		212

#define DALLEFT			200
#define DALCENTER		201
#define DALRIGHT		202
#define DALWRAP			203
#define DALWRAPL		204
#define DALWRAPF		205
#define DALWRAPR    	206
#define DALNAME			207
#define DTRIMNO     	208
#define DTRIMYES		209

#define DPRODNAME		200
#define DTHIRD_ONE		201
#define DTHIRD_TWO		202
#define DLICNAME		203
#define DLICCOMPANY		204
#define DSERIALNUM		205
#define DWARNING		206
//#ifdef RSW
#define DDBVERSION		207
#define DTHIRD_THREE		208
//#endif
#define DPRODVER		209

#define DMODALIGNB		200
#define DMODFONTB		201
#define DMODPICB 		202
#define DMODTRIMB		203
#define DMODEXPB    	204
#define DMODNOTEB		205
#define DMODFLD			206
#define DMODTYPE		207
#define DMODALIGN		208
#define DMODPIC 		209
#define DMODFONT		210
#define DMODTRIM		211
#define DMODEXP     	212
#define DMODSIZE    	213
#define DMODNOTE		214

#define DIMGEDIT		201
#define DIMGPART		202
#define DIMGNONE		203
#define DIMGFULL		204
#define DIMGFILE		205
#define DIMGWIDTH		206
#define DIMGWSPIN		207
#define DIMGHEIGHT		208
#define DIMGHSPIN		209
#define DIMGORG			210
#define DIMGCUR			211
#define DIMGSZGRP		212

#define DPREFDISP		200
#define DPREFWIZ		201
#define DPREFINST		202
#define DPREFBLANK		203
#define DPREFTEMP		204
#define DPREFBEEP   	205
#define DPREFSCHZ   	206
#define DPREFSCVT   	207
#define DPREFBANDCLR    208
#define DPREFDLG		209
#define DPREFDBMEMO		210
#define DPREFOTHER		211
#define DPREFTOOLHELP	212
#define DPREFFLFN		213
#define DPREFFLDDD		214
#define DPREFFLB		215

// Database Master
#define DMASTER     	200
#define DMASTALIAS		201
#define DINDEX      	202
#define DSBOF		  	203
#define DSLOVAL	    	204
#define DSLOSCOPE		205
#define DSLOPARAM		206
#define DSLOPARAMFLD	207
#define DSEOF			208
#define DSHIVAL			209
#define DSHISCOPE		210
#define DSHIPARAM		211
#define DSHIPARAMFLD	212
#define DINDTAGS     	213
#define DGETMAST	   	214
#define DGETINDEX		215
// keep together...
#define DINDNUM			216
#define DINDDATE		217
#define DINDCHAR		218
#define DINDDATETIME	219

#define DCLRINDEX		220
#define DSCOPEHELP		221
#define DMASTTAGTX		222
#define DDATATYPEGRP	223
#define DMASTKEYEXP		224
#define DMASTKEYTX		225
#define DCLRTABLE		226
#define DMASTGRP		227
#define DALIASTXT		228
#define DTABLETXT		229
#define DINDEXGRP		230
#define DFILETXT		231
#define DSSCOPETXT		232
#define DESCOPETXT		233
#define DUSEINDEX		234

// Field calc/tot/UDF Edit
#define DEDFLDS     	DRAGDROP_FIRST+1
//#define DEDFLDS     	200
#define DEDED       	201
#define DEDNEW      	202
#define DEDZAP      	203
#define DEDEXPR     	204
#define DEDRESET		205
#define DCOMMENT		206

// Calc/Tot Comment
#define DCNNAME		200
#define DCNCOMMENT	201

// View Toolbars
#define DTOOLBARS		200
#define DTOOLTIPS		201

#define DDELLIST    	200
#define DDELPROMPT  	201
#define DDELICON    	202
#define	DCHARTLIST		203

#define DGDLEN			200

#define DGDTOPMAR		201
#define DGDTOPSPIN		202

#define DGDBOTMAR		203
#define DGDBOTSPIN		204

#define DGDLEFMAR		205
#define DGDLEFSPIN		206

#define DGDRITMAR		207
#define DGDRITSPIN		208

#define DGDMARGRP   	209
#define DGDSIZETX    	210

#define DGDRULPITCH 	211
#define DGDHRULSPIN		212

#define DGDTYPEFACE 	213
#define DGDPTSIZE   	214
#define DGDLOGTRUE  	215
#define DGDLOGFALSE 	216
#define DGDFONT     	217
#define DGDPOINTS   	218
#define DGDALLOWWRITE	219

#define DGDVTPITCH		220
#define DGDVRULSPIN		221

#define DGDSNAPTO		222
#define DGDCOLOR		223
//#ifdef RSW
#define DGDDATADIR  	224
#define DGDIMGDIR  		225
#define DGDLIBDIR   	226
#define DGDMEMEXT   	227
#define DGDIMGEXT		228

// logon prefs
#define DDSNEWALLOWCHOICE	200
#define DDSNEWALWAYSUSE		201
#define DDSDEFDATASOURCE	202
#define DDSREADALLOWCHOICE	203
#define DDSREADALWAYSUSE	204
//#endif

#define DDDATADIR  		200
#define DDIMGDIR  		201
#define DDLIBDIR   		202
#define DDINDEXT   		203
#define DDMEMEXT   		204
#define DDIMGEXT		205
#define DDTEMPLATE		206
#define DDDATADICT		207
#define DDDICTINDEX		208
#define DDBROWSE		209

#define DRELLIST    	200
#define DDELETE     	201
#define DNEWREL     	202
#define DEDREL      	203
#define DRELGRP     	204
#define DRDESC      	205

#define DSCANCONT   	200
#define DSCANTERM   	201
#define DSGRPLIST      	202
#define DSMOVEUP		203
#define DSMOVEDOWN		204
#define DSCANHELP		205

#define DHELPICON		200
#define DHELPTEXT		201

#define DTXFILE			200
#define DTXALIAS		201
#define DTXSELFILE		202
#define DTXDETACH		203
#define DTXANSI			204
#define DTXPC			205

#define DCNTRLAB1		200
#define DCNTRLAB2		201
#define DCNTRLAB3		202
#define DCNTR1			203
#define DCNTR2			204
#define DCNTR3			205

#define DCALCFLDS		200
#define DCALCEXPR		201

#define DTAGLIST		200
#define DTAGFILE		201

#define DREPNAME		200
#define DLIBNAME		201
#define DLIBSELECT		202
#define DLIBDELETE		203
#define DLIBCREATE		204
#define DREPCOPY		205
#define DLIBDATASOURCE	206
#define DLIBDATASOURCETEXT	207
#define DDATETIME		208
#define DUSERID		209
#define DDATASRC		210

#define DRSLIBNAME	200
#define DRSREPNAME	201
#define DRSCOMMENT		202

#define DCRLIBNAME		200

#define DJLEFT			200
#define DJCENTER		201
#define DJRIGHT			202

#define DEXPLIST		200
#define DINSBTN			201
#define DAPPBTN			202
#define DEDITBTN		203
#define DDELBTN			204
#define DSHOWALIAS		205
#define DVERIFY			206

#define DQHELP			200
#define DANDOR			201
#define DLPAREN			202
#define DFIELDBOX		203
#define DCONDBOX		204
#define DEDIT			205
#define DRPAREN			206
#define DQFLD			207

#define DRTESTPRT		200

#define DRIPROMPT	100
#define DRIEDIT	101

#define DLBTHICK		200
#define DLBBORDCOLOR	201
#define DLBBORDLEFT		202
#define DLBBORDRIGHT	203
#define DLBBORDTOP		204
#define DLBBORDBOT		205
#define DLBPAT			206
#define DLBFORE			207
#define DLBBACK			208
#define DLBSTYLE		209

#define DREPNAME		200
#define DLIBSRC			201
#define DLIBDEST		202

#define DCIPATH			200
#define DCIPICRECT		201

// File New/Open dialogs
#define DWIZ_ICON	200
#define DINST_ICON	201
#define DBLANK_ICON	202
#define DTEMP_ICON	203
#define DOPEN_ICON	204
#define DWIZTEXT	205
// keep together

//#ifdef RSW
// Table list dialog
#define DTABLIST		200
#define DTABSQL			201
#define DTABSQLGROUP	202
#define DTABSQLSTMT		203
#define DTABDATABASES	204
#define DTABOWNERS		205
#define DTABDATABASESTEXT	206
#define DTABOWNERSTEXT		207
#define DTABCOPY			208
#define DTABPASTE			209
#define DTABNOMAST		210
#define DTABDS				211
#define DTABDIR			212
#define DTABDSLIST		213
#define DTABLAB			214
#define DTABTEXT			215

// No tables found dialog
#define DNOTABCONFIG		200
#define DNOTABCONNECT		201
#define DNOTABDATASOURCE	202
#define DNOTABDATABASE		203
#define DNOTABDRIVER		204
#define DNOTABICON			205

// Show SQL dialog
#define DSQLCOPY			200

// Limit Result dialog
#define DSERS				200
#define DSMAXROWVAL			201
#define DSMAXROW			202

// Data Source dialog
#define DPLATLIST			200
#define DSCONFIGURE			201

// Connected Data Source dialog
#define DCONDSLIST			200
#define DCONADD				201
#define DCONDISCONNECT		202

// Relations dialog===========================
#define DRELFROMFIELDS              201
#define DRELFROMTABLE               202
#define DRELTOTABLE                 203
#define DRELTOALIAS                 204
#define DRELTOFIELDS                205

// Note these need to be kept in this order
#define DRELJOINBUTT                206
#define DRELAPPROXBUTT              207
#define DRELHIMATCH                 208
#define DRELLOMATCH                 209

// Note these need to be kept in this order
#define DRELBLANKREL                210
#define DRELSKIP                    211
#define DRELBLANKINIT               212

#define DRELTOTABNAME               213
#define DRELOPTIONS					214
#define DRELFROMLIST				215
#define DRELTOLIST					216
#define DRELDELPAIR					217
#define DRELADDTEXT					218
#define DRELFROMALIAS				219
#define DRELALIASTEXT				220

//showSqlDialog=======================================
#define DSQLTEXT					201

//dbConnectDialog=====================================
// Note these IDs must correspond to ((ID in h\sql.h) minus 200)
// Code in dconnect.c relies on this relationship.
#define DBCONPLATGROUP				220
#define DBCONLOGID					221
#define DBCONPASSWD					222
#define DBCONDBNAME					223
#define DBCONDATAPATH				224
#define DBCONDICTPATH				225
#define DBCONDATAPATHTEXT			226
#define DBCONDBNAMETEXT				227
#define DBCONDICTPATHTEXT			228
#define DBCONPLATFORM				229
#define DBCONLOGIDTEXT				230
#define DBCONPASSWDTEXT				231

//
// IDs for the Btrieve Master/Related Table Dlg Box
//
#define ID_BUTTON_BROWSE            205
#define ID_STATIC_DICTIONARY        206
#define ID_LIST_TABLES              209
#define ID_RADIO_DICTIONARY         213
#define ID_RADIO_FILE               214

//
// IDs for the Report Copy Dialog Box
//
#define DCOPYPLATFORM		200
#define DCOPYNAMETEXT		201
#define DCOPYNAME			202
#define DCOPYDATAPATHTEXT	203
#define DCOPYDATAPATH		204
#define DCOPYDICTPATHTEXT	205
#define DCOPYDICTPATH		206
#define DCOPYSCHEMATEXT		207
#define DCOPYSCHEMA			208

// Field Comment property page
#define DCOMMENTEDIT		200
#define DCOMMENTHELPTEXT	201

// HTML Export Dialog
#define DEDIT_FILE_NAME		200
#define DCOLORCOMBO			201
#define DIMAGEPATH			202
#define DBORDERNONE			203
#define DBORDERWIDTH		204
#define DBORDERWIDTHEDIT	205
#define DWIDTHSPIN			206
#define DBSAMPLE			207
#define DEXPORTHTML			208
#define DBROWSER			209
#define DIMAGEGET			210
#define DCOLORSET			211
#define DIMAGESET			212

// Create Report Viewer HTML Document dialog
#define IDC_CODEURL			200
#define IDC_REPORTURL		201
#define IDC_CTRLWIDTH		202
#define IDC_HTMLPATH		203
#define IDC_CTRLHEIGHT		204
#define IDC_IMAGEPATH		205

// PDI Export Dialog (Report Viewer Control)
#define IDC_CREATEHTMLDOC	206
#define IDC_EXPORTOLE		207

// RSW Login Dialog
#define DUSERNAME	200
#define DPASSWORD	201

//#endif // RSW

#define IDC_OBJECT_SIZEGROUP            1000
#define IDC_OBJECT_WIDTH                1001
#define IDC_OBJECT_HEIGHT               1002
#define IDC_OBJECT_WIDTH_SPIN           1003
#define IDC_OBJECT_HEIGHT_SPIN          1004
#define IDC_OBJECT_ORIGINAL             1005
#define IDC_OBJECT_CURRENT              1006
#define IDC_OBJECT_SCALING_ZOOM         1008
#define IDC_OBJECT_SCALING_CROP         1009
#define IDC_OBJECT_SCALING_STRETCH      1010
#define IDC_OBJECT_TYPE                 1011
#define IDC_OBJECT_TYPENAME             1012
#define IDC_OBJECT_APPNAME              1013
#define IDD_OBJECT_PROPERTIES           7000

#endif // _WDIALOG_H_
