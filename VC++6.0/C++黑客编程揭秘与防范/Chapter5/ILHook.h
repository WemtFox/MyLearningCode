#ifdef	__ILHOOK_H__F47BF581_8D85_49ef_923D_895DCC9E4471_
#define	__ILHOOK_H__F47BF581_8D85_49ef_923D_895DCC9E4471_	

#include "Windows.h"

class CILHook
{
public:
	CILHook();//构造
	~CILHook();//析构

	//HOOK函数
	BOOL Hook(LPSTR pszModuleName, LPSTR pszFuncName, PROC pfnHookFunc);
	VOID UnHook();
	BOOL ReHook();
protected:
private:
	PROC m_pfnOrig;//函数地址
	BYTE m_bOldByte[5];//函数入口
	BYTE m_bNewByte[5];//Inline代码
}; 
#endif