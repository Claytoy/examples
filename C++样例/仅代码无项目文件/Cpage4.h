#pragma once
#include "afxwin.h"
#include"GridClass.h"

// Cpage4 �Ի���

//class CGridDlg;

class Cpage4 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage4)

public:
	Cpage4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cpage4();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
