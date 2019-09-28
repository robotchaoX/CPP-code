#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class arr
{

public:
	arr()
	{
	
		cout << "默认构造函数" << endl;
	}
	
	arr(int a)
	{
		cout << "有参构造函数" << endl;
	}

	arr(arr&ar)

	{
		cout << "拷贝构造函数" << endl;
	}

	~arr()
	{
		cout << "析构构造函数" << endl;
	}

	int age;

};

void test()

{
	arr(100);//匿名对象 匿名对象特点是，如果编译器发现对象是匿名的，那么在这行代码结束后就释放这个对象
	//不能用拷贝构造函数 初始化匿名对象

	arr a1 = 100;
	//arr a1;
	//arr a1(10);
	//a1.age = 10;
	
	arr a2(a1);


}




int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}