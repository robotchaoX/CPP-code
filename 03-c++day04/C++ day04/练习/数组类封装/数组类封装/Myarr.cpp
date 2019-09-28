#include"MyArr.h"


MyaArray::MyaArray()
{
	cout << "默认构造调用" << endl;
	this->nSize = 0;
	this->mCapacit = 100;
	pAdress = new int[mCapacit];
}
//拷贝构造
MyaArray::MyaArray(const MyaArray & array)
{

	cout << "拷贝构调用" << endl;
	pAdress = new int[array.mCapacit];
	this->mCapacit = array.mCapacit;

	for (int i = 0; i < array.nSize; ++i)
	{
		this->pAdress[i] = array.pAdress[i];
	}

}


//有参构造函数，用户指定容量初始化
 MyaArray::MyaArray(int capacity)
{
	this->mCapacit = capacity;
	pAdress = new int[capacity];
	nSize = 0;
	pAdress[capacity] = { 0 };

}
//根据位置添加元素
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
//获得指定位置数据
int MyaArray::GetData(int pos)
{
	if (pos < 0||pos > mCapacit-1 )
	{
		return -1;
	}

	return this->pAdress[pos];

}
//尾插法
void MyaArray::PushBack(int val)
{
	if (nSize == mCapacit)
	{
		return;
	}
	this->pAdress[nSize] = val;
	this->nSize++;

}
//获得长度
int MyaArray::GetLength()
{
	return this->nSize;

}
//析构函数，释放数组空间
MyaArray::~MyaArray()
{
	cout << "析构函数调用" << endl;
	if (pAdress != NULL)
	{
		delete[]pAdress;
	}
	pAdress = NULL;
}