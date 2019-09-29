#define _CRT_SECURE_NO_WARNINGS

#include "MyArray.h"
#include <iostream>
using namespace std;

void test01() {
    //堆区创建数组
    MyArray *array1 = new MyArray(30);

    MyArray *array2 = &*array1;

    //尾插法测试
    for (int i = 0; i < 10; i++) {
        array2->push_Back(i);
    }
    //获取数据测试
    for (int i = 0; i < 10; i++) {
        cout << array1->getData(i) << endl;
    }
    for (int i = 0; i < 10; i++) {
        cout << array2->getData(i) << endl;
    }

    //设置值测试
    array2->setData(0, 222);

    cout << array2->getData(0) << endl;

    delete array1; // 自己开辟自己释放

    // 使用[] 访问
    MyArray array3;
    // MyArray *array3 = array1;
    array3.push_Back(10000);
    cout << array3.getData(0) << endl;
    array3[0] = 100;
    cout << array3.getData(0) << endl;
    // cout << array3[0] << endl;
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}