#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person
{
public:
	void show()
	{
		cout << "构造函数调用" << endl;
	}
	void showAge()
	{
		cout << "age=" << age << endl;
	
	
	}
int age;

};
void test()
{

	Person *p1=NULL;
	p1->show();
	//p1->showAge();
}





int main(){


	test();

	system("pause");
	return EXIT_SUCCESS;
}