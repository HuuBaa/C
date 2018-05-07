#include <stdio.h>
#include <stdlib.h>
#define N 30
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
	float s,t; //t通项，s求的和
	s = 0;
	t = x;

	for (int i = 2; i <= 10000; i++)
	{	
		s = s + t;
		t = -1 * t*x*x / ((2*i-2)*(2*i-1));	
	}
	return s;
}


int main()
{	

	//长方形面积=长*宽

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


	/*斐波那契数列
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


	////杨辉三角
	//int a[N][N] = { 0 };
	//int n;
	//printf("请输入阶数！");
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




