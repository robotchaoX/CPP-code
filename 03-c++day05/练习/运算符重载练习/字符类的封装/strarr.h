
#define  _CRT_SECURE_NO_WARNINGS
#pragma once 
#include<iostream>
#include<string>


using namespace std;

class strarr
{
public:

	//�ַ�������
	int getstrsize();
	//����=�����
	strarr &operator=(strarr & str);
	strarr & operator=(const char * str);
	//����[]�����
	char operator[](int i);
	//����==�����
	bool operator==(strarr & str);
	bool operator==(char *str);
	//����+
	strarr strarr::operator+(const strarr &arr);
	strarr strarr::operator+(const char *str);
	//��������
	strarr(const strarr &p);
	//�вι���
	strarr(const char *p);

	//��������
	~strarr();

	char *m_strarr;
	int strsize;
};

