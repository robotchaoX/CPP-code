#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class chairMan
{

private:
	chairMan()
	{
		cout << "���ù��캯��������ϯ" << endl;
	}

	chairMan(const chairMan & cha){};
public:

    static chairMan * getInstance()
	{
		return singMan;
	}


private:
	static chairMan *singMan;
};

chairMan *chairMan::singMan = new chairMan;


void test()
{
	chairMan * p1 = chairMan::getInstance();
	

}




int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}