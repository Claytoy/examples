#pragma once
#include "afxcmn.h"
#include"GridClass.h"

// Cpage1 �Ի���

class Cpage1 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage1)

public:
	Cpage1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cpage1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listcontrol;
	void open(string name);
	void grid(int side);
	void V(int side);
	vector<Point> Data;
	Error E;
	Result R;
	GridClass my;

};
