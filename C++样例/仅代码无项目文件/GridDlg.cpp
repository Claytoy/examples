
// GridDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Grid.h"
#include "GridDlg.h"
#include "afxdialogex.h"
#include<string.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CGridDlg �Ի���



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


// CGridDlg ��Ϣ�������

BOOL CGridDlg::OnInitDialog()
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

	//�����˵� 
	CMenu m_menu;
	m_menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_menu);


	//����������
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
		| TBSTYLE_LIST, //��ʾ�ı���ť
		CRect(1, 1, 0, 0)) || !m_ToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		AfxMessageBox("fail to create toolbar\n");
		return FALSE;
	}
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);   //��ʾ��������״̬��  һ��Ҫд

	//��������ҳ
	m_tab.InsertItem(1,"���");
	m_tab.InsertItem(2, "����");
	m_tab.InsertItem(3, "����");
	m_tab.InsertItem(4, "��ͼ");

	//�������Ը�ҳ
	page1.Create(IDD_DIALOG1, GetDlgItem(IDC_TAB1));
	page2.Create(IDD_DIALOG2, GetDlgItem(IDC_TAB1));
	page3.Create(IDD_DIALOG3, GetDlgItem(IDC_TAB1));
	page4.Create(IDD_DIALOG4, GetDlgItem(IDC_TAB1));

	//��ȡ����ҳ��m_tab�ķ�Χ
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGridDlg::OnPaint()
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
	filter = "�ı��ļ���*.txt��||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);
	if (dlg.DoModal()==IDOK)
	{
		string name;
		name = dlg.GetPathName();
		if (name.length() <= 0)
		{
			AfxMessageBox("û��ѡ���ļ�����ѡ���ļ���");

		}
		page1.open(name);
		UpdateData(FALSE);
		flag = 1;
		AfxMessageBox("���ļ��ɹ���");
	}
}


void CAboutDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CGridDlg::Ontobao()
{
	if (flag == 1|page1.Data.size()>0)
	{
		page4.Data = page1.Data;
		page4.R = page1.R;
		page4.OnPaint();
		AfxMessageBox("����͹���ɹ���");
		page1.ShowWindow(FALSE);
		page2.ShowWindow(FALSE);
		page3.ShowWindow(FALSE);
		page4.ShowWindow(TRUE);
		flag = 2;

	}
	else if (page1.Data.size()<0)
	{
		AfxMessageBox("��û�����ݣ�");
	}
}




void CGridDlg::OnTin()
{
	if (flag==2)
	{
		CEdit* pside;
		pside = (CEdit*)GetDlgItem(IDC_EDIT1);
		//ȡֵ
		CString str; str = "5";
		pside->GetWindowText(str);
		m_grid = str;	//���浽������
		int side = atoi(m_grid.GetBuffer(m_grid.GetLength()));   //int side
		page1.grid(side);
		page4.Data = page1.Data;
		page4.R = page1.R;
		page4.OnPaint();
		AfxMessageBox("���������ɹ���");
		page1.ShowWindow(FALSE);
		page2.ShowWindow(FALSE);
		page3.ShowWindow(FALSE);
		page4.ShowWindow(TRUE);
		flag = 3;

	}
	else if (flag!=2)
	{
		AfxMessageBox("��û������͹����");
	}
}


void CGridDlg::OnV()
{
	if (flag == 3)
	{

		CEdit* pside;
		pside = (CEdit*)GetDlgItem(IDC_EDIT1);
		//ȡֵ
		CString str;
		pside->GetWindowText(str);
		m_grid = str;	//���浽������
		int side = atoi(m_grid.GetBuffer(m_grid.GetLength()));
		page1.V(side);
		page3.Data = page1.Data;
		page3.R = page1.R;
		page3.report();
		AfxMessageBox("���������ɣ�");
		page1.ShowWindow(FALSE);
		page2.ShowWindow(FALSE);
		page4.ShowWindow(FALSE);
		page3.ShowWindow(TRUE);
		flag = 4;

	}
	else if (flag != 3)
	{
		AfxMessageBox("��û�й���������");
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
		AfxMessageBox("��û�л�ͼ��");
	}
}


void CGridDlg::Onsave()
{
	if (page3.reportValue.GetLength() <= 0)
	{
		AfxMessageBox("����Ϊ�գ������ɱ����ٱ���");
		return;
	}
	CStdioFile file;
	FILE *f = NULL;
	CString FilePathName;//����·����  
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,//hide read only  ; over write prompt
		(LPCTSTR)_TEXT("�ı��ļ�(*.txt)||�����ļ�(*.*)||"), NULL);   //TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
	if (dlg.DoModal() == IDOK)
	{

		// CString strValue;
		FilePathName = dlg.GetPathName() + ".txt";
		f = fopen(FilePathName, "wb+");
		if (f == NULL)
		{
			AfxMessageBox("���ļ�[" + FilePathName + "]ʧ��");
			return;
		}

		fwrite(page3.reportValue, 1, page3.reportValue.GetLength(), f);   //
		fclose(f);
	}
	MessageBox(_T("���ݱ���ɹ���"));
}
