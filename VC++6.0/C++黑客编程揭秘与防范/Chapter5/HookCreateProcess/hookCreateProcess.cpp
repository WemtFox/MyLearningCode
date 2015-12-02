#include "ILHook.h"

CILHook CreateProcessHook;

//实现的Hook函数
BOOL WINAPI MYCreateProcessW(
		LPCWSTR lpApplicationName,
		LPWSTR lpCommandLine,
		LPSECURITY_ATTRIBUTES lpProcessAttributes,
		LPSECURITY_ATTRIBUTES lpThreadAttributes,
		BOOL bInheritHandles,
		DWORD dwCreationFlags,
		LPVOID lpEnvirronment,
		LPCWSTR lpCurrentDirectory,
		LPSTARTUPINFOW lpStartupInfo,
		LPPROCESS_INFORMATION lpProcessInformation 
		)
{
	BOOL bRet = FALSE;

	CreateProcessHook.UnHook();
/*
	//弹出被创建进程的进程名
	MessageBoxW(NULL, wcsstr(L"是否创建进程",lpApplicationName), lpCommandLine, MB_YESNOCANCEL);

	//创建进程
	bRet = CreateProcessW(lpApplicationName,
			lpCommandLine,
			lpProcessAttributes,
			lpThreadAttributes,
			bInheritHandles,
			dwCreationFlags,
			lpEnvirronment,
			lpCurrentDirectory,
			lpStartupInfo,
			lpProcessInformation
		);

	CreateProcessHook.ReHook();
*/

	//弹出被创建进程的进程名
	if (MessageBoxW(NULL, wcsstr(L"是否创建进程",lpApplicationName), lpCommandLine, MB_YESNOCANCEL) == IDYES){
		//创建进程
		bRet = CreateProcessW(lpApplicationName,
				lpCommandLine,
				lpProcessAttributes,
				lpThreadAttributes,
				bInheritHandles,
				dwCreationFlags,
				lpEnvirronment,
				lpCurrentDirectory,
				lpStartupInfo,
				lpProcessInformation
			);
		CreateProcessHook.ReHook();
	}else{
		MessageBox(NULL, "你启动的进程被拦截", "提示", MB_OK);
	}
	

	return bRet;
}

BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved){
	switch(ul_reason_for_call) {
		case DLL_PROCESS_ATTACH:
			{
				//Hook CreateProcessW函数
				CreateProcessHook.Hook("kernel32.dll", "CreateProcessW", (PROC)MYCreateProcessW);
				break;
			}
		case DLL_PROCESS_DETACH:
			{
				//取消HOOK
				CreateProcessHook.UnHook();
				break;
			}
	}
	return TRUE;
}