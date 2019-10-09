#define _CRT_SECURE_NO_WARNINGS
#include <unistd.h>
#include <iostream>
using namespace std;

/*
cin.get() //一次只能读取一个字符
cin.get(buf) // 读一个字符,到buf
cin.get(buf, 1024) // 可以读字符串，到buf
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
*/

void test01() {
  // 按键按下时值存在缓冲区中，回车之后才处理
  // 输入as   缓冲区中  a , s , 换行  ,第一个拿  a ,第二个拿 s ,第三次拿 换行
  // 第四次等待下次输入
  char c = cin.get();
  cout << "c = " << c << endl;

  c = cin.get();
  cout << "c = " << c << endl;

  c = cin.get();  // 可以拿到换行符
  cout << "c = " << c << endl;

  c = cin.get();
  cout << "c = " << c << endl;

  cin.get(c);
  cout << "c = " << c << endl;
}

void test02() {
  // cin.get(两个参数) //可以读字符串到
  char buf[1024];
  // cin.get(两个参数)读取字符串时，不会把换行符拿走，遗留在缓冲区中
  cin.get(buf, 1024);

  char c = cin.get();  // 检测是否存在换行符
  if (c == '\n') {
    cout << "cin.get(buf, 1024)换行还在缓冲区" << endl;
  } else {
    cout << "cin.get(buf, 1024)换行不在缓冲区" << endl;
  }

  cout << buf << endl;
}

// cin.getline()
void test03() {
  char buf[1024];
  // cin.getline 把换行符读取，并且扔掉
  cin.getline(buf, 1024);

  char c = cin.get();  // 检测是否存在换行符
  if (c == '\n') {
    cout << "cin.getline(buf, 1024)换行还在缓冲区" << endl;
  } else {
    cout << "cin.getline(buf, 1024)换行不在缓冲区" << endl;
  }
}

// cin.ignore() 忽略
void test04() {
  cin.ignore(2);  //没有参数 代表忽略一个字符 ，带参数N，代表忽略N个字符

  char c = cin.get();
  cout << "c = " << c << endl;
}

// cin.peek() 偷窥
void test05() {
  //输入as  偷看一眼 a，然后再放回缓冲区 缓冲区中还是as
  char c = cin.peek();
  cout << "c = " << c << endl;

  c = cin.get();
  cout << "c = " << c << endl;
}

// cin.putback() 放回
void test06() {
  char c = cin.get();
  cin.putback(c);

  c = cin.get();
  cout << "c = " << c << endl;
  //   char buf[1024];
  //   cin.getline(buf, 1024);
  //   cout << buf << endl;
}

//案例1  判断用户的是字符串 还是数字？
void test07() {
  cout << "请输入一串数字或者字符串" << endl;

  //偷窥
  char c = cin.peek();

  if (c >= '0' && c <= '9') {
    int num;
    cin >> num;
    cout << "您输入是数字 ：数字为" << num << endl;
  } else {
    char buf[1024];
    cin >> buf;
    cout << "您输入是字符串 ：字符串为" << buf << endl;
  }
}

//案例2 让用户输入 1 到 10 的数字 ，如果输入有误 重新输入????
void test08() {
  int num = -1;
  cout << "请输入一个1到10的数字：" << endl;

  while (true) {
    cin >> num;
    if (num > 0 && num <= 10) {
      cout << "输入的数字为" << num << endl;
      break;
    } else {
      cout << "输入为" << num << endl;
      cout << "对不起，请重新输入" << endl;
      cin.clear();  //重置标志位
      cin.sync();   //清空缓冲区
      // 错误的表示关闭了cin,所以会进入死循环.
      cout << "标志位: " << cin.fail() << endl;  //标志位 0 正常的  1 不正常
      usleep(10000);
    }
  }
}

int main() {
  //   test01();

  //   test02();

  //   test03();

  //   test04();

  //   test05();

  //   test06();

  //   test07();

  test08();

  //   system("pause");
  return EXIT_SUCCESS;
}