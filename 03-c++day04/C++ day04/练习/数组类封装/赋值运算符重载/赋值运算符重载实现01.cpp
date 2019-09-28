#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class Person
{
public:
	Person(){};
	Person(char *person)
	{
		this->person = new char[strlen(person) + 1];
		strcpy(this->person, person);
	}

	Person& operator=(Person & per)
	{
		if (this->person != NULL)
		{
			delete this->person;
			this->person = NULL;
		}
		this->person = new char[strlen(per.person) + 1];
		strcpy(this->person, per.person);

		return *this;
	}
	void show()
	{
		cout << this->person << endl;
	
	
	}



	~Person()
	{
		if (this->person != NULL)
		{
			delete[]this->person;
		}
	
	}



	char *person;

};


void test()
{
	Person p1("╨звс");
	Person p2;
	Person p3;
	p3 = p2 = p1;
	p3.show();
	p2.show();
	p1.show();


}


int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}