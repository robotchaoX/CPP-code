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
	//����strlcn()������ĵ�һ��Ԫ�ؿ�ʼ�����ֽ�����ֱ���������ַ�
	//����δ����ʼ�������ݵ�һ�����ַ��ĳ���ʱ�����
	cout << "Length of string in charr before intput:"
		<< strlen(charr) << endl;
	cout << "Length of string in str before input:"
		<< str.size() << endl;
	cout << "Enter a line of text:\n";
	//getline��istream���һ���෽��
	//��һ��������Ŀ�����飬�ڶ������������鳤��
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
