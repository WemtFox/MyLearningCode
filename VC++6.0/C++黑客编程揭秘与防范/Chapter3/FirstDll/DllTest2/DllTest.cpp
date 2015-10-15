#include <Windows.h>

typedef VOID (*PFUNMSG) (char *);	//

int main(int argc, char* argv[])
{
	HMODULE hMoudle = LoadLibrary("FirstDll.dll");
	if ( hMoudle == NULL)
	{
		MessageBox(NULL, "FirstDll.dll�ļ�������", "DLL����ʧ��", MB_OK);
		return -1;
	}

	PFUNMSG pFunMsg = (PFUNMSG)GetProcAddress(hMoudle, "MsgBox");
	pFunMsg("Hello First Dll!");
	
	return 0;
}