#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyString {
  public:
    // 可重载
    MyString(const char *str) {}

    // explict 明显的，显式的，禁止隐式转换
    explicit MyString(int a) { mSize = a; }

    char *mStr;
    int mSize;
};

void test01() {

    MyString str = "abc"; // 可重载，显式构造
    MyString str2(10);    // 显式构造
    // MyString str3 = 10;   //隐式类型转换  Mystring str3 = Mystring (10);
    // explicit关键字 ，防止隐式类型转换
}

int main() {
    test01();

    // system("pause");
    return EXIT_SUCCESS;
}