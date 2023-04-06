#pragma once
#include "afxwin.h"
#include"GridClass.h"

// Cpage4 对话框

//class CGridDlg;

class Cpage4 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage4)

public:
	Cpage4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic draw;
	CWnd *pWnd;
	vector<Point> Data;
	Error E;
	Result R;
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	CString m_r;
	CImage image;
	void OnFileSaveAs();
};
