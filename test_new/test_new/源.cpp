#include <stdio.h>
#include <stdlib.h>


int * arr2(int arr[], int n)
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



int main()
{

	int a[5] = { 2,-23,21,0,-21 };

	int *p = NULL;
	p = arr2(a, 5);


	for (int i = 0; i < 5; i++)
	{
		printf("*(p + %d) : %d\n", i, p[i]);
	}

	free(p);




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

	/*
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



	printf("\n");

	system("pause");
	return 0;
}