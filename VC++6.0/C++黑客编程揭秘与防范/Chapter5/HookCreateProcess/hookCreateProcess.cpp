#include "ILHook.h"

CILHook CreateProcessHook;

//ʵ�ֵ�Hook����
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
	//�������������̵Ľ�����
	MessageBoxW(NULL, wcsstr(L"�Ƿ񴴽�����",lpApplicationName), lpCommandLine, MB_YESNOCANCEL);

	//��������
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

	//�������������̵Ľ�����
	if (MessageBoxW(NULL, wcsstr(L"�Ƿ񴴽�����",lpApplicationName), lpCommandLine, MB_YESNOCANCEL) == IDYES){
		//��������
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
		MessageBox(NULL, "�������Ľ��̱�����", "��ʾ", MB_OK);
	}
	

	return bRet;
}

BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved){
	switch(ul_reason_for_call) {
		case DLL_PROCESS_ATTACH:
			{
				//Hook CreateProcessW����
				CreateProcessHook.Hook("kernel32.dll", "CreateProcessW", (PROC)MYCreateProcessW);
				break;
			}
		case DLL_PROCESS_DETACH:
			{
				//ȡ��HOOK
				CreateProcessHook.UnHook();
				break;
			}
	}
	return TRUE;
}