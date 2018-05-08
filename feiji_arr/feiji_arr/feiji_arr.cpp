#include <stdio.h> //printf()
#include <stdlib.h> //system()
#include <windows.h> //sleep()
#include <conio.h> //_getch()
#define Height 20
#define Width 40
#define eneNum 5
#define bulletWidth 20

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


int canvas[Height][Width];

int pos_x, pos_y;//飞机位置

int ene_x[eneNum], ene_y[eneNum];//敌人位置

int score;
int left, right;
void startUp() //初始化
{
	canvas[Height][Width] = { 0 };

	pos_x = 3*Height / 4;
	pos_y = Width / 2;

	for (int k = 0; k < eneNum; k++)
	{
		ene_x[k] = rand()%3;
		ene_y[k] = rand()%Width;
	}
	

	score = 0;

	canvas[pos_x][pos_y] = 1;
	for (int k = 0; k < eneNum; k++)
	{
		canvas[ene_x[k]][ene_y[k]] = 3;
	}

	HideCursor();
}

void show() //打印画面
{
	gotoxy(0, 0);
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (canvas[i][j] == 1)
				printf("*"); //飞机
			else if (canvas[i][j] == 2)
				printf("|"); //子弹
			else if (canvas[i][j] == 3)
				printf("@"); //敌人
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("得分:%2d\n",score);
}


void updateWithoutInput()//用户输入无关更新
{
	
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{		
			if (canvas[i][j] == 2)
			{				
				for (int k = 0; k < eneNum; k++)
				{
					if (i == ene_x[k] && j == ene_y[k])//击中敌人
					{

						canvas[ene_x[k]][ene_y[k]] = 0;
						ene_x[k] = 0;
						ene_y[k] = rand() % Width;
						canvas[ene_x[k]][ene_y[k]] = 3;
						score++;
					}
				}

				//子弹向上
				canvas[i][j] = 0;
				if (i > 0)
					canvas[i - 1][j] = 2;
			}
		}
	}


	for (int k = 0; k < eneNum; k++)
	{
		if (ene_x[k] >= Height) //飞机跑出边界刷新敌人
		{
			canvas[ene_x[k]][ene_y[k]] = 0;
			ene_x[k] = 0;
			ene_y[k] = rand() % Width;
			canvas[ene_x[k]][ene_y[k]] = 3;
			score--;
		}
	}

	
	static int speed = 10;
	if (speed < 20)
		speed++;
	if (speed == 20)
	{	
		for (int k = 0; k < eneNum; k++)
		{
			//飞机下落
			canvas[ene_x[k]][ene_y[k]] = 0;
			ene_x[k]++;
			canvas[ene_x[k]][ene_y[k]] = 3;
		}
		speed = 0;
	}
}


void updateWithInput() //用户输入相关更新
{
	char input;
	if (_kbhit())
	{
		input = _getch();
		if (input == 'a'&& pos_y>0)
		{
			canvas[pos_x][pos_y] = 0;
			pos_y--;
			canvas[pos_x][pos_y] = 1;
		}
		if (input == 'd'&& pos_y<Width-1)
		{
			canvas[pos_x][pos_y] = 0;
			pos_y++;
			canvas[pos_x][pos_y] = 1;
		}
		if (input == 'w'&& pos_x>0)
		{
			canvas[pos_x][pos_y] = 0;
			pos_x--;
			canvas[pos_x][pos_y] = 1;
		}
		if (input == 's'&& pos_x<Height - 1)
		{
			canvas[pos_x][pos_y] = 0;
			pos_x++;
			canvas[pos_x][pos_y] = 1;
		}
		if (input == ' ')
		{	
			
			left = pos_y - bulletWidth;
			if (left < 0) 
				left = 0;
			right = pos_y + bulletWidth;
			if (right > Width)
				right = Width;
			for (int i = left; i < right; i++)
			{
				canvas[pos_x - 1][i] = 2;
			}
			
		}
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