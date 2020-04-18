#include <iostream>
using namespace std;
#include <stdexcept>
#include <string>

/*
string 构造函数
string();//创建一个空的字符串 例如: string str;
string(const string& str);//使用一个string对象初始化另一个string对象
string(const char* s);//使用字符串s初始化
string(int n, char c);//使用n个字符c初始化
*/
void test00() {
    // 初始化
    string str1; // 默认构造
    string str2(str1); // 拷贝构造
    string str3 = str1; // string赋值
    string str4 = "abcd"; // “”字符串赋值
    string str6 = "z"; // “”单个字符的字符串
    // string str7 = 'z'; // 错误,不能是''单个字符
    string str5(30, '-'); // 30个字符’-‘的字符串
    cout << str5 << endl;
}

/*
string基本赋值操作
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
*/
void test01() {
    string str1 = "xyz";
    string str2;
    // 基本赋值
    str2 = str1;

    // assign修改容器的大小
    string str3;
    cout << "str3.size():" << str3.size() << "," << str3 << endl;
    // assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
    str3.assign("abcdef", 4); // 取“”前4个
    cout << "str3.size():" << str3.size() << "," << str3 << endl;

    // assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
    str1 = "abcdef";
    // cout << "str3.size():" << str3.size() << "," << str3 << endl;
    str3.assign(str1, 2, 3); // 从0索引,从start开始n个字符
    cout << "str3.size():" << str3.size() << "," << str3 << endl;
}

/*
string存取字符操作
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
*/
void test02() {
    string s = "hello";

    for (unsigned i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
        cout << s.at(i) << endl;
    }
    //[] 和at区别？[]访问越界  直接挂掉 at会抛出异常out_of_range
    try {
        // cout << s[100] << endl; // 访问越界,
        cout << s.at(100) << endl; // out_of_range异常
    } catch (out_of_range &e) {
        cout << "at() out_of_range异常 : " << e.what() << endl;
    } catch (...) {
        cout << "[] 越界异常" << endl;
    }
}

/*
string拼接操作
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c
*/
void test03() {
    //拼接
    string s1 = "我";
    string s2 = "爱北京";
    // +=
    s1 += s2;
    cout << s1 << endl;
    // append
    s1.append("天安门");
    cout << s1 << endl;

    string s4 = "xxx";
    string s5 = "abcdef";
    s4.append(s5, 2, 3); // 追加字符串中从pos开始n个字符
    cout << s4 << endl;
    s4.append(4, '-'); // 追加n个字符
    cout << s4 << endl;
}

/*
string查找和替换
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
*/
void test04() {
    // find查找
    string s = "abcdefg-abcdefg";
    int pos = s.find("cde"); //返回第一个匹配字符串的位置，从0开始
    cout << "pos = " << pos << endl;
    int pos2 = s.rfind("cde"); // 字符串最后位置，从0开始
    cout << "pos2 = " << pos2 << endl;
    pos = s.find("bbb"); //找不到返回是 -1,字符串需全部匹配
    cout << "pos = " << pos << endl;

    //替换
    string s3 = "hello";
    s3.replace(1, 3, "---"); // 替换从pos开始n个字符为字符串str
    cout << s3 << endl; // h---o
}

/*
string比较操作
compare函数在 > 时返回 >0，< 时返回 <0，== 时返回 ==0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A < 小写的a
int compare(const string &s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较
*/
void test05() {
    string s1 = "abcd";
    string s2 = "abceee"; // d < e

    // compare从第一个不同的字符开始比较,逐个字符比较
    if (s1.compare(s2) == 0) {
        cout << "s1 等于 s2" << endl;
    } else if (s1.compare(s2) > 0) {
        cout << "s1 大于 s2" << endl;
    } else if (s1.compare(s2) < 0) {
        cout << "s1 小于 s2" << endl;
    } else {
        cout << s1.compare(s2) << endl;
    }
}

/*
string子串
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
*/
void test06() {
    string s1 = "abcde";
    string s2 = s1.substr(1, 3); // 取子串，pos开始的n个字符,从0开始
    cout << "substr = " << s2 << endl;

    //需求  查找一个右键的 用户名
    string email = "zhangtao@sina.com";

    int pos = email.find("@"); // 8
    cout << "find(\"@\") pos = " << pos << endl;

    string usrName = email.substr(0, pos);
    cout << "用户名为：" << usrName << endl;
}

/*
string插入和删除操作
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
*/
void test07() {
    // 插入字符串
    string s1 = "hello";
    s1.insert(1, "123"); // 在pos插入字符串，增加长度
    cout << s1 << endl; // h123ello
    s1.insert(1, 3, '+'); // 在pos插入n个字符，增加长度
    cout << s1 << endl; // h+++123ello

    //删除字符串
    s1.erase(1, 6); //删除从Pos开始的n个字符
    cout << s1 << endl;
}

/*
string和C字符串转换
*/
void funstr(string s) {
    cout << "string : " << s << endl;
}
void funchar(const char *s) {
    cout << "char * : " << s << endl;
}

void test08() {
    string str = "abc";
    // funchar(str); // string 不能隐式类型转换为 char *
    // string 转 const char *
    const char *p = str.c_str();
    funchar(p); // char *

    const char *p3 = "abcd";
    funstr(p3); // const char * 隐式类型转换为 string
    // const char * 转 string
    string s3(p3); // 复制构造时 const char * -> string
    funstr(p3);
}

// 局部变量string重新分配了更大的空间，原来的地址变了，原来的引用失效了
void test09() {
    string str = "abcde";

    char &a = str[2]; // 引用,局部变量地址
    char &b = str[3];
    a = '1'; // 引用有效
    b = '2';
    cout << str << endl;
    cout << "地址 ： " << (int *)str.c_str() << endl; // 引用有效

    // string重新赋值分配了更大的空间，原来的地址变了，原来的引用失效了
    str = "--------------------------------------";
    cout << "a = " << a << "b = " << endl; // 原来的引用失效了
    a = '1'; // 原来的引用失效了
    b = '2';
    cout << str << endl;
    cout << "地址 ： " << (int *)str.c_str() << endl; // 重新申请更大空间的地址变了
}

/*
写一个函数，函数内部将string字符串中的所有小写字母都变为大写字母。
*/
void test10() {
    string s = "abCdEfg";

    for (int i = 0; i < s.size(); i++) {
        // s[i] = toupper(s[i]); //全变大写
        // 每个字符全变小写
        s[i] = tolower(s[i]); // 全变小写
    }

    cout << s << endl;
}

int main() {

    test00();
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    test08();
    test09();
    test10();

    return EXIT_SUCCESS;
}