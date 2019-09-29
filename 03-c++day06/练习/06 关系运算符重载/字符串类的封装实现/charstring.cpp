#include"charstring.h"

String::String()
{
	cout << "Ĭ�Ϲ������" << endl;
}

String::String(char *name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->size = strlen(name) + 1;
	//cout << "���������:" << this->name << endl;

}
//�������캯��
String::String(const String &p1)
{
	this->name = new char[strlen(p1.name)+1];
	strcpy(this->name, p1.name);
	this->size = p1.size;
}




String::~String()
{
	if (this->name != NULL)
	{
		delete[]this->name;
		this->name = NULL;
	}
	//cout << "��������" << endl;
}
//����<<�����
ostream& operator<<(ostream &cout, String &p)
{
	cout << p.name;
	return cout;
}
//����>>����
istream& operator>>(istream &cin, String &p)
{
	char buf[1024] = { 0 };
	cin >> buf;
	if (p.name != NULL)
	{
		delete[]p.name;
		p.name = NULL;
	}
	p.name = new char[strlen(buf) + 1];
	memset(p.name, 0, strlen(buf) + 1);
	strncpy(p.name, buf, strlen(buf) + 1);
	return cin;
}
//����+���㣬������������
String String::operator+(String &p1)
{
	//�����Ѿ���һ
	int size = strlen(p1.name) + this->size + 1;

	char *temp = new char[size];

	memset(temp, 0, size);
	strcat(temp, this->name);
	strcat(temp, p1.name);
	
	String str(temp);
	//if (temp != NULL)
	
		delete[]temp;
		//temp = NULL;
	return str;
}
//==���� ���ð汾
bool String::operator==(String &p1)
{
	if (strcmp(this->name, p1.name)==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//==���� ָ��汾
bool String::operator==(char *p)
{
	if (strcmp(this->name, p) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//[]������
char String::operator[](int i)
{
	if (i >= this->size)
	{
		cout << "��������������ַ�����" << endl;
		return NULL;
	}
	return this->name[i];
}

//��ֵ����汾1
String & String::operator=(String &p1)
{
	if (this->name != NULL)
	{//���ͷ�ԭ�е�����
		//���¿����٣����ݽ����ַ������ȵ��ڴ�
		delete[]this->name;
		this->name = NULL;
	}
	this->name = new char[strlen(p1.name) + 1];
	memset(this->name, 0, strlen(p1.name) + 1);
	strcpy(this->name, p1.name);
	return *this;
}

//��ֵ����汾2
String & String::operator=(char *p)
{
	if (this->name != NULL)
	{
		delete[]this->name;
		this->name = NULL;
	}
	this->name = new char[strlen(p) + 1];
	memset(this->name, 0, strlen(p) + 1);
	strcpy(this->name, p);
	return *this;
}

char String::operator*()
{
	return *this->name;
}