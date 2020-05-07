#include <algorithm> // set_intersection
#include <iostream>
#include <iterator> // insert_iterator
#include <set>
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
    vTarget.resize(min(v1.size(), v2.size())); // 必须分配空间

    // set_intersection算法 求两个set集合的交集
    // 返回值，最后一个迭代器？？
    // 两个集合都必须是有序的且是相同的排序
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    vTarget.resize(itEnd - vTarget.begin()); // 截断正好交集大小

    for_each(vTarget.begin(), vTarget.end(), [](int val) { cout << val << ", "; });
    cout << endl;

    // 无序vector
    vector<int> n1 = {1, 4, 3, 4, 3};
    vector<int> n2 = {6, 4, 5, 6, 3};
    vector<int> res1; // 不需要准备空间
    std::set_intersection(n1.begin(), n1.end(), n2.begin(), n2.end(), insert_iterator<vector<int>>(res1, res1.begin()),
                          [](int &v1, int &v2) { return v1 == v2; }); // insert_iterator 将复制转换为插入
    for_each(res1.begin(), res1.end(), [](int val) { cout << val << " "; });
    cout << endl;
    cout << "---" << endl;

    // 无序vector
    vector<int> num1 = {1, 4, 3, 4, 3};
    vector<int> num2 = {6, 4, 5, 6, 3};
    vector<int> res2; // 不需要准备空间
    // sort排序
    std::sort(num1.begin(), num1.end());
    std::sort(num2.begin(), num2.end());
    std::set_intersection(num1.begin(), num1.end(), num2.begin(), num2.end(),
                          insert_iterator<vector<int>>(res2, res2.begin())); // insert_iterator 将复制转换为插入
    for_each(res2.begin(), res2.end(), [](int val) { cout << val << ", "; });
    cout << endl;

    // 无序vector
    vector<int> nums1 = {1, 4, 3, 4, 3};
    vector<int> nums2 = {6, 4, 5, 6, 3};
    vector<int> res;
    // 转换为set，自动排序
    set<int> cod1(nums1.begin(), nums1.end());
    set<int> cod2(nums2.begin(), nums2.end());
    std::set_intersection(cod1.begin(), cod1.end(), cod2.begin(), cod2.end(),
                          insert_iterator<vector<int>>(res, res.begin())); // insert_iterator 将复制转换为插入
    for_each(res.begin(), res.end(), [](int val) { cout << val << ", "; });
    cout << endl;
}

class Point {
  public:
    Point(int px, int py) : x(px), y(py) {
    }
    friend ostream &operator<<(ostream &cout, Point &p1);

    int x;
    int y;
};

// 只能利用全局函数 进行 << 运算符的重载
ostream &operator<<(ostream &cout, Point &p1) { //第一个参数 cout  第二个参数  p1 // 全局 operator<<(cout,p1)

    cout << "( " << p1.x << "," << p1.y << " )" << endl; // 插入到输出流cout

    return cout; // 返回输出流cout的引用
}

void test11() {
    vector<Point> v1 = {Point(1, 1), Point(1, 3), Point(8, 2), Point(4, 1), Point(2, 4), Point(3, 3)};
    vector<Point> v2 = {
        Point(1, 2), Point(4, 3), Point(1, 2), Point(3, 3), Point(4, 4), Point(1, 3),
    };
    vector<Point> res; // 不需要准备空间
    // v1,v2排序,先按x排序，x相同的按y排，升序
    sort(v1.begin(), v1.end(), [](Point &p1, Point &p2) { return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x; });
    sort(v2.begin(), v2.end(), [](Point &p1, Point &p2) { return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x; });
    for_each(v1.begin(), v1.end(), [](Point &p) { cout << p; });
    cout << "--" << endl;
    for_each(v2.begin(), v2.end(), [](Point &p) { cout << p; });
    cout << "--" << endl;

    std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), insert_iterator<vector<Point>>(res, res.begin()),
                          [](Point &p1, Point &p2) {
                              return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
                          }); // insert_iterator 将复制转换为插入
    for_each(res.begin(), res.end(), [](Point &p) { cout << p; });
    cout << "------" << endl;
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
    test11();

    test02();

    test03();

    return EXIT_SUCCESS;
}