// Number24Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Number24.h"
#include "Number24Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumber24Dlg dialog

CNumber24Dlg::CNumber24Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNumber24Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNumber24Dlg)
	m_Number1 = 1;
	m_Number2 = 1;
	m_Number3 = 1;
	m_Number4 = 1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hCursor=AfxGetApp()->LoadCursor(IDC_CURSOR1);
}

void CNumber24Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNumber24Dlg)
	DDX_Text(pDX, IDC_NUMBER1, m_Number1);
	DDV_MinMaxInt(pDX, m_Number1, 1, 10);
	DDX_Text(pDX, IDC_NUMBER2, m_Number2);
	DDV_MinMaxInt(pDX, m_Number2, 1, 10);
	DDX_Text(pDX, IDC_NUMBER3, m_Number3);
	DDV_MinMaxInt(pDX, m_Number3, 1, 10);
	DDX_Text(pDX, IDC_NUMBER4, m_Number4);
	DDV_MinMaxInt(pDX, m_Number4, 1, 10);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNumber24Dlg, CDialog)
	//{{AFX_MSG_MAP(CNumber24Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CACULATE, OnCaculate)
	ON_EN_CHANGE(IDC_NUMBER1, OnChangeNumber)
	ON_EN_CHANGE(IDC_NUMBER2, OnChangeNumber)
	ON_EN_CHANGE(IDC_NUMBER3, OnChangeNumber)
	ON_EN_CHANGE(IDC_NUMBER4, OnChangeNumber)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumber24Dlg message handlers

BOOL CNumber24Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	SetCursor(m_hCursor);
	// TODO: Add extra initialization here
	ResultString.Empty();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNumber24Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNumber24Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNumber24Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNumber24Dlg::OnCaculate() 
{
    int a[4];
	UpdateData(TRUE);
	a[0]=m_Number1;
	a[1]=m_Number2;
	a[2]=m_Number3;
	a[3]=m_Number4;
	ResultString.Empty();
	Process(a);
	if(!ResultString.IsEmpty())
	{
		ResultString.Delete(ResultString.GetLength()-1);
		ResultString+="=24";
		this->SetDlgItemText(IDC_RESULT,ResultString);
	    ResultString.Empty();
	}
	else
		this->SetDlgItemText(IDC_RESULT,"нч╫Б");
	//this->SetDlgItemText(IDC_RESULT,"zhangyi talent");
}

void CNumber24Dlg::Process(int a[])
{
  int Counter;
  int Used[4];
  for (Counter=0;Counter<4;Counter++)
    Used[Counter]=0;
  Compute(a,Used,1,24.0); 
}

int CNumber24Dlg::Compute(int a[], int Used[], int Level, double Answer)
{
  int Counter;
  CString TempString;
  if (Level==4)
    {
      for(Counter=0;Counter<4;Counter++)
	  {
	      if ((!Used[Counter])&&(a[Counter]==Answer))
		  {
	          TempString.Format("((%d",a[Counter]);
		      ResultString+=TempString;
	          return TRUE;
		  }
	  }
      return FALSE;
    }
  for(Counter=0;Counter<4;Counter++)
    {
      if(!Used[Counter])
	  {
	      Used[Counter]=TRUE;
	      if (Compute(a,Used,Level+1,Answer-a[Counter]))
		  {
	          TempString.Format("+%d)",a[Counter]);
		      ResultString+=TempString;
			  return TRUE;
		  }
	      if (Compute(a,Used,Level+1,Answer+a[Counter]))
		  {
	          TempString.Format("-%d)",a[Counter]);
		      ResultString+=TempString;
			  return TRUE;
		  }
	      if (Compute(a,Used,Level+1,Answer*a[Counter]))
		  {
	          TempString.Format("/%d)",a[Counter]);
		      ResultString+=TempString;
			  return TRUE;
		  }
	      if (Compute(a,Used,Level+1,Answer/a[Counter]*1.0))
		  {
	          TempString.Format("*%d)",a[Counter]);
		      ResultString+=TempString;
		      return TRUE;
		  }
	      Used[Counter]=FALSE;
	  }
   }
   return FALSE; 
}

void CNumber24Dlg::OnChangeNumber() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
}


void CNumber24Dlg::OnHelpAbout() 
{
    CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}
