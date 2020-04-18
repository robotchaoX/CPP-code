#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

/*vector构造函数
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。
 */
void test01() {
    // 默认构造
    vector<int> v;
    v = {2, 2, 2};
    vector<int> v5(v); // 拷贝构造
    printVector(v5);

    vector<int> v9(20); // 20个数,默认0,初始化vector
    printVector(v9);

    vector<int> v3(4, 3); // 4个3 初始化vector
    printVector(v3);

    // 直接初始化vector
    vector<int> v0 = {1, 1, 1, 1, 1, 1}; // 直接数组初始化vector
    printVector(v0);

    // 数组初始化vector，数组 转 vector
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(int)); // 数组初始化vector
    printVector(v1);

    // vector值初始化vector
    vector<int> v2(v0.begin(), v0.end()); // vector初始化vector
    printVector(v2);
}

/**
vector常用赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。
 */
void test02() {
    vector<int> v0 = {2, 2, 2, 2, 2, 2}; // 直接数组初始化vector
    vector<int> v1(20);
    // =赋值,改变容器大小
    v1 = v0;
    cout << "v1.size()" << v1.size() << endl;
    printVector(v1);

    // assign赋值,改变容器大小
    vector<int> v2(2); // 2个初始化vector
    v1.assign(v2.begin(), v2.end());
    cout << "v1.size()" << v1.size() << endl;
    printVector(v1);

    vector<int> v3(300);
    vector<int> v4(3);
    v3.swap(v4);
    printVector(v3);
    cout << "交换后v3的大小 : " << v3.size() << endl;
}

/*
vector大小操作
size();//返回容器中元素的个数
capacity();//容器的容量
empty();//判断容器是否为空
resize(int
num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num,
elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/
void test03() {
    vector<int> v5(4);
    cout << "v5.size(): " << v5.size() << endl;
    // size大小 等于 迭代器首位差end-begin
    cout << "v5.end()-v5.begin(): " << v5.end() - v5.begin() << endl;

    if (v5.empty()) {
        cout << "v5空" << endl;
    } else {
        cout << "v5不空" << endl;
    }

    vector<int> v6 = {3, 2, 1};
    v6.resize(8); //增长，默认补0
    v6.resize(20, -11); //第一个参数总长20，第二个参数是新增的默认值-11
    printVector(v6);

    v6.resize(10); // 截断
    printVector(v6);
    v6.resize(2, -55); // 截断，默认值-55无效
    printVector(v6);

    vector<int> vc;
    for (int i = 0; i < 10; i++) {
        vc.push_back(i); // capacity() 增长是系统定的 2^n ??
        cout << "capacity : " << vc.capacity() << endl; // v.capacity()容器的容量
    }

    vector<int> v;
    // 若已知数据长度很大，预留空间效率高
    v.reserve(100000); //预留出空间大小
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
    }
    cout << "v的容量 : " << v.capacity() << endl;
    cout << "v的大小 : " << v.size() << endl;

    v.resize(3); // resize只改变size不改变capacity
    cout << "resize 后 v的容量 : " << v.capacity() << endl;
    cout << "resize 后 v的大小 : " << v.size() << endl;

    // 巧用swap收缩capacity空间 vector<int>(v).swap(v);
    vector<int>(v).swap(v); // vector<int>() 匿名对象 //  vector<int>(v) 用v初始化匿名对象，匿名对象与v的size一致
    cout << "swap 后 v的容量 ： " << v.capacity() << endl;
    cout << "swap 后 v的大小 ： " << v.size() << endl;
}

/**
 * reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
 */
void test04() {
    vector<int> v;

    // 若已知数据长度很大，预留空间效率高
    v.reserve(100000); //预留出空间大小

    int *p = NULL;
    int num = 0;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
        if (p != &v[0]) {
            p = &v[0];
            num++; // 重新申请空间次数
        }
    }
    cout << "重新申请空间次数:" << num << endl;
    // 不预留开辟100000数据用了多少次
}

/*
find算法 查找元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return 返回查找元素的位置
*/
// find查找数据 及其下标
void test41() {
    vector<int> v = {-1, 2, 9, 100, 200};

    // 查找数据是否存在,数据不存在返回end()
    vector<int>::iterator pos1 = find(v.begin(), v.end(), 2);
    if (pos1 != v.end()) {
        cout << "找到了数据：" << *pos1 << endl;
    } else {
        cout << "数据不存在" << endl;
    }

    // 查找数据对应下标
    vector<int>::iterator pos = find(v.begin(), v.end(), 2);
    if (pos != v.end()) {
        cout << "对应下标: " << pos - v.begin() << endl;
    } else {
        cout << "数据不存在" << endl;
    }
}

/*
vector数据存取操作
at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[];//返回索引idx所指的数据，越界时，运行直接报错
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素

vector插入和删除操作
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
push_back(ele); //尾部插入元素ele
pop_back();//删除最后一个元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器指向的元素
clear();//删除容器中所有元素
*/
void test05() {
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);

    // 数据存取
    v[2] = 222; // 存
    cout << v[2] << endl; // 取
    v.at(3) = 333;
    cout << v.at(3) << endl;

    // 首值/尾值
    cout << "v.front() : " << v.front() << endl;
    cout << "v.back() : " << v.back() << endl;

    // 插值
    v.insert(v.begin() + 2, 4, -11); //参数1 迭代器， 参数2 N个数， 参数3 具体插入的内容
    printVector(v);

    // 合并，将vec1和vec2的内容合并到vec3中
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2 = {4, 5, 6};
    vector<int> vecall;
    //.vec1,vec2的值insert插入到vecall之后
    vecall.insert(vecall.end(), vec1.begin(), vec1.end());
    vecall.insert(vecall.end(), vec2.begin(), vec2.end());
    printVector(vecall);
    cout << "-----" << endl;

    // 尾插
    v.push_back(555);
    //尾删
    v.pop_back();
    printVector(v);

    //删除值
    v.erase(v.begin());
    printVector(v);

    // v.erase(v.begin(), v.end());
    v.clear(); //清空所有数据
    if (v.empty()) {
        cout << "为空" << endl;
    }
}

void test06() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    // printVector(v);

    // 顺序遍历
    // iterator 顺序迭代器 begin首 end尾
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    //逆序遍历
    // reverse_iterator 逆序迭代器 rbegin逆首 rend逆尾
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // vector迭代器是随机访问的迭代器  支持跳跃式访问
    vector<int>::iterator it = v.begin();
    it = it + 3;
    //如果上述写法不报错，这个迭代器是随机访问迭代器
    cout << *it << endl;

    list<int> l;
    for (int i = 0; i < 10; i++) {
        l.push_back(i);
    }
    list<int>::iterator lIt = l.begin();
    // lIt = lIt + 1; //不支持随机访问
}

//排序规则,普通函数
bool myCompare(const int &v1, const int &v2) {
    return v1 > v2; // > 降序
}

void test10() {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(40);
    v1.push_back(20);
    v1.push_back(90);
    v1.push_back(50);

    for_each(v1.begin(), v1.end(), [](int val) { cout << val << " "; });
    cout << endl;

    sort(v1.begin(), v1.end()); //  默认升序, 默认算法less<int>()
    sort(v1.begin(), v1.end(), less<int>()); // 升序,默认算法 less 内置算法
    sort(v1.begin(), v1.end(), greater<int>()); // 降序, greater 内置算法
    // 自定义排序规则
    sort(v1.begin(), v1.end(), myCompare); // 比较函数

    sort(v1.begin(), v1.end(), [](int &v1, int &v2) { return v1 > v2; }); //匿名函数  lambda表达式  [](){};
    // for_each 遍历容器
    for_each(v1.begin(), v1.end(), [](int &val) { cout << val << " "; });
    cout << endl;
}

// 对类对象排序
class Frame {
  public:
    Frame() { // 默认构造
        cout << "Frame默认构造" << endl;
    }
    Frame(int tm) { // 有参构造
        this->time = tm;
        ++count_1;
        cout << "Frame有参构造 第 " << count_1 << " 次" << endl;
    }
    Frame(const Frame &ff) { // 拷贝构造
        this->time = ff.time;
        ++count;
        cout << "\t Frame拷贝构造 第 " << count << " 次" << endl;
    }

    // 排序调用为什么发生了多次不必要的拷贝??
    // 重载()，函数对象，仿函数
    bool operator()(const Frame &f1, const Frame &f2) { // 排序规则,依据time对Frame排序
        cout << "."; // 每比较一次,输出 .
        return f1.time > f2.time; //降序
    }

    int time; // 排序依据

  private:
    static int count; // 不初始化报错
    static int count_1; // 不初始化报错
};

int Frame::count = 0; // 类外初始化static
int Frame::count_1 = 0; // 类外初始化static

// 全局函数，排序规则,依据time对Frame排序
bool myCompare_c(const Frame &f1, const Frame &f2) {
    cout << "."; // 每比较一次,输出 .
    return f1.time > f2.time; //降序
}

void test11() {
    vector<Frame> v1;
    v1.reserve(10); // 必须reserve,不然每次push_back可能会拷贝扩容

    cout << "---f0---" << endl;
    Frame f1 = Frame(10); // 构造时初始化只有一次有参构造，不是先有参构造，再拷贝构造
    cout << "---f1---" << endl;
    v1.push_back(f1); // push_back发生一次拷贝构造
    Frame f2 = Frame(50);
    v1.push_back(f2);
    Frame f3 = Frame(99);
    v1.push_back(f3);
    Frame f4 = Frame(80);
    v1.push_back(f4);
    Frame f5 = Frame(20); // 有参构造
    v1.push_back(f5); // 拷贝构造
    cout << "---f5---" << endl;
    v1.push_back(Frame(90)); //先有参构造，然后拷贝构造
    v1.push_back(Frame(30));
    v1.push_back(Frame(60));
    v1.push_back(Frame(40));
    v1.push_back(Frame(70)); // push_back的拷贝构造必不可少
    cout << "----------------" << endl;

    // [](Frame val) {} // 传值发生拷贝构造
    // [](Frame &val) {} // 传引用不会拷贝构造
    // [],[=] 按值访问作用域内所有变量, [&] 按引用访问作用域内所有变量？？
    // [&](Frame val) {} // 传值发生拷贝构造？？
    // [=](Frame &val) {} // 传引用不会拷贝构造？？
    for_each(v1.begin(), v1.end(), [](Frame &val) { cout << val.time << " "; });
    cout << endl;
    cout << "----------------" << endl;

    // 自定义排序规则
    // 1.比较函数，全局函数
    // sort(v1.begin(), v1.end(), myCompare_c); // 比较函数 // 排好序必然所有拷贝一次

    // 2.匿名函数lambda表达式 []()->void{}; //Frame &f1,不会发生拷贝构造
    // [] , [=] 可以按值访问作用域内所有变量, [&] 可以按引用访问作用域内所有变量？？
    sort(v1.begin(), v1.end(), [](const Frame &f1, const Frame &f2) { // 排好序必然所有拷贝一次
        cout << "."; // 每比较一次,输出 .
        return f1.time > f2.time;
    });
    /*
    // -> bool 指定返回值类型
    sort(v1.begin(), v1.end(), [&](const Frame &f1, const Frame &f2) -> bool { // 排好序必然所有拷贝一次
        cout << "."; // 每比较一次,输出 .
        return f1.time > f2.time;
    });
    */
    // [](Frame f1, Frame f2) {} 会发生多次拷贝构造
    // [&](Frame f1, Frame f2) {} 会发生多次拷贝构造
    // [](Frame &f1, Frame &f2) {} 不会发生多次拷贝构造
    // [&](Frame &f1, Frame &f2) {} 不会发生多次拷贝构造
    /*
     sort(v1.begin(), v1.end(), [](Frame f1, Frame f2) { return f1.time > f2.time; });
     //不好，值传递发生多次拷贝构造，95次
     */

    // 3.运算符()重载比较函数,有问题?? 46次
    // sort(v1.begin(), v1.end(), Frame()); // 运算符()重载比较函数// 为什么发生了多次不必要的拷贝??

    cout << endl;
    // for_each 遍历容器显示
    for_each(v1.begin(), v1.end(), [](Frame &val) { cout << val.time << " "; });
    cout << endl;
}

//二元谓词
class MyCompare_class {
  public:
    // 重载()
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};
void test12() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    sort(v.begin(), v.end(), MyCompare_class());

    // for_each 遍历容器
    for_each(v.begin(), v.end(), [](int &val) { cout << val << " "; }); //匿名函数  lambda表达式  [](){};
}

int main() {
    test01();

    test02();

    test03();

    test04();
    test41();

    test05();

    test06();

    test10();

    test11();

    return EXIT_SUCCESS;
}