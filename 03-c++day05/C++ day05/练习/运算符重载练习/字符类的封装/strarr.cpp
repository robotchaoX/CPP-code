#include"strarr.h"


strarr::strarr(const char* str)
{

	this->m_strarr = new char[strlen(str) + 1];

	memset(this->m_strarr, 0, strlen(str) + 1);
	strcpy(this->m_strarr, str);
	this->strsize = strlen(str);

}



//��������
strarr::~strarr()
{
	if (this->m_strarr != NULL)
	{
		delete[]this->m_strarr;
 		this->m_strarr = NULL;
	}
}






//�ַ�������
int strarr::getstrsize()
{
	return this->strsize;
}


//����=�����
strarr & strarr::operator=(strarr & str)
{

	if (this->m_strarr != NULL)
	{
		delete[]this->m_strarr;
		this->m_strarr = NULL;
	}

	this->m_strarr = new char[strlen(str.m_strarr) + 1];
	strcpy(this->m_strarr, str.m_strarr);
	this->strsize = str.strsize;
	cout << this->strsize << endl;

	return *this;
}

strarr & strarr::operator=(const char * str)
{


	//if (this->m_strarr != NULL)
	//{
	//	delete[]this->m_strarr;
	//	this->m_strarr = NULL;
	//}
	this->m_strarr = new char[strlen(str) + 1];
	strcpy(this->m_strarr, str);
	this->strsize = strlen(str) + 1;
	cout << this->strsize << endl;
	return *this;

}



//����[]�����
char strarr::operator[](int i)
{
	return this->m_strarr[i]; 

}

//����==�����
bool strarr::operator==(strarr & str)
{
	if (strcmp(this->m_strarr, str.m_strarr) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//����==
bool  strarr::operator==(char *str)
{
	if (strcmp(this->m_strarr, str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}



//����+
strarr strarr::operator+(const strarr &arr)
{

	int atrsize = this->strsize + strlen(arr.m_strarr) + 1;
	char *temp = new char[atrsize];
	memset(temp, 0, atrsize);

	strcat(temp, this->m_strarr);
	strcat(temp, arr.m_strarr);

	strarr mystr(temp);

	delete []temp;
	temp = NULL;
	return mystr;
}

strarr strarr::operator+(const char *str)
{
	int atrsize = strlen(this->m_strarr)+ strlen(str) + 1;
	cout << atrsize << endl;

	char *temp = new char[atrsize];
	memset(temp, 0, atrsize);

	strcat(temp, this->m_strarr);
	strcat(temp,str);

	strarr mystr(temp);

	delete[]temp;
	temp = NULL;
	return mystr;

}


//��������
strarr::strarr(const strarr &p)
{

	this->m_strarr = new char[strlen(p.m_strarr) + 1];
	memset(m_strarr, 0, strlen(p.m_strarr) + 1);
	strcpy(this->m_strarr, p.m_strarr);
	this->strsize = p.strsize;

}


