#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		this->age = 100;
	}
	int age;

};

class One : public virtual Base
{

};
class Two : public virtual Base
{

};


class ther :public One, public Two
{
public:
	void show()
	{
		cout<<this->age<<endl;	
	}
};



void test()
{


	//Base v1;
	//
	//One O1;
	//Two T1;
	//
	ther p1;
	//cout << O1.Base::age << endl;
	//cout << v1.Base::age << endl;
	//cout << p1.Base::age << endl;
	p1.One::age = 666;
	p1.show();

	

	cout << "One:"<<p1.One::age << endl;
	cout << "Two:"<<p1.Two::age << endl;

	cout << p1.Base::age << endl;

}




int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}