#include <stdio.h> //printf()
#include <stdlib.h> //system()
#include <windows.h> //sleep()
#include <conio.h> //_getch()
#define Height 28
#define Width 60

void gotoxy(int x, int y)//类似于清屏函数，光标移动到原点位置进行重画
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void HideCursor()//隐藏光标 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int canvas[Height][Width] = { 0 }; //-1边框，1蛇头，>1蛇身，0空格，-2食物
int moveDirection;		//小蛇移动方向 1,2,3,4 对应 上，下，左，右
int food_x, food_y;		//食物坐标

//移动小蛇函数
void moveSnakeByDirection()
{	
	int max=0;//最大数字为蛇尾
	int oldTail_x, oldTail_y;//记录旧蛇尾位置
	int oldHead_x, oldHead_y;//记录旧蛇头位置
	int newHead_x, newHead_y;//新蛇头位置

	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (canvas[i][j] > 0)
			{	
				
				canvas[i][j]++;

				//寻找旧蛇尾
				if (max < canvas[i][j])
				{
					max = canvas[i][j];
					oldTail_x = i;
					oldTail_y = j;
				}

				//记录旧蛇头位置
				if (canvas[i][j] == 2)
				{	
					oldHead_x = i;
					oldHead_y = j;
				}
					
			}
		}
	}


	//根据移动方向设置新蛇头坐标,完成移动
	if (moveDirection==1)
	{	
		newHead_x = oldHead_x - 1;
		newHead_y = oldHead_y;
	}
	if (moveDirection == 2)
	{
		newHead_x = oldHead_x + 1;
		newHead_y = oldHead_y;
	}
	if (moveDirection == 3)
	{
		newHead_x = oldHead_x;
		newHead_y = oldHead_y-1;
	}
	if (moveDirection == 4)
	{
		newHead_x = oldHead_x;
		newHead_y = oldHead_y+1;
	}

	//如果吃到食物，重新生成食物，旧蛇尾无需改变
	if (canvas[newHead_x][newHead_y] == -2)
	{	
		canvas[food_x][food_y] = 0;

		food_x = rand() % (Height - 5) + 2;
		food_y = rand() % (Width - 5) + 2;
		canvas[food_x][food_y] = -2;
	}
	else
	//没吃到食物,数字最大位置，旧蛇尾设为0
	{
		
		canvas[oldTail_x][oldTail_y] = 0;
	}

	//新蛇头如果碰到边框，或自身游戏结束
	if (canvas[newHead_x][newHead_y] == -1 || canvas[newHead_x][newHead_y]>0)
	{
		printf("Game Over");
		system("pause");
		exit(0);
	}
	else
	//设置新蛇头位置,完成移动
	{
		canvas[newHead_x][newHead_y] = 1;
	}
}

void startUp() //初始化
{
	//设定边框
	for (int i = 0; i < Width; i++)
	{
		canvas[0][i] = -1;
		canvas[Height - 1][i] = -1;
	}
	for (int i = 0; i < Height; i++)
	{
		canvas[i][0] = -1;
		canvas[i][Width-1] = -1;
	}
	
	//初始化蛇头
	canvas[Height / 2][Width / 2] = 1;

	//初始化蛇身
	for (int i = 1; i < 5; i++)
	{
		canvas[Height / 2][Width / 2-i] = i+1;
	}

	//初始化食物
	food_x = rand() % (Height - 5);
	food_y = rand() % (Width - 5);
	canvas[food_x][food_y] = -2;

	//初始化移动方向
	moveDirection = 4;

	HideCursor();
}

void show() //打印画面
{
	gotoxy(0, 0);

	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (canvas[i][j] == -1)
				printf("#"); //边框
			else if (canvas[i][j] == 1)
				printf("@"); //蛇头
			else if (canvas[i][j] > 1)
				printf("*"); //蛇身
			else if (canvas[i][j] == -2)
				printf("F"); //食物
			else
				printf(" ");
		}
		printf("\n");
	}

	Sleep(100);
}


void updateWithoutInput()//用户输入无关更新
{
	moveSnakeByDirection();	
}


void updateWithInput() //用户输入相关更新
{
	char input;
	if (_kbhit())
	{
		input = _getch();
		if (input == 'w'&&moveDirection!=2)
			moveDirection = 1;
		if (input == 's'&&moveDirection != 1)
			moveDirection = 2;
		if (input == 'a'&&moveDirection != 4)
			moveDirection = 3;
		if (input == 'd'&&moveDirection != 3)
			moveDirection = 4;
	}
}

int main()
{
	startUp();//初始化

	while (1)
	{
		show();//打印画面
		updateWithoutInput(); //用户输入无关，更新
		updateWithInput(); //用户输入相关，更新
	}

	return 0;
}