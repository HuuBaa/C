#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "help.h"

int height, width;//边界
int bird_x, bird_y;//小鸟坐标
int block_y, block_x_top, block_x_down;//挡板位置
int score;//得分




void startUp()//初始化
{
	height = 24;
	width = 40;

	bird_x = height / 2;
	bird_y = width / 4;

	block_y = width / 2;
	block_x_top = height / 4;
	block_x_down = block_x_top + height / 3;

	score = 0;

	HideCursor();
}

void show()//打印画面
{
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i <= height + 1; i++)
	{
		for (j = 0; j <= width; j++)
		{
			if ((i == bird_x) && (j == bird_y))
				printf("@");//小鸟	
			else if ((j == block_y) && ((i <= block_x_top) || (i >= block_x_down)))
			{
				printf("*");
			}
			else
				printf(" ");

		}
		printf("\n");
	}
	printf("得分：%d\n", score);

}




void updateWithoutInput() //用户输入无关，更新
{

	static int speed = 0;//控制小球速度
	if (speed < 6)
		speed++;
	if (speed == 6)
	{
		//小鸟，障碍碰撞检测
		if (bird_y == block_y)
		{
			if ((bird_x > block_x_top) && (bird_x < block_x_down))
			{
				score++;

			}
			else
			{	//游戏结束
				printf("Game Over!");
				system("pause");
				exit(0);

			}
		}

		bird_x++;//小鸟下落
		
		if (block_y > 0)
			block_y--;//障碍左移
		else
		{	
			//重新生成障碍
			block_y = width;
			block_x_top = rand() % (height - 8);
			block_x_down = block_x_top + height / 3;
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
		if (input == ' ')
		{
			bird_x -= 2;//小鸟向上飞
		}

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