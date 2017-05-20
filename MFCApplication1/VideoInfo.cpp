#include "stdafx.h"
#include "VideoInfo.h"

CVideoInfo::CVideoInfo(void)  //缺省构造函数
{
	m_pCapture = NULL;
	m_pFrameImage = NULL;
}

CVideoInfo::~CVideoInfo(void)//缺省析构函数
{
}