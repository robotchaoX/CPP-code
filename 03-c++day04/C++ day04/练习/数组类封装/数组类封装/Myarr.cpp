#include"MyArr.h"


MyaArray::MyaArray()
{
	cout << "Ĭ�Ϲ������" << endl;
	this->nSize = 0;
	this->mCapacit = 100;
	pAdress = new int[mCapacit];
}
//��������
MyaArray::MyaArray(const MyaArray & array)
{

	cout << "����������" << endl;
	pAdress = new int[array.mCapacit];
	this->mCapacit = array.mCapacit;

	for (int i = 0; i < array.nSize; ++i)
	{
		this->pAdress[i] = array.pAdress[i];
	}

}


//�вι��캯�����û�ָ��������ʼ��
 MyaArray::MyaArray(int capacity)
{
	this->mCapacit = capacity;
	pAdress = new int[capacity];
	nSize = 0;
	pAdress[capacity] = { 0 };

}
//����λ�����Ԫ��
void MyaArray::SetData(int pos, int val)
{
	if (pos < 0 || pos > mCapacit - 1)
	{
		return;
	}
	for (int i = pos; i < mCapacit - 1; ++i)
	{
		this->pAdress[i + 1] = pAdress[i];
	}
	this->pAdress[pos] = val;
	this->nSize++;

}
//���ָ��λ������
int MyaArray::GetData(int pos)
{
	if (pos < 0||pos > mCapacit-1 )
	{
		return -1;
	}

	return this->pAdress[pos];

}
//β�巨
void MyaArray::PushBack(int val)
{
	if (nSize == mCapacit)
	{
		return;
	}
	this->pAdress[nSize] = val;
	this->nSize++;

}
//��ó���
int MyaArray::GetLength()
{
	return this->nSize;

}
//�����������ͷ�����ռ�
MyaArray::~MyaArray()
{
	cout << "������������" << endl;
	if (pAdress != NULL)
	{
		delete[]pAdress;
	}
	pAdress = NULL;
}