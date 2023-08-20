#include <Windows.h>
#include <stdlib.h> 
#include <malloc.h>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		MessageBoxA(NULL, "Missing filename as an argument, use via dragndrop.", "DDRAW <-> GGRAW", MB_OK);
		return 0;
	}
    
    if (argc > 2)
    {
        MessageBoxA(NULL, "Too many arguments, dragndrop only one file.", "DDRAW <-> GGRAW", MB_OK);
		return 0;        
    }
		

	HANDLE h = CreateFileA(argv[1], GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (h == INVALID_HANDLE_VALUE)
	{
		MessageBoxA(NULL, "Failed to open the file!", "DDRAW <-> GGRAW", MB_OK);
		return 0;
	}
	
	BOOL found = FALSE;
	DWORD nr;
	size_t siz = GetFileSize(h, NULL);
	BYTE* bytes = (BYTE*) malloc(sizeof(*bytes) * siz);
	ReadFile(h, bytes, siz, &nr, 0);

	for (int i = 0; i < siz - 5; i++) 
	{
		if (bytes[i] == 'd' || bytes[i] == 'D')
		{
			char buf[6] = "";
			CopyMemory(buf, (bytes + i), 5);
			if (!_stricmp(buf, "ddraw"))
			{
				SetFilePointer(h, i, NULL, FILE_BEGIN);
				WriteFile(h, "GGRAW", 5, &nr, NULL);
				MessageBoxA(NULL, "DDRAW.DLL changed to GGRAW.DLL", "DDRAW <-> GGRAW", MB_OK);
				found = TRUE;
				break;
			}
		}
		else if (bytes[i] == 'g' || bytes[i] == 'G')
		{
			char buf[6] = "";
			CopyMemory(buf, (bytes + i), 5);
			if (!_stricmp(buf, "ggraw"))
			{
				SetFilePointer(h, i, NULL, FILE_BEGIN);
				WriteFile(h, "DDRAW", 5, &nr, NULL);
				MessageBoxA(NULL, "GGRAW.DLL changed to DDRAW.DLL", "DDRAW <-> GGRAW", MB_OK);
				found = TRUE;
				break;
			}
		}
	}
	
	CloseHandle(h);
	free(bytes);

	if (!found)
		MessageBoxA(NULL, "LoadLibrary(DDRAW.DLL) not found within the file!", "DDRAW <-> GGRAW", MB_OK);
	
	return 0;
}