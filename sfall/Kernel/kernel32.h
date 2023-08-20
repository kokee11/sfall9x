#pragma once

#define	WININIT_FILENAME	"wininit.ini"
#define RENAME_SECTION		"rename"
#define BUFSIZE				32767

typedef enum WINVER_enum {
	UNDEF = 0,
	WINVER_95,
	WINVER_98,
	WINVER_ME,
	WINVER_NT351,
	WINVER_NT4,
	WINVER_NT5,
	WINVER_NT51,
	WINVER_NT52,
	WINVER_NT6
} WINVER_enum, *pWINVER_enum;

int acp_mcs;

#define WtoA(str, bsize) WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)str##W, -1, (LPSTR)str##A, bsize, NULL, NULL)

#define _ALLOC_WtoA(str) \
        const WCHAR* p; \
        int c; \
        for (p = str##W ; *p ; p++); \
        c = p - str##W + 1; \
        c *= acp_mcs; \
        str##A = (char*) alloca(c); \
        WtoA(str, c)


#define ALLOC_WtoA(str) \
        char* str##A; \
        if (str##W) \
        { \
            _ALLOC_WtoA(str); \
        } \
        else str##A = NULL
            