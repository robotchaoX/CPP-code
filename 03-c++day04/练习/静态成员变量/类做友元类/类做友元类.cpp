#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//������
class Building;
class goodGay
{
public:
	goodGay();
	void visit();
private:

	Building *building;
};
//������Ԫ��
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

//����ʵ��
goodGay::goodGay()
{
	building = new Building;
}

void goodGay::visit()
{
	cout << "�û������ڷ���" << this->building->m_BedRoom << endl;
	cout << "�û������ڷ���" << this->building->m_SittingRoom << endl;
}

Building::Building()
{	
	this->m_SittingRoom = "����";
	this->m_BedRoom = "����";
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