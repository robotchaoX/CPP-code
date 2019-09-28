#include<iostream>
void test()
{
	using namespace std;
	//newÊý×é
	double *p3 = new double[3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;			//.\n»»ÐÐ
	cout << "p3[1] is " << p3[1] << "\n";
	p3 = p3 + 1;
	cout << "Now p3[0] is " << p3[0] << " and ";
	cout << "p3[1] is " << p3[1] << ".\n";
	p3 = p3 - 1;

	delete[]p3;

}


void test02()
{




}