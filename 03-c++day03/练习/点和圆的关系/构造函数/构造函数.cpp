#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class arr
{

public:
	arr()
	{
	
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	
	arr(int a)
	{
		cout << "�вι��캯��" << endl;
	}

	arr(arr&ar)

	{
		cout << "�������캯��" << endl;
	}

	~arr()
	{
		cout << "�������캯��" << endl;
	}

	int age;

};

void test()

{
	arr(100);//�������� ���������ص��ǣ�������������ֶ����������ģ���ô�����д����������ͷ��������
	//�����ÿ������캯�� ��ʼ����������

	arr a1 = 100;
	//arr a1;
	//arr a1(10);
	//a1.age = 10;
	
	arr a2(a1);


}




int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}