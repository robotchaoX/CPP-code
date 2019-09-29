#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Phone
{
public:
	Phone()
	{
		cout << "手机的默认构造函数调用" << endl;
	}
	Phone(string name)
	{
		cout << "手机的有参构造调用" << endl;
		m_PhoneName = name;
	}

	~Phone()
	{
		cout << "手机的析构函数调用" << endl;
	}

	string m_PhoneName;
};

class Game
{
public:
	Game()
	{
		cout << "Game的默认构造函数调用" << endl;
	
	}
	Game(string name)
	{
		cout << "Game的有参构造调用" << endl;
		m_GameName = name;
	}
	~Game()
	{
		cout << "Game的析构函数调用" << endl;
	}
	string m_GameName;

};


class Person
{
public:
	Person()
	{
		cout << "Person的构造函数调用" << endl;
	}
	//初始化列表
	Person(string name, string phoneName, string gameName) :m_Name(name), m_Phone(phoneName), m_Game(gameName)
	{
		cout << "Person的有参构造调用" << endl;
	}
	void playGame()
	{
		cout << m_Name << "拿着《" << m_Phone.m_PhoneName << "》玩着《" << m_Game.m_GameName << "》游戏" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	
	}

	string m_Name;//姓名
	Phone m_Phone;//手机
	Game m_Game;//游戏
};

//类对象作为类成员时候，构造顺序现将类对象一一构造，然后构造自己，机构的顺序是相反的
void test()
{
	Person p{ "马云", "魅族", "大富翁" };
	p.playGame();
	
}


int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}