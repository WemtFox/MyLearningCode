#include <Windows.h>
#include <stdio.h>

int g_Num_One = 0;
DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	int nTmp = 0;

	for (int i = 0; i < 10; i++)
	{
		nTmp = g_Num_One;
		nTmp++;

		//Sleep(1)的作用是让出CPU
		//使其他线程调度运行
		Sleep(1);
		g_Num_One = nTmp;
	}

	return 0;
}

int main(int argc,char* argv[])
{
	HANDLE hThread[10];

	for (int i = 0; i < 10; i++)
	{
		hThread[i] = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
		if (hThread == NULL)
		{
			printf("%d CreatThread Error \r\n", i);
		}
	}
	


	WaitForMultipleObjects(10, hThread, TRUE, INFINITE);

	for (i = 0; i < 10; i++)
	{
		CloseHandle(hThread[i]);
	}
	
	printf("%d \r\n", g_Num_One);

	return 0;
}