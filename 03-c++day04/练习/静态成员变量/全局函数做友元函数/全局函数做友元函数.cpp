#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Building
{
	friend void mygoodgay(Building *building);
public:

	Building();

private:

	string m_SittingRoom;
	string  m_BedRoom;

};


Building::Building()
{
	m_SittingRoom = "����";
	m_BedRoom = "����";
}

void mygoodgay(Building *building)
{
	cout << "���ϰ���" << building->m_SittingRoom << endl;
	cout << "���ϰ��������" << building->m_BedRoom << "�������Ͻ��ر�С��Ӱ" << endl;
}


void test()
{
	Building *building = new Building;
	mygoodgay(building);



}



int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}