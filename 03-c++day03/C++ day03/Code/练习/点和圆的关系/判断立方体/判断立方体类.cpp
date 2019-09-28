#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Cub
{
public:

	void getL(int a){ c_L = a; };
	void getW(int b){ c_W = b; };
	void getH(int c){ c_H = c; };

	int setL(){ return c_L; };
	int setW(){ return c_W; };
	int setH(){ return c_H; };

	void cuds()
	{  
		int s = (c_L*c_W + c_L*c_H + c_W*c_H) * 2;
		cout << "立方体的面积为" << s << endl;
		
	};
	void cudv()
	{ 
		int v = c_H*c_L*c_W;
		cout << "立方体的体积为" << v << endl;
	};

	void conpare(Cub & d1)
	{
		if (d1.s)
	
	
	}




private:
	int c_L, c_W, c_H;


};

void test()
{
	Cub p1;
	p1.getL(10);
	p1.getW(10);
	p1.getH(10);
	Cub p2;
	p2.getL(10);
	p2.getW(10);
	p2.getH(10);

	p1.cuds();
	p2.cuds();

	p1.cudv();
	p2.cudv();

		if (p1.setH() == p2.setH() && p1.setL() == p2.setL() && p1.setW() == p2.setW())
	{
		cout << "p1与p2相等" << endl;
	}
	else
	{
		cout << "p1与p2不等" << endl;
	}
		



}




int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}