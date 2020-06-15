// #include "Person.h"

//建议 模板不要做分文件编写,写到一个类中即可,类内进行声明和实现，最后把后缀名改为.hpp 约定俗成

// // 类模板实现
// template <class T1, class T2>
// Person<T1, T2>::Person(T1 name, T2 age) { // 类<>也必须声明类型
//     this->m_Name = name;
//     this->m_Age = age;
// }

// // 类模板实现
// template <class T1, class T2> // 每个方法都要声明template
// void Person<T1, T2>::showPerson() { // 类<>也必须声明类型
//     cout << "姓名：" << this->m_Name << "  年龄：  " << this->m_Age << endl;
// }
