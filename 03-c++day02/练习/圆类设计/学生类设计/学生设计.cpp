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

	cout << "ѧ��������" << p1.name << endl <<"ѧ�����䣺" << p1.age << endl;
	system("pause");
	return EXIT_SUCCESS;
}