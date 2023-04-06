// Cpage4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Grid.h"
#include "Cpage4.h"
#include "afxdialogex.h"
#include"GridDlg.h"

using namespace std;

class CGridDlg;
// Cpage4 �Ի���
IMPLEMENT_DYNAMIC(Cpage4, CDialogEx)

Cpage4::Cpage4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

Cpage4::~Cpage4()
{
}

void Cpage4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_DRAW, draw);
}


BEGIN_MESSAGE_MAP(Cpage4, CDialogEx)

	ON_WM_PAINT()
END_MESSAGE_MAP()


// Cpage4 ��Ϣ�������


void Cpage4::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
		  // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	pWnd->Invalidate();
	pWnd->UpdateWindow();
	 
	CGridDlg *parent = (CGridDlg*)GetParent();//CGridDlg�����Ի����Ӧ����
	int r = parent->side;//i�����Ի�����int���͵Ĺ�����������

			
	

	//�����Ի������������Ӧ�����ӶԻ���
   //m_r=((CGridDlg*)GetDlgItem(IDC_EDIT1))->m_grid;
	

//	int a = _ttoi(m_r);  //��CStringת��Ϊint


	CDC *pDC = pWnd->GetDC();

	pDC->Rectangle(0, 0, 870, 260);

	CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen*poldpen = pDC->SelectObject(&pen);

	CString str;
	pDC->MoveTo(60, 20);
	pDC->LineTo(60, 220);
	pDC->LineTo(700, 220);
	pDC->TextOutA(70, 50, "Y");
	pDC->TextOutA(500, 210, "X");

	CBrush newbrush, *pOldBrush;//������ˢ
	newbrush.CreateSolidBrush(RGB(255, 0, 0));    //��ˢԭ��Ϊ��ɫ
	pOldBrush = pDC->SelectObject(&newbrush);

	if (R.numlength == 0)
	{
		for (int m = 0; m < R.hull.size(); m++)
		{
			int x, y;
			pDC->LineTo(60 + (R.hull[m].Px - 3740) * 7 + 3, 220 - (R.hull[m].Py - 2845) * 7 + 3);
			x = 60 + (R.hull[m].Px - 3740) * 7;
			y = 220 - (R.hull[m].Py - 2845) * 7;
			pDC->MoveTo(x + 3, y + 3);
			pDC->Ellipse(x, y, x + 6, y + 6);
		}

		for (int j = 0; j < Data.size(); j++)
		{
			int x, y;
			
			x = 60 + (Data[j].Px - 3740) * 7;
			y = 220 - (Data[j].Py - 2845) * 7;
			
			pDC->Ellipse(x, y, x + 6, y + 6);
		}

	}
	else if (R.numwidth > 0)
	{
		for (int m = 0; m < R.hull.size(); m++)
		{
			int x, y;
			pDC->LineTo(60 + (R.hull[m].Px - 3740) * 7 + 3, 220 - (R.hull[m].Py - 2845) * 7 + 3);
			x = 60 + (R.hull[m].Px - 3740) * 7;
			y = 220 - (R.hull[m].Py - 2845) * 7;
			pDC->MoveTo(x + 3, y + 3);
			pDC->Ellipse(x, y, x + 6, y + 6);
		}



		for (int j = 0; j < Data.size(); j++)
		{
			int x, y;

			x = 60 + (Data[j].Px - 3740) * 7;
			y = 220 - (Data[j].Py - 2845) * 7;

			pDC->Ellipse(x, y, x + 6, y + 6);
		}

		int xnum = R.numwidth;
		int ynum = R.numlength;  //���ݸ�����

		int xmin = 60 + (R.fixedpoint.Px - 3740) * 7 + 3;
		int ymin = 220 - (R.fixedpoint.Py - 2845) * 7 + 3;//��͵�

	   //�����ı߽�

		int  xmax = xmin + R.width * 7 + 3;
		int  ymax = ymin - R.length * 7 + 3;

		//������
		for (int i = 0; i < R.numlength; i++)
		{
			pDC->MoveTo(xmin, ymin - 7 *  1 * i);
			pDC->LineTo(xmax, ymin - 7 * 1 * i);

		}


		//������
		for (int i = 0; i < R.numwidth; i++)
		{
			pDC->MoveTo(xmin + 7 * 1 * i, ymin);
			pDC->LineTo(xmin + 7 * 1 * i, ymax);
		}
	}


}


BOOL Cpage4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	pWnd = GetDlgItem(IDC_STATIC_DRAW);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void Cpage4::OnFileSaveAs()
{

	HWND hwnd = this->GetSafeHwnd();   //�õ����ھ��
	HDC hDC = ::GetWindowDC(hwnd);//��ȡDC ָ���Ĵ��ڵ��豸����

	RECT rect;
	::GetWindowRect(hwnd, &rect);//��ȡ��Ļ��С   �ú�������ָ�����ڵı߿���εĳߴ�
								 //�óߴ����������Ļ�������Ͻǵ���Ļ�������

	HDC hDCMem = ::CreateCompatibleDC(hDC);//��������DC  
										   //����һ����ָ���豸���ݵ��ڴ��豸�����Ļ���(DC)��

	HBITMAP hBitMap = ::CreateCompatibleBitmap(hDC, rect.right - rect.left, rect.bottom - rect.top);
	//��������λͼ    
	HBITMAP hOldMap = (HBITMAP)::SelectObject(hDCMem, hBitMap);
	//��λͼѡ��DC�������淵��ֵ    

	::BitBlt(hDCMem, 0, 0, rect.right - rect.left, rect.bottom - rect.top, hDC, 0, 0, SRCCOPY);
	//����ĻDC��ͼ���Ƶ��ڴ�DC��    

	image.Attach(hBitMap);

	//image.Save(_T("c:\\B.jpg"));//����ļ���׺Ϊ.bmp���򱣴�ΪΪbmp��ʽ 
	//���³�������ѡ��ͼƬ����·������Ϣ    

	CString strFilter = "JPEG ͼ���ļ�|*.jpgλͼ�ļ�(*.bmp)|*.bmp||GIF ͼ���ļ�|*.gif|PNG ͼ���ļ�|*.png||";
	CFileDialog dlg(FALSE, NULL, ".jpg", NULL, strFilter);
	if (IDOK != dlg.DoModal())
		return;
	// ����û�û��ָ���ļ���չ������Ϊ�����һ��
	CString strFileName;
	CString strExtension;

	strFileName = dlg.m_ofn.lpstrFile;


	// ͼ�񱣴�
	HRESULT hResult = image.Save(strFileName);
	if (FAILED(hResult))
		MessageBox("����ͼ���ļ�ʧ�ܣ�");
	else
		MessageBox("����ͼ���ļ��ɹ���");



	image.Detach();

	::SelectObject(hDCMem, hOldMap);//ѡ���ϴεķ���ֵ    

									//�ͷ�    
	::DeleteObject(hBitMap);
	::DeleteDC(hDCMem);
	::DeleteDC(hDC);


}


