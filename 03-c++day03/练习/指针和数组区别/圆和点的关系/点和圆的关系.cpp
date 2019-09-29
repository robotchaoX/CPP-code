#include"circle.h"
#include"point.h"


void test()
{

	point p1;
	p1.setX(10);
	p1.setY(10);

	circle p2;
	p2.setm_R(10);
	point p3;
	p3.setX(10);
	p3.setY(0);
	p2.setm_Center(p3);
	p2.opinion(p1);

	cout << "Ô²ÐÄ" << p2.getm_Center().getX()<<" , "<<p2.getm_Center().getY() << endl;
	cout << "µã" << p1.getX() << " , " << p1.getY() << endl;

}


void main()
{
	test();
	system("pause");

}


