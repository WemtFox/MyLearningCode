
CILHook::CILHook(){
	//�ӳ�Ա������ʼ��
	m_pfnOrig = NULL;
	ZeroMemory(m_bOldByte, 5);
	ZeroMemory(m_bNewByte, 5);
}

CILHook::~CILHook(){
	//ȡ��HOOK
	UnHook();
}

/*
�������ƣ�Hook
��������:��ָ��ģ��ĺ������йҹ�
����˵����
	pszModuleName:ģ������
	pszModuleName����������
	pfnHookFunc�����Ӻ���
*/
BOOL CILHook::Hook(LPSTR pszModuleName, LPSTR pszFuncName, PROC pfnHookFunc){
	BOOL bRet = FALSE;

	//��ȡָ��ģ���к����ĵ�ַ
	m_pfnOrig = (PROC)GetProcAddress(GetModuleHandle(pszModuleName), pszFuncName);

	if (m_pfnOrig != NULL)
	{
		//����õ�ַ��5���ֽڵ�����
		DWORD dwNum = 0;
		ReadProcessMemory(GetCurrentProcess(), m_pfnOrig, m_bOldByte, 5, &dwNum);

		//����JMPָ��
		m_bNewByte[0] = '\xe9';			//jmp Opcode
		//pfnHookFunc��HOOK���Ŀ���ַ
		//m_pfnOrig��ԭ����ַ
		//5��ָ���
		*(DWORD *)(m_bNewByte + 1) = (DWORD)pfnHookFunc - (DWORD)m_pfnOrig - 5;
		//������õĵ�ַ
		WriteProcessMemory(GetCurrentProcess(), m_pfnOrig, m_bNewByte, 5, &dwNum);

		bRet = TRUE;
	}
}

/*
�������ƣ�UnHook
��������:ȡ�������ҹ�
*/
VOID CILHook::UnHook(){
	if (m_pfnOrig != 0)
	{
		DWORD dwNum = 0;
		WriteProcessMemory(GetCurrentProcess(), m_pfnOrig, m_bOldByte, 5, &dwNum);
	}
}

/*
�������ƣ�ReHook
��������:���¶Ժ������йҹ�
*/
BOOL CILHook::ReHook(){
	BOOL bRet = FALSE;
	
	if (m_pfnOrig != 0)
	{
		DWORD dwNum = 0;
		WriteProcessMemory(GetCurrentProcess(), m_pfnOrig, m_bOldByte, 5, &dwNum);
		bRet = TRUE;
	}

	return bRet;
}



