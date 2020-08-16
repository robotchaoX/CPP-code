#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Person {
    int m_Age;
};

// 指针的指针
// 指针的指针p_ptr -> 对象的指针p -> Person对象
void newMemByPtr(Person **p_ptr) { // 二重指针,p_ptr是指针的指针
    *p_ptr = (Person *)malloc(sizeof(Person)); // 开辟内存
    (*p_ptr)->m_Age = 100;
}
void test01() {
    Person *p = NULL;
    newMemByPtr(&p); // 传入&p指针的指针
    cout << "p的年龄： " << p->m_Age << endl;
}

// 指针的引用(推荐)
void newMemByRef(Person *&p_ref) { // 指针的引用,p_ref是指针的引用
    //利用指针引用开辟空间
    p_ref = (Person *)malloc(sizeof(Person));
    p_ref->m_Age = 1000;
}
void test02() {
    Person *p = NULL;
    newMemByRef(p); //传入p指针
    cout << "p的年龄：" << p->m_Age << endl;
}

int main() {

    test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}