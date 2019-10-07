#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}

};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

//调用doSpeak ，speak函数的地址早就绑定好了，早绑定，静态联编，编译阶段就确定好了地址
//如果想调用猫的speak，不能提前绑定好函数的地址了，所以需要在运行时候再去确定函数地址
//动态联编，写法 doSpeak方法改为虚函数,在父类上声明虚函数，发生了多态
// 父类的引用或者指针 指向 子类对象
void doSpeak(Animal & animal) //Animal & animal = cat
{
	animal.speak();
}
//如果发生了继承的关系，编译器允许进行类型转换

void test01()
{
	Cat cat;
	doSpeak(cat);

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}