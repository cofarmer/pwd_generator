
// pwgenerator.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CpwgeneratorApp:
// �йش����ʵ�֣������ pwgenerator.cpp
//

class CpwgeneratorApp : public CWinAppEx
{
public:
	CpwgeneratorApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CpwgeneratorApp theApp;