#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	//普通成员函数可以访问static和non-static成员属性
	void changeParaml(int param)
	{
		mParam = param;
		sNum = param;
	}
	static void changeParam2(int param)
	{
		//mParam=param;
		sNum = param;
	}


private:
	static void changeParam3(int param)
	{
		//mParam=parm;//无法访问
		sNum = param;
	}
public:
	int mParam;
	static int sNum;

};
//静态成员属性类外初始化
int Person::sNum = 0;

int main(){

	Person::changeParam2(100);
	//

	system("pause");
	return EXIT_SUCCESS;
}