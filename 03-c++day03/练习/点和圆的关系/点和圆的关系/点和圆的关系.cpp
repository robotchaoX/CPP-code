#include"circle.h"
#include"point.h"


//设计一个圆形类（AdvCircle），和一个点类（Point），计算点和圆的关系。
//假如圆心坐标为x0, y0, 半径为r，点的坐标为x1, y1：
//1）点在圆上：(x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0) == r*r
//2）点在圆内：(x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0) < r*r
//3）点在圆外：(x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0) > r*r

//利用全局函数 判断点和圆的关系
void isInCircle(Circle &c, Point &p)
{
	//获取圆心和点的距离 的平方

	int distame = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY())*(c.getCenter().getY() - p.getY());
	int rDistance = c.getR()*c.getR();
	if (rDistance == distame)
	{
		cout << "点在圆上" << endl;
	}
	else if (rDistance < distame)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}

}



void test()
{
	
	//定义一个点
	Point d1;
	d1.setX(10);
	d1.setY(6);
	//定义一个圆
	Circle p1;
	Point d2;
	d2.setX(10);
	d2.setY(0);
	p1.setCenter(d2);
	p1.setR(10);
	
	p1.isInCircleByClass(d1);

	isInCircle(p1, d1);


}

void main()
{

	test();
	system("pause");
}