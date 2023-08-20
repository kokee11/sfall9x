.model flat

EXTERN _LibInitializeSListHead@4 : PROC
EXTERN _LibInitializeCriticalSectionAndSpinCount@8 : PROC
EXTERN _LibGetModuleHandleExW@12 : PROC
EXTERN _LibSetFilePointerEx@20 : PROC
EXTERN _LibDecodePointer@4 : PROC
EXTERN _LibEncodePointer@4 : PROC
EXTERN _LibInterlockedFlushSList@4 : PROC
EXTERN _LibMoveFileExW@12 : PROC
EXTERN _LibMoveFileExA@12 : PROC

.data

PUBLIC __imp__InitializeSListHead@4
__imp__InitializeSListHead@4 dd _LibInitializeSListHead@4

PUBLIC __imp__InitializeCriticalSectionAndSpinCount@8
__imp__InitializeCriticalSectionAndSpinCount@8 dd _LibInitializeCriticalSectionAndSpinCount@8

PUBLIC __imp__GetModuleHandleExW@12
__imp__GetModuleHandleExW@12 dd _LibGetModuleHandleExW@12

PUBLIC __imp__SetFilePointerEx@20
__imp__SetFilePointerEx@20 dd _LibSetFilePointerEx@20

PUBLIC __imp__DecodePointer@4
__imp__DecodePointer@4 dd _LibDecodePointer@4

PUBLIC __imp__EncodePointer@4
__imp__EncodePointer@4 dd _LibEncodePointer@4

PUBLIC __imp__InterlockedFlushSList@4
__imp__InterlockedFlushSList@4 dd _LibInterlockedFlushSList@4

PUBLIC __imp__MoveFileExW@12
__imp__MoveFileExW@12 dd _LibMoveFileExW@12

PUBLIC __imp__MoveFileExA@12
__imp__MoveFileExA@12 dd _LibMoveFileExA@12

END
