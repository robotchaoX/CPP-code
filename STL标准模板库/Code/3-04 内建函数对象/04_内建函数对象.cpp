#include <iostream>
using namespace std;
#include <algorithm>
// #include <functional> //内建函数对象头文件
#include <vector>

void test01() {
    // template<class T> T negate<T>
    //取反仿函数
    negate<int> n;
    cout << n(10) << endl;

    //加法  template<class T> T plus<T>
    //加法仿函数
    plus<int> pl;
    cout << pl(1, 2) << endl;
}

// template<class T> bool greater<T>
// 大于
void test02() {
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    // 使用内建函数greater<int>()规则排序
    sort(v.begin(), v.end(), greater<int>());

    for_each(v.begin(), v.end(), [](int &val) { cout << val << " "; });
}

int main() {

    test01();

    test02();

    return EXIT_SUCCESS;
}