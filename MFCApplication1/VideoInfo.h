#pragma once
#include "opencv2/opencv.hpp"

class CVideoInfo
{
public:

	CvCapture* m_pCapture;     //用于存储摄像头输入的视频流
	IplImage* m_pFrameImage;   //存储图片

	int m_FrameWidth;          //图片宽度
	int m_FrameHeight;         //图片高度
	HDC m_pPicCtlHdc;
	CRect m_PicCtlRect;

public:
	CVideoInfo(void);          //缺省构造函数
public:
	~CVideoInfo(void);         //缺省析构函数
};