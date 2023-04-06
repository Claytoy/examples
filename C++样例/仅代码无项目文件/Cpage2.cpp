// Cpage2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Grid.h"
#include "Cpage2.h"
#include "afxdialogex.h"


// Cpage2 �Ի���

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
	dwStyle |= LVS_EX_FULLROWSELECT;	//ʹ���и���
	dwStyle |= LVS_EX_GRIDLINES;//������
	m_list.SetExtendedStyle(dwStyle);
	//���ñ�ͷ����һ�б��⣬��������ֱ�ʾ�п�
	m_list.InsertColumn(0, _T("����"), LVCFMT_CENTER, 50, 0);
	m_list.InsertColumn(1, _T("X��m��"), LVCFMT_CENTER, 80, 1);
	m_list.InsertColumn(2, _T("Y��m��"), LVCFMT_CENTER, 80, 2);
	m_list.InsertColumn(3, _T("Բ���߰뾶"), LVCFMT_CENTER, 80, 3);
	m_list.InsertColumn(4, _T("�����߳�"), LVCFMT_CENTER, 80, 4);
}


void Cpage2::OnBnClickedButton2()
{
	UpdateData(TRUE);//����������ݸ��µ���Ӧ�ı�����
	CString P_Str, x_Str, y_Str, h_Str;
	double x, y, h;
	int count = m_list.GetItemCount();//��ȡ��ǰ���ڵ���������
	string p;
	GetDlgItem(IDC_EDIT1)->GetWindowText(P_Str);
	GetDlgItem(IDC_EDIT2)->GetWindowText(x_Str);
	GetDlgItem(IDC_EDIT3)->GetWindowText(y_Str);
	GetDlgItem(IDC_EDIT4)->GetWindowText(h_Str);
	

	m_list.InsertItem(count, "");//����һ��
	m_list.SetItemText(count, 0, P_Str);//�ı���1����ʾ����
	m_list.SetItemText(count, 1, x_Str);//�ı���2����ʾ����
	m_list.SetItemText(count, 2, y_Str);//�ı���3����ʾ����
	m_list.SetItemText(count, 3,h_Str);//�ı���4����ʾ����
	

										//������ת��Ϊdouble
	x = atof(x_Str);
	y = atof(y_Str);
	h = atof(h_Str);
	

	//��CStringתΪstring
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
