
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "VideoInfo.h"
#include <opencv2\opencv.hpp>
#include "CvvImage.h"
using namespace std;
using namespace cv;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTURE, m_showing);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Video, &CMFCApplication1Dlg::OnBnClickedButtonVideo)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CMFCApplication1Dlg::OnBnClickedButtonStop)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	m_showing.OnInit();
	//m_pVideoInfo = new CVideoInfo;

//	m_pPicCtlHdc = GetDlgItem(IDC_PICTURE)->GetDC()->GetSafeHdc();   //返回控件句柄
	//GetDlgItem(IDC_PICTURE)->GetClientRect(m_PicCtlRect);            //关联控件位置
//	CVideoInfo* m_pVideoInfo;
	//HDC m_pPicCtlHdc;
	//CRect m_PicCtlRect;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication1Dlg::OnBnClickedButtonVideo()
{
	// TODO:  在此添加控件通知处理程序代码
	//m_pVideoInfo->m_pCapture = cvCreateFileCapture("C:/Users/Administrator/Desktop/1.flv");//创建一个Capture（摄像头）
	//while (1)
	//{ 
	//	m_pVideoInfo->m_pFrameImage = cvQueryFrame(m_pVideoInfo->m_pCapture);//得到视频流中的下一帧

	//	CvvImage cvvImage;
	//	cvvImage.CopyOf(m_pVideoInfo->m_pFrameImage);
	//	cvvImage.DrawToHDC(m_pPicCtlHdc, m_PicCtlRect);
	//}
	
	//CVideoInfo* m_pVideoInfo;
	
	hThread_show = AfxBeginThread(playThread, &m_showing);


}
UINT playThread(LPVOID pParam){  //播放线程，固定格式

	CV_picture* m_showing = (CV_picture*)pParam;
	VideoCapture capture(0);//创建一个Capture（摄像头）
	while (1)
	{
		Mat frame;
		capture >> frame;
		if (frame.empty())
		{
			break;
		}
		m_showing->ShowImage(frame);
	}

	return 0;

}

void CMFCApplication1Dlg::OnBnClickedButtonStop()
{
	// TODO:  在此添加控件通知处理程序代码
	static int sum = 1;
	if (sum)
	{
		hThread_show->SuspendThread();
		sum = 0;
	}
	else{
		hThread_show->ResumeThread();
		sum = 1;
	}
	
}
