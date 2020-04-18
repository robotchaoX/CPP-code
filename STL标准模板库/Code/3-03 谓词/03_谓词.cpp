#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 全局函数
bool isGreater(int val) {
    return val > 20;
}

//一元谓词
class GreaterThen20 {
  public:
    // 重载()，函数对象，仿函数
    bool operator()(int val) {
        return val > 20;
    }
};

//查找第一个大于20的数字
void test01() {
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);

    // find_if 返回一个指向被找到对象的迭代器 // 第三个参数 函数指针，类对象，匿名对象
    // 函数指针
    vector<int>::iterator pos1 = find_if(v.begin(), v.end(), isGreater);
    // 类对象（函数对象，仿函数）
    GreaterThen20 grt;
    vector<int>::iterator pos2 = find_if(v.begin(), v.end(), grt);
    // 匿名对象
    vector<int>::iterator pos3 = find_if(v.begin(), v.end(), GreaterThen20());
    if (pos1 != v.end()) {
        cout << "找到大于20的数字为：" << *pos1 << endl;
    } else {
        cout << "未找到" << endl;
    }
}

//二元谓词
class MyCompare {
  public:
    // 重载()
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

    // MyCompare() 匿名对象
    sort(v.begin(), v.end(), MyCompare());
    // 类对象（函数对象，仿函数）
    MyCompare cmp;
    sort(v.begin(), v.end(), cmp);

    // for_each 遍历容器
    //匿名函数  lambda表达式  [](){};
    for_each(v.begin(), v.end(), [](int &val) { cout << val << " "; });
}

int main() {

    test01();

    test02();

    return EXIT_SUCCESS;
}