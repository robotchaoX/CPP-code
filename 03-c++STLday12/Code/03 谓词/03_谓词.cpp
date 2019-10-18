#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class GreaterThen20 {
  public:
    bool operator()(int val) {
        return val > 20;
    }
};

bool IsGreater(int val) {
    return val > 20;
}

//一元谓词
void test01() {
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);

    //查找第一个大于20的数字

    // find_if 返回一个指向被找到对象的迭代器
    //第三个参数 函数指针，类对象，匿名对象
    // vector<int>::iterator pos = find_if(v.begin(), v.end(), IsGreater); // 函数指针
    // GreaterThen20 grt;
    // vector<int>::iterator pos = find_if(v.begin(), v.end(), grt); // 类对象
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen20()); // 匿名对象
    if (pos != v.end()) {
        cout << "找到大于20的数字为：" << *pos << endl;
    } else {
        cout << "未找到" << endl;
    }
}

//二元谓词
class MyCompare {
  public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};
void test02() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    sort(v.begin(), v.end(), MyCompare());

    // for_each 遍历容器
    //匿名函数  lambda表达式  [](){};
    for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
}

int main() {

    // test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}