#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test()
{

	int *p = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		p[i] = i + 1;
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << p[i] << endl;
	}
	//cout << p << endl;
	
	delete[] p;
}




int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}