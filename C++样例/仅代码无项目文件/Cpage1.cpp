// Cpage1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Grid.h"
#include "Cpage1.h"
#include "afxdialogex.h"


// Cpage1 �Ի���

IMPLEMENT_DYNAMIC(Cpage1, CDialogEx)

Cpage1::Cpage1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Cpage1::~Cpage1()
{
}

void Cpage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listcontrol);
}


BEGIN_MESSAGE_MAP(Cpage1, CDialogEx)
END_MESSAGE_MAP()


// Cpage1 ��Ϣ�������

void Cpage1::open(string name)
{
	CRect rect;
	m_listcontrol.GetClientRect(&rect);
	m_listcontrol.SetExtendedStyle(m_listcontrol.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_listcontrol.InsertColumn(0, _T("����"), LVCFMT_CENTER, 60,0);
	m_listcontrol.InsertColumn(1, _T("X"), LVCFMT_CENTER, 80, 1);
	m_listcontrol.InsertColumn(2, _T("Y"), LVCFMT_CENTER, 80, 2);
	m_listcontrol.InsertColumn(3, _T("H"), LVCFMT_CENTER, 80, 3);


	
	my.readfile(name);
	Data = my.Data;
	my.gethull();
	R = my.R;

	int line=0;
	for (int i = 0; i < Data.size(); i++)
	{
		CString  P_Str, x_Str, y_Str, h_Str;
		P_Str.Format("%s", Data[i].Pname.c_str());
		x_Str.Format("%.4lf", Data[i].Px);
		y_Str.Format("%.4lf", Data[i].Py);
		h_Str.Format("%.4lf", Data[i].Ph);

		m_listcontrol.InsertItem(line, "");  //����һ������
		m_listcontrol.SetItemText(line, 0, P_Str);
		m_listcontrol.SetItemText(line, 1, x_Str);
		m_listcontrol.SetItemText(line, 2, y_Str);
		m_listcontrol.SetItemText(line, 3, h_Str);

		line++;
	}
}


void Cpage1::grid(int side)
{
	
	my.creategrid(side);
	R = my.R;

}

void Cpage1::V(int side)
{

    my.calvertical(side);
//	my.calvertical(5);
//	my.calvertical(10);
	R = my.R;


}