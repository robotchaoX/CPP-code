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
	cout << "好基友正在访问:" << building->m_BedRoom << endl;
	cout << "好基友正在访问:" << building->m_SittingRoom << endl;
}

Building::Building()
{
	this->m_BedRoom = "卧室";
	this->m_SittingRoom = "客厅";
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