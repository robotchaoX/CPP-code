#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//声明类
class Building;
class goodGay
{
public:
	goodGay();
	void visit();
private:

	Building *building;
};
//类做友元类
class Building
{
	friend class goodGay;

public:
	Building();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

//函数实现
goodGay::goodGay()
{
	building = new Building;
}

void goodGay::visit()
{
	cout << "好基友正在访问" << this->building->m_BedRoom << endl;
	cout << "好基友正在访问" << this->building->m_SittingRoom << endl;
}

Building::Building()
{	
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}

void test()
{
	goodGay gg;
	gg.visit();
}


int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}