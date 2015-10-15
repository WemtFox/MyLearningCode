// AutoRun.h : main header file for the AUTORUN application
//

#if !defined(AFX_AUTORUN_H__FE8E69FF_D70C_4F15_9AA7_982EDA9E5AE4__INCLUDED_)
#define AFX_AUTORUN_H__FE8E69FF_D70C_4F15_9AA7_982EDA9E5AE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAutoRunApp:
// See AutoRun.cpp for the implementation of this class
//

class CAutoRunApp : public CWinApp
{
public:
	CAutoRunApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoRunApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAutoRunApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTORUN_H__FE8E69FF_D70C_4F15_9AA7_982EDA9E5AE4__INCLUDED_)
