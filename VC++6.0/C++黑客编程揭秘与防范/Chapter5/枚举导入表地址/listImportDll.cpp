#include "stdio.h"
#include "windows.h"
#include "Dbghelp.h"

int main(){
	DWORD dwNum = 0;
	PVOID lpBase = GetModuleHandle("Kernel32.dll");
	PIMAGE_IMPORT_DESCRIPTOR pImpDes = (PIMAGE_IMPORT_DESCRIPTOR)ImageDirectoryEntryToData(lpBase, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, &dwNum);

	PIMAGE_IMPORT_DESCRIPTOR pTMpImpDes = pImpDes;
	while (pTMpImpDes->Name)
	{
		printf("DllName = %s \r\n", (DWORD)lpBase);
	}

	return 0;
}
