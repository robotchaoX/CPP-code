#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//��������
	void setAge(int age)
	{
		if (age < 0 || age>100)
		{
			cout << "����ϲ�����" << endl;
		}
		m_Age = age;
	}
	//��ȡ���� ��Ȩ��
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

	//ֻд����
	void setLover(string lover)
	{
		m_lover = lover;
	}


private://���ⲻ�ɷ��ʣ����ڿ��Է���
	int m_Age = 0;
	string m_Name;
	string m_lover;


};


void test01()
{
	Person p1;
	p1.setName("С��");
	cout << "p1������" << p1.getName() << endl;
	p1.setAge(120);
	cout << "p1������" << p1.getAge() << endl;
	p1.setLover("�־�");
	cout << "p1������" << p1.getLover() << endl;

}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}