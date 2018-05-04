#include <stdio.h>
#include <stdlib.h>

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

	
	printf("%f", Sin(3.1415/6));

	system("pause");
	return 0;
}




