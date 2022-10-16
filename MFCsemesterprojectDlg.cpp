
// MFCsemesterprojectDlg.cpp : implementation file
// programmer: Christopher Rowley

#include "pch.h"
#include "framework.h"
#include "MFCsemesterproject.h"
#include "MFCsemesterprojectDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "decimalConvertInit.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCsemesterprojectDlg dialog



CMFCsemesterprojectDlg::CMFCsemesterprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSEMESTERPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCsemesterprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCsemesterprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCsemesterprojectDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &CMFCsemesterprojectDlg::OnBnClickedOk)
	ON_STN_CLICKED(IDC_STATIC5, &CMFCsemesterprojectDlg::OnStnClickedStatic5)
	//ON_STN_CLICKED(IDC_STATIC6, &CMFCsemesterprojectDlg::OnStnClickedStatic6)
	//ON_STN_CLICKED(IDC_STATIC7, &CMFCsemesterprojectDlg::OnStnClickedStatic7)
END_MESSAGE_MAP()


// CMFCsemesterprojectDlg message handlers
//
BOOL CMFCsemesterprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	pCombo->InsertString(0, _T("Decimal to Roman Numerals"));
	pCombo->InsertString(1, _T("Decimal to Binary"));
	pCombo->InsertString(2, _T("Decimal to Octal"));
	pCombo->InsertString(3, _T("Binary to Decimal"));
	pCombo->SetCurSel(0); // or -1 for unselected

		// Picture control setup
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC5));
	pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture->SetBitmap(hb);




	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCsemesterprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCsemesterprojectDlg::OnPaint()
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
HCURSOR CMFCsemesterprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCsemesterprojectDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here

}


void CMFCsemesterprojectDlg::OnBnClickedOk()
{

	CString mInput1;
	CEdit* pInput1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	pInput1->GetWindowText(mInput1);
	int userNums = _ttoi(mInput1);

	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int n = pCombo->GetCurSel();

	CEdit* pEdit4 = (CEdit*)GetDlgItem(IDC_EDIT2);
	ostringstream sout;
	
	// TODO: Add your control notification handler code here

	if (n == 0) {
		string c = decimalToRomanNum(userNums);
		sout << c;

		pEdit4->SetWindowText(CString(sout.str().c_str()));
		CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC5));
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);

	}
	else if (n == 1) {

		CString b;
		int c = convertToBinary(userNums);
		sout << c;
		pEdit4->SetWindowText(CString(sout.str().c_str()));
	}
	else if (n == 2) {
		int c = convertToOctal(userNums);
		sout << c;
		pEdit4->SetWindowText(CString(sout.str().c_str()));
	}
	else if (n == 3) {
		int c = binaryToDecimal(userNums);
		sout << c;
		pEdit4->SetWindowText(CString(sout.str().c_str()));
	}
}


void CMFCsemesterprojectDlg::OnStnClickedStatic5()
{
	// TODO: Add your control notification handler code here
}




void CMFCsemesterprojectDlg::OnStnClickedStatic7()
{
	// TODO: Add your control notification handler code here
}
