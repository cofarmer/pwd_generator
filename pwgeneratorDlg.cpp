
// pwgeneratorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "pwgenerator.h"
#include "pwgeneratorDlg.h"

#pragma warning(disable: 4995)
#pragma warning(disable: 4996)
#include "adkprecomp.h"
#include "adkfile.h"
#include "adkmd5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int g_client = 0;

//
// 预生成事件中增加的脚本处理
// echo g_client = 1; > magic.dat 生成客户端使用的工具
// echo g_client = 0; > magic.dat 生成公司管理者使用的工具
//


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CpwgeneratorDlg 对话框




CpwgeneratorDlg::CpwgeneratorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CpwgeneratorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CpwgeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CpwgeneratorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON2, &CpwgeneratorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CpwgeneratorDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CpwgeneratorDlg 消息处理程序

BOOL CpwgeneratorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

#include "magic.dat"

	if (g_client == 1)
	{
		int move_size = 50;
		this->SetDlgItemText(IDC_BUTTON2, L"显示密码");
		this->SetDlgItemText(IDC_BUTTON1, L"复制密码");
		this->SetDlgItemText(IDC_STATIC1, L"输入产品密钥：");

		((CStatic *)this->GetDlgItem(IDC_STATIC))->ShowWindow(FALSE);
		((CEdit *)this->GetDlgItem(IDC_EDIT3))->ShowWindow(FALSE);

		RECT re = {0};
		RECT re2 = {0};
		RECT re3 = {0};
		RECT re4 = {0};
		RECT re5 = {0};
		RECT re6 = {0};
		((CStatic *)this->GetDlgItem(IDC_STATIC1))->GetWindowRect(&re);
		((CStatic *)this->GetDlgItem(IDC_STATIC2))->GetWindowRect(&re2);
		((CEdit *)this->GetDlgItem(IDC_EDIT2))->GetWindowRect(&re3);
		((CEdit *)this->GetDlgItem(IDC_EDIT1))->GetWindowRect(&re4);
		((CButton *)this->GetDlgItem(IDC_BUTTON2))->GetWindowRect(&re5);
		((CButton *)this->GetDlgItem(IDC_BUTTON1))->GetWindowRect(&re6);
		re.top -= move_size;
		re.bottom -= move_size;
		re2.top -= move_size;
		re2.bottom -= move_size;
		re3.top -= move_size;
		re3.bottom -= move_size;
		re4.top -= move_size;
		re4.bottom -= move_size;
		re5.top -= move_size;
		re5.bottom -= move_size;
		re6.top -= move_size;
		re6.bottom -= move_size;
		((CStatic *)this->GetDlgItem(IDC_STATIC1))->MoveWindow(&re);
		((CStatic *)this->GetDlgItem(IDC_STATIC2))->MoveWindow(&re2);
		((CEdit *)this->GetDlgItem(IDC_EDIT2))->MoveWindow(&re3);
		((CEdit *)this->GetDlgItem(IDC_EDIT1))->MoveWindow(&re4);
		((CButton *)this->GetDlgItem(IDC_BUTTON2))->MoveWindow(&re5);
		((CButton *)this->GetDlgItem(IDC_BUTTON1))->MoveWindow(&re6);
	}

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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CpwgeneratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CpwgeneratorDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CpwgeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CpwgeneratorDlg::OnBnClickedButton2()
{
	wchar_t serial_product[1024] = {0};
	wchar_t password[1024] = {0};
	MD5_CTX t_md5 = {0};
	unsigned char digest[16] = {0};

	this->GetDlgItemText(IDC_EDIT2, serial_product, sizeof(serial_product)/sizeof(serial_product[0]));

	if (!serial_product[0])
	{
		if (g_client == 0)
		{
			this->MessageBox(L"请输入产品编号", L"消息", MB_OK|MB_ICONINFORMATION);
		}
		else
		{
			this->MessageBox(L"请输入产品密钥", L"消息", MB_OK|MB_ICONINFORMATION);
		}
		this->SetDlgItemText(IDC_EDIT1, L"");
		return ;
	}

	AdkMD5Init(&t_md5);
	AdkMD5Update(&t_md5, (BYTE *)serial_product, wcslen(serial_product)*sizeof(wchar_t));
	AdkMD5Final(&t_md5, digest);

	int val = 0;
	for (int idx=0; idx<sizeof(digest); ++idx)
	{
		if (digest[idx] < 33)
		{
			password[val] = 33 + digest[idx];
		}
		else if (digest[idx] > 126)
		{
			digest[idx] = digest[idx] - 126;
			--idx;
			continue;
		}
		else
		{
			password[val] = digest[idx];
		}

		++val;
	}

	this->SetDlgItemText(IDC_EDIT1, password);

	return ;
}

void CpwgeneratorDlg::OnBnClickedButton1()
{
	wchar_t serial_client[1024] = {0};
	wchar_t serial_product[1024] = {0};
	wchar_t password[1024] = {0};
	wchar_t file_name[MAX_PATH] = {0};
	wchar_t *file_buffer = NULL;
	unsigned long file_size = 0;
	unsigned short file_bom = 0xfeff;


	this->GetDlgItemText(IDC_EDIT3, serial_client,  sizeof(serial_client)/sizeof(serial_client[0]));
	this->GetDlgItemText(IDC_EDIT2, serial_product, sizeof(serial_product)/sizeof(serial_product[0]));
	this->GetDlgItemText(IDC_EDIT1, password, sizeof(password)/sizeof(password[0]));

	if (g_client == 1)
	{
		if (!password[0])
		{
			this->MessageBox(L"密码为空", L"消息", MB_OK|MB_ICONINFORMATION);
			return ;
		}

		HANDLE hclip;
		if(OpenClipboard())
		{
			EmptyClipboard();
			hclip = GlobalAlloc(GMEM_MOVEABLE, wcslen(password + 1)*sizeof(wchar_t));
			if (hclip)
			{
				char *buf = (char *)GlobalLock(hclip);
				if (buf)
				{
					char *passwa = AdkWStrToStr(password);
					if (passwa)
					{
						memcpy(buf, passwa, strlen(passwa)*sizeof(char));
						buf[strlen(passwa)*sizeof(char)] = '\0';
						AdkFree(passwa);
					}
				}
				GlobalUnlock(hclip);
				SetClipboardData(CF_TEXT, hclip);

				this->MessageBox(L"成功复制到粘贴板!", L"消息", MB_OK|MB_ICONINFORMATION);
			}
		}
		CloseClipboard();
		
		return ;
	}

	if (!serial_client[0])
	{
		this->MessageBox(L"请输入客户编号", L"消息", MB_OK|MB_ICONINFORMATION);
		return ;
	}
	if (!serial_product[0])
	{
		this->MessageBox(L"请输入产品编号", L"消息", MB_OK|MB_ICONINFORMATION);
		return ;
	}
	if (!password[0])
	{
		this->MessageBox(L"密码为空", L"消息", MB_OK|MB_ICONINFORMATION);
		return ;
	}

	do 
	{
#define FILE_FORMATION L"客户编号：%ws\r\n产品编号：%ws\r\n密码展示：%ws\r\n"

		file_size = 1024 * 500;
		file_buffer = (wchar_t *)AdkMalloc(file_size);
		if (file_buffer == NULL)
		{
			break ;
		}

		swprintf_s(file_buffer, file_size >> 1, FILE_FORMATION, serial_client, serial_product, password);
		
		GetModuleFileNameW(NULL, file_name, sizeof(file_name)/sizeof(file_name[0]));
		file_name[wcslen(file_name) - wcslen(wcsrchr(file_name, L'\\')) + 1] = L'\0';
		wcscat(file_name, serial_client);
		wcscat(file_name, L".txt");

		if (!AdkFileWriterW(file_name, &file_bom, sizeof(file_bom)))
		{
			break;
		}
		if (!AdkFileAppendWriterW(file_name, file_buffer, wcslen(file_buffer)*sizeof(wchar_t)))
		{
			break;
		}

		this->MessageBox(L"操作成功!", L"消息", MB_OK|MB_ICONINFORMATION);

	} while (0);
	
	if (file_buffer)
	{
		AdkFree(file_buffer);
	}

	return ;
}
