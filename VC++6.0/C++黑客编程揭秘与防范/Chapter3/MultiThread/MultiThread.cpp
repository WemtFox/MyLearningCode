#include <Windows.h>
#include "stdio.h"

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	printf("ThreadProc \r\n");

	return 0;
}

int main(int argc,char* argv[])
{
	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);

	//只能等待一个线程
	WaitForSingleObject(hThread, 1);

	printf("main \r\n");

	CloseHandle(hThread);

	return 0;
}

