
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
using namespace std;

// todo

/* 懒汉式 */
class Chairman_lazy {
  private:
    Chairman_lazy() {
    }

  public:
    static Chairman_lazy *getInstance() {
        if (s_singleton == NULL) {
            // Sleep(1000); //等到1000秒
            s_singleton = new Chairman_lazy;
        }
        return s_singleton;
    }

  private:
    static Chairman_lazy *s_singleton;
};
//初始化NULL
Chairman_lazy *Chairman_lazy::s_singleton = NULL;

DWORD WINAPI MyThread_lazy(LPVOID lpThreadParameter) {

    Chairman_lazy *chairman = Chairman_lazy::getInstance();
    cout << "单例对象地址:" << (int *)chairman << endl;
    return 0;
}

//懒汉式单例碰到多线程
void test01() {

    HANDLE handler[10];
    for (int i = 0; i < 10; i++) {
        handler[i] = CreateThread(NULL, NULL, MyThread_lazy, NULL, NULL, NULL);
    }
}

/* 饿汉式 */
class Chairman_hangry {
  private:
    Chairman_hangry() {
    }

  public:
    static Chairman_hangry *getInstance() {
        return s_singleton;
    }

  private:
    static Chairman_hangry *s_singleton;
};
//初始化
Chairman_hangry *Chairman_hangry::s_singleton = new Chairman_hangry;

DWORD WINAPI MyThread_hangry(LPVOID lpThreadParameter) {

    Chairman_hangry *chairman = Chairman_hangry::getInstance();
    cout << "单例对象地址:" << (int *)chairman << endl;

    return 0;
}

//饿汉式单例碰到多线程测试
void test02() {

    HANDLE handler[10];
    for (int i = 0; i < 10; i++) {
        handler[i] = CreateThread(NULL, NULL, MyThread_hangry, NULL, NULL, NULL);
    }
}

int main() {

    // test01();
    test02();

    return EXIT_SUCCESS;
}
