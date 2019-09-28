#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class student
{
public:
	void getname(string a){ name = a; };
	void getage(int b){ age = b; };


	int setage(){ return age; };
	string setname(){ return name; };




private:
	string name;
	int age;



};



void test()
{
	student p1;
	string a = "sanshu";
	p1.getname(a);
	p1.getage(19);

	cout << p1.setname() << " " << p1.setage() << endl;


}



int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}