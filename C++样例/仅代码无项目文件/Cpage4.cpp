// Cpage4.cpp : 实现文件
//

#include "stdafx.h"
#include "Grid.h"
#include "Cpage4.h"
#include "afxdialogex.h"
#include"GridDlg.h"

using namespace std;

class CGridDlg;
// Cpage4 对话框
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


// Cpage4 消息处理程序


void Cpage4::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
		  // 不为绘图消息调用 CDialogEx::OnPaint()
	pWnd->Invalidate();
	pWnd->UpdateWindow();
	 
	CGridDlg *parent = (CGridDlg*)GetParent();//CGridDlg是主对话框对应的类
	int r = parent->side;//i是主对话框内int类型的公共变量变量

			
	

	//将主对话框输入的数据应用于子对话框
   //m_r=((CGridDlg*)GetDlgItem(IDC_EDIT1))->m_grid;
	

//	int a = _ttoi(m_r);  //将CString转换为int


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

	CBrush newbrush, *pOldBrush;//创建笔刷
	newbrush.CreateSolidBrush(RGB(255, 0, 0));    //笔刷原来为红色
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
		int ynum = R.numlength;  //横纵格网数

		int xmin = 60 + (R.fixedpoint.Px - 3740) * 7 + 3;
		int ymin = 220 - (R.fixedpoint.Py - 2845) * 7 + 3;//最低点

	   //格网的边界

		int  xmax = xmin + R.width * 7 + 3;
		int  ymax = ymin - R.length * 7 + 3;

		//画行线
		for (int i = 0; i < R.numlength; i++)
		{
			pDC->MoveTo(xmin, ymin - 7 *  1 * i);
			pDC->LineTo(xmax, ymin - 7 * 1 * i);

		}


		//画列线
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
				  // 异常: OCX 属性页应返回 FALSE
}


void Cpage4::OnFileSaveAs()
{

	HWND hwnd = this->GetSafeHwnd();   //得到窗口句柄
	HDC hDC = ::GetWindowDC(hwnd);//获取DC 指定的窗口的设备环境

	RECT rect;
	::GetWindowRect(hwnd, &rect);//获取屏幕大小   该函数返回指定窗口的边框矩形的尺寸
								 //该尺寸以相对于屏幕坐标左上角的屏幕坐标给出

	HDC hDCMem = ::CreateCompatibleDC(hDC);//创建兼容DC  
										   //创建一个与指定设备兼容的内存设备上下文环境(DC)。

	HBITMAP hBitMap = ::CreateCompatibleBitmap(hDC, rect.right - rect.left, rect.bottom - rect.top);
	//创建兼容位图    
	HBITMAP hOldMap = (HBITMAP)::SelectObject(hDCMem, hBitMap);
	//将位图选入DC，并保存返回值    

	::BitBlt(hDCMem, 0, 0, rect.right - rect.left, rect.bottom - rect.top, hDC, 0, 0, SRCCOPY);
	//将屏幕DC的图象复制到内存DC中    

	image.Attach(hBitMap);

	//image.Save(_T("c:\\B.jpg"));//如果文件后缀为.bmp，则保存为为bmp格式 
	//以下程序用于选择图片保存路径等信息    

	CString strFilter = "JPEG 图像文件|*.jpg位图文件(*.bmp)|*.bmp||GIF 图像文件|*.gif|PNG 图像文件|*.png||";
	CFileDialog dlg(FALSE, NULL, ".jpg", NULL, strFilter);
	if (IDOK != dlg.DoModal())
		return;
	// 如果用户没有指定文件扩展名，则为其添加一个
	CString strFileName;
	CString strExtension;

	strFileName = dlg.m_ofn.lpstrFile;


	// 图像保存
	HRESULT hResult = image.Save(strFileName);
	if (FAILED(hResult))
		MessageBox("保存图像文件失败！");
	else
		MessageBox("保存图像文件成功！");



	image.Detach();

	::SelectObject(hDCMem, hOldMap);//选入上次的返回值    

									//释放    
	::DeleteObject(hBitMap);
	::DeleteDC(hDCMem);
	::DeleteDC(hDC);


}


