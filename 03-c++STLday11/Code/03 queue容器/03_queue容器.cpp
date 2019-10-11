#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>

/*
queue构造函数
queue<T> queT;//queue采用模板类实现，queue对象的默认构造形式：
queue(const queue &que);//拷贝构造函数
3.5.3.2 queue存取、插入和删除操作
push(elem);//往队尾添加元素
pop();//从队头移除第一个元素
back();//返回最后一个元素
front();//返回第一个元素

3.5.3.3 queue赋值操作
queue& operator=(const queue &que);//重载等号操作符
3.5.3.4 queue大小操作
empty();//判断队列是否为空
size();//返回队列的大小
*/
void test01() {
    // 队列
    queue<int> q;
    q.push(10); //往队尾添加元素
    q.push(20);
    q.push(30);
    q.push(40);
    // 不能使用STL<algorithm.h>中的sort()进行排序，因为sort()只能对支持随机访问的数据结构进行排序
    // sort(q); // 队列不可以排序吗？？
    // q.sort();???

    while (!q.empty()) {
        //  10 40  20 40  30  40  40  40
        cout << "队头: " << q.front() << endl;
        cout << "队尾: " << q.back() << endl;
        //弹出队头元素
        q.pop();
    }

    cout << "size : " << q.size() << endl;
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}