#include <Windows.h>

int main(int argc, char** argv)
{
	if (argc != 3)
		return 0;

	if (_stricmp(argv[1], "sfall9x") != 0)
		return 0;

	Sleep(100);

	CopyFileA(argv[2], "SFALLHRP.EXE", FALSE);

	HANDLE hf = CreateFileA("SFALLHRP.EXE", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hf == INVALID_HANDLE_VALUE)
	{
		DeleteFileA("SFALLHRP.EXE");
		MessageBoxA(NULL, "Failed to disable MashHRP. Please set HiResMode=0 in ddraw.ini and restart the game.", "", MB_OK);
		return 0;
	}

	BYTE restore1[] = { 0xC7, 0x05, 0x88, 0x27, 0x6B, 0x00, 0x00, 0xE7, 0x4D, 0x00 };
	DWORD restore2[10] = { 0 };
	DWORD dd;
	DWORD err = 0;

	err += (SetFilePointer(hf, 0xD4880, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER);
	err += (WriteFile(hf, restore1, 10, &dd, NULL) == NULL);
	err += (SetFilePointer(hf, 0xEE5C0, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER);
	err += (WriteFile(hf, restore2, 40, &dd, NULL) == NULL);

	CloseHandle(hf);

	if (err)
	{
		DeleteFileA("SFALLHRP.EXE");
		MessageBoxA(NULL, "Failed to disable MashHRP. Please set HiResMode=0 in ddraw.ini and restart the game.", "", MB_OK);
		return 0;
	}

	DeleteFileA(argv[2]);
	MoveFileA("SFALLHRP.EXE", argv[2]);
	ShellExecuteA(0, 0, argv[2], NULL, 0, SW_SHOWDEFAULT); // restart game

    return 0;
}
