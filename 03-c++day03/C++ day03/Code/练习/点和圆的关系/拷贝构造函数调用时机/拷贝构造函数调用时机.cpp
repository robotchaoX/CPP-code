#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
	
		cout << "Ĭ�Ϲ��캯������" << endl;	
	}
	Person(int a)
	{
		cout << "�вι��캯������" << endl;
	}
	Person(const Person &p)
	{
		m_Age = p.m_Age;
		cout << "�������캯������" << endl;
	}
	~Person()
	{
		cout << "������������" << endl;
	
	}

	int m_Age;
};


//����������õ�ʱ��
//1�����Դ����õĶ�������ʼ���µĶ���
void test01()
{
	Person p1;
	p1.m_Age = 10;
	Person p2(p1);
}
//2����ֵ���ݵķ�ʽ������������ֵ
void doWork(Person p1)//Person p1 = Person(p)
{

}

void test02()
{
	Person p;
	p.m_Age = 10;
	doWork(p);
}

//3����ֵ��ʽ���ؾֲ�����
Person doWork2()
{
	Person p1;
	return p1;
}

void test03()
{
	Person p = doWork2();
}
//Release���Ż���ʲô����
/*
Person p;������Ĭ�Ϲ���
doWork2(p);
void doWork2(Person &p)
{
Person p1//����Ĭ�Ϲ���

}

*/


int main(){

	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}