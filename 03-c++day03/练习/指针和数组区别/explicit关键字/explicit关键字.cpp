#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//
class MyString
{
public:
	explicit MyString(int n)
	{
		cout << "MySting(int n)!" << endl;
	}
	MyString(const char *str)
	{
		cout << "Mysrintg(cont char *str)" << endl;	
	}
};





int main(){

	//explicit 关键字是让意思有不清晰的不能通过编译
	//MyString str1 = 1;
	MyString str2(10);
	MyString str3 = "abcd";
	MyString str4("abcd");

	system("pause");
	return EXIT_SUCCESS;
}