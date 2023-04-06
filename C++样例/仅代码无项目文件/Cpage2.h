#pragma once
#include "afxcmn.h"
#include"GridClass.h"

// Cpage2 对话框

class Cpage2 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage2)

public:
	Cpage2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	vector<Point> Data;
};
