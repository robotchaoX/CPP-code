#include <algorithm>
// #include <functional>
#include <iostream>
#include <vector>
using namespace std;

/*
for_each遍历算法 遍历容器元素
@param beg 开始迭代器
@param end 结束迭代器
@param _callback  函数回调或者函数对象(一元函数对象)
@return 函数对象
*/
/**
 *  @brief for_each Apply a function to every element of a sequence.
 *  @param  __first  An input iterator.
 *  @param  __last   An input iterator.
 *  @param  __f      A unary function object.
 *  @return @p __f  (std::move(@p __f) in C++0x).
 *
 *  Applies the function object @p __f to each element in the range
 *  @p [first,last).  @p __f must not modify the order of the sequence.
 *  If @p __f has a return value it is ignored.
*/

// 全局函数
void glPrint(int v) {
    cout << v << " ";
}

class MyPrint01 {
  public:
    // 重载() 函数对象，仿函数
    void operator()(int v) {
        cout << v << " ";
    }
};

void test01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), MyPrint01()); // MyPrint01()匿名对象
    cout << endl;
    for_each(v.begin(), v.end(), glPrint); // 普通函数
    cout << endl;
}

class CountPrint {
  public:
    // 重载() 函数对象，仿函数
    void operator()(int v) {
        cout << v << endl;
        val = v;
        m_Count++;
    }
    int val;
    int m_Count = 0;
};

// for_each有返回值
void test02() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    // for_each返回值为 传入最后一个值的类对象
    CountPrint cpt = for_each(v.begin(), v.end(), CountPrint());
    cout << "cpt.m_Count: " << cpt.m_Count << " cpt.val: " << cpt.val << endl;
}

// for_each可以绑定参数进行输出
class myPrint03 : public binary_function<int, int, void> { // 二元函数
  public:
    // 重载() 函数对象，仿函数
    void operator()(int v, int start) const {
        cout << v + start << endl;
    }
};

void test03() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    // 适配器
    for_each(v.begin(), v.end(), bind2nd(myPrint03(), 10000));
}

/*
transform算法 将指定容器区间元素搬运到另一容器中，可在转移时进行一些操作（等效遍历）
注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
@param beg1 源容器开始迭代器
@param end1 源容器结束迭代器
@param beg2 目标容器开始迭代器
@param _cakkback 回调函数或者函数对象
@return 返回目标容器迭代器
*/
class TransForm {
  public:
    int operator()(int val) {
        return val + 10;
    }
};

void test04() {
    vector<int> v; //原容器
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    vector<int> vTarget; //目标容器
    vTarget.resize(v.size()); // 分配内存

    // transform在转移时进行一些操作（等效遍历操作）
    // transform 将指定容器区间元素搬运到另一容器中
    transform(v.begin(), v.end(), vTarget.begin(), TransForm());

    for_each(vTarget.begin(), vTarget.end(), [](int val) { cout << val << " "; }); // [](){}匿名函数 输出
    cout << endl;
}

// transform 第二种用法 将两个容器数据相加搬运到目标容器
class TransForm2 {
  public:
    int operator()(int val, int val2) {
        return val + val2;
    }
};

void test05() {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v1.push_back(100 + i);
        v2.push_back(200 + i);
    }
    vector<int> vTarget; //目标容器
    vTarget.resize(v1.size()); // 分配内存

    // transform在转移时进行一些操作（等效遍历操作）
    // transform 将两个容器数据相加搬运到目标容器
    transform(v1.begin(), v1.end(), v2.begin(), vTarget.begin(), TransForm2());

    // 300 302...
    for_each(vTarget.begin(), vTarget.end(), [](int val) { cout << val << " "; }); // [](){}匿名函数 输出
    cout << endl;
}

int main() {

    test01();

    test02();

    test03();

    test04();

    test05();

    return EXIT_SUCCESS;
}