// Cpage2.cpp : 实现文件
//

#include "stdafx.h"
#include "Grid.h"
#include "Cpage2.h"
#include "afxdialogex.h"


// Cpage2 对话框

IMPLEMENT_DYNAMIC(Cpage2, CDialogEx)

Cpage2::Cpage2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Cpage2::~Cpage2()
{
}

void Cpage2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(Cpage2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cpage2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cpage2::OnBnClickedButton2)
END_MESSAGE_MAP()




void Cpage2::OnBnClickedButton1()
{
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//使整行高亮
	dwStyle |= LVS_EX_GRIDLINES;//网格线
	m_list.SetExtendedStyle(dwStyle);
	//设置表头，第一行标题，后面的数字表示列宽
	m_list.InsertColumn(0, _T("点名"), LVCFMT_CENTER, 50, 0);
	m_list.InsertColumn(1, _T("X（m）"), LVCFMT_CENTER, 80, 1);
	m_list.InsertColumn(2, _T("Y（m）"), LVCFMT_CENTER, 80, 2);
	m_list.InsertColumn(3, _T("圆曲线半径"), LVCFMT_CENTER, 80, 3);
	m_list.InsertColumn(4, _T("缓曲线长"), LVCFMT_CENTER, 80, 4);
}


void Cpage2::OnBnClickedButton2()
{
	UpdateData(TRUE);//将界面的数据更新到对应的变量中
	CString P_Str, x_Str, y_Str, h_Str;
	double x, y, h;
	int count = m_list.GetItemCount();//获取当前存在的数据总量
	string p;
	GetDlgItem(IDC_EDIT1)->GetWindowText(P_Str);
	GetDlgItem(IDC_EDIT2)->GetWindowText(x_Str);
	GetDlgItem(IDC_EDIT3)->GetWindowText(y_Str);
	GetDlgItem(IDC_EDIT4)->GetWindowText(h_Str);
	

	m_list.InsertItem(count, "");//插入一行
	m_list.SetItemText(count, 0, P_Str);//改变列1的显示文字
	m_list.SetItemText(count, 1, x_Str);//改变列2的显示文字
	m_list.SetItemText(count, 2, y_Str);//改变列3的显示文字
	m_list.SetItemText(count, 3,h_Str);//改变列4的显示文字
	

										//将数据转换为double
	x = atof(x_Str);
	y = atof(y_Str);
	h = atof(h_Str);
	

	//将CString转为string
	p = P_Str.GetBuffer(0);

	string line;
	stringstream ss(line);
	Point D;
	ss >> p; D.Pname = p;
	ss >> x; D.Px = x;
	ss >> y; D.Py = y;
	ss >> h; D.Ph = h;
	Data.push_back(D);
}
