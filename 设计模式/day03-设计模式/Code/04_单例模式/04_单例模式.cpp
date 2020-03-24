#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 简单单例
class Single {
  private:
    // 1. 构造函数私有化
    Single() {
        sgl = new Single;
    }

  public:
    // 3. 静态 对外接口
    static Single *getInstace() {
        return sgl;
    }

  private:
    // 2. 静态 私有 的当前类的指针
    static Single *sgl;
};
//类外初始化
Single *Single::sgl = NULL;

//实现单例步骤
// 1. 构造函数私有化
// 2. 增加静态私有的当前类的指针变量
// 3. 提供静态对外接口，可以让用户获得单例对象

//单例 分为懒汉式 饿汉式
// 懒汉式,线程不安全
class Singleton_lazy {
  private:
    // 1. 构造函数私有化
    Singleton_lazy() {
    }

  public:
    // 3. 静态 对外接口
    static Singleton_lazy *getInstance() {
        if (pSingleton == NULL) {
            pSingleton = new Singleton_lazy;
        }
        return pSingleton;
    }

    //单例对象释放问题
    // 用嵌套类的析构函数释放
    class Garbage {
        ~Garbage() {
            if (pSingleton != NULL) {
                delete pSingleton;
            }
        }
    };

  private:
    // 2. 静态 私有 的当前类的指针
    static Singleton_lazy *pSingleton;
    static Garbage garbage; // 释放内存
};
//类外初始化,懒汉式在
Singleton_lazy *Singleton_lazy::pSingleton = NULL;

// 饿汉式,线程安全
class Singleton_hungry {
    // 1. 构造函数私有化
  private:
    Singleton_hungry() {
    }

  public:
    // 3. 静态 对外接口
    static Singleton_hungry *getInstance() {
        return pSingleton;
    }

    // #if 0
    // 手动释放对象指针资源
    // 	static void freeSpace(){
    // 		if (pSingleton != NULL	){
    // 			delete pSingleton;
    // 		}
    // 	}
    // #endif

    // 用嵌套类的析构函数释放
    class Garbage {
        ~Garbage() {
            if (pSingleton != NULL) {
                delete pSingleton;
            }
        }
    };

  private:
    // 2. 静态 私有 的当前类的指针
    static Singleton_hungry *pSingleton;
    static Garbage garbage; // 释放内存
};
//类外初始化,饿汉式在main之前new，不管用不用
Singleton_hungry *Singleton_hungry::pSingleton = new Singleton_hungry;

void test01() {
    // 创建对象
    Singleton_lazy *p1 = Singleton_lazy::getInstance();
    Singleton_lazy *p2 = Singleton_lazy::getInstance();
    if (p1 == p2) {
        cout << "两个指针指向同一块内存空间,是单例!" << endl;
    } else {
        cout << "不是单例模式！" << endl;
    }

    // 创建对象
    Singleton_hungry *p3 = Singleton_hungry::getInstance();
    Singleton_hungry *p4 = Singleton_hungry::getInstance();
    if (p3 == p4) {
        cout << "两个指针指向同一块内存空间,是单例!" << endl;
    } else {
        cout << "不是单例模式！" << endl;
    }
}

int main(void) {
    test01();

    return 0;
}