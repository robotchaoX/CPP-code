#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{

public:
	Person()
	{
	//m_Age=10;//�ڹ��캯���г�ʼ��������������ʱ��������ù��캯��
	
	}
	//����ȫ�־�̬��
	static int m_Age;//����static���Ǿ�̬��Ա���� �Ṳ������
	//��̬��Ա������������������������г�ʼ��
	//��̬��Ա���� Ҳ����Ȩ�޵�
	int m_A;

	//��̬��Ա����
	//�����Է��� ��ͨ��Ա����
	//���Է��ʾ�̬��Ա����
	static void func()
	{
		//m_A=10;
		m_Age = 100;
		cout << "func����" << endl;
	}

	//��ͨ��Ա���� ���Է�����ͨ��Ա������Ҳ���Է��ʾ�̬��Ա����
	void myFunc()
	{
		m_A = 200;
		m_Age = 200;
	}

private:
	static int m_other;//˽��Ȩ�� �����ⲻ�ܷ���
	static void func2()
	{
		cout << "func2����" << endl;
	}

};

//�����ʼ����ʽ ��Ա�������� ������::��Ա������
int Person::m_Age = 0;//�����ʼ��ʵ��
int Person::m_other = 10;//˽�о�̬��Ա�������������ʼ��
//int Person::m_other = 6666;��̬��Ա���������Զ�γ�ʼ��
//int Person::m_Age;

void test()

{

	//1��ͨ�������������
	Person p1;
	p1.m_Age = 10;

	Person p2;
	p2.m_Age = 20;
	cout << "p1 =" << p1.m_Age << endl;
	cout << "p2 =" << p2.m_Age << endl;
	//2��ͨ��������������
	cout << "ͨ����������Age" << Person::m_Age << endl;
	//cout << "ͨ����������˽�г�Ա" << Person::m_other << endl;�޷�����
	//��̬��Ա��������
	p1.func();
	p2.func();
	Person::func();

	//��̬��Ա���� Ҳ����Ȩ��
	//Person::func2();

}




int main(){


	test();

	system("pause");
	return EXIT_SUCCESS;
}