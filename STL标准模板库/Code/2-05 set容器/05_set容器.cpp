#include <iostream>
#include <set> // set  multiset头文件
#include <string>

using namespace std;

/*
set构造函数
set<T> st;//set默认构造函数：
mulitset<T> mst; //multiset默认构造函数:
set(const set &st);//拷贝构造函数

set赋值操作
set& operator=(const set &st);//重载等号操作符
swap(st);//交换两个集合容器

set大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

set插入和删除操作
insert(elem);//在容器中插入元素。
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);//删除容器中值为elem的元素。
clear();//清除所有元素
*/

void printSet(set<int> &s) {
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    set<int> s0 = {1, 2, 3};
    printSet(s0);
    set<int> s2(s0);
    printSet(s2);

    set<int> s1;
    //关联式容器 key进行排序，默认从小到大自动排序
    // set插入值
    s1.insert(5);
    s1.insert(1);
    s1.insert(9);
    s1.insert(3);
    s1.insert(7);
    printSet(s1);

    if (s1.empty()) {
        cout << "空" << endl;
    } else {
        cout << "size = " << s1.size() << endl;
    }

    // 按迭代器删
    s1.erase(s1.begin()); // 3 5 7 9
    printSet(s1);
    // 按值删
    s1.erase(5); //  3 7 9
    printSet(s1);

    // set第一个元素值
    set<int>::iterator itben = s1.begin();
    cout << *itben << endl;

    auto itben2 = s1.begin();
    cout << *itben2 << endl;

    // set遍历
    set<int>::iterator iter = s1.begin();
    while (iter != s1.end()) {
        cout << *iter;
        iter++;
    }

    //遍历
    for (auto i : s1) {
        cout << i << endl;
    }
}

/*
set查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key);//查找键key的元素个数
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/
void test02() {
    set<int> s1;
    s1.insert(5);
    s1.insert(1);
    s1.insert(9);
    s1.insert(3);
    s1.insert(7);
    //对于set 没有value  key就是value

    // set查找值
    set<int>::iterator pos = s1.find(3);
    if (pos != s1.end()) {
        cout << "find找到了：值为：" << *pos << endl;
    } else {
        cout << "未找到" << endl;
    }

    // count(key);//查找键key的元素个数，set而言结果0或者1
    int num = s1.count(2);
    cout << "2的个数为： " << num << endl;

    // lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    set<int>::iterator it = s1.lower_bound(4); // 10就是未找到
    if (it != s1.end()) {
        cout << "找到了 lower_bound (4)的值为：" << *it << endl;
    } else {
        cout << "未找到" << endl;
    }

    // upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
    set<int>::iterator it2 = s1.upper_bound(4);
    if (it2 != s1.end()) {
        cout << "找到了 upper_bound (4)的值为：" << *it2 << endl;
    } else {
        cout << "未找到" << endl;
    }

    // equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
    //上下限 就是lower_bound   upper_bound
    pair<set<int>::iterator, set<int>::iterator> ret = s1.equal_range(4);
    //获取第一个值
    if (ret.first != s1.end()) {
        cout << "找到equal_range中 lower_bound 的值 ：" << *(ret.first) << endl;
    } else {
        cout << "未找到" << endl;
    }
    //获取第二个值
    if (ret.second != s1.end()) {
        cout << "找到equal_range中 upper_bound 的值 ：" << *(ret.second) << endl;
    } else {
        cout << "未找到" << endl;
    }
}

// set容器 不允许插入重复的键值
void test03() {
    set<int> s1;
    // insert返回值记录了插入结果
    pair<set<int>::iterator, bool> ret = s1.insert(10);

    if (ret.second) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败" << endl;
    }

    ret = s1.insert(10);
    if (ret.second) {
        cout << "第二次插入成功" << endl;
    } else {
        cout << "第二次插入失败" << endl;
    }
    printSet(s1);

    // multiset允许插入重复值
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
}

// set 自动排序，修改自动排序规则需用仿函数
//指定set排序规则 从大到小
//仿函数
class myCompare {
  public:
    //仿函数
    //重载 ()
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

// set容器排序
void test04() {
    // // 内建函数greater<int>()规则排序 不可以这样？？
    // set<int, greater<int>()> s0;
    // s0.insert(5);
    // s0.insert(1);
    // s0.insert(9);
    // s0.insert(3);
    // s0.insert(7);

    // // 打印结果，修改了自动排序规则
    // for (set<int, greater<int>()>::iterator it = s0.begin(); it != s0.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;

    //从大到小排序
    //在set插入之前就指定排序规则
    set<int, myCompare> s1;

    s1.insert(5);
    s1.insert(1);
    s1.insert(9);
    s1.insert(3);
    s1.insert(7);
    // printSet(s1);

    // 打印结果，修改了自动排序规则
    for (set<int, myCompare>::iterator it = s1.begin(); it != s1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//自定义数据类型
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

    string m_Name;
    int m_Age;
};
// set 自动排序，修改自动排序规则需用仿函数
// 指定set排序规则 从大到小
// 仿函数
class myComparePerson {
  public:
    //仿函数
    //重载(),仿函数
    bool operator()(const Person &p1, const Person &p2) {
        if (p1.m_Age > p2.m_Age) { //降序
            return true;
        } else {
            return false;
        }
    }
};

void test05() {
    //从大到小排序
    //在set插入之前就指定排序规
    //插入自定义数据类型，上来就指定好排序规则
    set<Person, myComparePerson> s1;

    Person p1("大娃", 100);
    Person p2("二娃", 90);
    Person p3("六娃", 10);
    Person p4("爷爷", 1000);

    cout << "----" << endl;
    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);
    cout << "----" << endl;

    //显示
    for (set<Person, myComparePerson>::iterator it = s1.begin(); it != s1.end(); it++) {
        cout << "姓名：" << (*it).m_Name << " 年龄：" << it->m_Age << endl;
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