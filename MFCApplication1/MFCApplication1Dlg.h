
// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <opencv2\opencv.hpp>
#include "CvvImage.h"
#include "VideoInfo.h"
#include"CV_picture.h"
#include "afxwin.h"
// CMFCApplication1Dlg �Ի���
class CMFCApplication1Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonVideo();

	
	CWinThread* hThread_show;
	// ����������һ��CStatic��Ķ���
	
	
	CV_picture m_showing;
	afx_msg void OnBnClickedButtonStop();
};
UINT playThread(LPVOID pParam);