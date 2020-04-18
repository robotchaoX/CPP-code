#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 全局函数
void glPrintSum2(int v, int start) {
    cout << v + start << endl;
}

// 1.ptr_fun函数指针适配器，将函数指针 适配为 函数对象
void test01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    int sum2 = 100;
    // ptr_fun 将一个普通的函数 适配成 一个仿函数(functor)
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(glPrintSum2), sum2));
}

class Person {
  public:
    Person() { // 无参构造
    }
    Person(string name, int age) { // 有参构造
        this->m_Name = name;
        this->m_Age = age;
    }
    // 重载()  函数对象，仿函数
    void operator()(Person &p) {
        cout << "operator()中：姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
    }

    void showPerson() {
        cout << "成员函数中：姓名： " << m_Name << " 年龄：" << m_Age << endl;
    }

    string m_Name;
    int m_Age;
};

// 全局函数
void glPrintPerson(Person &p) {
    cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}

// 2.mem_fun_ref成员函数适配器，将成员函数 适配成 函数对象（仿函数）
void test02() {
    vector<Person> v;

    Person p1("aaa", 10); // 先有参构造
    v.push_back(p1); // 拷贝构造
    v.push_back(Person("bbb", 15)); // 先有参构造，然后拷贝构造

    // 全局函数
    for_each(v.begin(), v.end(), glPrintPerson); // 函数指针

    // 函数对象
    Person pt; // 类对象（函数对象），不需要有参初始化
    for_each(v.begin(), v.end(), pt); // 类对象（函数对象）
    for_each(v.begin(), v.end(), Person()); //  Person()匿名对象

    // 成员函数适配器
    // mem_fun_ref 将成员函数 适配成 函数对象（仿函数）
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

// 3.类对象(仿函数)适配器？？
//继承类 binary_function<参数类型1 ，参数类型2 ，返回值类型>
//加const修饰 operator()
class MyPrint : public binary_function<int, int, void> { // 继承二元函数
  public:
    // 重载()  两个参数
    void operator()(int sum1, int sum2) const { // const修饰
        cout << "sum1 = " << sum1 << " sum2 = " << sum2 << " sum1+sum2 = " << sum1 + sum2 << endl;
    }
};

// 二元 -> 一元
void test03() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    // 绑定需适配参数
    int sum2 = 3;
    // 绑定第二个参数 bind2nd  二元->一元
    for_each(v.begin(), v.end(), bind2nd(MyPrint(), sum2)); // MyPrint()匿名对象

    int sum1 = -1;
    MyPrint pt; // 类对象
    // 绑定第一个参数 bind1st  二元->一元
    for_each(v.begin(), v.end(), bind1st(pt, sum1)); // 类对象
}

// 继承 unary_function <参数类型1，返回值类型>
// const修饰
class GreaterThenFive : public unary_function<int, bool> { // 继承一元函数
  public:
    // 重载()  一个参数
    bool operator()(int v) const { // const修饰
        return v > 5;
    }
};

// 全局函数
bool greatThan5(int val) {
    return val > 5;
}

// 4.一元取反适配器  not1
void test04() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    //原始查找大于5的数字
    //需求改为 找小于5的数字

    //一元取反适配器 not1
    // 类对象
    vector<int>::iterator pos1 = find_if(v.begin(), v.end(), not1(GreaterThenFive())); // GreaterThenFive()匿名对象
    GreaterThenFive gt5; // 类对象
    vector<int>::iterator pos2 = find_if(v.begin(), v.end(), not1(gt5)); // 类对象

    // 内建函数对象 greater<int>()
    vector<int>::iterator pos3 = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));

    // 全局函数
    // not1 一元取反适配器 // ptr_fun函数指针适配器
    vector<int>::iterator pos0 = find_if(v.begin(), v.end(), not1(ptr_fun(greatThan5)));
    if (pos1 != v.end()) {
        cout << "找到第一个小于5的数字为 " << *pos1 << endl;
    } else {
        cout << "未找到" << endl;
    }
}

int main() {
    test01();

    test02();

    test03();

    test04();

    return EXIT_SUCCESS;
}