#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
	friend  ostream & operator<<(ostream &cout, Person &p1);
	friend Person & operator++(Person &p);
public:
	Person()
	{
		m_A = 0;
	};

	Person & operator++()
	{
		this->m_A++;
		return *this;
	}
	//���üӼӷ��ص���һ��ֵ�����üӼ�Ҫ��һ��ռλ
	//���üӼ��ȱ�������ֵ
	Person operator++(int)
	{
		Person temp = *this;
		this->m_A++;
		return temp;
	}



private:
	int m_A;
};

Person & operator++(Person &p)
{
	p.m_A++;
	return p;
}



//����<<�����
 ostream & operator<<(ostream &cout, Person &p1)
{
	cout << p1.m_A;
 return cout;
}



 void test()
 {
	
	 Person p1;
	 
	 cout << p1++<<endl;
	 
	 //cout << ++p1;
 
 
 }





int main(){
	test();


	system("pause");
	return EXIT_SUCCESS;
}