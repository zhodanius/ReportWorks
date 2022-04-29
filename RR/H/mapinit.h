#define SZ_MAPILOGON "MAPILogon"
#define SZ_MAPILOGOFF "MAPILogoff"
#define SZ_MAPISENDMAIL "MAPISendMail"
#define SZ_MAPISENDDOC "MAPISendDocuments"
#define SZ_MAPIFINDNEXT "MAPIFindNext"
#define SZ_MAPIREADMAIL "MAPIReadMail"
#define SZ_MAPISAVEMAIL "MAPISaveMail"
#define SZ_MAPIDELMAIL "MAPIDeleteMail"
#define SZ_MAPIFREEBUFFER "MAPIFreeBuffer"
#define SZ_MAPIADDRESS "MAPIAddress"
#define SZ_MAPIDETAILS "MAPIDetails"
#define SZ_MAPIRESOLVENAME "MAPIResolveName"
#define MAPIDLL "MAPI.DLL"

#define ERR_LOAD_LIB  0x02
#define ERR_LOAD_FUNC 0x04

typedef ULONG (FAR PASCAL *LPFNMAPILOGON)(ULONG, LPSTR, LPSTR, FLAGS, ULONG, LPLHANDLE);

typedef ULONG (FAR PASCAL *LPFNMAPILOGOFF)(LHANDLE, ULONG, FLAGS,ULONG);

typedef ULONG (FAR PASCAL *LPFNMAPISENDMAIL)(LHANDLE, ULONG, lpMapiMessage, FLAGS,
                                     ULONG);

typedef ULONG (FAR PASCAL *LPFNMAPISENDDOCUMENTS)(ULONG, LPSTR, LPSTR, LPSTR, ULONG);

typedef ULONG (FAR PASCAL *LPFNMAPIFINDNEXT)(LHANDLE, ULONG, LPSTR, LPSTR, FLAGS,
                                     ULONG, LPSTR);

typedef ULONG (FAR PASCAL *LPFNMAPIREADMAIL)(LHANDLE, ULONG, LPSTR, FLAGS, ULONG,
                                     lpMapiMessage FAR *);

typedef ULONG (FAR PASCAL *LPFNMAPISAVEMAIL)(LHANDLE, ULONG, lpMapiMessage, FLAGS,
                                     ULONG, LPSTR);

typedef ULONG (FAR PASCAL *LPFNMAPIDELETEMAIL)(LHANDLE, ULONG, LPSTR, FLAGS, ULONG);

typedef ULONG (FAR PASCAL *LPFNMAPIFREEBUFFER)(LPVOID);

typedef ULONG (FAR PASCAL *LPFNMAPIADDRESS)(LHANDLE, ULONG, LPSTR, ULONG, LPSTR,
					                ULONG, lpMapiRecipDesc, FLAGS, ULONG,
                                    LPULONG, lpMapiRecipDesc FAR *);

typedef ULONG (FAR PASCAL *LPFNMAPIDETAILS)(LHANDLE, ULONG,lpMapiRecipDesc, FLAGS,
                                    ULONG);

typedef ULONG (FAR PASCAL *LPFNMAPIRESOLVENAME)(LHANDLE, ULONG, LPSTR, FLAGS,
						                ULONG, lpMapiRecipDesc FAR *);

// Storage for function pointers described above.

LPFNMAPILOGON				lpfnMAPILogon;
LPFNMAPILOGOFF 			lpfnMAPILogoff;
LPFNMAPISENDMAIL 			lpfnMAPISendMail;
LPFNMAPISENDDOCUMENTS	lpfnMAPISendDocuments;
LPFNMAPIFINDNEXT			lpfnMAPIFindNext;
LPFNMAPIREADMAIL			lpfnMAPIReadMail;
LPFNMAPISAVEMAIL			lpfnMAPISaveMail;
LPFNMAPIDELETEMAIL		lpfnMAPIDeleteMail;
LPFNMAPIFREEBUFFER		lpfnMAPIFreeBuffer;
LPFNMAPIADDRESS			lpfnMAPIAddress;
LPFNMAPIDETAILS			lpfnMAPIDetails;
LPFNMAPIRESOLVENAME		lpfnMAPIResolveName;
