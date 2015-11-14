#include "Windows.h"
#include "ILHook.h"

//����ȫ�ֱ���
CILHook MsgHook;

//�Զ���MessageBoxA
WINAPI
MyMessageBoxA(
	  HWND hWnd,
	  LPCSTR lpText,
	  LPCSTR lpCaption,
	  UINT uType
	  )
{
	//�ָ�HOOK
	MsgHook.UnHook();
	MessageBox(hWnd, "HOOk", lpCaption, uType);
	MessageBox(hWnd, lpText, lpCaption, uType);

	//����HOOK
	MsgHook.ReHook();
	MessageBox(NULL, "test", "test", MB_OK);
	return 0;
}

int main(){
	//������HOOK��MessageBox
	MessageBox(NULL, "test", "test", MB_OK);

	//HOOK��
	MsgHook.Hook("User32.dll", "MessageBoxA", (PROC)MyMessageBoxA);
	MessageBox(NULL, "test", "test", MB_OK);
	MsgHook.UnHook();
	

	return 0;
}
