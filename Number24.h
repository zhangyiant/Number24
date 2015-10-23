// Number24.h : main header file for the NUMBER24 application
//

#if !defined(AFX_NUMBER24_H__5C54C81D_1346_4D25_9DB6_BB52769CBFB5__INCLUDED_)
#define AFX_NUMBER24_H__5C54C81D_1346_4D25_9DB6_BB52769CBFB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNumber24App:
// See Number24.cpp for the implementation of this class
//

class CNumber24App : public CWinApp
{
public:
	CNumber24App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumber24App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNumber24App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMBER24_H__5C54C81D_1346_4D25_9DB6_BB52769CBFB5__INCLUDED_)
