#include <iostream>
using namespace std;
#include <algorithm>
#include <deque>

void printDeque(const deque<int> &d) {
    // iterator 普通迭代器
    // reverse_iterator 逆序迭代器
    // const_iterator 只读迭代器
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        //*it = 100000;
        cout << *it << " ";
    }
    cout << endl;
}

/*
deque构造函数
deque<T> deqT;//默认构造形式
deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem);//构造函数将n个elem拷贝给本身。
deque(const deque &deq);//拷贝构造函数。

deque赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
deque& operator=(const deque &deq); //重载等号操作符
swap(deq);// 将deq与本身的元素互换

deque大小操作
deque.size();//返回容器中元素的个数
deque.empty();//判断容器是否为空
deque.resize(num);//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num,
elem);//重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。
*/

void test01() {
    deque<int> d;

    deque<int> d1 = {1, 2, 3};
    printDeque(d1);

    deque<int> d2(d1);
    printDeque(d2);

    deque<int> d3(d1.begin(), d1.end());
    printDeque(d3);

    //交换
    d.swap(d1);
    printDeque(d);

    // d2
    if (d2.empty()) {
        cout << "为空" << endl;
    } else {
        cout << "不为空 大小为：" << d2.size() << endl;
    }
}

/*
deque双端插入和删除操作
push_back(elem);//在容器尾部添加一个数据
push_front(elem);//在容器头部插入一个数据
pop_back();//删除容器最后一个数据
pop_front();//删除容器第一个数据

deque数据存取
at(idx);//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
operator[];//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
front();//返回第一个数据。
back();//返回最后一个数据

deque插入操作
insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。

deque删除操作
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
*/
void test02() {
    deque<int> d;
    d.push_back(10);
    d.push_back(30);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    printDeque(d); // 200 100 10 30 20

    //删除
    // 尾删
    d.pop_back();
    // 头删
    d.pop_front();
    printDeque(d); // 100 10 30

    cout << "front: " << d.front() << endl;
    cout << "back: " << d.back() << endl;

    //插入
    deque<int> d2;
    // 头插
    d2.push_front(6);
    // 尾插
    d2.push_back(5);
    printDeque(d2); // 6 5
    // insert插入
    d2.insert(d2.begin(), d.begin(), d.end());
    printDeque(d2); //  100 10 30 6 5
}

//排序规则
bool myCompare(int v1, int v2) {
    return v1 > v2; // 100 10
}

//排序 sort
void test03() {
    deque<int> d;
    d.push_back(5);
    d.push_back(15);
    d.push_back(3);
    d.push_back(40);
    d.push_back(7);

    printDeque(d);
    //排序
    sort(d.begin(), d.end()); // 默认升序
    printDeque(d);

    //从大到小
    sort(d.begin(), d.end(), myCompare);
    printDeque(d);
}

int main() {

    test01();

    test02();

    test03();

    return EXIT_SUCCESS;
}