#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "默认的构造函数调用" << "\n";
	}
	//初始化属性
	Person(char *name, int age)
	{
		m_Name = (char *)malloc(strlen(name) + 1);
		strcpy(m_Name, name);
		m_age = age;
		cout << "有参构造函数调用" << endl;
	}
	//加上const修饰符就是只读 &p引用
	Person(const Person &p)//拷贝构造标准格式，复制它不修改它
	{
		m_age = p.m_age;
		m_Name = (char *)malloc(strlen(p.m_Name) + 1);
		strcpy(m_Name, p.m_Name);
		cout << "拷贝构造函数调用" << endl;
	}
	~Person()
	{
		cout << "析构函数调用" << endl;
		if (m_Name != NULL)
		{
			free(m_Name);
			m_Name = NULL;
		}
	}



	char *m_Name;
	int m_age;

};
void test()
{
	Person p1("赵信", 10);
	Person p2(p1);

	cout << "p1的姓名：" << p1.m_Name << "p1的年龄：" << p1.m_age << endl;
}





int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}