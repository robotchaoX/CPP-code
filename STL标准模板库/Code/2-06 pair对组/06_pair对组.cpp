#include <iostream>
#include <string>
using namespace std;

//创建对组
void test01() {
    // 构造时直接初始化
    pair<string, int> p1("Hak", 100); // 初始化直接给值
    // pair<string, int> p1(string("Tom"), 10);
    cout << "姓名：" << p1.first << endl; //取值
    cout << "年龄： " << p1.second << endl;

    // 拷贝构造
    pair<string, int> p = p1; // 拷贝构造
    cout << "姓名：" << p.first << endl; //取值
    cout << "年龄： " << p.second << endl;

    // 匿名pair构造赋值
    pair<string, int> p0;
    p0 = pair<string, int>("Mmu", 10);
    cout << "姓名：" << p0.first << endl; //取值
    cout << "年龄： " << p0.second << endl;

    // make_pair赋值
    pair<string, int> p2;
    p2 = make_pair("Jerry", 200); // make_pair 赋值
    cout << "姓名：" << p2.first << endl;
    cout << "年龄： " << p2.second << endl;
}

int main() {
    test01();

    return EXIT_SUCCESS;
}