#include"strarr.h"




void test()
{
	strarr p1("�����յ��磬");
	strarr p2("ѧC������࣡");
	cout << p1.m_strarr << endl;
	cout << p2.m_strarr << endl;

	strarr p3 = "aaaaaaa";


	strarr p4 = "aaaaaaa";


	p3 = "aaaaaaaaa";


	
	p3 = p1 + p2;//p3(p1+p2);
	
	cout << p3.m_strarr << endl;

	if (p3 == "aaaa")
	{
		cout << "��ͬ" << endl;
	}
	else
	{
		cout << "����ͬ" << endl;
	}

	

	p4 = p3 + "bbbbb";



	cout << p4.m_strarr << endl;
	//cout << p3[3] << endl;

}






int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}