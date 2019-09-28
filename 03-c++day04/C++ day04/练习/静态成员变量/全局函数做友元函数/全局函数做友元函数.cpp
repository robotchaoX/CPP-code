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
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

void mygoodgay(Building *building)
{
	cout << "你老爸在" << building->m_SittingRoom << endl;
	cout << "你老爸在向你的" << building->m_BedRoom << "赶来，赶紧关闭小电影" << endl;
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