#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	//��ͨ��Ա�������Է���static��non-static��Ա����
	void changeParaml(int param)
	{
		mParam = param;
		sNum = param;
	}
	static void changeParam2(int param)
	{
		//mParam=param;
		sNum = param;
	}


private:
	static void changeParam3(int param)
	{
		//mParam=parm;//�޷�����
		sNum = param;
	}
public:
	int mParam;
	static int sNum;

};
//��̬��Ա���������ʼ��
int Person::sNum = 0;

int main(){

	Person::changeParam2(100);
	//

	system("pause");
	return EXIT_SUCCESS;
}