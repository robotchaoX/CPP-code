#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Building;
class goodGay
{
public:
	goodGay();
	void show();
private:

	Building *building;
};

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

goodGay::goodGay()
{

	building = new Building;
}

void goodGay::show()
{
	cout << "�û������ڷ���:" << building->m_BedRoom << endl;
	cout << "�û������ڷ���:" << building->m_SittingRoom << endl;
}

Building::Building()
{
	this->m_BedRoom = "����";
	this->m_SittingRoom = "����";
}















void test()
{
	goodGay gg;
	gg.show();


}

int main(){
	test();


	system("pause");
	return EXIT_SUCCESS;
}