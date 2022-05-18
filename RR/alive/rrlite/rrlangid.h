//****************************************************************************
//
//    RRLANGID.H - Language and String Table ID's
//
//		(C) Copyright 1996 Concentric Data Systems, Inc.
//						All Rights Reserved.
//

/////////////////////////////////////////////////
//  Language ID's
/////////////////////////////////////////////////
#define LANG_ENG	0x409	// English
#define LANG_GER	0x407	// German
#define LANG_SPA	0x40A	// Spanish
#define LANG_FRE	0x40C	// French
#define LANG_ITA	0x410	// Italian
#define LANG_POR	0x816	// Portougese

/////////////////////////////////////////////////
//  Amount to bias base English ID's for
//  each language.  This delta is set based on
//  the language ID passed in the object tag,
//  which can be one of the values above.
/////////////////////////////////////////////////
#define GERMAN_DELTA	100
#define	FRENCH_DELTA	200
#define SPANISH_DELTA	300
#define ITALIAN_DELTA	400
#define PORTOUGESE_DELTA	500

/////////////////////////////////////////////////
//  English String ID's
/////////////////////////////////////////////////
#define IDS_PRINTREPORT                 400
#define IDS_PROPERTIES                  401
#define IDS_PAGENUMBER                  402
#define IDS_PAGE_N_OF_N                 403
#define IDS_ERR_READ_SYSTEM             404
#define IDS_ERR_READ_THREAD             405
#define IDS_ERR_PRT_START               406
#define IDS_ERR_PRINT                   407
#define IDS_ERR_IMAGELIB                408
#define IDS_ERR_READ_TYPE               409
#define IDS_ERR_READ_VERSION            410
#define IDS_ERR_READ_EMPTY              411
#define IDS_CTRL_CAPTION                412
#define IDS_REPLABEL                    413
#define IDS_DATELABEL                   414
#define IDS_ABOUTTEXT                   415
#define IDS_VERTEXT                     416
#define IDS_VERSION                     417
#define IDS_ABOUT                       418
#define IDS_ERR_READ_ALL                419
//AMH 5/16/97 added two new string ids for the about box
#define IDS_INCORPTEXT					420
#define IDS_WARNING_1					421
#define IDS_WARNING_2					422
#define IDS_INCORPTEXT_2				423



/////////////////////////////////////////////////
//  German String ID's
/////////////////////////////////////////////////
#define IDS_GER_PRINTREPORT             500
#define IDS_GER_PROPERTIES              501
#define IDS_GER_PAGENUMBER              502
#define IDS_GER_PAGE_N_OF_N             503
#define IDS_GER_ERR_READ_SYSTEM         504
#define IDS_GER_ERR_READ_THREAD         505
#define IDS_GER_ERR_PRT_START           506
#define IDS_GER_ERR_PRINT               507
#define IDS_GER_ERR_IMAGELIB            508
#define IDS_GER_ERR_READ_TYPE           509
#define IDS_GER_ERR_READ_VERSION        510
#define IDS_GER_ERR_READ_EMPTY          511
#define IDS_GER_CTRL_CAPTION            512
#define IDS_GER_REPLABEL                513
#define IDS_GER_DATELABEL               514
#define IDS_GER_ABOUTTEXT               515
#define IDS_GER_VERTEXT                 516
#define IDS_GER_VERSION                 517
#define IDS_GER_ABOUT                   518
#define IDS_GER_ERR_READ_ALL            519

/////////////////////////////////////////////////
//  French String ID's
/////////////////////////////////////////////////
#define IDS_FRA_PRINTREPORT             600
#define IDS_FRA_PROPERTIES              601
#define IDS_FRA_PAGENUMBER              602
#define IDS_FRA_PAGE_N_OF_N             603
#define IDS_FRA_ERR_READ_SYSTEM         604
#define IDS_FRA_ERR_READ_THREAD         605
#define IDS_FRA_ERR_PRT_START           606
#define IDS_FRA_ERR_PRINT               607
#define IDS_FRA_ERR_IMAGELIB            608
#define IDS_FRA_ERR_READ_TYPE           609
#define IDS_FRA_ERR_READ_VERSION        610
#define IDS_FRA_ERR_READ_EMPTY          611
#define IDS_FRA_CTRL_CAPTION            612
#define IDS_FRA_REPLABEL                613
#define IDS_FRA_DATELABEL               614
#define IDS_FRA_ABOUTTEXT               615
#define IDS_FRA_VERTEXT                 616
#define IDS_FRA_VERSION                 617
#define IDS_FRA_ABOUT                   618
#define IDS_FRA_ERR_READ_ALL            619

/////////////////////////////////////////////////
//  Spanish String ID's
/////////////////////////////////////////////////
#define IDS_SPA_PRINTREPORT             700
#define IDS_SPA_PROPERTIES              701
#define IDS_SPA_PAGENUMBER              702
#define IDS_SPA_PAGE_N_OF_N             703
#define IDS_SPA_ERR_READ_SYSTEM         704
#define IDS_SPA_ERR_READ_THREAD         705
#define IDS_SPA_ERR_PRT_START           706
#define IDS_SPA_ERR_PRINT               707
#define IDS_SPA_ERR_IMAGELIB            708
#define IDS_SPA_ERR_READ_TYPE           709
#define IDS_SPA_ERR_READ_VERSION        710
#define IDS_SPA_ERR_READ_EMPTY          711
#define IDS_SPA_CTRL_CAPTION            712
#define IDS_SPA_REPLABEL                713
#define IDS_SPA_DATELABEL               714
#define IDS_SPA_ABOUTTEXT               715
#define IDS_SPA_VERTEXT                 716
#define IDS_SPA_VERSION                 717
#define IDS_SPA_ABOUT                   718
#define IDS_SPA_ERR_READ_ALL            719

/////////////////////////////////////////////////
//  Italian String ID's
/////////////////////////////////////////////////
#define IDS_ITA_PRINTREPORT             800
#define IDS_ITA_PROPERTIES              801
#define IDS_ITA_PAGENUMBER              802
#define IDS_ITA_PAGE_N_OF_N             803
#define IDS_ITA_ERR_READ_SYSTEM         804
#define IDS_ITA_ERR_READ_THREAD         805
#define IDS_ITA_ERR_PRT_START           806
#define IDS_ITA_ERR_PRINT               807
#define IDS_ITA_ERR_IMAGELIB            808
#define IDS_ITA_ERR_READ_TYPE           809
#define IDS_ITA_ERR_READ_VERSION        810
#define IDS_ITA_ERR_READ_EMPTY          811
#define IDS_ITA_CTRL_CAPTION            812
#define IDS_ITA_REPLABEL                813
#define IDS_ITA_DATELABEL               814
#define IDS_ITA_ABOUTTEXT               815
#define IDS_ITA_VERTEXT                 816
#define IDS_ITA_VERSION                 817
#define IDS_ITA_ABOUT                   818
#define IDS_ITA_ERR_READ_ALL            819

/////////////////////////////////////////////////
//  Portougese String ID's
/////////////////////////////////////////////////
#define IDS_POR_CREATED                 900
#define IDS_POR_CTRL_CAPTION            901
#define IDS_POR_PAGE_N_OF_N             902
#define IDS_POR_PAGENUMBER              903
#define IDS_POR_REPNAME                 904
#define IDS_POR_ERR_NOPRINTER           905
#define IDS_POR_ERR_IMAGELIB            906
#define IDS_POR_ERR_READ_TYPE           907
#define IDS_POR_ERR_READ_VERSION        908
#define IDS_POR_ERR_READ_EMPTY          909
#define IDS_POR_ERR_READ_SYSTEM         910
#define IDS_POR_ERR_READ_THREAD         911
#define IDS_POR_ERR_PRT_START           912
#define IDS_POR_ERR_PRINT               913
#define IDS_POR_ERR_READ_ALL            914
