#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>  //使用<<控制符的头文件
#include <iostream>
using namespace std;

/*
cout.put() //向缓冲区写字符
cout.write() //从buffer中写num个字节到当前输出流中。
*/

void test01() {
  cout.put('a').put('b');
  cout << endl;

  char buf[1024] = "hellowrold";
  cout.write(buf, sizeof(buf));
}

void test02() {
  //通过流成员函数
  int number = 99;
  cout.width(20);            // 宽度
  cout.fill('*');            // 填充
  cout.setf(ios::left);      //设置格式  输入内容做对齐
  cout.unsetf(ios::dec);     //卸载十进制，必须先卸载10进制？？
  cout.setf(ios::hex);       //安装16进制
  cout.setf(ios::showbase);  // 强制输出整数基数  0  0x
                             //   cout.unsetf(ios::hex);
                             //   cout.setf(ios::oct);
  cout << number << endl;
}

//控制符的方式显示,#include <iomanip>头文件
void test03() {
  int number = 99;
  cout.width(20);                     // 宽度
  cout.fill('*');                     // 填充
  cout.setf(ios::left);               //设置格式  输入内容做对
  cout << setiosflags(ios::showbase)  //基数
       << setiosflags(ios::left)      //左对齐
       << hex                         // 十六进制
       << number << endl;
}

void test04() {
  int number = 99;
  cout.width(20);            // 宽度
  cout.fill('*');            // 填充
  cout.setf(ios::left);      //设置格式  输入内容做对齐
  cout.setf(ios::showbase);  // 强制输出整数基数  0  0x
  cout << hex                // 十六进制
       << number << endl;
}

int main() {
  //   test01();

  //   test02();

  //   test03();

  test04();

  //   system("pause");
  return EXIT_SUCCESS;
}