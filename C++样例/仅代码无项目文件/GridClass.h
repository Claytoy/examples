#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>

#define pi 3.1415926
using namespace std;

//����Ϣ
struct Point
{
	string Pname;
	double Px;
	double Py;
	double Ph;
	double Pangle;//������ļн�
};

struct Error
{
	int efile;//�ļ����쳣Ϊ1
};
struct Result
{
	vector<Point> hull;//͹���㼯
	Point fixedpoint;//�������½�
	double length;//���߳���
	double width;//�̱߳���
	int numlength;//���ߵĸ�������
	int numwidth;//�̱ߵĸ�������
	int numinhull;//��͹���ڸ���������
	vector<Point> centerpoint;//��͹���ڵĸ������ĵ�  ***������ʾ
	double vertical;//͹�����
};
class GridClass
{
public:
	GridClass();
	~GridClass();
	vector<Point> Data;
	Error E;
	Result R;

	void readfile(string name);
	void gethull();
	void creategrid(int side);
	double getheight(Point p1);
	void calvertical(int side);
};

