#pragma once
#include<iostream>
#include"point.h"
using namespace std;

//圆类
class circle
{
public:
	void setm_R(int a);
	void setm_Center(point p);
	 
	//返回半径
	int getm_R();
	//返回圆心
	point getm_Center();
	//调用成员函数判读点和圆的关系
	void opinion(point &p);

	

private:

	point m_Center;
	int m_R;

};




