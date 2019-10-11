#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

/*
map构造函数
map<T1, T2> mapTT;//map默认构造函数:
map(const map &mp);//拷贝构造函数
3.8.2.2 map赋值操作
map& operator=(const map &mp);//重载等号操作符
swap(mp);//交换两个集合容器

3.8.2.3 map大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空
3.8.2.4 map插入数据元素操作
map.insert(...); //往容器插入元素，返回pair<iterator,bool>
map<int, string> mapStu;
// 第一种 通过pair的方式插入对象
mapStu.insert(pair<int, string>(3, "小张"));
// 第二种 通过pair的方式插入对象
mapStu.inset(make_pair(-1, "校长"));
// 第三种 通过value_type的方式插入对象
mapStu.insert(map<int, string>::value_type(1, "小李"));
// 第四种 通过数组的方式插入值
mapStu[3] = "小刘";
mapStu[5] = "小王";
*/

void test01() {
    map<int, int> m;
    // map 插入值 // 4种方式
    //第一种
    m.insert(pair<int, int>(1, 10));
    //第二种 推荐
    m.insert(make_pair(2, 20));
    //第三种 不推荐
    m.insert(map<int, int>::value_type(3, 30));
    //第四种 如果保证key存在 ，那么可以通过[]访问
    m[4] = 40; // 键值对

    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << "key = " << it->first << "    value = " << it->second << endl;
    }

    cout << "m[4] : " << m[4] << "  m.size : " << m.size() << endl;
    cout << "m[5] : " << m[5] << "   m.size : " << m.size() << endl; // 若键不存在的则自动插入键，默认值为0

    cout << string(30, '-') << endl;

    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << "key = " << it->first << "    value = " << it->second << endl;
    }

    if (m.empty()) {
        cout << "空" << endl;
    } else {
        cout << "size = " << m.size() << endl;
    }
}

/*
map删除操作
clear();//删除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg,end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(keyElem);//删除容器中key为keyElem的对组。
3.8.2.6 map查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/
void test02() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;
    m[5] = 50;

    m.erase(3); // 删除key为3的
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << "key = " << it->first << " ， value = " << it->second << endl;
    }

    map<int, int>::iterator pos = m.find(2); // 查找key为2的
    if (pos != m.end()) {
        cout << "找到 key：" << pos->first << "  value:" << pos->second << endl;
    } else {
        cout << "未找到" << endl;
    }

    int num = m.count(3); // map的count 要么0 要么1
    cout << "num = " << num << endl;

    // lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    map<int, int>::iterator ret = m.lower_bound(3);
    if (ret != m.end()) {
        cout << "lower_bound 中 key:" << ret->first << " ,  value: " << ret->second << endl;
    } else {
        cout << "未找到" << endl;
    }

    // upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
    ret = m.upper_bound(3);
    if (ret != m.end()) {
        cout << "upper_bound 中 key:" << ret->first << " ,  value: " << ret->second << endl;
    } else {
        cout << "未找到" << endl;
    }

    // equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
    pair<map<int, int>::iterator, map<int, int>::iterator> ret2 = m.equal_range(3);
    if (ret2.first != m.end()) {
        cout << "找到了equal_range 中的lower_bound 的key " << ret2.first->first << " value: " << ret2.first->second
             << endl;
    } else {
        cout << "未找到" << endl;
    }
    if (ret2.second != m.end()) {
        cout << "找到了equal_range 中的upper_bound 的key " << ret2.second->first << " value: " << ret2.second->second
             << endl;
    } else {
        cout << "未找到" << endl;
    }
}

// map 自动排序，修改自动排序规则需用仿函数重载()
//修改自动排序规则
class myCompare {
  public:
    // 仿函数
    // 重载()
    bool operator()(int v1, int v2) { //
        return v1 > v2;
    }
};

void test03() {
    //从大到小排序
    map<int, int, myCompare> m; // 修改自动排序规则
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;

    for (map<int, int, myCompare>::iterator it = m.begin(); it != m.end(); it++) {
        cout << "key: " << it->first << " value: " << it->second << endl;
    }
}

int main() {

    // test01();

    // test02();

    test03();

    // system("pause");
    return EXIT_SUCCESS;
}