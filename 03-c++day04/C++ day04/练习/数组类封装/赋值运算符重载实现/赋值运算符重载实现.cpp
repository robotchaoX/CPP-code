#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(){};
	Person(char *person)
	{
		this->person = new char[strlen(person)+1];
		strcpy(this->person, person);
	}

	//=��������,
	void operator=(Person &p)
	{
		if (this->person != NULL)
		{
			delete[]this->person;
			this->person = NULL;
		}

		this->person = new char[strlen(p.person) + 1];
		strcpy(this->person, p.person);
	}


	~Person()
	{
		if (this->person != NULL)
		{
			delete[]person;
			//this->person = NULL;
		}
	}



	void show()
	{
		cout << this->person << endl;
	}


	char *person;

};

void test()
{
	Person p1("����");
	Person p2("����");
	p2 = p1;
	p2.show();

}





int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}