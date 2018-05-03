#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
int main()
{

	//计算三角形面积
	/*
	float a, b, c, s, area;

	scanf_s("%f%f%f", &a, &b, &c);
	if (!((a+b>c)&&(a+c>b)&&(b+c>a)))
	{
		printf("不是三角形");
	}
	else
	{
		s = 1.0 / 2 * (a + b + c);
		area = sqrt(s*(s - a)*(s - b)*(s - c));

		printf("a=%f,b=%f,c=%f,s=%f\n", a, b, c, s);
		printf("area=%f\n", area);
	}
	*/


	//打印星号
	//int n, m; //n行，m列
	//printf("请输入 行数 列数:\n");
	//scanf_s("%d%d", &n, &m);

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}



	//斐波那契数列
	/*
	int f1 = 1, f2 = 1;
	for (int i = 0; i < 20; i++)
	{
		printf("%d %d ", f1, f2);
		f1 = f1 + f2;
		f2 = f2 + f1;
	}
	printf("\n");
	*/


	//九九乘法表
	//int i, j;
	////第一行
	//printf("    ");
	//for (int i = 1; i <= 9; i++)
	//{
	//	printf("%3d ", i);
	//}
	//printf("\n");



	//for (j = 1; j <= 9; j++)
	//{
	//	printf("%3d ", j);
	//	for (i = 1; i <= j; i++)
	//	{	
	//		
	//		printf("%3d ", i*j);
	//	}
	//	printf("\n");
	//}



	//水仙花数
	//int a, b, c, i; // a百位 ，b十位 ，c个位
	//for (i = 100; i < 1000; i++)
	//{
	//	a = i / 100;
	//	b = i % 100 / 10;
	//	c = i % 10;
	//	if ((a*a*a + b*b*b + c*c*c) == i)
	//	{
	//		printf("%d ", i);
	//	}
	//}

	//system("pause");


	////弹跳小球
	//int x, y; //x为行，y为列
	//y = 10;
	//x = 1;
	//int velocity_x = 1;
	//int velocity_y = 1;

	//int left = 0;
	//int right = 40;
	//int top = 0;
	//int bottom = 20;

	//while (1)
	//{
	//	x = x + velocity_x;
	//	y = y + velocity_y;

	//	system("cls"); //清屏函数

	//	for (int i = 0; i < x; i++) //打印行
	//	{
	//		printf("\n");
	//	}

	//	for (int j = 0; j < y; j++) //打印列
	//	{
	//		printf(" ");
	//	}

	//	printf("O\n"); //小球

	//	if (x == bottom || x == top)
	//	{
	//		velocity_x = -1 * velocity_x;
	//		printf("\a"); //铃声
	//	}

	//	if (y == left || y == right)
	//	{
	//		velocity_y = -1 * velocity_y;
	//		printf("\a");
	//	}

	//}


	//星号塔
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < (n - i); j++)
		{
			printf(" ");
		}
		for (int k = 0; k < (2 * i - 1); k++)
		{
			printf("*");
		}
		printf("\n");
	}



	system("pause");
	return 0;
}
