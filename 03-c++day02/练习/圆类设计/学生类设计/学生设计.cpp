#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


class student
{
public:

	string	name;
	int age;

};




int main(){

	student p1;
	p1.name = "lllll";
	p1.age = 24;

	cout << "学生姓名：" << p1.name << endl <<"学生年龄：" << p1.age << endl;
	system("pause");
	return EXIT_SUCCESS;
}