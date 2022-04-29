#ifndef _APIDEF_H
#define _APIDEF_H

#ifndef EXPORT_API
#if defined ( WIN32 )
#define EXPORT_API __declspec( dllexport )
#else
#define EXPORT_API __export FAR PASCAL
#endif
#endif

#define INTFUNC WINAPI

#endif

