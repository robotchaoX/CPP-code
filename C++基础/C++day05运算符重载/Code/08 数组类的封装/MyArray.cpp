#include "MyArray.h"

//默认构造
MyArray::MyArray() {
    cout << "默认构造" << endl;
    this->m_Capacity = 100;
    this->m_Size = 0;
    // 类普通属性可以作为new空间大小的参数
    this->pAddress = new int[this->m_Capacity]; // 开辟内存,大小为非const类属性
}

//有参构造  参数 数组容量
MyArray::MyArray(int capacity) {
    cout << "有参函数调用" << endl;
    this->m_Capacity = capacity;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

//拷贝构造
MyArray::MyArray(const MyArray &array) {
    cout << "拷贝构造调用" << endl;
    this->m_Size = array.m_Size;
    this->m_Capacity = array.m_Capacity;
    this->pAddress = new int[array.m_Capacity]; // 深拷贝？？

    for (int i = 0; i < array.m_Size; i++) { // 拷贝值
        this->pAddress[i] = array.pAddress[i];
    }
}

//析构
MyArray::~MyArray() {
    if (this->pAddress != NULL) {
        cout << "析构调用" << endl;
        delete[] this->pAddress;
        this->pAddress = NULL;
    }
}

void MyArray::push_Back(int val) {
    //判断越界？ 用户自己处理
    this->pAddress[this->m_Size] = val;
    this->m_Size++;
}

int MyArray::getData(int index) {
    return this->pAddress[index];
}

void MyArray::setData(int index, int val) {
    this->pAddress[index] = val;
}

// [] 重载实现
int &MyArray::operator[](int index) {
    return this->pAddress[index];
}
