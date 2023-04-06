
// GridDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include"Cpage1.h"
#include"Cpage2.h"
#include"Cpage3.h"
#include"Cpage4.h"
#include"GridClass.h"

// CGridDlg 对话框
class CGridDlg : public CDialogEx
{
// 构造
public:
	CGridDlg(CWnd* pParent = NULL);	// 标准构造函数

/////////////////////
	Cpage1 page1;
	Cpage2 page2;
	Cpage3 page3;
	Cpage4 page4;




// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GRID_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CToolBar m_ToolBar;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void Onopen();
	int flag;
	afx_msg void Ontobao();
	afx_msg void OnTin();
	afx_msg void OnV();
	CString m_grid;       //存放edit输入的间隔数据的变量
	int side; //存放格网间隔的公共变量
	afx_msg void Onsavejpg();
	afx_msg void Onsave();
};
