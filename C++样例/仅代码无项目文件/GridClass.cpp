#include "GridClass.h"



GridClass::GridClass()
{
}


GridClass::~GridClass()
{
}

void GridClass::readfile(string name)
{
	fstream file(name);
	if (!file)
	{
		E.efile = 1;
	}
	else
	{
		string line;
		while (getline(file, line))
		{
			for (size_t i = 0; i < line.size(); i++)
			{
				if (line[i] == ',')
					line[i] = ' ';
			}
			stringstream ss(line);
			Point readpoint;
			ss >> readpoint.Pname >> readpoint.Px >> readpoint.Py >> readpoint.Ph;
			Data.push_back(readpoint);
		}
	}
	file.close();
}

//����͹�������
void GridClass::gethull()
{
	//���һ���
	double ymin = 50000, xmin = 50000;
	Point P0;//����
	int count;//��������λ��
	for (size_t i = 0; i < Data.size(); i++)
	{
		if (Data[i].Py < ymin)
		{
			ymin = Data[i].Py;
			xmin = Data[i].Px;
			count = i;
		}
		else if (fabs(Data[i].Py - ymin) < 1e-6)
		{
			if (Data[i].Px < xmin)
			{
				ymin = Data[i].Py;
				xmin = Data[i].Px;
				count = i;
			}
		}
	}
	P0 = Data[count];
	vector<Point> M=Data;
	M.erase(M.begin() + count);
	//��������ļнǴ�С����Ե㼯��������
	vector<double> Angle;
	for (size_t i1 = 0; i1 < M.size(); i1++)//����н�
	{
		double angle;
		double dx, dy;
		dy = M[i1].Py - P0.Py;
		dx = M[i1].Px - P0.Px;
		if (dy == 0)
		{
			angle = 0;
		}
		else if (dx == 0)
		{
			angle = pi / 2;
		}
		else
		{
			angle = atan(dy / dx);
			if (dx < 0)
				angle += pi;
		}
		M[i1].Pangle = angle;
		Angle.push_back(angle);
	}
	sort(Angle.begin(), Angle.end());//�ԽǶȽ�������
	vector<Point> O;
	for (size_t i2 = 0; i2 < Angle.size(); i2++)//�Ե�����
	{
		for (size_t i3 = 0; i3 < M.size(); i3++)
		{
			if (M[i3].Pangle == Angle[i2])
				O.push_back(M[i3]);
		}
	}
	//������͹���㹹�ɵĶ�ջ
	vector<Point> S;
	S.push_back(P0); S.push_back(O[0]); S.push_back(O[1]);
	for (size_t i4 = 2; i4 < O.size(); i4++)
	{
		Point p1, p2, p3;
		p2 = S.back(); p1 = S.at(S.size()-2); p3 = O[i4];
		double m;
		m = (p1.Px-p2.Px)*(p3.Py-p2.Py) - (p1.Py - p2.Py)*(p3.Px - p2.Px);
		if (m > 0)
		{
			S.pop_back();
			i4--;
		}
		else if (m < 0)
		{
			S.push_back(p3);
		}
	}
	S.push_back(P0);
	R.hull = S;
}
//��������
//side Ϊ������Ԫ�߳���Ϊ����
void GridClass::creategrid(int side)
{
	//�����������
	double xmin = 50000, xmax = 0, ymin = 50000, ymax = 0;
	for (size_t i = 0; i < Data.size(); i++)
	{
		if (Data[i].Px < xmin)
			xmin = Data[i].Px;
		else if (Data[i].Px > xmax)
			xmax = Data[i].Px;
		if (Data[i].Py < ymin)
			ymin = Data[i].Py;
		else if (Data[i].Py > ymax)
			ymax = Data[i].Py;
	}
	R.fixedpoint.Px = xmin; R.fixedpoint.Py = ymin;//�������½Ƕ���
	double length, width;  //���α߳�
	length = ymax - ymin; width = xmax - xmin;
	R.length = length; R.width = width;
	int num_l, num_w;//���γ���Ԫ������
	num_l = ceil(length / side);
	num_w = ceil(width / side);
	R.numlength = num_l; R.numwidth = num_w;
	//�жϵ�Ԫ�����ĵ��Ƿ���͹����
	int inhull=0;//��¼��͹���ڵĵ�Ԫ������
	vector<Point> center;//��͹���ڵĸ������ĵ�
	for (int j = 0; j < num_l; j++)
	{
		double x, y;//��Ԫ�������ĵ�
		y = ymin + side*j + side / 2.0;
		for (int j1 = 0; j1 < num_w; j1++)
		{
			x = xmin + side*j1 + side / 2.0;
			//�ж����ĵ���͹���ߵĹ�ϵ
			int count = 0;//��¼���߽������
			for (size_t k = 0; k < R.hull.size()-1; k++)
			{
				if ((R.hull[k].Py - y)*(R.hull[k + 1].Py - y) < 0)
				{
					double xk;
					xk = (R.hull[k + 1].Px - R.hull[k].Px)*(y - R.hull[k].Py) / (R.hull[k + 1].Py - R.hull[k].Py);
					xk += R.hull[k].Px;
					if (xk > x)
						count++;
				}
			}
			if (count % 2 == 1)
			{
				inhull++;
				Point p;
				p.Px = x; p.Py = y; 
				center.push_back(p);
			}
		}
	}
	R.numinhull = inhull;
	R.centerpoint = center;
}
//�������Ȩ�󶥵�߳�
double GridClass::getheight(Point p1)
{
	double h;
	double r = (R.length + R.width)*0.2;
	double deno = 0, mol = 0;//����̹߳�ʽ�ķ�ĸ������
	for (size_t i = 0; i < Data.size(); i++)
	{
		double d;//����㵽��ɢ�����
		d = sqrt((p1.Px - Data[i].Px)*(p1.Px - Data[i].Px) + (p1.Py - Data[i].Py)*(p1.Py - Data[i].Py));
		if (d < r)
		{
			mol += Data[i].Ph / d;
			deno += 1 / d;
		}
	}
	h = mol / deno;
	return h;
}

//�������
void GridClass::calvertical(int side)
{
	double V=0;//���������
	for (size_t i = 0; i < R.centerpoint.size(); i++)
	{
		//������������
		Point p1, p2, p3, p4;
		p1.Px = R.centerpoint[i].Px + side / 2.0;
		p1.Py = R.centerpoint[i].Py + side / 2.0;
		p2.Px = R.centerpoint[i].Px + side / 2.0;
		p2.Py = R.centerpoint[i].Py - side / 2.0;
		p3.Px = R.centerpoint[i].Px - side / 2.0;
		p3.Py = R.centerpoint[i].Py - side / 2.0;
		p4.Px = R.centerpoint[i].Px - side / 2.0;
		p4.Py = R.centerpoint[i].Py + side / 2.0;
		//��������߳�
		double h1, h2, h3, h4;
		h1 = getheight(p1);
		h2 = getheight(p2);
		h3 = getheight(p3);
		h4 = getheight(p4);
		double vi;//��i�����������
		vi = (h1 + h2 + h3 + h4 - 4 * 9.0)*side*side / 4.0;
		V += vi;
	}
	R.vertical = V;
}

