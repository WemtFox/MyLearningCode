#ifdef	__ILHOOK_H__F47BF581_8D85_49ef_923D_895DCC9E4471_
#define	__ILHOOK_H__F47BF581_8D85_49ef_923D_895DCC9E4471_	

#include "Windows.h"

class CILHook
{
public:
	CILHook();//����
	~CILHook();//����

	//HOOK����
	BOOL Hook(LPSTR pszModuleName, LPSTR pszFuncName, PROC pfnHookFunc);
	VOID UnHook();
	BOOL ReHook();
protected:
private:
	PROC m_pfnOrig;//������ַ
	BYTE m_bOldByte[5];//�������
	BYTE m_bNewByte[5];//Inline����
}; 
#endif