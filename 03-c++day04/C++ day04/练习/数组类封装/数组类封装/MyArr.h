#pragma once
#include<iostream>
using namespace std;


class MyaArray
{
public:
	//Ĭ�Ϲ��캯��
	MyaArray();
	//�вι��캯�����û�ָ��������ʼ��
	explicit MyaArray(int capacity);
	//��������
	MyaArray(const MyaArray & array);

	//����λ�����Ԫ��
	void SetData(int pos, int val);
	//���ָ��λ�ó���
	int GetData(int pos);
	//β�巨
	void PushBack(int val);
	//��ó���
	int GetLength();
	//�����������ͷ�����ռ�
	~MyaArray();






private:
	int mCapacit;//��������ɶ��ٸ�Ԫ��
	int nSize;//��ǰ�������ж��ٸ�Ԫ��
	int *pAdress;//ָ�������׵�ַ
};
