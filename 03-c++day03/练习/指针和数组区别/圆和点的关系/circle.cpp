#include"circle.h"

void circle::setm_R(int a)
{
	m_R = a;
}

void circle::setm_Center(point p)
{
	m_Center =p;
}

	//���ذ뾶
int circle::getm_R(){ return m_R; };
	//����Բ��
point circle::getm_Center(){ return m_Center; };
	//���ó�Ա�����ж����Բ�Ĺ�ϵ
	void circle::opinion(point &p)
	{
		int mr = (p.getX() - m_Center.getX()) * (p.getX() - m_Center.getX()) + (p.getY() - m_Center.getY())*(p.getY() - m_Center.getY());
		int RR = m_R*m_R;
		if (RR == mr)
		{
			cout << "����Բ��" << endl;
		}
		else if (mr < RR)
		{
			cout << "����Բ��" << endl;
		}
		else
		{
			cout << "����Բ��" << endl;
		}
	}



