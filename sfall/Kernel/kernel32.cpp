#define _WIN32_WINNT _WIN32_WINNT_WINXP

#include <SDKDDKVer.h>
#include <Windows.h>
#include <intrin.h>

#include "kernel32.h"

static WINVER_enum wv = UNDEF;

static VOID WINAPI __InitializeSListHead(PSLIST_HEADER);
static BOOL WINAPI __GetModuleHandleExW(DWORD, LPCWSTR, HMODULE*);
static BOOL WINAPI __GetModuleHandleExA(DWORD, LPCSTR, HMODULE*);
static BOOL WINAPI __SetFilePointerEx(HANDLE, LARGE_INTEGER, PLARGE_INTEGER, DWORD);
static PVOID WINAPI __DecodePointer(PVOID);
static PVOID WINAPI __EncodePointer(PVOID);
static PSLIST_ENTRY WINAPI __InterlockedFlushSList(PSLIST_HEADER);
static BOOL WINAPI __MoveFileExW(LPCWSTR, LPCWSTR, DWORD);
static BOOL WINAPI __MoveFileExA(LPCSTR, LPCSTR, DWORD);

typedef VOID(WINAPI *PFN_INITIALIZESLISTHEAD)(PSLIST_HEADER);
typedef BOOL(WINAPI *PFN_GETMODULEHANDLEEXW)(DWORD, LPCWSTR, HMODULE*);
typedef BOOL(WINAPI *PFN_SETFILEPOINTEREX)(HANDLE, LARGE_INTEGER, PLARGE_INTEGER, DWORD);
typedef PVOID(WINAPI *PFN_DECODEPOINTER)(PVOID);
typedef PVOID(WINAPI *PFN_ENCODEPOINTER)(PVOID);
typedef PSLIST_ENTRY(WINAPI *PFN_INTERLOCKEDFLUSHSLIST)(PSLIST_HEADER);
typedef BOOL(WINAPI *PFN_MOVEFILEEXW)(LPCWSTR, LPCWSTR, DWORD);
typedef BOOL(WINAPI *PFN_MOVEFILEEXA)(LPCSTR, LPCSTR, DWORD);
typedef BOOL(WINAPI *PFN_INITIALIZECRITICALSECTIONANDSPINCOUNT)(LPCRITICAL_SECTION, DWORD);

static PFN_INITIALIZESLISTHEAD pfnInitializeSListHead = nullptr;
static PFN_GETMODULEHANDLEEXW pfnGetModuleHandleExW = nullptr;
static PFN_SETFILEPOINTEREX pfnSetFilePointerEx = nullptr;
static PFN_DECODEPOINTER pfnDecodePointer = nullptr;
static PFN_ENCODEPOINTER pfnEncodePointer = nullptr;
static PFN_INTERLOCKEDFLUSHSLIST pfnInterlockedFlushSList = nullptr;
static PFN_MOVEFILEEXW pfnMoveFileExW = nullptr;
static PFN_MOVEFILEEXA pfnMoveFileExA = nullptr;
static PFN_INITIALIZECRITICALSECTIONANDSPINCOUNT pfnInitializeCriticalSectionAndSpinCount = nullptr;

extern "C" BOOL WINAPI
LibMoveFileExA(LPCSTR lpExistingFileNameA, LPCSTR lpNewFileNameA, DWORD dwFlags)
{

	if (!pfnMoveFileExA)
	{		
		HMODULE hKernel32 = GetModuleHandleA("kernel32");
		pfnMoveFileExA = reinterpret_cast<PFN_MOVEFILEEXA>(GetProcAddress(hKernel32, "MoveFileExA"));

		// OVERRIDE
		if (wv <= WINVER_ME)
			pfnMoveFileExA = __MoveFileExA;
	}

	// MessageBoxA(NULL, __FUNCTION__" called!", "", MB_OK);

	return pfnMoveFileExA(lpExistingFileNameA, lpNewFileNameA, dwFlags);

}

extern "C" BOOL WINAPI
LibMoveFileExW(LPCWSTR lpExistingFileName, LPCWSTR lpNewFileName, DWORD dwFlags)
{

	if (!pfnMoveFileExW)
	{		
		HMODULE hKernel32 = GetModuleHandleA("kernel32");
		pfnMoveFileExW = reinterpret_cast<PFN_MOVEFILEEXW>(GetProcAddress(hKernel32, "MoveFileExW"));

		if (wv <= WINVER_ME)
			pfnMoveFileExW = __MoveFileExW;
	}

	// MessageBoxA(NULL, __FUNCTION__" called!", "", MB_OK);

	return pfnMoveFileExW(lpExistingFileName, lpNewFileName, dwFlags);

}

extern "C" VOID WINAPI
LibInitializeSListHead(PSLIST_HEADER ListHead)
{

	if (!pfnInitializeSListHead)
	{		
		HMODULE hKernel32 = GetModuleHandleA("kernel32");
		pfnInitializeSListHead = reinterpret_cast<PFN_INITIALIZESLISTHEAD>(GetProcAddress(hKernel32, "InitializeSListHead"));

		// OVERRIDE
		if (wv <= WINVER_NT5)
			pfnInitializeSListHead = __InitializeSListHead;
	}

	// MessageBoxA(NULL, __FUNCTION__" called!", "", MB_OK);

	return pfnInitializeSListHead(ListHead);
}

extern "C" BOOL WINAPI
LibInitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount)
{

	if (!pfnInitializeCriticalSectionAndSpinCount)
	{
		DWORD v;
		DWORD nt = 0;
		v = GetVersion();

		if (v < 0x80000000)
			nt = 1;

		DWORD dwMajorVersion = (DWORD)(LOBYTE(LOWORD(v)));
		DWORD dwMinorVersion = (DWORD)(HIBYTE(LOWORD(v)));

		if (!nt && dwMajorVersion == 4 && dwMinorVersion == 0) wv = WINVER_95;
		if (!nt && dwMajorVersion == 4 && dwMinorVersion == 10) wv = WINVER_98;
		if (!nt && dwMajorVersion == 4 && dwMinorVersion == 90) wv = WINVER_ME;
		if (nt && dwMajorVersion == 3 && dwMinorVersion == 51) wv = WINVER_NT351;
		if (nt && dwMajorVersion == 4 && dwMinorVersion == 0) wv = WINVER_NT4;
		if (nt && dwMajorVersion == 5 && dwMinorVersion == 0) wv = WINVER_NT5;
		if (nt && dwMajorVersion == 5 && dwMinorVersion == 1) wv = WINVER_NT51;
		if (nt && dwMajorVersion == 5 && dwMinorVersion == 2) wv = WINVER_NT52;
		if (wv == UNDEF && nt) wv = WINVER_NT6;
		if (wv == UNDEF) wv = WINVER_95;

		HMODULE hKernel32 = GetModuleHandleA("kernel32");
		pfnInitializeCriticalSectionAndSpinCount = reinterpret_cast<PFN_INITIALIZECRITICALSECTIONANDSPINCOUNT>(GetProcAddress(hKernel32, "InitializeCriticalSectionAndSpinCount"));
	}

	// OVERRIDE
	if (wv <= WINVER_NT4)
	{
		pfnInitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
		return TRUE;
	}
	else 
		return pfnInitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
}

extern "C" BOOL WINAPI
LibGetModuleHandleExW(DWORD dwFlags, LPCWSTR lpModuleName, HMODULE* phModule)
{

	if (!pfnGetModuleHandleExW)
	{
		
		HMODULE hKernel32 = GetModuleHandleA("kernel32");
		pfnGetModuleHandleExW = reinterpret_cast<PFN_GETMODULEHANDLEEXW>(GetProcAddress(hKernel32, "GetModuleHandleExW"));

		// OVERRIDE
		if (wv <= WINVER_NT5)
			pfnGetModuleHandleExW = __GetModuleHandleExW;

	}

	// MessageBoxA(NULL, __FUNCTION__" called!", "", MB_OK);

	return pfnGetModuleHandleExW(dwFlags, lpModuleName, phModule);
}

extern "C" BOOL WINAPI
LibSetFilePointerEx(HANDLE hFile, LARGE_INTEGER liDistanceToMove, PLARGE_INTEGER lpNewFilePointer, DWORD dwMoveMethod)
{

	if (!pfnSetFilePointerEx)
	{		
		HMODULE hKernel32 = GetModuleHandleA("kernel32");
		pfnSetFilePointerEx = reinterpret_cast<PFN_SETFILEPOINTEREX>(GetProcAddress(hKernel32, "SetFilePointerEx"));
		
		// OVERRIDE
		if (wv <= WINVER_NT4)
			pfnSetFilePointerEx = __SetFilePointerEx;
	}

	// MessageBoxA(NULL, __FUNCTION__" called!", "", MB_OK);

	return pfnSetFilePointerEx(hFile, liDistanceToMove, lpNewFilePointer, dwMoveMethod);
}

extern "C" PVOID WINAPI
LibDecodePointer(PVOID Ptr)
{

	if (!pfnDecodePointer)
	{		
		HMODULE hKernel32 = GetModuleHandleA("kernel32");
		pfnDecodePointer = reinterpret_cast<PFN_DECODEPOINTER>(GetProcAddress(hKernel32, "DecodePointer"));

		// OVERRIDE
		if (wv <= WINVER_NT52)
			pfnDecodePointer = __DecodePointer;
	}

	// MessageBoxA(NULL, __FUNCTION__" called!", "", MB_OK);
	
	return pfnDecodePointer(Ptr);
}

extern "C" PVOID WINAPI
LibEncodePointer(PVOID Ptr)
{

	if (!pfnEncodePointer)
	{		
		HMODULE hKernel32 = GetModuleHandleA("kernel32");
		pfnEncodePointer = reinterpret_cast<PFN_ENCODEPOINTER>(GetProcAddress(hKernel32, "EncodePointer"));

		// OVERRIDE
		if (wv <= WINVER_NT52)
			pfnEncodePointer = __EncodePointer;
	}

	// MessageBoxA(NULL, __FUNCTION__" called!", "", MB_OK);

	return pfnEncodePointer(Ptr);

}

extern "C" PSLIST_ENTRY WINAPI
LibInterlockedFlushSList(PSLIST_HEADER ListHead)
{
	if (!pfnInterlockedFlushSList)
	{		
		HMODULE hKernel32 = GetModuleHandleA("kernel32");
		pfnInterlockedFlushSList = reinterpret_cast<PFN_INTERLOCKEDFLUSHSLIST>(GetProcAddress(hKernel32, "InterlockedFlushSList"));

		// OVERRIDE
		if (wv <= WINVER_NT5)
			pfnInterlockedFlushSList = __InterlockedFlushSList;
	}
	
	// MessageBoxA(NULL, __FUNCTION__" called!", "", MB_OK);

	return pfnInterlockedFlushSList(ListHead);
}

static VOID WINAPI
__InitializeSListHead(PSLIST_HEADER ListHead)
{
	// Due to the union, this member encompasses the entire SLIST_HEADER structure.
	ListHead->Alignment = 0;
}

static BOOL WINAPI
__GetModuleHandleExW(DWORD dwFlags, LPCWSTR lpModuleNameW, HMODULE* phModule)
{
		CPINFO cpi;
		if (!GetCPInfo(CP_ACP, &cpi))
			acp_mcs = 2;
		else
			acp_mcs = cpi.MaxCharSize;

		if (dwFlags & GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS)
			return __GetModuleHandleExA(dwFlags, (LPSTR)lpModuleNameW, phModule);
		ALLOC_WtoA(lpModuleName);

		return __GetModuleHandleExA(dwFlags, lpModuleNameA, phModule);
}

static BOOL WINAPI
__GetModuleHandleExA(DWORD dwFlags, LPCSTR lpModuleName, HMODULE* phModule)
{
	char buf[MAX_PATH];
	if (!phModule)
	{
		SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}
	*phModule = NULL;
	if (dwFlags & GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS)
	{
		MEMORY_BASIC_INFORMATION mbi;
		if (!VirtualQuery(lpModuleName, &mbi, sizeof(mbi))) return FALSE;
		*phModule = (HMODULE)mbi.AllocationBase;
	}
	else
		*phModule = GetModuleHandleA(lpModuleName);
	if (*phModule == NULL || !GetModuleFileNameA(*phModule, buf, MAX_PATH))
	{
		*phModule = NULL;
		return FALSE;
	}
	if (!(dwFlags & GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT))
		LoadLibraryA(buf);

	return TRUE;
}

static BOOL WINAPI
__SetFilePointerEx(HANDLE hFile, LARGE_INTEGER liDistanceToMove, PLARGE_INTEGER lpNewFilePointer, DWORD dwMoveMethod)
{
	// This function can be implemented in its entirety using SetFilePointer.
	liDistanceToMove.LowPart = SetFilePointer(hFile, liDistanceToMove.LowPart, &liDistanceToMove.HighPart, dwMoveMethod);
	if (liDistanceToMove.LowPart == INVALID_SET_FILE_POINTER)
	{
		return FALSE;
	}

	if (lpNewFilePointer)
	{
		lpNewFilePointer->QuadPart = liDistanceToMove.QuadPart;
	}

	return TRUE;
}

static PVOID WINAPI
__DecodePointer(PVOID Ptr)
{
	// Just return the input pointer without any decoding.
	return Ptr;
}

static PVOID WINAPI
__EncodePointer(PVOID Ptr)
{
	// Just return the input pointer without any encoding.
	return Ptr;
}

static PSLIST_ENTRY WINAPI
__InterlockedFlushSList(PSLIST_HEADER ListHead)
{
	SLIST_HEADER InitialHead = *ListHead;

	for (;;)
	{
		// Check if the list is already empty.
		if (InitialHead.Next.Next == nullptr)
		{
			// Nothing to do for us and no list entry to return.
			return nullptr;
		}

		// Zero the depth and first list entry pointer while keeping the sequence number intact.
		SLIST_HEADER NewHead = InitialHead;
		NewHead.Depth = 0;
		NewHead.Next.Next = nullptr;

		// Do the following things in a single atomic operation:
		// * Check if the list is still the same we last saved in InitialHead.
		// * If that is the case, update it to our modified NewHead.
		// * If not, someone else was faster than us. Store the changed list in PreviousHead.
		SLIST_HEADER PreviousHead;
		PreviousHead.Alignment = static_cast<ULONGLONG>(_InterlockedCompareExchange64(
			reinterpret_cast<long long*>(&ListHead->Alignment),
			static_cast<long long>(NewHead.Alignment),
			static_cast<long long>(InitialHead.Alignment)
			));

		if (InitialHead.Alignment == PreviousHead.Alignment)
		{
			// We successfully flushed the list.
			// Return the previous first list entry.
			return PreviousHead.Next.Next;
		}
		else
		{
			// Someone else was faster than us.
			// Repeat the entire process with the new InitialHead.
			InitialHead = PreviousHead;
		}
	}
}

static BOOL WINAPI
__MoveFileExW(LPCWSTR lpExistingFileNameW, LPCWSTR lpNewFileNameW, DWORD dwFlags)
{
	char lpExistingFileNameA[MAX_PATH];
	char lpNewFileNameA[MAX_PATH];
	
	WideCharToMultiByte(CP_ACP, NULL, lpExistingFileNameW, -1, lpExistingFileNameA, MAX_PATH, NULL, NULL);
	WideCharToMultiByte(CP_ACP, NULL, lpNewFileNameW, -1, lpNewFileNameA, MAX_PATH, NULL, NULL);

	return __MoveFileExA(lpExistingFileNameA, lpNewFileNameA, dwFlags);
}

static BOOL WINAPI
__MoveFileExA(LPCSTR lpExistingFileNameA, LPCSTR lpNewFileNameA, DWORD dwFlags)
{
	BOOL	fSuccess = FALSE;	// assume failure

								// Windows 9x has a special mechanism to move files after reboot

	if (dwFlags & MOVEFILE_DELAY_UNTIL_REBOOT)
	{
		CHAR	szExistingFileNameA[MAX_PATH];
		CHAR	szNewFileNameA[MAX_PATH];
		lstrcpyA(szNewFileNameA, "NUL");

		// Path names in WININIT.INI must be in short path name form

		if (
			GetShortPathNameA(lpExistingFileNameA, szExistingFileNameA, MAX_PATH) &&
			(!lpNewFileNameA || GetShortPathNameA(lpNewFileNameA, szNewFileNameA, MAX_PATH))
			)
		{
			CHAR*	szBuffer = (CHAR*)HeapAlloc(GetProcessHeap(), 0, BUFSIZE);	// The buffer size must not exceed 32K
			DWORD	dwBufLen = GetPrivateProfileSectionA(RENAME_SECTION, szBuffer, BUFSIZE, WININIT_FILENAME);

			CHAR	szRename[MAX_PATH];	// This is enough for at most to times 67 chracters
			size_t	lnRename;
			lstrcpyA(szRename, szNewFileNameA);
			lstrcatA(szRename, "=");
			lstrcatA(szRename, szExistingFileNameA);
			lnRename = lstrlenA(szRename);

			if (dwBufLen + lnRename + 2 <= BUFSIZE)
			{
				lstrcpyA(&szBuffer[dwBufLen], szRename);
				szBuffer[dwBufLen + lnRename + 1] = 0;

				fSuccess = WritePrivateProfileSectionA(RENAME_SECTION, szBuffer, WININIT_FILENAME);
			}
			else
				SetLastError(ERROR_BUFFER_OVERFLOW);

			HeapFree(GetProcessHeap(), 0, szBuffer);
		}
	}
	else
	{

		fSuccess = MoveFileA(lpExistingFileNameA, lpNewFileNameA);

		if (!fSuccess && 0 != (dwFlags & (MOVEFILE_COPY_ALLOWED | MOVEFILE_REPLACE_EXISTING)))
		{
			BOOL	bFailIfExist = 0 == (dwFlags & MOVEFILE_REPLACE_EXISTING);

			fSuccess = CopyFileA(lpExistingFileNameA, lpNewFileNameA, bFailIfExist);

			// In case of successfull copy do not return FALSE if delete fails.
			// Error detection is done by GetLastError()

			if (fSuccess)
			{
				SetLastError(NO_ERROR);
				DeleteFileA(lpExistingFileNameA);
			}
		}

	}

	return fSuccess;
}
