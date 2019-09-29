#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include"test.h"
using namespace std;
//声明show函数是在外部，且以C语言方式解析
extern "C" void show();

int main()

{
	show();
	system("pause");
	return EXIT_SUCCESS;
}