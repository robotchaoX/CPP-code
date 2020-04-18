#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*
sort算法 容器元素排序
@param beg 容器1开始迭代器
@param end 容器1结束迭代器
@param _callback 回调函数或者谓词(返回bool类型的函数对象)
*/
void test01() {
    vector<int> v1 = {1, 4, 2, 9, 5};

    sort(v1.begin(), v1.end()); //  默认升序, 默认算法less<int>()
    sort(v1.begin(), v1.end(), less<int>()); // 升序,默认算法 less 内置算法
    for_each(v1.begin(), v1.end(), [](int val) { cout << val << " "; });
    cout << endl;

    sort(v1.begin(), v1.end(), greater<int>()); // 降序, greater 内置算法
    for_each(v1.begin(), v1.end(), [](int val) { cout << val << " "; });
    cout << endl;

    // list 自带sort方法，不支持随机访问，不可以sort函数排序
    list<int> lis = {1, 4, 2, 9, 5};
    // sort(lis.begin(), lis.end()); //不支持随机访问不可以sort排序
    // list自带sort方法
    lis.sort();
    for_each(lis.begin(), lis.end(), [](int val) { cout << val << " "; });
    cout << endl;
}

// reverse(iterator beg, iterator end)
void test02() {
    // vector
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    // 反序
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
    cout << endl;

    // list
    list<int> lis;
    for (int i = 0; i < 10; i++) {
        lis.push_back(i);
    }
    // 反序
    reverse(lis.begin(), lis.end());
    for_each(lis.begin(), lis.end(), [](int val) { cout << val << " "; });
    cout << endl;
}

// random_shuffle(iterator beg, iterator end) 洗牌
void test03() {
    vector<int> v;
    // list<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
    cout << endl;
}

int main() {
    srand((unsigned int)time(NULL));

    test01();

    test02();

    test03();

    return EXIT_SUCCESS;
}