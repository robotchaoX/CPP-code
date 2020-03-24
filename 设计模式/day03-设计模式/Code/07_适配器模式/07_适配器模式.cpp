#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//适配器模式 就是将已经写好的接口，但是这个接口不符合需求
//将写好的接口转换成目标接口

//这函数我已经写好
struct MyPrint {
    void operator()(int v1, int v2) { // 2个参数
        cout << v1 + v2 << endl;
    }
};

//定义目标接口 我要是配偶 适配成什么样的
class Target {
  public:
    virtual void operator()(int v) = 0; // 1个参数
};

//写适配器
class Adapter : public Target {
  public:
    Adapter(int param) { // 构造时传参
        this->param = param;
    }
    virtual void operator()(int v1) { // 1个参数
        myprint(v1, param);
    }

  public:
    MyPrint myprint;
    int param;
};

// MyBind2nd
Adapter MyBind2nd(int v2) {
    return Adapter(v2);
}

int main(void) {

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), MyBind2nd(100));

    return 0;
}