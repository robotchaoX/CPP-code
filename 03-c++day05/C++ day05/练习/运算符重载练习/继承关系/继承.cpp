#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class base
{
public:
	base(){}


	void show()
	{
		cout << "base�е�show" << endl;
	}
};


class son :public base
{
public:
	void show()
	{
		cout << "son�е�show" << endl;
	}
};





int main(){

	base p1;
	p1.show();
	son p2;
	p2.show();
	p2.base::show();

	system("pause");
	return EXIT_SUCCESS;
}