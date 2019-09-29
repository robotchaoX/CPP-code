#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//设置年龄
	void setAge(int age)
	{
		if (age < 0 || age>100)
		{
			cout << "你个老不死的" << endl;
		}
		m_Age = age;
	}
	//获取年龄 读权限
	int getAge()
	{
		return m_Age;
	}

	string getName()
	{
		return m_Name;
	
	}


	void setName(string name)
	{
		m_Name = name;
	}

	string getLover()
	{
		return m_lover;
	}

	//只写情人
	void setLover(string lover)
	{
		m_lover = lover;
	}


private://类外不可访问，类内可以访问
	int m_Age = 0;
	string m_Name;
	string m_lover;


};


void test01()
{
	Person p1;
	p1.setName("小青");
	cout << "p1的姓名" << p1.getName() << endl;
	p1.setAge(120);
	cout << "p1的年龄" << p1.getAge() << endl;
	p1.setLover("仓井");
	cout << "p1的情人" << p1.getLover() << endl;

}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}