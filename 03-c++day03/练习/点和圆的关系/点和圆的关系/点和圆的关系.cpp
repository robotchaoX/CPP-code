#include"circle.h"
#include"point.h"


//���һ��Բ���ࣨAdvCircle������һ�����ࣨPoint����������Բ�Ĺ�ϵ��
//����Բ������Ϊx0, y0, �뾶Ϊr���������Ϊx1, y1��
//1������Բ�ϣ�(x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0) == r*r
//2������Բ�ڣ�(x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0) < r*r
//3������Բ�⣺(x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0) > r*r

//����ȫ�ֺ��� �жϵ��Բ�Ĺ�ϵ
void isInCircle(Circle &c, Point &p)
{
	//��ȡԲ�ĺ͵�ľ��� ��ƽ��

	int distame = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY())*(c.getCenter().getY() - p.getY());
	int rDistance = c.getR()*c.getR();
	if (rDistance == distame)
	{
		cout << "����Բ��" << endl;
	}
	else if (rDistance < distame)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}

}



void test()
{
	
	//����һ����
	Point d1;
	d1.setX(10);
	d1.setY(6);
	//����һ��Բ
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