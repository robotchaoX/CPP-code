#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	//��ľ�̬��Ա����
	static int sNum;
private:
	static int sOther;
};
//�����ʼ������ʼ��ʱ����static
int Person::sNum = 0; 
int Person::sOther = 0;


int main(){

	//1��ͨ������ֱ�ӷ���
	Person::sNum = 100;
	cout << "Person::sNum:" << Person::sNum << endl;



	//2��ͨ������������
	Person p1, p2;
	p1.sNum = 200;
	cout << "p1.sNum" << p1.sNum << endl;
	cout << "p2.sNum" << p2.sNum << endl;


	//3����̬��ԱҲ�з���Ȩ�ޣ����ⲻ�ܷ���˽�г�Ա
	//cout << "Peeson::s0ther" << Person::sOther << endl;���ɷ���
	Person p3;
	//cout << "p3.sOther" << p3.sOther << endl;���ɷ���



	system("pause");
	return EXIT_SUCCESS;
}