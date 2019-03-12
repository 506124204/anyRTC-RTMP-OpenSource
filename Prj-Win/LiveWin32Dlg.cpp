/*
*  Copyright (c) 2016 The AnyRTC project authors. All Rights Reserved.
*
*  Please visit https://www.anyrtc.io for detail.
*
* The GNU General Public License is a free, copyleft license for
* software and other kinds of works.
*
* The licenses for most software and other practical works are designed
* to take away your freedom to share and change the works.  By contrast,
* the GNU General Public License is intended to guarantee your freedom to
* share and change all versions of a program--to make sure it remains free
* software for all its users.  We, the Free Software Foundation, use the
* GNU General Public License for most of our software; it applies also to
* any other work released this way by its authors.  You can apply it to
* your programs, too.
* See the GNU LICENSE file for more info.
*/
#include "stdafx.h"
#include <crtdbg.h>
#include "LiveWin32.h"
#include "LiveWin32Dlg.h"
#include "afxdialogex.h"
#include "DlgRtmpPush.h"
#include "DlgRtmpPull.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CLiveWin32Dlg �Ի���



CLiveWin32Dlg::CLiveWin32Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLiveWin32Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLiveWin32Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CLiveWin32Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_PUSH, &CLiveWin32Dlg::OnBnClickedBtnPush)
	ON_BN_CLICKED(IDC_BTN_PULL, &CLiveWin32Dlg::OnBnClickedBtnPull)
	ON_BN_CLICKED(IDC_BTN_RTCP, &CLiveWin32Dlg::OnBnClickedBtnRtcp)
END_MESSAGE_MAP()


// CLiveWin32Dlg ��Ϣ�������

BOOL CLiveWin32Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//* ShowWindow(SW_MINIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	
	// Specify CEF global settings here.
	CefSettings settings;
	settings.log_severity = cef_log_severity_t::LOGSEVERITY_VERBOSE;
	settings.multi_threaded_message_loop = true;
#if !defined(CEF_USE_SANDBOX)
	settings.no_sandbox = true;
#endif

	// SimpleApp implements application-level callbacks for the browser process.
	// It will create the first browser instance in OnContextInitialized() after
	// CEF has initialized.
	//CefMainArgs main_args(theApp.m_hInstance);
	theApp.app.get()->hWnd = GetSafeHwnd();
	// Initialize CEF.
	CefInitialize(theApp.main_args, settings, theApp.app.get(), NULL);


	// Specify CEF browser settings here.
	CefBrowserSettings browser_settings;

	std::string url;

	// Check if a "--url=" value was provided via the command-line. If so, use
	// that instead of the default URL.
	//url = command_line->GetSwitchValue("url");
	if (url.empty())
		url = "http://www.qq.com";

	CefWindowInfo window_info;

#if defined(OS_WIN)
	// On Windows we need to specify certain flags that will be passed to
	// CreateWindowEx().
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.bottom = 500;
	rc.right = 500;
	window_info.SetAsChild(m_hWnd, rc);
	//window_info.SetAsPopup(NULL, "cefsimple");
#endif

	// Create the first browser window.
	CefBrowserHost::CreateBrowser(window_info, theApp.handler, url, browser_settings,
		NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

BOOL CLiveWin32Dlg::DestroyWindow()
{
	
	//_CrtDumpMemoryLeaks();
	return CDialog::DestroyWindow();
}

void CLiveWin32Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLiveWin32Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		/*
		CPaintDC dc(this);
		CRect rect;
		GetClientRect(&rect);
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);

		CBitmap bmpBackground;
		bmpBackground.LoadBitmap(IDB_BG);

		BITMAP bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap *pbmpOld = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0
			, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
		*/
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLiveWin32Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLiveWin32Dlg::OnBnClickedBtnPush()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DlgRtmpPush dlg;
	dlg.DoModal();
}


void CLiveWin32Dlg::OnBnClickedBtnPull()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DlgRtmpPull dlg;
	dlg.DoModal();
}


void CLiveWin32Dlg::OnBnClickedBtnRtcp()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CLiveWin32Dlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	if (AfxMessageBox(_T("�˳��룿"), MB_YESNO) == IDYES) {

		CDialogEx::OnCancel();
	}
}


BOOL CLiveWin32Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CDialogEx::PreTranslateMessage(pMsg);
}


LRESULT CLiveWin32Dlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CDialogEx::WindowProc(message, wParam, lParam);
}
