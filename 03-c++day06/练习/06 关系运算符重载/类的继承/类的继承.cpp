#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//�����̳и���ĳ�Ա���ԣ���Ա����
//���಻��̳и���Ĺ��캯������������
//ֻ�и����Լ�֪���Լ����캯�� �������������ԣ������಻֪��
class Base
{
public:
	Base()
	{
		int age;
		cout << "����Ĺ��캯������" << endl;
	}
	~Base()
	{
		cout << "�����������������" << endl;
	}
};

class Son :public Base
{
public:
	Son()
	{
		cout << "���๹�캯������" << endl;
	}
	~Son()
	{
		cout << "����������������" << endl;
	
	}


};







class Father
{
public:
	 
	Father(int a)
	{
	
		this->age = a;
		cout << "�����вι������" << endl;
		cout << age << endl;
	}
	int age; 

};

class Son :public Father
{

public:
	Son(int a) :Father(a)
	{
		cout << "���๹�����" << endl;
	}


		//int age;
};

void test()
{
	Son p1(10);
	
}





int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}