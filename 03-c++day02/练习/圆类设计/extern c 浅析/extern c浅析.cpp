#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include"test.h"
using namespace std;
//����show���������ⲿ������C���Է�ʽ����
extern "C" void show();

int main()

{
	show();
	system("pause");
	return EXIT_SUCCESS;
}