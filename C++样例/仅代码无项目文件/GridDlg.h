
// GridDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include"Cpage1.h"
#include"Cpage2.h"
#include"Cpage3.h"
#include"Cpage4.h"
#include"GridClass.h"

// CGridDlg �Ի���
class CGridDlg : public CDialogEx
{
// ����
public:
	CGridDlg(CWnd* pParent = NULL);	// ��׼���캯��

/////////////////////
	Cpage1 page1;
	Cpage2 page2;
	Cpage3 page3;
	Cpage4 page4;




// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GRID_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CToolBar m_ToolBar;

	// ���ɵ���Ϣӳ�亯��
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
	CString m_grid;       //���edit����ļ�����ݵı���
	int side; //��Ÿ�������Ĺ�������
	afx_msg void Onsavejpg();
	afx_msg void Onsave();
};
