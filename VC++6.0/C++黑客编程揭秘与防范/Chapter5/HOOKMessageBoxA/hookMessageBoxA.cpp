#include "Windows.h"
#include "ILHook.h"

//创建全局变量
CILHook MsgHook;

//自定义MessageBoxA
WINAPI
MyMessageBoxA(
	  HWND hWnd,
	  LPCSTR lpText,
	  LPCSTR lpCaption,
	  UINT uType
	  )
{
	//恢复HOOK
	MsgHook.UnHook();
	MessageBox(hWnd, "HOOk", lpCaption, uType);
	MessageBox(hWnd, lpText, lpCaption, uType);

	//重新HOOK
	MsgHook.ReHook();
	MessageBox(NULL, "test", "test", MB_OK);
	return 0;
}

int main(){
	//不进行HOOK的MessageBox
	MessageBox(NULL, "test", "test", MB_OK);

	//HOOK后
	MsgHook.Hook("User32.dll", "MessageBoxA", (PROC)MyMessageBoxA);
	MessageBox(NULL, "test", "test", MB_OK);
	MsgHook.UnHook();
	

	return 0;
}
