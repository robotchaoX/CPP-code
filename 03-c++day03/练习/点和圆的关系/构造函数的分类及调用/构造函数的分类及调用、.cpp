#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//����
//���ղ������з��� 1���޲ι��캯��(Ĭ�Ϲ��캯�� 2���вι��캯��
//�������ͽ��з��� 1����ͨ���캯�� 2���������캯��
class Person
{
public://�������������д��public�²ſ��Ե���
	Person()//Ĭ�� ���޲ι��캯��
	{
		cout << "Ĭ�Ϲ��캯������" << endl;
	
	}
	Person(int a)
	{
		cout << "�вκ����͵���" << endl;

	
	}
	Person(const Person &p)//�������캯��
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
void test()
{
	//���캯�����÷�ʽ
	//���ŵ���
	//Person p1(1);//�в�
	//p1.m_Age = 10;
	//Person p2(p1);
	//cout << "p2������" << p2.m_Age << endl;
	//Person p3;//Ĭ�Ϲ��캯�� ��Ҫ��() person p3();��������Ϊ�����Ǻ���������
	//��ʾ������
	//Person p4 = Person(100);//��Person p4(100);�ȼ�
	//Person p5 = Person(p4);//��Person p5(p4);�ȼ�
	//Person(100);//���������ص�����������������˶����������ģ���ô���д����������ͷ��������
	//�����ÿ������캯�� ��ʼ����������
	//Person p6 = Person(p5);//���д����ֵ����������Ϊ��д�� Person p5��������������д����ֵ����ô����

	Person p7 = 100;//�൱�������Person p7 = Person(100),��ʽ����ת��
	//�൱�� Person p8=Person(p7);
}




int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}