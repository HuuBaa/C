#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "help.h"
#include <time.h>

int height, width;//边界

int pos_x, pos_y;
int enemy1_x, enemy1_y; //敌人
int enemy2_x, enemy2_y;
int enemy3_x, enemy3_y;
int enemy4_x, enemy4_y;
int enemy5_x, enemy5_y;
clock_t start, end; //时间间隔
float duration;
void startUp()//初始化
{	
	start = clock();


	height = 24;
	width = 60;

	pos_x=20;
	pos_y = 12;

	enemy1_x = 1;
	enemy1_y = 1;

	enemy2_x = 1;
	enemy2_y = 59;

	enemy3_x = 23;
	enemy3_y = 24;

	enemy4_x = 10;
	enemy4_y = 32;

	enemy5_x = 4;
	enemy5_y = 40;

	HideCursor();
}

void show()//打印画面
{
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i <= height; i++)
	{
		for (j = 0; j <= width; j++)
		{
			if (i == height)
				printf("-");//下边界	
			else if ((i == pos_x) && (j == pos_y))
				printf("o");
			else if ((i == enemy1_x) && (j == enemy1_y))
				printf("#");
			else if ((i == enemy2_x) && (j == enemy2_y))
				printf("#");
			else if ((i == enemy3_x) && (j == enemy3_y))
				printf("#");
			else if ((i == enemy4_x) && (j == enemy4_y))
				printf("#");
			else if ((i == enemy5_x) && (j == enemy5_y))
				printf("#");
			else if (j == width)
				printf("|");//右边界	
			else
				printf(" ");
		}
		printf("\n");
		
	}
	end = clock();
	duration = (float)(end - start) / CLOCKS_PER_SEC;
	printf("你坚持了%.3f秒",duration);
}



void updateWithoutInput() //用户输入无关，更新
{

	static int speed = 0;//控制刷新速度
	if (speed < 15)
		speed++;
	if (speed == 15)
	{
		if ((enemy1_x == pos_x) && (enemy1_y == pos_y))
		{
			printf("Game Over");
			system("pause");
		}
		else
		{
			if (enemy1_x > pos_x)
				enemy1_x--;
			if (enemy1_x < pos_x)
				enemy1_x++;
			if (enemy1_y > pos_y)
				enemy1_y--;
			if (enemy1_y < pos_y)
				enemy1_y++;

		}

		if ((enemy2_x == pos_x) && (enemy2_y == pos_y))
		{
			printf("Game Over");
			system("pause");
		}
		else
		{
			if (enemy2_x > pos_x)
				enemy2_x--;
			if (enemy2_x < pos_x)
				enemy2_x++;
			if (enemy2_y > pos_y)
				enemy2_y--;
			if (enemy2_y < pos_y)
				enemy2_y++;

		}


		if ((enemy3_x == pos_x) && (enemy3_y == pos_y))
		{
			printf("Game Over");
			system("pause");
		}
		else
		{
			if (enemy3_x > pos_x)
				enemy3_x--;
			if (enemy3_x < pos_x)
				enemy3_x++;
			if (enemy3_y > pos_y)
				enemy3_y--;
			if (enemy3_y < pos_y)
				enemy3_y++;

		}


		if ((enemy4_x == pos_x) && (enemy4_y == pos_y))
		{
			printf("Game Over");
			system("pause");
		}
		else
		{
			if (enemy4_x > pos_x)
				enemy4_x--;
			if (enemy4_x < pos_x)
				enemy4_x++;
			if (enemy4_y > pos_y)
				enemy4_y--;
			if (enemy4_y < pos_y)
				enemy4_y++;

		}

		if ((enemy5_x == pos_x) && (enemy5_y == pos_y))
		{
			printf("Game Over");
			system("pause");
		}
		else
		{
			if (enemy5_x > pos_x)
				enemy5_x--;
			if (enemy5_x < pos_x)
				enemy5_x++;
			if (enemy5_y > pos_y)
				enemy5_y--;
			if (enemy5_y < pos_y)
				enemy5_y++;

		}

		speed = 0;
	}

}


void updateWithInput() //用户输入相关，更新
{
	char input; //输入按键
	if (_kbhit())
	{
		input = _getch();
		if (input == 'a') pos_y--;
		if (input == 'd') pos_y++;
		if (input == 'w') pos_x--;
		if (input == 's') pos_x++;
		
	}
}


int main()
{

	startUp();//初始化

	while (1)
	{
		show();//打印画面
		updateWithInput(); //用户输入相关更新
		updateWithoutInput(); //用户输入无关更新

	}


	return 0;
}