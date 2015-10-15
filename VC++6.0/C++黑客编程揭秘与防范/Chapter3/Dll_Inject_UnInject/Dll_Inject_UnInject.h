// Dll_Inject_UnInject.h : main header file for the DLL_INJECT_UNINJECT application
//

#if !defined(AFX_DLL_INJECT_UNINJECT_H__D44C60C4_3B85_49B6_A6CD_C5D8D555E7FD__INCLUDED_)
#define AFX_DLL_INJECT_UNINJECT_H__D44C60C4_3B85_49B6_A6CD_C5D8D555E7FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDll_Inject_UnInjectApp:
// See Dll_Inject_UnInject.cpp for the implementation of this class
//

class CDll_Inject_UnInjectApp : public CWinApp
{
public:
	CDll_Inject_UnInjectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDll_Inject_UnInjectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDll_Inject_UnInjectApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLL_INJECT_UNINJECT_H__D44C60C4_3B85_49B6_A6CD_C5D8D555E7FD__INCLUDED_)
