#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

struct Person
{
	char mName[64];
	int mAge;
	void PersonEat()
	{
		cout << mName << "���˷�" << endl;
	}

};

struct Dog
{
	char mName[64];
	int mAge;
	void DogEat()
	{
		cout << mName << "�Թ���" << endl;
	}

};


//c++�еķ�װ���ϸ�����ת����⣬�����Ժ���Ϊ�󶨵�һ��
//1�����Ժ���Ϊ��Ϊһ����������ʾ�����е�����
//2������Ȩ��public����Ȩ�� protected ����Ȩ�� private ˽��Ȩ��
void test01()
{
	Person p1;
	strcpy(p1.mName, "����");
	p1.PersonEat();
	//p1.DogEat();

}
//struct ��class��һ����˼,Ψһ�Ĳ�ͬ Ĭ��Ȩ�ޣ�struct��public������classĬ��Ȩ����private
class Animal
{
	


};
int main(){


	test01();
	system("pause");
	return EXIT_SUCCESS;
}