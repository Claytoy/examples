// Cpage3.cpp : 实现文件
//

#include "stdafx.h"
#include "Grid.h"
#include "Cpage3.h"
#include "afxdialogex.h"


// Cpage3 对话框

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


// Cpage3 消息处理程序

void Cpage3::report()
{
	CString ss, s, str, result;
	result += str + _T("**********************************规则格网计算结果**********************************\r\n");	
	result += str + _T("\r\n");
	result += str + _T("\r\n");
	result += str + _T("\r\n");
	result += str + _T("--------------------基本信息--------------------\r\n");
	ss.Format("基准高程：9  \r\n");
	result += ss;
	ss.Format("单位格网边长：1  \r\n");
	result += ss;
	ss.Format("格网纵向个数：%d  ",R.numwidth);
	result += ss;
	result += str + _T("\r\n");
	ss.Format("格网横向个数：%d  ",R.numlength);
	result += ss;
	result += str + _T("\r\n");
	ss.Format("单位格网总数：%d  ", R.numwidth*R.numlength);
	result += ss;
	result += str + _T("\r\n");
	ss.Format("总体积： %.4lf ",R.vertical);
	result += ss;
	result += str + _T("\r\n");
	result += str + _T("\r\n");
	result += str + _T("\r\n");
	
	result += str + _T("\r\n");
	result += str + _T("--------------------凸包点信息--------------------\r\n");
	result += str + _T("点名 \t X坐标 \t  Y坐标 \t  H高程 \t \r\n");

	for (size_t i = 0; i < R.hull.size(); i++)
	{
		ss.Format("%s  \t  %.4lf \t %.4lf \t %.4lf  \t",R.hull[i].Pname.c_str(), R.hull[i].Px, R.hull[i].Py, R.hull[i].Ph);
		result += ss + _T("\r\n");
	}



	GetDlgItem(IDC_EDIT1)->SetWindowText(result);
	reportValue = result;	//保存到变量里
	UpdateData(FALSE); //更新控件值


	



}