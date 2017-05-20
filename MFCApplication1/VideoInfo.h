#pragma once
#include "opencv2/opencv.hpp"

class CVideoInfo
{
public:

	CvCapture* m_pCapture;     //���ڴ洢����ͷ�������Ƶ��
	IplImage* m_pFrameImage;   //�洢ͼƬ

	int m_FrameWidth;          //ͼƬ���
	int m_FrameHeight;         //ͼƬ�߶�
	HDC m_pPicCtlHdc;
	CRect m_PicCtlRect;

public:
	CVideoInfo(void);          //ȱʡ���캯��
public:
	~CVideoInfo(void);         //ȱʡ��������
};