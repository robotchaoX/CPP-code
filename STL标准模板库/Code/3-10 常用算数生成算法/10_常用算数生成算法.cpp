#include <algorithm> //不好使
#include <iostream>
#include <iterator>
#include <numeric> //好使
#include <vector>

using namespace std;

/*
accumulate算法 计算容器元素累计总和
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 结果偏移值
*/
void test01() {
    vector<int> v;
    for (int i = 0; i <= 100; i++) {
        v.push_back(i);
    }

    // 0~100累积和  5050

    // accumulate算法 计算容器元素累计总和
    int sum = accumulate(v.begin(), v.end(), 0); //第三个参数  结果偏移值
    cout << "总和为：" << sum << endl;
}

/*
fill算法 向容器中添加元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value t填充元素
*/
void test02() {
    vector<int> v;
    v.resize(10);

    // fill算法 向容器中添加元素
    fill(v.begin(), v.end() - 2, 111);

    for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
    cout << endl;
}

int main() {
    test01();

    test02();

    return EXIT_SUCCESS;
}