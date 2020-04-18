#include <algorithm>
#include <iostream>
using namespace std;
#include <functional>
#include <string>
#include <vector>

/*
find算法 查找元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return 返回查找元素的位置
*/
// find查找数据 及其下标
void test01() {
    vector<int> v = {-1, 2, 9, 100, 200};

    // 查找数据是否存在,数据不存在返回end()
    vector<int>::iterator pos1 = find(v.begin(), v.end(), 2);
    if (pos1 != v.end()) {
        cout << "找到了数据：" << *pos1 << endl;
    } else {
        cout << "数据不存在" << endl;
    }

    // 查找数据对应下标
    vector<int>::iterator pos = find(v.begin(), v.end(), 2);
    if (pos != v.end()) {
        cout << "对应下标: " << pos - v.begin() << endl;
    } else {
        cout << "数据不存在" << endl;
    }
}

class Person {
  public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
    Person(const Person &p) {
        this->m_Name = p.m_Name;
        this->m_Age = p.m_Age;
        cout << "拷贝构造" << endl;
    }
    // find查找自定义类型 必需重载 ==
    bool operator==(const Person &p) {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
            return true;
        }
        return false;
    }

    string m_Name;
    int m_Age;
};
// find查找自定义数据类型
void test02() {
    vector<Person> v; // 存类对象

    Person p1("aaa", 10); // 构造
    Person p2("bbb", 20);

    cout << "---" << endl;
    v.push_back(p1); // 拷贝构造
    v.push_back(p2);
    v.push_back(Person("ccc", 30)); // 有参构造，再拷贝构造
    v.push_back(Person("ddd", 40));
    cout << "---" << endl;

    // 查找自定义类型，类必需重载 ==
    Person pf = Person("bbb", 20); // 有参构造pf
    vector<Person>::iterator pos = find(v.begin(), v.end(), pf);

    if (pos != v.end()) {
        cout << "找到了数据姓名：" << (*pos).m_Name << " 年龄：" << pos->m_Age << endl;
    } else {
        cout << "未找到" << endl;
    }
}

/**
 *  @brief find_if Find the first element in a sequence for which a
 *         predicate is true.
 *  @param  __first  An input iterator.
 *  @param  __last   An input iterator.
 *  @param  __pred   A predicate.
 *  @return   The first iterator @c i in the range @p [__first,__last)
 *  such that @p __pred(*i) is true, or @p __last if no such iterator exists.
*/

// find_if 指针查找
class MyCompare : public binary_function<Person *, Person *, bool> {
  public:
    // 重载(),函数对象，仿函数
    bool operator()(Person *p1, Person *p2) const {
        if (p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age) {
            return true;
        }
        return false;
    }
};

void test03() {

    vector<Person *> v; // 存类对象的指针

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    cout << "---" << endl;
    v.push_back(&p1); // 不会拷贝构造
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    cout << "---" << endl;

    // find_if 指针查找
    Person *p = new Person("bbb", 20);
    vector<Person *>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyCompare(), p));

    if (pos != v.end()) {
        cout << "找到了数据姓名：" << (*pos)->m_Name << " 年龄：" << (*pos)->m_Age << endl;
    } else {
        cout << "未找到" << endl;
    }
}

/*
adjacent_find算法 查找相邻重复元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  _callback 回调函数或者谓词(返回bool类型的函数对象)
@return 返回相邻元素的第一个位置的迭代器
*/
void test04() {
    vector<int> v = {1, 2, 3, 3, 4, 5, 5, 6};

    // 查找第一个相邻重复元素
    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());

    if (pos != v.end()) {
        cout << "找到了相邻重复元素为： " << *pos << endl;
    } else {
        cout << "未找到" << endl;
    }
}

/*
binary_search算法 二分查找法
注意: 在无序序列中不可用
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return bool 查找返回true 否则false
*/
void test05() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    // 有序数列的二分查找
    bool ret = binary_search(v.begin(), v.end(), 8);
    if (ret) {
        cout << "找到了8" << endl;
    } else {
        cout << "未找到" << endl;
    }
}

/*
count算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  value回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/
void test06() {
    vector<int> v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);

    // count统计元素出现次数
    int num = count(v.begin(), v.end(), 4);
    cout << "4的个数为" << num << endl;
}

/*
count_if算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  callback 回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/

class GreaterThen4 {
  public:
    // 重载()
    bool operator()(int v) {
        return v >= 4;
    }
};
void test07() {
    vector<int> v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);

    // count_if算法 统计元素出现次数
    int num = count_if(v.begin(), v.end(), GreaterThen4());
    cout << "大于等于 4的个数为" << num << endl;
}

int main() {

    test01();

    test02();

    test03();

    test04();

    test05();

    test06();

    test07();

    return EXIT_SUCCESS;
}