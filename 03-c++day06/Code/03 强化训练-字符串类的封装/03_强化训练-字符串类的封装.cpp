#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>
using namespace std;

//测试 MyString
void test01() {
    MyString str1 = "abc";
    cout << "origin str1 = " << str1 << endl;
    MyString str2(str1);
    cout << "origin str2 = " << str2 << endl;
    MyString str3 = "123456";
    cout << "origin str3 = " << str3 << endl;

    /*cout << "请输入str新的内容：" << endl;
    cin >> str;
    cout << "新内容为：" << str << endl;*/

    str3 = str2;
    cout << "str3 = " << str3 << endl;
    str3 = "aaaa";
    cout << "str3 = " << str3 << endl;

    str3[0] = 'w';
    cout << "str3 第一个位置为 = " << str3[0] << endl;

    MyString str4 = "";
    str4 = str2 + str3; //字符串拼接
    cout << "str2 = " << str2 << endl;
    cout << "str3 = " << str3 << endl;
    cout << "str4 = str2 + str3 为 " << str4 << endl;

    if (str3 == str4) {
        cout << "str3 与 str4相等" << endl;
    } else {
        cout << "str3 与 str4不相等" << endl;
    }

    /*int a = 10;
    cin >> a;
    cout << "a = " << a << endl;*/
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}