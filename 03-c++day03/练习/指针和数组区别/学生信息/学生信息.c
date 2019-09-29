#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FILENAME1 "./student1.txt"
#define FILENAME2 "./student2.txt"

//定义学生信息结构体
typedef struct _tag_Student
{
	char name[64];
	int age;
}Student;
//链表节点
typedef struct _listNode
{
	Student *stu; 
	struct _listNode *next;
}ListNode;

/*
函数功能:从studentInfo所指向的字符串中提取出学生的姓名年龄，并保存到一个结构体变量中。
函数参数:studentInfo：指向包含学生name和age的一个字符串。
stu：指向用于保存学生信息的结构体。
函数返回值: 成功返回0，失败返回-1。
*/

int getStudentInfo(const char *strudentInfo, Student *stu)
{
	if (NULL == strudentInfo || NULL == stu)
	{
		return -1;
	}
	const char *pbegin = NULL;
	const char *pend = NULL;
	//处理字符串，得到学生信息name 和age
	//name =haha age=23
	//查找字符串中"="出现的位置
	pbegin = strchr(strudentInfo, '=');
	pbegin++;//去除空格
	while (*pbegin == ' ')
		pbegin++;
	pend = pbegin;
	while (*pend != ' ')//从pbegin的位置向后遍历，找到第一个为空格的字符
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
函数功能:将学生的信息按age从大到小的顺序插入到链表中
函数参数:
函数返回值: 成功 0 ,失败 -1
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
函数功能:将链表结点中学生的信息写入文件中
函数参数:
函数返回值:
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
		printf("文件打开失败\n");
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