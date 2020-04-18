#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

/*
copy算法 将容器内指定范围的元素拷贝到另一容器中
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param dest 目标起始迭代器
*/
void test01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    vector<int> vTarget;
    vTarget.resize(v.size() + 10);

    // copy算法 将容器内指定范围的元素拷贝到另一容器中,目标容器必须足够大
    copy(v.begin(), v.end(), vTarget.begin());

    for_each(vTarget.begin(), vTarget.end(), [](int val) { cout << val << " "; });
    cout << endl;

    // copy(vTarget.begin(), vTarget.end(), ostream_iterator<int>(cout, " "));
}

/*
replace算法 将容器内指定范围的旧元素修改为新元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param oldvalue 旧元素
@param oldvalue 新元素

replace_if算法 将容器内指定范围满足条件的元素替换为新元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param callback函数回调或者谓词(返回Bool类型的函数对象)
@param oldvalue 新元素
*/
class MyCompare {
  public:
    bool operator()(int v) {
        return v > 3;
    }
};
void test02() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    // replace算法 将容器内指定范围的旧元素修改为新元素
    replace(v.begin(), v.end(), 3, 333); // 把容器中的3  替换成333
    for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
    cout << endl;

    // replace_if 条件替换
    // 把容器指定范围中大于3的数字 都替换成 88
    replace_if(v.begin(), v.end(), MyCompare(), 88);
    for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
    cout << endl;
}

/*
swap算法 互换两个容器的元素
@param c1容器1
@param c2容器2
*/
void test03() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(30);
    v2.push_back(20);
    v2.push_back(40);

    cout << "交换前数据：" << endl;
    for_each(v1.begin(), v1.end(), [](int val) { cout << val << " "; });
    cout << endl;
    for_each(v2.begin(), v2.end(), [](int val) { cout << val << " "; });
    cout << endl;

    // swap算法 互换两个容器的元素
    swap(v1, v2);

    cout << "交换后的数据:" << endl;
    for_each(v1.begin(), v1.end(), [](int val) { cout << val << " "; });
    cout << endl;
    for_each(v2.begin(), v2.end(), [](int val) { cout << val << " "; });
    cout << endl;
}

/*
merge算法 容器元素合并，并存储到另一容器中(依然有序)
注意：这两个容器必须是有序的
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
*/

void test04() {
    // 这两个容器必须是有序的
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {3, 4, 5, 6, 7};

    vector<int> vTarget;
    vTarget.resize(v1.size() + v2.size()); // 分配内存

    // merge容器元素合并，并存储到另一容器中(依然有序)
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), vTarget.end(), [](int v) { cout << v << " "; });
    cout << endl;
}

int main() {

    test01();

    test02();

    test03();

    test04();

    return EXIT_SUCCESS;
}