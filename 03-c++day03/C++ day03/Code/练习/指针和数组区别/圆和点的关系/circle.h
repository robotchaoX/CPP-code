#pragma once
#include<iostream>
#include"point.h"
using namespace std;

//Բ��
class circle
{
public:
	void setm_R(int a);
	void setm_Center(point p);
	 
	//���ذ뾶
	int getm_R();
	//����Բ��
	point getm_Center();
	//���ó�Ա�����ж����Բ�Ĺ�ϵ
	void opinion(point &p);

	

private:

	point m_Center;
	int m_R;

};




