#include<iostream>
#include<string>
using namespace std;




void test()
{
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	cout << "Enter a kind of feline:";
	cin >> charr1;
	cout << "Enter a kind of feline:";
	cin >> str1;
	cout << "Here are some felines:\n";


	cout << charr1 << " " << charr2 << " "
		<< str1 << " " << str2 << endl;
	cout << "The third letter in " << charr2 << " is " << charr2[2] << endl;
	cout << "The third letter in " << str2 << " is " << str2[2] << endl;

}
void test02()
{
	char charr[20];
	string str;
	//函数strlcn()从数组的第一个元素开始计算字节数，直到遇到空字符
	//对于未被初始化的数据第一个空字符的出现时随机的
	cout << "Length of string in charr before intput:"
		<< strlen(charr) << endl;
	cout << "Length of string in str before input:"
		<< str.size() << endl;
	cout << "Enter a line of text:\n";
	//getline是istream类的一个类方法
	//第一个参数是目标数组，第二个参数是数组长度
	cin.getline(charr, 20);
	cout << "You entered:" << charr << endl;
	cout << "Enter another line of text:\n";
		getline(cin, str);
		cout << "You entered:" << str << endl;
		cout << "Length of string in charr after input:"
			<< strlen(charr) << endl;
		cout << "Length of string in str after input:"
			<< str.size() << endl;
}




void main()
{
	//test();
	test02();
	system("pause");


}
