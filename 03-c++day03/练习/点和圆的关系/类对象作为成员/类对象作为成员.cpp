#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Phone
{
public:
	Phone()
	{
		cout << "�ֻ���Ĭ�Ϲ��캯������" << endl;
	}
	Phone(string name)
	{
		cout << "�ֻ����вι������" << endl;
		m_PhoneName = name;
	}

	~Phone()
	{
		cout << "�ֻ���������������" << endl;
	}

	string m_PhoneName;
};

class Game
{
public:
	Game()
	{
		cout << "Game��Ĭ�Ϲ��캯������" << endl;
	
	}
	Game(string name)
	{
		cout << "Game���вι������" << endl;
		m_GameName = name;
	}
	~Game()
	{
		cout << "Game��������������" << endl;
	}
	string m_GameName;

};


class Person
{
public:
	Person()
	{
		cout << "Person�Ĺ��캯������" << endl;
	}
	//��ʼ���б�
	Person(string name, string phoneName, string gameName) :m_Name(name), m_Phone(phoneName), m_Game(gameName)
	{
		cout << "Person���вι������" << endl;
	}
	void playGame()
	{
		cout << m_Name << "���š�" << m_Phone.m_PhoneName << "�����š�" << m_Game.m_GameName << "����Ϸ" << endl;
	}
	~Person()
	{
		cout << "Person��������������" << endl;
	
	}

	string m_Name;//����
	Phone m_Phone;//�ֻ�
	Game m_Game;//��Ϸ
};

//�������Ϊ���Աʱ�򣬹���˳���ֽ������һһ���죬Ȼ�����Լ���������˳�����෴��
void test()
{
	Person p{ "����", "����", "����" };
	p.playGame();
	
}


int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}