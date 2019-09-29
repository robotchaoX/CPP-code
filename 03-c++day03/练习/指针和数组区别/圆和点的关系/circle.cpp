#include"circle.h"

void circle::setm_R(int a)
{
	m_R = a;
}

void circle::setm_Center(point p)
{
	m_Center =p;
}

	//返回半径
int circle::getm_R(){ return m_R; };
	//返回圆心
point circle::getm_Center(){ return m_Center; };
	//调用成员函数判读点和圆的关系
	void circle::opinion(point &p)
	{
		int mr = (p.getX() - m_Center.getX()) * (p.getX() - m_Center.getX()) + (p.getY() - m_Center.getY())*(p.getY() - m_Center.getY());
		int RR = m_R*m_R;
		if (RR == mr)
		{
			cout << "点在圆上" << endl;
		}
		else if (mr < RR)
		{
			cout << "点在圆内" << endl;
		}
		else
		{
			cout << "点在圆外" << endl;
		}
	}



