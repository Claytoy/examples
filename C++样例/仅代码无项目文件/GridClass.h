#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>

#define pi 3.1415926
using namespace std;

//点信息
struct Point
{
	string Pname;
	double Px;
	double Py;
	double Ph;
	double Pangle;//到基点的夹角
};

struct Error
{
	int efile;//文件打开异常为1
};
struct Result
{
	vector<Point> hull;//凸包点集
	Point fixedpoint;//矩形左下角
	double length;//长边长度
	double width;//短边长度
	int numlength;//长边的格子数量
	int numwidth;//短边的格子数量
	int numinhull;//在凸包内格网的数量
	vector<Point> centerpoint;//在凸包内的格网中心点  ***无需显示
	double vertical;//凸包体积
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

