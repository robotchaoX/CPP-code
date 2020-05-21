#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//分类
//按照参数进行分类  无参构造函数（默认构造函数）   有参构造函数
//按照类型进行分类  普通构造函数                拷贝构造函数
class Person {
  public:
    //构造和析构必须是public才能自动调用
    Person() { //无参构造函数
        cout << "默认构造函数调用" << endl;
    }

    Person(int a) { // 有参构造函数
        cout << "有参构造函数调用" << endl;
    }

    //拷贝构造函数, const type &
    Person(const Person &p) { // 常引用
        // Person(Person &p) { // 不加const也行？？必须是引用&
        m_Age = p.m_Age;
        cout << "拷贝构造函数调用" << endl;
    }

    ~Person() {
        cout << "析构函数调用" << endl;
    }

    int m_Age;
};

void test01() {
    //构造函数调用方式

    // 1.默认构造对象
    Person p1; //默认构造函数, 不要加()
    Person pppfun(); //编译器认为这行是函数的声明，是函数pppfun()声明，返回类型为Person

    // 2.有参构造
    // 括号法有参构造
    Person p2(1); //有参构造
    //! 初始化表,有参构造
    Person p21{2}; // 初始化表传参数
    Person p22 = {2}; // 隐式转换,初始化表??
    //?? 隐式类型转换的调用
    Person p71 = 100; //隐式类型转换,相当于 Person p7 = Person(100)

    //! 显式有参构造,显式说明类型
    Person p3 = Person(100); // 直接一次有参构造,不是先有参构造匿名对象再拷贝构造
    cout << "Person p3=Person(100) 等效 Person p3(100)？？" << endl;

    cout << "---" << endl;
    Person(200); //匿名对象 ,匿名对象特点，如果编译器发现了对象是匿名的，那么在这行代码结束后就释放这个对象
    cout << "释放立即匿名对象Person(200)" << endl;
    cout << "---" << endl;

    // 3.拷贝构造
    Person p4(p3); // 拷贝
    //! 初始化表,拷贝构造
    Person p51{p1};
    Person p52 = {p1}; // 隐式转换,初始化表??
    //?? 隐式转换的调用
    Person p5 = p3; // 隐式转换，拷贝构造,相当于 Person p5(p3);

    cout << "--6--" << endl;
    //! 显式拷贝构造,显式说明类型
    Person p6 = Person(p5); //直接一次拷贝构造,不是先有参拷贝构造匿名对象再拷贝构造
    cout << "Person p6=Person(p5); 等效 Person p6(p5)？？" << endl;
    cout << "--6--" << endl;

    // 4.隐式类型转换
    Person p7 = 100; //相当于调用了 Person p7 = Person(100) ，隐式类型转换
    Person p8 = p7; // 相当于  Person p8 = Person(p7); // Person p8(p7);
}

int main() {

    test01();

    // system("pause");
    return EXIT_SUCCESS;
}