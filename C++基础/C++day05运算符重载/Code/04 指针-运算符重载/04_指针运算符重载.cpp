#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person {
  public:
    Person(int age) {
        this->m_Age = age;
    }

    void showAge() {
        cout << "年龄为：" << this->m_Age << endl;
    }

    ~Person() {
        cout << "Person的析构调用" << endl;
    }

    int m_Age;
};

// 智能指针
// 用来托管自定义类型的对象，让对象进行自动的释放
class SmartPointer {
  public:
    // 有参构造
    SmartPointer(Person *per) {
        this->person = per;
    }

    // 重载 ->   让智能指针对象 像Person *p一样去使用 p->
    Person *operator->() { // 返回值对象指针类型
        return this->person; // 对象指针
    }

    // 重载 *   让智能指针对象 像Person *p一样去使用 *p
    Person &operator*() { // 返回值对象引用类型
        return *this->person; // 对象本身
    }

    ~SmartPointer() { // 析构时 delete
        cout << "智能指针析构了" << endl;
        if (this->person != NULL) {
            delete this->person;
            this->person = NULL;
        }
    }

  private:
    // 维护私有指针
    Person *person;
};

void test01() {
    // 自动析构
    Person p1(1); // 栈
    p1.showAge();

    // 手动删除
    Person *p2 = new Person(2); // 堆
    p2->showAge();
    delete p2;

    // 智能指针
    SmartPointer sp(new Person(3)); // sp开辟到了栈上，sp自动释放
    sp->showAge(); // 实际是sp->->showAge(); ？？编译器优化了 写法??
    (*sp).showAge();
}

int main() {

    test01();

    // system("pause")
    return EXIT_SUCCESS;
}