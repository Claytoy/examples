#pragma once
#include"GridClass.h"

// Cpage3 �Ի���

class Cpage3 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage3)

public:
	Cpage3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cpage3();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString reportValue;
	void report();

	vector<Point> Data;
	Error E;
	Result R;
};
