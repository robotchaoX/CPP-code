#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	//���캯��д��
	//��������ͬ��û�з���ֵ����дvoid�����Է�������(�����в���)
	//���캯���б������Զ����ã��������ֶ�������ֻ�����һ��
	Person()
	{
		cout << "���캯������" << endl;
	
	}
	Person(int a)
	{
		cout << "���캯������(int a)" << endl;
	}
	//��������д��
	//��������ͬ ����ǰ���һ������ "~",Ҳû�з���ֵ����дvoid����������
	//�Զ����ã�ֻ�����һ��
	~Person()
	{
		cout << "������������" << endl;
	
	}

};

void test01()
{
	Person p1(1);//Ĭ�ϵ����˹������������ϵͳ�ṩ��������ʵ�ֵĺ���

}

int main(){

	//test01();
	Person p1(1);//������������ǿ����������������ã�ֻ��main���������Ż����
	
	system("pause");
	return EXIT_SUCCESS;
}