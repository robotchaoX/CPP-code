#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//设计立方体类(Cube)，
//求出立方体的面积(2 * a*b + 2 * a*c + 2 * b*c)和体积(a * b * c)，
//分别用全局函数和成员函数判断两个立方体是否相等。
//成员函数
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

	cout << "c1立方体面积" << c1.cubicS() << "c1立方体体积" << c1.cubicB() << endl;
	cout << "c2立方体面积" << c2.cubicS() << "c2立方体体积" << c2.cubicB() << endl;


	if (c1.compare(c2))
	{
		cout << "相同立方体" << endl;
	}
	else
	{
		cout << "不同立方体" << endl;
	}


	if (compare(c1,c2))
	{
		cout << "相等立方体" << endl;
	}

	else
	{
		cout << "不同立方体" << endl;
	}
}




int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}