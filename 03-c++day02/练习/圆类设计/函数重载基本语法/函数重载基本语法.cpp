#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��������
//c++�к������ƿ����ظ�
//������ͬһ�������򣬺���������ͬ
//�����Ĳ���������ͬ�������Ͳ�ͬ����˳�� ��ͬ
void func()
{
	cout << "�޲�����func" << endl;
}
void func(int a)
{
	cout << "�в�����func(int a)" << endl;
}

void func(double a)
{
	cout << "�в�����func(double a)" << endl;
}

void func(double a, int b)
{
	cout << "�в�����func(double a, int b)" << endl;
}
//����ֵ��������Ϊ������������
//int func(int a,double b)
//{
//cout<<"�в���defunc(int a,double b)"<<endl;
//return 1;
//}
void test01()
{
//func(1.1,3);
	func(1, 3.14);
}
//��������������Ĭ�ϲ���ʱ��Ҫע��������������
void func2(int a, int b = 10)
{

}
void func2(int a)
{


}
//����������
void test02()
{
	//func2(10);
}

//���õ����ذ汾
void fun3(int &a)//���ñ���Ҫ���Ϸ����ڴ�ռ�
{
	cout << "int &a" << endl;
}
void fun3(const int &a)//constҲ�ǿ���Ϊ�������� int tmp=10 ;const int &a=tmp;
{
	cout << "cout int &a" << endl;

}

void test03()
{
//int a=10;
	//func3(10);

}

int main(){



	system("pause");
	return EXIT_SUCCESS;
}