#include <stdio.h>
#include <stdlib.h>


int * arr2(int arr[], int n)// [-213,023] => [-1,0,1]
{
	int *q;

	q = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		if (arr[i] > 0)
		{
			*(q + i) = 1;
		}
		else if (arr[i] < 0)
		{
			*(q + i) = -1;
		}
		else
		{
			*(q + i) = 0;
		}
	}

	return q;
}


int strLength(char *str)
{	
	int i=0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

void strcopy(char *str1,char *str2)
{	
	int i = 0;
	while (str2[i] != '\0')
	{	
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}

void Int2Str(int num, char *s)//数字转换字符串
{
	int r;
	int i=0;
	int length=0;
	int low=0;
	int high;

	if (num < 0)
	{	
		s[0] = '-';
		low = 1;
		i = 1;
		length = 1;
		num = -num;
	}

	if (num == 0)
	{
		s[i] = '0';
		i++;
	}

	while (num > 0)
	{
		r = num % 10;
		num = num / 10;
		s[i] = r + '0' - 0;
		length++;
		i++;
	}
	s[i] = '\0';


	high = length - 1;
	while (low<high)
	{
		int t = s[low];
		s[low] = s[high];
		s[high] = t;
		low++;
		high--;
	}

}


int main()

{	

	

	////数字转换字符串
	//char s[20];
	//int num = 1230;
	//Int2Str(num, s);
	//puts(s);

	/*char s[] = "我靠你妹啊";
	char s1[20];
	strcopy(s1, s);
	puts(s1);

	int n = strLength(s);
	printf("length:%d", n);*/


	/*char *p[]= {"sad","das"}; //二重指针表示字符串数组
	char **q;
	q = p;
	for (int i = 0; i < 2; i++)
	{
		printf("%s\n", *q);
		q++;
	}

	char s[][4] = { "sad","das"};*/


	//int a[5] = { 2,-23,21,0,-21 };

	//int *p = NULL;
	//p = arr2(a, 5);


	//for (int i = 0; i < 5; i++)
	//{
	//	printf("*(p + %d) : %d\n", i, p[i]);
	//}

	//free(p);


	//数组用指针逆序
	/*int a[5] = { 1,2,3,4,5 }; 
	int *p,*q;
	int i, j;
	p = a;
	q = &a[4];

	while (p < q)
	{
		int t;
		t = *p;
		*p = *q;
		*q = t;
		p++;
		q--;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d", *(a+i));
		printf("\n");
	}*/



	/*
	int *a=NULL;
	int n;
	scanf_s("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	if (a == NULL)
	{
		printf("内存不足");
		exit(0);
	}
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i < n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	for (int i = 0; i < n; i++)
	{
		if ((i + 1) % 5 == 0)
		{
			printf("%-12d\n", a[i]);
		}
		else
		{
			printf("%-12d", a[i]);
		}

	}*/

	/* 输入数字排序
	int n;
	int *p;
	printf("请输入排序数字的个数：\n");
	scanf_s("%d", &n);
	p = (int *)malloc(n*sizeof(int));
	printf("请输入%d个数字的个数\n",n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", p + i);
	}
	printf("--------------------------\n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (p[j] > p[j+1])
			{
				int t;
				t = p[j];
				p[j] = p[j+1];
				p[j + 1] = t;
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		if ((i + 1) % 5 == 0)
		{
			printf("%-6d\n", p[i]);
		}
		else
		{
			printf("%-6d", p[i]);
		}

	}
	*/


	//struct node {
	//	int data;
	//	node *next;
	//};

	//node *head;
	//node *p1, *p2;
	//p2 = (node*)malloc(sizeof(node*));
	//head = 0;
	//for (int i = 0; i < 5; i++)
	//{	
	//	p1 = (node*)malloc(sizeof(node*));
	//	p1->data = i;
	//	if (head == 0)
	//	{
	//		head = p1;
	//		p2 = p1;
	//	}
	//	else
	//	{
	//		p2->next = p1;
	//		p2 = p1;
	//	}
	//}
	//p2->next = 0;
	////输出链表

	//node *p;
	//p = head;
	//while (p != 0)
	//{
	//	printf("%d ->", p->data);
	//	p = p->next;

	//}
	//printf("\n");

	////删除链表

	//p1 = head;
	//while (p1->data!=2)
	//{	
	//	p2 = p1;
	//	p1 = p1->next;
	//}
	//p2->next = p1->next;

	//

	////输出链表
	//
	//p = head;
	//while (p != 0)
	//{
	//	printf("%d ->", p->data);
	//	p = p->next;

	//}



	int arr[5][2] = { 1,2,3,4,5,6,7,8,9,10 };
	int (*pp)[2];
	pp = arr;
	printf("%d", **pp);
	
	system("pause");
	return 0;
}