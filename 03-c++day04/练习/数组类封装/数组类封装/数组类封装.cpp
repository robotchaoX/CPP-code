#include"MyArr.h"


void test()
{

	MyaArray *p = new MyaArray(30);
	MyaArray p2(*p);

	for (int i = 0; i < 10; ++i)
	{
		p2.PushBack(i);
	}

	for (int i = 0; i < p2.GetLength(); ++i)
	{
		cout << p2.GetData(i)<< endl;
	}


}
void main()
{
	test();
	system("pause");

}