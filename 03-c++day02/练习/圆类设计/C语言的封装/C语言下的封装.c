#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct Person
{
	char mName[64];
	int mAge;
};
void PersonEat(struct Person *p)
{
	printf("%s�ڳ��˷� \n", p->mName);

}


void stes01()
{

	struct Person p1;
	strcpy(p1.mName, "����");
	PersonEat(&p1);
}



struct Dog
{
	char mName[64];
	int mAge;
};

void DogEat(struct Dog *dog)
{
	printf("%s �ٳԹ��� \n", dog->mName);
}

void test02()
{
	struct Dog p1;
	strcpy(p1.mName, "����");
	DogEat(&p1);
	PersonEat(&p1);
}

//C���Է�װ ���Ժ���Ϊ�ֿ������ˣ����ͼ�ⲻ��
int main()
{

	//stes01();
	test02();
	system("pause");

}