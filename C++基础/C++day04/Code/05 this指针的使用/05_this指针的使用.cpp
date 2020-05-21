#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// this指向当前对象的指针
class Person {
  public:
    // this可以解决命名冲突,区分类属性和形参
    Person(int age) {
        this->age = age; // age命名相同
    }

    // 编译器会偷偷加入 形参this指针 (Person * this) ??
    // void showAge(Person * this)
    void showAge() {
        cout << "年龄 " << this->age << endl;
    }

    //对比年龄
    void compareAge(Person &p) {
        if (this->age == p.age) {
            cout << "年龄相等" << endl;
        } else {
            cout << "年龄不相等" << endl;
        }
    }

    //年龄相加
    // 返回*this当前对象
    Person &PlusAge(Person &p) {
        this->age += p.age;
        return *this; // *this指向对象本体
    }

    int age;
};

void test01() {
    Person p1(10);
    cout << "p1的年龄" << p1.age << endl;

    Person p2(10);

    p1.compareAge(p2);

    //链式编程,函数调用后返回当前对象,可继续调用
    p1.PlusAge(p2).PlusAge(p2).PlusAge(p2);

    cout << "p1的年龄" << p1.age << endl;
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}