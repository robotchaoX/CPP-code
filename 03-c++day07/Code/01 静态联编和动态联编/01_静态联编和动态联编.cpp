#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}

};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

//����doSpeak ��speak�����ĵ�ַ��Ͱ󶨺��ˣ���󶨣���̬���࣬����׶ξ�ȷ�����˵�ַ
//��������è��speak��������ǰ�󶨺ú����ĵ�ַ�ˣ�������Ҫ������ʱ����ȥȷ��������ַ
//��̬���࣬д�� doSpeak������Ϊ�麯��,�ڸ����������麯���������˶�̬
// ��������û���ָ�� ָ�� �������
void doSpeak(Animal & animal) //Animal & animal = cat
{
	animal.speak();
}
//��������˼̳еĹ�ϵ�������������������ת��

void test01()
{
	Cat cat;
	doSpeak(cat);

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}