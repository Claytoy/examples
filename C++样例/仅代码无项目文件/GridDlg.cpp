
// GridDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Grid.h"
#include "GridDlg.h"
#include "afxdialogex.h"
#include<string.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CGridDlg 对话框



CGridDlg::CGridDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GRID_DIALOG, pParent)
	, m_grid(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGridDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Text(pDX, IDC_EDIT1, m_grid);
}

BEGIN_MESSAGE_MAP(CGridDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CGridDlg::OnTcnSelchangeTab1)
	ON_COMMAND(ID_open, &CGridDlg::Onopen)
	ON_COMMAND(ID_tobao, &CGridDlg::Ontobao)
	ON_COMMAND(ID_TIN, &CGridDlg::OnTin)
	ON_COMMAND(ID_V, &CGridDlg::OnV)
	ON_COMMAND(ID_savejpg, &CGridDlg::Onsavejpg)
	ON_COMMAND(ID_save, &CGridDlg::Onsave)
END_MESSAGE_MAP()


// CGridDlg 消息处理程序

BOOL CGridDlg::OnInitDialog()
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

	//创建菜单 
	CMenu m_menu;
	m_menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_menu);


	//创建工具栏
	CToolBar m_toolbar;
	if (!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE
		| CBRS_ALIGN_TOP
		| CBRS_FLYBY
		| CBRS_GRIPPER
		| CBRS_TOOLTIPS
		| CBRS_SIZE_DYNAMIC
		| CBRS_TOP
		| BTNS_SHOWTEXT
		| TBSTYLE_EX_MIXEDBUTTONS
		| TBSTYLE_LIST, //显示文本按钮
		CRect(1, 1, 0, 0)) || !m_ToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		AfxMessageBox("fail to create toolbar\n");
		return FALSE;
	}
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);   //显示工具栏、状态栏  一定要写

	//创建属性页
	m_tab.InsertItem(1,"表格");
	m_tab.InsertItem(2, "输入");
	m_tab.InsertItem(3, "报告");
	m_tab.InsertItem(4, "画图");

	//建立属性各页
	page1.Create(IDD_DIALOG1, GetDlgItem(IDC_TAB1));
	page2.Create(IDD_DIALOG2, GetDlgItem(IDC_TAB1));
	page3.Create(IDD_DIALOG3, GetDlgItem(IDC_TAB1));
	page4.Create(IDD_DIALOG4, GetDlgItem(IDC_TAB1));

	//获取属性页在m_tab的范围
	CRect rect;
	m_tab.GetClientRect(&rect);
	rect.bottom -= 25;
	rect.top += 4;
	rect.left += 4;
	rect.right -= 4;

	page1.MoveWindow(&rect);
	page2.MoveWindow(&rect);
	page3.MoveWindow(&rect);
	page4.MoveWindow(&rect);


	page1.ShowWindow(TRUE);

	m_tab.SetCurSel(0);  

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGridDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGridDlg::OnPaint()
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
HCURSOR CGridDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGridDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int cursel;
	cursel=m_tab.GetCurSel()  ;
	switch (cursel)
		case 0:
	{
		page1.ShowWindow(TRUE);
		page2.ShowWindow(FALSE);
		page3.ShowWindow(FALSE);
		page4.ShowWindow(FALSE);
		break;
	
		case 1:
		
			page2.ShowWindow(TRUE);
			page1.ShowWindow(FALSE);
			page3.ShowWindow(FALSE);
			page4.ShowWindow(FALSE);
			break;
		

		case 2:

			page3.ShowWindow(TRUE);
			page2.ShowWindow(FALSE);
			page1.ShowWindow(FALSE);
			page4.ShowWindow(FALSE);
			break;
	
		case 3:

			page4.ShowWindow(TRUE);
			page2.ShowWindow(FALSE);
			page1.ShowWindow(FALSE);
			page3.ShowWindow(FALSE);
			break;
		default:;
	
	}
	*pResult = 0;
}


void CGridDlg::Onopen()
{
	CString filter;
	filter = "文本文件（*.txt）||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);
	if (dlg.DoModal()==IDOK)
	{
		string name;
		name = dlg.GetPathName();
		if (name.length() <= 0)
		{
			AfxMessageBox("没有选择文件，请选择文件！");

		}
		page1.open(name);
		UpdateData(FALSE);
		flag = 1;
		AfxMessageBox("打开文件成功！");
	}
}


void CAboutDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CGridDlg::Ontobao()
{
	if (flag == 1|page1.Data.size()>0)
	{
		page4.Data = page1.Data;
		page4.R = page1.R;
		page4.OnPaint();
		AfxMessageBox("生成凸包成功！");
		page1.ShowWindow(FALSE);
		page2.ShowWindow(FALSE);
		page3.ShowWindow(FALSE);
		page4.ShowWindow(TRUE);
		flag = 2;

	}
	else if (page1.Data.size()<0)
	{
		AfxMessageBox("还没有数据！");
	}
}




void CGridDlg::OnTin()
{
	if (flag==2)
	{
		CEdit* pside;
		pside = (CEdit*)GetDlgItem(IDC_EDIT1);
		//取值
		CString str; str = "5";
		pside->GetWindowText(str);
		m_grid = str;	//保存到变量里
		int side = atoi(m_grid.GetBuffer(m_grid.GetLength()));   //int side
		page1.grid(side);
		page4.Data = page1.Data;
		page4.R = page1.R;
		page4.OnPaint();
		AfxMessageBox("构建格网成功！");
		page1.ShowWindow(FALSE);
		page2.ShowWindow(FALSE);
		page3.ShowWindow(FALSE);
		page4.ShowWindow(TRUE);
		flag = 3;

	}
	else if (flag!=2)
	{
		AfxMessageBox("还没有生成凸包！");
	}
}


void CGridDlg::OnV()
{
	if (flag == 3)
	{

		CEdit* pside;
		pside = (CEdit*)GetDlgItem(IDC_EDIT1);
		//取值
		CString str;
		pside->GetWindowText(str);
		m_grid = str;	//保存到变量里
		int side = atoi(m_grid.GetBuffer(m_grid.GetLength()));
		page1.V(side);
		page3.Data = page1.Data;
		page3.R = page1.R;
		page3.report();
		AfxMessageBox("体积计算完成！");
		page1.ShowWindow(FALSE);
		page2.ShowWindow(FALSE);
		page4.ShowWindow(FALSE);
		page3.ShowWindow(TRUE);
		flag = 4;

	}
	else if (flag != 3)
	{
		AfxMessageBox("还没有构建格网！");
	}
}


void CGridDlg::Onsavejpg()
{

	if (flag == 3)
	{
		page4.OnFileSaveAs();
	}
	else if (flag != 3)
	{
		AfxMessageBox("还没有绘图！");
	}
}


void CGridDlg::Onsave()
{
	if (page3.reportValue.GetLength() <= 0)
	{
		AfxMessageBox("报告为空，请生成报告再保存");
		return;
	}
	CStdioFile file;
	FILE *f = NULL;
	CString FilePathName;//保存路径名  
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,//hide read only  ; over write prompt
		(LPCTSTR)_TEXT("文本文件(*.txt)||所有文件(*.*)||"), NULL);   //TRUE为OPEN对话框，FALSE为SAVE AS对话框
	if (dlg.DoModal() == IDOK)
	{

		// CString strValue;
		FilePathName = dlg.GetPathName() + ".txt";
		f = fopen(FilePathName, "wb+");
		if (f == NULL)
		{
			AfxMessageBox("打开文件[" + FilePathName + "]失败");
			return;
		}

		fwrite(page3.reportValue, 1, page3.reportValue.GetLength(), f);   //
		fclose(f);
	}
	MessageBox(_T("数据保存成功！"));
}
