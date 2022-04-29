//****************************************************************************
// File: runlib.h
//
// Purpose: prototypes and defines for runandwait sample
//
// Functions: none
//
//
// Development Team: richhe
//
//
// Written by Microsoft Product Support Services, Windows Developer Support
// Copyright (c) 1992 Microsoft Corporation. All rights reserved.
//****************************************************************************



// typedefs for calling LoadModule

typedef struct tagCMDSHOW
{
   WORD wFirst;
   WORD wSecond;
}
CMDSHOW;

typedef CMDSHOW FAR * LPCMDSHOW ;

typedef struct tagPARAMETERBLOCK
{
   WORD      wEnvSeg;
   LPSTR     lpCmdLine;
   LPCMDSHOW lpCmdShow;
   DWORD     dwUnused;
}
PARAMETERBLOCK;

typedef PARAMETERBLOCK FAR * LPPARAMETERBLOCK ;

//typedef for linked list structure and functions

typedef struct tagNode
{
   HTASK hTask;
   WORD  wCode;
   struct tagNode FAR * lpNext;
} NODE;

typedef NODE FAR * LPNODE;

LPNODE PASCAL NodeAdd(void);
void   PASCAL NodeDelete(LPNODE lpNode);
LPNODE PASCAL NodeFind(HTASK hTask);

// typedefs and functions for SpawnAndWait 

typedef void (CALLBACK* LPMSGPROC) (LPMSG);

typedef struct tagSPAWNWAIT
{
   HWND   hwnd;         /* handle of parent window */
   LPCSTR lpszOp;       /* address of string for operation to perform   */
   LPCSTR lpszFile;     /* address of string for filename   */
   LPCSTR lpszParams;   /* address of string for executable-file parameters   */
   LPCSTR lpszDir;      /* address of string for default directory   */
   int    fsShowCmd;    /* whether file is shown when opened   */
   LPMSGPROC lpmsgproc; /* address of callback message pump */
} SPAWNWAIT;

typedef SPAWNWAIT FAR * LPSPAWNWAIT;

DWORD CALLBACK __export SpawnAndWait(HWND hwnd, LPCSTR lpszOp, LPCSTR lpszFile, LPCSTR lpszParams, LPCSTR lpszDir, int fsShowCmd);
DWORD CALLBACK __export SpawnAndWaitIndirect(LPSPAWNWAIT lpSpawnWait);

BOOL  CALLBACK __export ToolHelpNotifyProc(WORD wID, DWORD dwData);


// called via GetProcAddress from RunTask module

//must match .DEF file export ordinal values

#define NOTIFYPROC  3
#define HOOKPROC    5

void    CALLBACK __export Hook(void);
typedef BOOL (CALLBACK* LPHOOKPROC)(void);




