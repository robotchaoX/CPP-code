#include"MySting.h"



void test()
{
	MyString p1="����";
	cout << p1 << endl;
	//cin >> p1;
	MyString p2=" ";
	p2 = p1;
	p2 = "̹��";
	MyString p4 = "aaaaa";
	MyString p5=" ";
	p5 = p1 + p4;
	cout << p5 << endl;
	cout << p2 << endl;
	if (p1 == p2)
	{
		cout << "�ַ������" << endl;
	}
	else
	{
		cout << "�ַ�������" << endl;
	}

	if (p1 == "aaaaa")
	{
		cout << "�ַ������" << endl;
	}
	else
	{
		cout << "�ַ�������" << endl;
	}

	p1.getSize();
}


void main()
{

	test();
	system("pause");


}
