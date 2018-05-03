#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main() {
	int i, j;
	int x = 10;
	int y = 5;
	char input;

	int ny = 5; 

	int isFired = 0;
	int isKilled = 0;

	while (1)
	{	
		//清屏
		system("cls");


		//打印靶子
		if (isKilled == 0)
		{
			for (i = 0; i < ny; i++)
				printf(" ");
			printf("+\n");
		}
		

		//子弹打印
		if (isFired)
		{
			for (i = 0; i < x; i++)
			{
				for (j = 0; j < y; j++)
				{
					printf(" ");
				}
				//打印子弹
				printf("  |\n");
			}

			//击中判断
			if (y + 2 == ny) 
				isKilled = 1;

			//发射后子弹消失，进入下一循环
			isFired = 0;
			continue;

		}
		else
		{
			for (i = 0; i < x; i++)
				printf("  \n");
		}

		//打印飞机
		for (j = 0; j < y; j++)
			printf(" ");
		printf("  *\n");
		for (j = 0; j < y; j++)
			printf(" ");
		printf("*****\n");
		for (j = 0; j < y; j++)
			printf(" ");
		printf(" * * \n");

		//获取指令
		input = _getch();
		if (input == 's') x++;
		if (input == 'w') x--;
		if (input == 'a') y--;
		if (input == 'd') y++;
		if (input == ' ') isFired = 1;

	}
	return 0;
}
