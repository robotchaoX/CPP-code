#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//�����������(Cube)��
//�������������(2 * a*b + 2 * a*c + 2 * b*c)�����(a * b * c)��
//�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ���ȡ�
//��Ա����
class cube
{
public:

	void setL(int a){ L = a; };
	void setW(int b){ W = b; };
	void setT(int c){ T = c; };

	int getL(){ return L; };
	int getW(){ return W; };
	int getT(){ return T; };

	int cubicS(){ return (L* W + L * T + W * T) * 2; };

	int cubicB(){ return L * W * T; };

	bool compare(cube &c)
	{
		if (getL() == c.getL() && getW() == c.getW() && getT() == c.getT())
		{
			return true;
		}
		else
		{
			return false;
		}
	
	}

	
private:

	int L, W, T;
};


bool compare(cube &c1, cube &c2)
{

	if (c1.getL() == c2.getL() && c1.getT() == c2.getT() && c1.getW() == c2.getW())
	{
		return true;
	}
	else
	{
		return false;
	}

}



void test01()
{
	cube c1, c2;

	c1.setL(2);
	c1.setT(2);
	c1.setW(2);
			
	c2.setL(12);
	c2.setT(12);
	c2.setW(12);

	cout << "c1���������" << c1.cubicS() << "c1���������" << c1.cubicB() << endl;
	cout << "c2���������" << c2.cubicS() << "c2���������" << c2.cubicB() << endl;


	if (c1.compare(c2))
	{
		cout << "��ͬ������" << endl;
	}
	else
	{
		cout << "��ͬ������" << endl;
	}


	if (compare(c1,c2))
	{
		cout << "���������" << endl;
	}

	else
	{
		cout << "��ͬ������" << endl;
	}
}




int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}