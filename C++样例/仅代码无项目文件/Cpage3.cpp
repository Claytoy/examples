// Cpage3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Grid.h"
#include "Cpage3.h"
#include "afxdialogex.h"


// Cpage3 �Ի���

IMPLEMENT_DYNAMIC(Cpage3, CDialogEx)

Cpage3::Cpage3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, reportValue(_T(""))
{

}

Cpage3::~Cpage3()
{
}

void Cpage3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, reportValue);
}


BEGIN_MESSAGE_MAP(Cpage3, CDialogEx)
END_MESSAGE_MAP()


// Cpage3 ��Ϣ�������

void Cpage3::report()
{
	CString ss, s, str, result;
	result += str + _T("**********************************�������������**********************************\r\n");	
	result += str + _T("\r\n");
	result += str + _T("\r\n");
	result += str + _T("\r\n");
	result += str + _T("--------------------������Ϣ--------------------\r\n");
	ss.Format("��׼�̣߳�9  \r\n");
	result += ss;
	ss.Format("��λ�����߳���1  \r\n");
	result += ss;
	ss.Format("�������������%d  ",R.numwidth);
	result += ss;
	result += str + _T("\r\n");
	ss.Format("�������������%d  ",R.numlength);
	result += ss;
	result += str + _T("\r\n");
	ss.Format("��λ����������%d  ", R.numwidth*R.numlength);
	result += ss;
	result += str + _T("\r\n");
	ss.Format("������� %.4lf ",R.vertical);
	result += ss;
	result += str + _T("\r\n");
	result += str + _T("\r\n");
	result += str + _T("\r\n");
	
	result += str + _T("\r\n");
	result += str + _T("--------------------͹������Ϣ--------------------\r\n");
	result += str + _T("���� \t X���� \t  Y���� \t  H�߳� \t \r\n");

	for (size_t i = 0; i < R.hull.size(); i++)
	{
		ss.Format("%s  \t  %.4lf \t %.4lf \t %.4lf  \t",R.hull[i].Pname.c_str(), R.hull[i].Px, R.hull[i].Py, R.hull[i].Ph);
		result += ss + _T("\r\n");
	}



	GetDlgItem(IDC_EDIT1)->SetWindowText(result);
	reportValue = result;	//���浽������
	UpdateData(FALSE); //���¿ؼ�ֵ


	



}