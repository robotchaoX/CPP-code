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
	this->m_BedRoom = "����";
	this->m_SittingRoom = "����";

}

void goodGay::vist()
{
	//���ֺ���û�����⣬������ȷִ��
	cout << "�û������ڷ���:" << this->building->m_BedRoom << endl;
	cout << "С������ڷ���:" << this->building->m_SittingRoom << endl;

}
void goodGay::visrt2()
{
	cout << "����ϰ��ڿ���:" << this->building->m_SittingRoom << endl;
	//cout << "�û������ڷ���:" << this->building->m_BedRoom << endl;

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