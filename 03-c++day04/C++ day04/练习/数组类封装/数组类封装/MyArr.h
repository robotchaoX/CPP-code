#pragma once
#include<iostream>
using namespace std;


class MyaArray
{
public:
	//默认构造函数
	MyaArray();
	//有参构造函数，用户指定容量初始化
	explicit MyaArray(int capacity);
	//拷贝构造
	MyaArray(const MyaArray & array);

	//根据位置添加元素
	void SetData(int pos, int val);
	//获得指定位置长度
	int GetData(int pos);
	//尾插法
	void PushBack(int val);
	//获得长度
	int GetLength();
	//析构函数，释放数组空间
	~MyaArray();






private:
	int mCapacit;//数组可容纳多少个元素
	int nSize;//当前数组中有多少个元素
	int *pAdress;//指向数组首地址
};
