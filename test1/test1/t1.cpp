#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
int main()
{

	//�������������
	/*
	float a, b, c, s, area;

	scanf_s("%f%f%f", &a, &b, &c);
	if (!((a+b>c)&&(a+c>b)&&(b+c>a)))
	{
		printf("����������");
	}
	else
	{
		s = 1.0 / 2 * (a + b + c);
		area = sqrt(s*(s - a)*(s - b)*(s - c));

		printf("a=%f,b=%f,c=%f,s=%f\n", a, b, c, s);
		printf("area=%f\n", area);
	}
	*/


	//��ӡ�Ǻ�
	//int n, m; //n�У�m��
	//printf("������ ���� ����:\n");
	//scanf_s("%d%d", &n, &m);

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}



	//쳲���������
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


	//�žų˷���
	//int i, j;
	////��һ��
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



	//ˮ�ɻ���
	//int a, b, c, i; // a��λ ��bʮλ ��c��λ
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


	////����С��
	//int x, y; //xΪ�У�yΪ��
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

	//	system("cls"); //��������

	//	for (int i = 0; i < x; i++) //��ӡ��
	//	{
	//		printf("\n");
	//	}

	//	for (int j = 0; j < y; j++) //��ӡ��
	//	{
	//		printf(" ");
	//	}

	//	printf("O\n"); //С��

	//	if (x == bottom || x == top)
	//	{
	//		velocity_x = -1 * velocity_x;
	//		printf("\a"); //����
	//	}

	//	if (y == left || y == right)
	//	{
	//		velocity_y = -1 * velocity_y;
	//		printf("\a");
	//	}

	//}


	//�Ǻ���
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
