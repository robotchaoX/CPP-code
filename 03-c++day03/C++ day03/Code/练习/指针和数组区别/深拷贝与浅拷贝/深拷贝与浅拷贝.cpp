#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "Ĭ�ϵĹ��캯������" << "\n";
	}
	//��ʼ������
	Person(char *name, int age)
	{
		m_Name = (char *)malloc(strlen(name) + 1);
		strcpy(m_Name, name);
		m_age = age;
		cout << "�вι��캯������" << endl;
	}
	//����const���η�����ֻ�� &p����
	Person(const Person &p)//���������׼��ʽ�����������޸���
	{
		m_age = p.m_age;
		m_Name = (char *)malloc(strlen(p.m_Name) + 1);
		strcpy(m_Name, p.m_Name);
		cout << "�������캯������" << endl;
	}
	~Person()
	{
		cout << "������������" << endl;
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
	Person p1("����", 10);
	Person p2(p1);

	cout << "p1��������" << p1.m_Name << "p1�����䣺" << p1.m_age << endl;
}





int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}