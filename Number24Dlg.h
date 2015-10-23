// Number24Dlg.h : header file
//

#if !defined(AFX_NUMBER24DLG_H__5BCBCAF7_8315_4E98_9145_DC78124BB7AF__INCLUDED_)
#define AFX_NUMBER24DLG_H__5BCBCAF7_8315_4E98_9145_DC78124BB7AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNumber24Dlg dialog

class CNumber24Dlg : public CDialog
{
// Construction
public:
	CNumber24Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNumber24Dlg)
	enum { IDD = IDD_NUMBER24_DIALOG };
	int		m_Number1;
	int		m_Number2;
	int		m_Number3;
	int		m_Number4;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumber24Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HCURSOR m_hCursor;
	CString ResultString;
	int Compute(int a[],int Used[],int Level,double Answer);
	void Process(int a[4]);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNumber24Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCaculate();
	afx_msg void OnChangeNumber();
	afx_msg void OnHelpAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMBER24DLG_H__5BCBCAF7_8315_4E98_9145_DC78124BB7AF__INCLUDED_)
