#include <stdio.h>
#include <stdlib.h>
#define N 8
#define SPACE 32
int Sum(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	return sum;
}

int power(int x, int y)
{
	int z = 1;
	for (int i = 0; i < y; i++)
	{
		z *= x;
	}
	return z;
}

float Sin(float x)
{
	float s,t; //tͨ�s��ĺ�
	s = 0;
	t = x;

	for (int i = 2; i <= 10000; i++)
	{	
		s = s + t;
		t = -1 * t*x*x / ((2*i-2)*(2*i-1));	
	}
	return s;
}


void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}



void insertArray(int arr[],int n,int key)//��key���뵽ǰn�������ź����arr��
{
	for (int i = n-1; i >= 0; i--)
	{
		if (key > arr[i])
		{
			arr[i+1] = key;
			break;
		}
		else
		{
			arr[i + 1] = arr[i];
			arr[i] = key;
		}
	}
	
}


void SelectArray(int arr[], int n)
{
	int k;
	int t;
	for (int i = 0; i < n; i++)
	{	
		k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[k])
				k = j;
			if(k!=i)
			{
				t = arr[i];
				arr[i] = arr[k];
				arr[k] = t;
			}
		}
	}
}


void BubleArray(int arr[], int n)
{
	int t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

int main()
{	






	//int array1[N] = {10,1,4,3,9,8,7,2};
	//printArray(array1, N);

	////��������
	//for (int i = 1; i < N; i++)
	//{
	//	insertArray(array1, i, array1[i]);
	//}
	
	//ѡ������
	//SelectArray(array1, N);

	//ð������
	//BubleArray(array1, N);

	//printArray(array1, N);
	



	//���������=��*��

	/*double length, width, area;
	length = 3;
	width = 4;

	area = length*width;

	printf("%f", area);*/

	//printf("%d,%d", Sum(50), Sum(100));

	//printf("2^10=%d", power(2,10));

	
	/*printf("%f", Sin(3.1415/6));*/

	//int arr[N];
	//int k;
	//for (int i = 0; i < N; i++)
	//{
	//	scanf_s("%d", &arr[i]);
	//}
	//for (int i = 0; i < N-1; i++)
	//{
	//	for (int j = i+1; j < N; j++)
	//	{
	//		if (arr[j]<arr[i])
	//		{
	//			k = arr[j];
	//			arr[j] = arr[i];
	//			arr[i] = k;
	//		}
	//	}
	//}

	//for (int i = 0; i < N; i++)
	//{
	//	printf("%d ", arr[i]);
	//}


	/*쳲���������
	int f[40];
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < 40; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	for (int i = 0; i < 40; i++)
	{
		printf("%d,",f[i]);
			
	}*/


	////�������
	//int a[N][N] = { 0 };
	//int n;
	//printf("�����������");
	//scanf_s("%d", &n);

	//for (int i = 0; i < n; i++)
	//	a[i][0] = 1;

	//for (int i = 0; i < n; i++)
	//	a[i][i] = 1;

	//for (int i = 2; i < n; i++)
	//{
	//	for (int j = 1; j < i; j++)
	//	{
	//		a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
	//	}
	//}

	//for (int i = 0; i < n; i++)
	//{	
	//	
	//	for (int j = 0; j <n-i; j++)
	//	{
	//		printf("%3c", SPACE);
	//	}


	//	for (int j = 0; j <= i; j++)
	//	{
	//		printf("%6d", a[i][j]);
	//	}
	//	printf("\n");
	//}

	


	system("pause");

	return 0;
}




