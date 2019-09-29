//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
//class Person
//{
//
//public:
//	Person(char *p)
//	{
//		
//		this->p1 = new char[strlen(p) + 1];
//		strcpy(this->p1, p);
//	}
//
//	Person& operator=(const Person &p)
//	{
//		if (this->p1 != NULL)
//		{
//			delete[]this->p1;
//			p1 = NULL;
//		}
//		this->p1 = new char[strlen(p.p1) + 1];
//		strcpy(p1, p.p1);
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "析构函数调用" << endl;
//		if (this->p1 != NULL)
//		{
//			delete[]p1;
//			//this->p1 = NULL;
//		}
//	}
//	char *p1;
//};
//
//
//void test()
//{
//	Person p1("狗子");
//	Person p2("坦克");
//
//	p1 = p2;
//	cout << p1.p1 << endl;
//	cout << p2.p1 << endl;
//}
//
//
//
//int main(){
//
//
//	test();
//	system("pause");
//	return EXIT_SUCCESS;
//}