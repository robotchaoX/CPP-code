
#define  _CRT_SECURE_NO_WARNINGS
#pragma once 
#include<iostream>
#include<string>


using namespace std;

class strarr
{
public:

	//字符串长度
	int getstrsize();
	//重载=运算符
	strarr &operator=(strarr & str);
	strarr & operator=(const char * str);
	//重载[]运算符
	char operator[](int i);
	//重载==运算符
	bool operator==(strarr & str);
	bool operator==(char *str);
	//重载+
	strarr strarr::operator+(const strarr &arr);
	strarr strarr::operator+(const char *str);
	//拷贝构造
	strarr(const strarr &p);
	//有参构造
	strarr(const char *p);

	//析构函数
	~strarr();

	char *m_strarr;
	int strsize;
};

