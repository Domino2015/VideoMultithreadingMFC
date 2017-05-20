
// MFCApplication1Dlg.h : 头文件
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
// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonVideo();

	
	CWinThread* hThread_show;
	// 关联并建立一个CStatic类的对象
	
	
	CV_picture m_showing;
	afx_msg void OnBnClickedButtonStop();
};
UINT playThread(LPVOID pParam);