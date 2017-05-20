
// MFCApplication1Dlg.cpp : ʵ���ļ�
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


// CMFCApplication1Dlg �Ի���



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


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_showing.OnInit();
	//m_pVideoInfo = new CVideoInfo;

//	m_pPicCtlHdc = GetDlgItem(IDC_PICTURE)->GetDC()->GetSafeHdc();   //���ؿؼ����
	//GetDlgItem(IDC_PICTURE)->GetClientRect(m_PicCtlRect);            //�����ؼ�λ��
//	CVideoInfo* m_pVideoInfo;
	//HDC m_pPicCtlHdc;
	//CRect m_PicCtlRect;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
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
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication1Dlg::OnBnClickedButtonVideo()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//m_pVideoInfo->m_pCapture = cvCreateFileCapture("C:/Users/Administrator/Desktop/1.flv");//����һ��Capture������ͷ��
	//while (1)
	//{ 
	//	m_pVideoInfo->m_pFrameImage = cvQueryFrame(m_pVideoInfo->m_pCapture);//�õ���Ƶ���е���һ֡

	//	CvvImage cvvImage;
	//	cvvImage.CopyOf(m_pVideoInfo->m_pFrameImage);
	//	cvvImage.DrawToHDC(m_pPicCtlHdc, m_PicCtlRect);
	//}
	
	//CVideoInfo* m_pVideoInfo;
	
	hThread_show = AfxBeginThread(playThread, &m_showing);


}
UINT playThread(LPVOID pParam){  //�����̣߳��̶���ʽ

	CV_picture* m_showing = (CV_picture*)pParam;
	VideoCapture capture(0);//����һ��Capture������ͷ��
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
