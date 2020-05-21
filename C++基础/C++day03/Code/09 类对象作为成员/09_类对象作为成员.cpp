#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Phone {
  public:
    Phone() {
        cout << "Phone的默认构造函数调用" << endl;
    }
    Phone(string name) {
        cout << "Phone的有参构造调用" << endl;
        m_PhoneName = name;
    }

    ~Phone() {
        cout << "Phone的析构函数调用" << endl;
    }

  public:
    string m_PhoneName;
};

class Game {
  public:
    Game() {
        cout << "Game的默认构造函数调用" << endl;
    }
    Game(string name) {
        cout << "Game的有参构造调用" << endl;
        m_GameName = name;
    }
    ~Game() {
        cout << "Game的析构函数调用" << endl;
    }

  public:
    string m_GameName;
};

class Person {
  public:
    Person() {
        cout << "Person的默认构造函数调用" << endl;
    }

    Person(string name, string phoneName, string gameName) : m_Name(name), m_Phone(phoneName), m_Game(gameName) {
        cout << "Person的有参构造调用" << endl;
    }

    void playGame() {
        cout << m_Name << " 拿着《" << m_Phone.m_PhoneName << "》牌手机 ，玩着《" << m_Game.m_GameName << "》游戏"
             << endl;
    }

    ~Person() {
        cout << "Person的析构函数调用" << endl;
    }

  public:
    string m_Name; //姓名
    // 类对象作为类成员时候,类组合
    Phone m_Phone; //手机
    Game m_Game; //游戏
};

//类对象作为类成员时候，构造顺序先将类对象一一构造，然后构造自己，析构的顺序是相反的
void test01() {
    // 先构造类成员对象Phone Game,再构造自己
    cout << "--- 先构造包含的类成员对象再构造自己，析构相反" << endl;
    Person p("狗蛋", "苹果", "切水果");
    p.playGame();
    cout << "--- 析构顺序相反" << endl;
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}