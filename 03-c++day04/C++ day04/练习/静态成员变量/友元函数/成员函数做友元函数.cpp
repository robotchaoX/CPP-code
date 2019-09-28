#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Building;

class goodGay
{
public:
	goodGay();
	void vist();
	void visrt2();
private:
	Building *building;

};
class Building
{
	friend void goodGay::vist();
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

Building::Building()
{
	this->m_BedRoom = "卧室";
	this->m_SittingRoom = "客厅";

}

void goodGay::vist()
{
	//出现红线没有问题，可以正确执行
	cout << "好基友正在访问:" << this->building->m_BedRoom << endl;
	cout << "小伙伴正在访问:" << this->building->m_SittingRoom << endl;

}
void goodGay::visrt2()
{
	cout << "你的老爸在客厅:" << this->building->m_SittingRoom << endl;
	//cout << "好基友正在访问:" << this->building->m_BedRoom << endl;

}


void test()
{
	goodGay gg;
	gg.vist();



}






int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}