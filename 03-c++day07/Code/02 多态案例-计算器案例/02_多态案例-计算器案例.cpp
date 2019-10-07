#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class Calculator
//{
//public:
//
//	void setv1(int v)
//	{
//		this->val1 = v;
//	}
//
//	void setv2(int v)
//	{
//		this->val2 = v;
//	}
//
//
//	int getResult(string oper)
//	{
//		if (oper == "+")
//		{
//			return val1 + val2;
//		}
//		else if (oper == "-")
//		{
//			return val1 - val2;
//		}
//	}
//private:
//	int val1;
//	int val2;
//
//};
//
//void test01()
//{
//	Calculator cal;
//	cal.setv1(10);
//	cal.setv2(10);
//	cout << cal.getResult("+") << endl;
//	cout << cal.getResult("-") << endl;
//
//}

//�����Ŀ����У��и�����ԭ�� ����ԭ��
// ����չ����  ���޸Ĺر�


//���ö�̬ʵ�ּ�����
class abstractCalculator
{
public:

	//�麯�� virtual int getResult(){ return 0; };

	//���麯��
	//������������� ���麯��  ����̳и��࣬�ͱ���Ҫʵ�� ���麯��
	//��������� ���� ���麯�� ��������� ���޷�ʵ����������
	//��������˴��麯����ͨ���ֳ�Ϊ ������
	virtual int getResult()  = 0;


	void setv1(int v)
	{
		this->val1 = v;
	}

	void setv2(int v)
	{
		this->val2 = v;
	}

public:
	int val1;
	int val2;

};

//������������� ���麯��  ����̳и��࣬�ͱ���Ҫʵ�� ���麯��
class A:public abstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}
};

//�ӷ�������
class PlusCalculator :public abstractCalculator
{
public:
	virtual int getResult()
	{ 
		return val1 + val2;
	};
};
class SubCalculator : public abstractCalculator
{
public:
	virtual int getResult()
	{
		return val1 - val2;
	};
};
class ChengCalculator :public abstractCalculator
{
public:
	virtual int getResult()
	{
		return val1 * val2;
	};

};

void test02()
{
	abstractCalculator * abc ; 
	//�ӷ�������
	abc =  new PlusCalculator;

	abc->setv1(10);
	abc->setv2(20);

	cout << abc->getResult() << endl;

	delete abc;

	abc = new SubCalculator;
	abc->setv1(10);
	abc->setv2(20);
	cout << abc->getResult() << endl;

	delete abc;

	abc = new ChengCalculator;
	abc->setv1(10);
	abc->setv2(20);
	cout << abc->getResult() << endl;


	//����������˴��麯��������ʵ����������
	/*abstractCalculator aaa;
	abstractCalculator * abc = new abstractCalculator;*/

}

int main(){

	//test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}