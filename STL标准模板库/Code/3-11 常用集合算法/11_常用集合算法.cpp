#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

/*
set_intersection算法 求两个set集合的交集
注意:集合运算两个集合容器必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
*/
void test01() {
    // 集合运算两个容器必须是有序的
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {3, 4, 5, 6, 7};

    vector<int> vTarget;
    vTarget.resize(min(v1.size(), v2.size()));

    // set_intersection算法 求两个set集合的交集
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, [](int val) { cout << val << " "; });
    cout << endl;
}

/*
set_union算法 求两个set集合的并集
注意:集合运算两个集合容器必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
*/
void test02() {
    // 集合运算两个容器必须是有序的
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {3, 4, 5, 6, 7};

    vector<int> vTarget;
    vTarget.resize(v1.size() + v2.size());

    // set_union算法 求两个set集合的并集
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, [](int val) { cout << val << " "; });
    cout << endl;
}

/*
set_difference算法 求两个set集合的差集
注意:集合运算两个集合容器必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
*/
void test03() {
    // 集合运算两个容器必须是有序的
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {3, 4, 5, 6, 7};

    vector<int> vTarget;
    vTarget.resize(max(v1.size(), v2.size()));

    // v1差v2
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, [](int val) { cout << val << " "; });
    cout << endl;

    // v2 差 v1
    // set_difference算法 求两个set集合的差集
    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, [](int val) { cout << val << " "; });
    cout << endl;
}

int main() {

    test01();

    test02();

    test03();

    return EXIT_SUCCESS;
}