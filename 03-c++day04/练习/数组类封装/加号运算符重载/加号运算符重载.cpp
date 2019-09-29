#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//成员函数
class plusPerson
{

public:
	plusPerson(){ m_A = 0; m_B = 0; };

	plusPerson(int a,int b):m_A(a),m_B(b){};
	
	//重载+号
	//plusPerson operator + (plusPerson &p)
	//{
	//	plusPerson temp;
	//
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//
	//	return temp;
	//}

	int m_A;
	int m_B;

};


plusPerson operator + (plusPerson &p1, plusPerson &p2)
{
	
	plusPerson temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;

	return temp;
}


plusPerson operator + (plusPerson &p1, int a)
{

	plusPerson temp;
	temp.m_A = p1.m_A + a;
	temp.m_B = p1.m_B + a;

	return temp;
}
//参数太多,报错
//plusPerson operator + (plusPerson &p1, int a, int b)




void test()
{
	plusPerson p1(10,10);
	plusPerson p2(10,10);


	//p1.m_A = 10;
	//p1.m_B = 10;

	//p2.m_A = 10;
	//p2.m_B = 10;

	plusPerson temp = p1 + p2;
	plusPerson p4 = p1 + 666;
	cout << "temp.m_A:" << temp.m_A << " temp.m_B:" << temp.m_B << endl;
	cout << "temp.m_A:" << p4.m_A << " temp.m_B:" << p4.m_B << endl;
}


int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}