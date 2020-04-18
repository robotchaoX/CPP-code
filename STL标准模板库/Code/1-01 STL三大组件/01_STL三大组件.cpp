#include <iostream>
#include <string>
using namespace std;

//容器 vector
#include <vector>

//使用系统算法的头文件
#include <algorithm>

// 迭代器 遍历功能 用指针理解
//普通指针也算一种迭代器
void test01() {
    int array[5] = {0, 1, 2, 3, 4};

    int *p = array; //指针指向数组首地址  &array[0]

    for (int i = 0; i < 5; i++) {
        // cout << array[i] << endl;
        cout << *(p++) << endl; // 先*p再p++
        // cout << *(++p) << endl; // 错误，先p++再*p,越界
    }
}

void myPrint(int v) {
    cout << v << endl;
}

void test02() {
    //声明容器
    vector<int> v; //声明一个容器  这个容器中存放int类型数据 对象名称v
    //向容器中加入数据

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //遍历容器中的数据
    //利用迭代器
    vector<int>::iterator itBegin = v.begin(); // v.begin()指向的是v容器中的起始位置
    vector<int>::iterator itEnd = v.end(); // v.end()指向v容器中最后一个位置的下一个地址,哨兵

    //第一种遍历方式
    while (itBegin != itEnd) {
        cout << *itBegin << endl;
        itBegin++;
    }

    //第二种遍历方式,推荐
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }

    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }

    //第三种方式 利用算法for_each
    for_each(v.begin(), v.end(), myPrint);
}

//操作自定义数据类型
class Person {
  public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
    // 拷贝构造
    Person(const Person &p) {
        this->m_Name = p.m_Name;
        this->m_Age = p.m_Age;
        cout << "拷贝构造" << endl;
    }

    string m_Name;
    int m_Age;
};

void test03() {
    vector<Person> v; // 存对象
    Person p1("大头儿子", 10);
    Person p2("小头爸爸", 32);
    Person p3("隔壁王叔叔", 30);
    Person p4("围裙妈妈", 28);

    cout << "1-1-1-1，存对象，push_back进行拷贝构造" << endl;
    v.push_back(p1); // 存对象，push_back进行拷贝构造
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    cout << "1-1-1-1" << endl;

    //遍历
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "姓名: " << (*it).m_Name << " 年龄：" << it->m_Age << endl;
    }
}

//存放自定义数据类型的指针
void test04() {
    vector<Person *> v; // 存对象指针
    Person p1("大头儿子", 10);
    Person p2("小头爸爸", 32);
    Person p3("隔壁王叔叔", 30);
    Person p4("围裙妈妈", 28);

    cout << "2-2-2-2，存对象指针，push_back不会发生拷贝构造" << endl;
    v.push_back(&p1); // 存对象指针，push_back不会发生拷贝构造
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    cout << "2-2-2-2" << endl;

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "姓名：： " << (*it)->m_Name << " 年龄： " << (*it)->m_Age << endl;
    }
}

//容器嵌套容器
void test05() {
    // 二维数组，3×5
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    for (int i = 0; i < 5; i++) {
        v1.push_back(i);
        v2.push_back(i + 10);
        v3.push_back(i + 100);
    }
    //将小容器放入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    //遍历所有数据 3×5
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) { // 遍历大容器
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) { // 遍历小容器
            cout.width(4);
            cout << *vit << " ";
        }
        cout << endl;
    }
}

int main() {
    test01();
    test02();
    test03();
    test04();
    test05();

    return EXIT_SUCCESS;
}