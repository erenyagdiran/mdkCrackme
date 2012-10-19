
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication1Dlg::OnEnChangeEdit1)
ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	// TODO: Add extra initialization here

	this->GetDlgItem(IDC_EDIT1)->SetWindowTextW(_T("Username"));
	this->GetDlgItem(IDC_EDIT2)->SetWindowTextW(_T("Code"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



unsigned int func1(char username[])
{
     unsigned long usernamesize;
     unsigned long local1;
     unsigned long i;
     unsigned long edx;
     unsigned long eax;
     unsigned long cl;
     unsigned char ecx;
     unsigned long local4;
     unsigned long local3;
     
     int firsttime = 0;
     local1 = 0;
     local4 = 0;
     local3 = 0;
     usernamesize = strlen(username);
     eax = usernamesize;
     
    
     for(i=0;i<usernamesize;i++)
     {
        if(firsttime == 1)
        {
                     ecx = local1;
                     ecx += 1;
                     local1 = ecx;
        }
        edx = local1;
                                       
        ecx = username[i];
        ecx = ecx & 0x8000001F;
        cl = ecx & 0xFF;
        
        edx = 1;
        edx = edx << cl;
        ecx = username[i];
        edx = edx * ecx;
        edx += local4;
        local4 = edx;
        firsttime =1;
     }
     
     return local4;
}

unsigned int pf1(unsigned long int arg1 , unsigned long int arg2)
{
         unsigned long local1;
         unsigned long ecx;
         unsigned long edx;
         unsigned long local2;
         unsigned long eax;

         local1 = arg1 & arg2;
         ecx = ~local1;
         local1 = ecx;
         edx = arg2;
         edx = edx & local1;
         local2 = edx;
         eax = local2;
         eax = ~eax;
         local2 = eax;
         ecx = arg1;
         ecx = ecx & local1;
         local1 = ecx;
         edx = local1;
         edx = ~edx;
         local1 = edx;
         eax = local1;
         eax = eax & local2;
         eax = ~eax;
         
         return eax;
         
         
} 

unsigned long pf2(unsigned long arg1 , unsigned long arg2)
{
         unsigned long eax;
         unsigned long local1;
         unsigned long local2;
         unsigned long ecx;
         unsigned long edx;
         
         eax = arg1;
         eax = eax & arg2;
         local1 = eax;
         ecx = local1;
         ecx = ~ecx;
         local1 = ecx;
         edx = arg2;
         edx = edx & local1;
         local2 = edx;
         eax = local2;
         eax = ~eax;
         local2 = eax;
         ecx = arg1;
         ecx = ecx & local1;
         local1 = ecx;
         edx = local1;
         edx = ~edx;
         local1 = edx;
         eax = local1;
         eax = eax & local2;
         eax = ~eax;
         
         return eax;
         
         
         
}

unsigned long pf3(unsigned long arg1 , unsigned long arg2)
{
         unsigned long eax;
         unsigned long local1;
         unsigned long local2;
         unsigned long ecx;
         unsigned long edx;
         
         eax = arg1;
         eax = eax & arg2;
         local1 = eax;
         ecx = local1;
         ecx = ~ecx;
         local1 = ecx;
         edx = arg2;
         edx = edx & local1;
         local2 = edx;
         eax = local2;
         eax = ~eax;
         
         local2 = eax;
         ecx = arg1;
         ecx = ecx & local1;
         local1 = ecx;
         edx = local1;
         edx = ~edx;    
         local1 = edx;
         eax = local1;
         eax = eax & local2;
         eax = ~eax;
         return eax;
         
}

unsigned long pf4(unsigned long arg1 , unsigned long arg2)
{
         unsigned long eax;
         unsigned long ecx;
         unsigned long local1;
         unsigned long local2;
         unsigned long edx;
         
         eax = arg1;
         eax = eax & arg2;
         local1 = eax;
         ecx = local1;
         ecx = ~ecx;
         
         local1 = ecx;
         edx = arg2;
         edx = edx & local1;
         local2 = edx;
         eax = local2;
         eax = ~eax;
         
         local2 = eax;
         ecx = arg1;
         ecx = ecx & local1;
         local1 = ecx;
         edx = local1;
         edx = ~edx;
         
         local1 = edx;
         eax = local1;
         eax = eax & local2;
         eax = ~eax;
         
         return eax;
         
}

char * func2(char password[] , unsigned int code)
{
        // int local4[4] ={0x0,0x25,0x30,0x38};
         int local3[4] ={0x58,0x2D,0x25,30};
         int local2[4] ={0x38,0x58,0};
         int local1;
         local1 = 0;
         int firstloop = 0;
         unsigned long esi;
         unsigned long local6;
         unsigned long eax;
         unsigned long esi2;
         unsigned long local5;
         unsigned long local4;
         unsigned long ecx;
         char  temp[100];
         int i;
         
         for(i=0;i<strlen(password);i++)
         {
                                        
         }
         
           esi = pf1(0x2EFB3718,code);
           esi = esi + pf2(0x32f54b88,code);
           local6 = esi;
           local1 = 0;
           eax = strlen(password) + 1;
           eax = eax & 0xF;
           
           esi2 = pf3(0x25b27aef,code);
           esi2 = esi2 + pf4(0x37075c49,code);
           local5 = esi2;
           local4 = 0x58;
           eax = local5;
           ecx = local6;
          // printf("%x-%x",esi,esi2);
           sprintf(temp,"%X-%X",esi,esi2);
           return temp;
           
}


void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	
	CString input;
	unsigned int code;
	const char *  foo;
	char output[100];
	this->GetDlgItemTextW(IDC_EDIT1,input);

	char *my_char = new char[];
	sprintf(my_char,"%ls",input.GetBuffer());


	code = func1(my_char);
	my_char = func2("12341234123412341",code);
	strcpy(output,my_char);
	CString atName(output);

	this->SetDlgItemTextW(IDC_EDIT2,atName);
	
}




