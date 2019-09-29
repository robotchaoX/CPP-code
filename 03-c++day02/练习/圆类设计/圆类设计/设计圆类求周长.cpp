#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

const double pi = 3.14;

class Circle
{
	//私有的
	private:
	//公有的
	public:

	double calculateZC()
	{
		return 2 * pi * m_R;
	}


	void setR(int r)

	{
		m_R = r;
	}

	int m_R;
};

class student
{
private:
	string name;

public:
	int stuage(int r)
	{
		return 2017 - r;
	}

	int age;

};






int main(){

	//Circle c1;
	//c1.setR(10);
	student p1;
	int i=p1.stuage(1990);
	p1.
	cout << "年龄为：" << i << endl;

	//cout << "c1的周长为：" << c1.calculateZC() << endl;

	system("pause");
	return EXIT_SUCCESS;
}