#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FILENAME1 "./student1.txt"
#define FILENAME2 "./student2.txt"

//����ѧ����Ϣ�ṹ��
typedef struct _tag_Student
{
	char name[64];
	int age;
}Student;
//����ڵ�
typedef struct _listNode
{
	Student *stu; 
	struct _listNode *next;
}ListNode;

/*
��������:��studentInfo��ָ����ַ�������ȡ��ѧ�����������䣬�����浽һ���ṹ������С�
��������:studentInfo��ָ�����ѧ��name��age��һ���ַ�����
stu��ָ�����ڱ���ѧ����Ϣ�Ľṹ�塣
��������ֵ: �ɹ�����0��ʧ�ܷ���-1��
*/

int getStudentInfo(const char *strudentInfo, Student *stu)
{
	if (NULL == strudentInfo || NULL == stu)
	{
		return -1;
	}
	const char *pbegin = NULL;
	const char *pend = NULL;
	//�����ַ������õ�ѧ����Ϣname ��age
	//name =haha age=23
	//�����ַ�����"="���ֵ�λ��
	pbegin = strchr(strudentInfo, '=');
	pbegin++;//ȥ���ո�
	while (*pbegin == ' ')
		pbegin++;
	pend = pbegin;
	while (*pend != ' ')//��pbegin��λ�����������ҵ���һ��Ϊ�ո���ַ�
		pend++;
	strncpy(stu->name, pbegin, pend - pbegin);
	pbegin = strchr(pend, '=');
	pbegin++;
	while (*pbegin == ' ')
		pbegin++;
	sscanf(pbegin, "%d", &stu->age);

	return 0;
}
/*
��������:��ѧ������Ϣ��age�Ӵ�С��˳����뵽������
��������:
��������ֵ: �ɹ� 0 ,ʧ�� -1
*/
int insertNodeByAge(ListNode *head, Student *stu)
{
	if (NULL == head || NULL == stu)
	{
		return -1;
	}

	ListNode *pCur = NULL;
	ListNode *pPre = NULL;
	ListNode *newNode = NULL;
	pPre = head;
	pCur = pPre->next;
	while (pCur!=NULL)
	{
		if (pCur->stu->age > stu->age)
		{
			pPre = pCur;
			pCur = pCur->next;
		}
		else
		{
			break;
		}
	}

	newNode = (ListNode *)malloc(sizeof(ListNode));
	if (NULL == newNode)
	{
		return -1;
	}
	newNode->stu = stu;
	newNode->next = pCur;
	pPre->next = newNode;

	return 0;

}

/*
��������:����������ѧ������Ϣд���ļ���
��������:
��������ֵ:
*/

int writeToFile(ListNode *head, const char *filename)
{
	if (NULL == head || NULL == filename)
	{
		return -1;
	}
	FILE *fp = NULL;
	ListNode *pCur = NULL;

	fp = fopen(filename, "w");
	if (NULL == fp)
	{
		return -1;
	}
	pCur = head->next;
	while (pCur != NULL)
	{
		fprintf(fp, "name=%s age=%d", pCur->stu->name, pCur->stu->age);
		pCur = pCur->next;
	}
	fclose(fp);
	return 0;
}


void destoryListNode(ListNode * head)
{
	if (NULL == head)
	{
		return;
	}
	ListNode *pCur = head;
	while (head != NULL)
	{
		pCur= pCur->next;
		if (head->stu != NULL)
		{
			free(head->stu);
			head->stu = NULL;
		}
		free(head);
		head = pCur;
	}

}

void test()
{
	FILE *fp = NULL;
	ListNode *head = NULL;
	char buf[BUFSIZ] = { 0 };

	fp = fopen(FILENAME1, "r");
	if (NULL == fp)
	{
		printf("�ļ���ʧ��\n");
		exit(1);
	}
	head = (ListNode *)malloc(sizeof(ListNode));
	if (NULL == head)
	{
		printf("mallo error!!\n");
		exit(1);
	}
	head->stu = NULL;
	head->next = NULL;

	while (fgets(buf, BUFSIZ, fp) != NULL)
	{
		Student *stu = (Student *)malloc(sizeof(Student));
		memset(stu, 0, sizeof(Student));
		if (NULL == stu)
		{
			printf("malloc error\n");
			exit(1);
		}

		getStudentInfo(buf, stu);

		insertNodeByAge(head, stu);
	}
	writeToFile(head, FILENAME2);
	destoryListNode(head);


}






int main()
{

	test();


	system("pause");

}