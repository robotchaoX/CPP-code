#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

struct Person
{
	char mName[64];
	int mAge;
	void PersonEat()
	{
		cout << mName << "吃人饭" << endl;
	}

};

struct Dog
{
	char mName[64];
	int mAge;
	void DogEat()
	{
		cout << mName << "吃狗粮" << endl;
	}

};


//c++中的封装，严格类型转换检测，让属性和行为绑定到一起
//1、属性和行为作为一个整体来表示生活中的事物
//2、控制权限public公有权限 protected 保护权限 private 私有权限
void test01()
{
	Person p1;
	strcpy(p1.mName, "老王");
	p1.PersonEat();
	//p1.DogEat();

}
//struct 和class是一个意思,唯一的不同 默认权限，struct是public，但是class默认权限是private
class Animal
{
	


};
int main(){


	test01();
	system("pause");
	return EXIT_SUCCESS;
}