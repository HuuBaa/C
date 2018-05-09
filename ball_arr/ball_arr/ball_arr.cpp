#include <stdio.h> //printf()
#include <stdlib.h> //system()
#include <windows.h> //sleep()
#include <conio.h> //_getch()
#define Height 24
#define Width 40


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

int canvas[Height][Width] = { 0 }; //-1 右边框,-2下边框，0空格，1挡板，2方块,3小球

int pos_x, pos_y;//挡板中心坐标
int left, right;//挡板左右坐标
int radius;//挡板半径

int ball_x, ball_y;//小球坐标
int ball_vx, ball_vy;//小球速度



void startUp() //初始化
{

	//设定边框
	for (int i = 0; i < Width; i++)
	{
		canvas[Height - 1][i] = -2;
	}
	for (int i = 0; i < Height; i++)
	{
		canvas[i][Width - 1] = -1;
	}

	//初始化方块
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < Width - 1; j++)
		{
			canvas[i][j] = 2;
		}
	}

	//初始化挡板
	pos_x = Height - 2;
	pos_y = Width / 2;
	radius = 5;

	left = pos_y - radius;
	if (left < 0)
		left = 0;

	right = pos_y + radius;
	if (right > Width - 1)
		right = Width - 2;

	for (int i = left; i < right; i++)
	{
		canvas[pos_x][i] = 1;
	}


	//初始化小球
	ball_vx = 1;
	ball_vy = 1;

	ball_x = 5;
	ball_y = rand()%Width;

	canvas[ball_x][ball_y] = 3;

	HideCursor();
}

void show() //打印画面
{
	gotoxy(0, 0);

	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (canvas[i][j] == -2)
				printf("-"); //下边框
			else if (canvas[i][j] == -1)
				printf("|"); //右边框
			else if (canvas[i][j] == 1)
				printf("*"); //挡板
			else if (canvas[i][j] == 2)
				printf("#"); //方块
			else if (canvas[i][j] == 3)
				printf("O"); //小球
			else
				printf(" ");
		}
		printf("\n");
	}

	Sleep(50);
}


void updateWithoutInput()//用户输入无关更新
{
	
	//小球移动
	//清除小球
	canvas[ball_x][ball_y] = 0;

	//反弹检测
	if (ball_y == 0 || ball_y == Width - 2)
		ball_vy = -1 * ball_vy;
	
	if (ball_x==0)
		ball_vx = -1 * ball_vx;

	if (ball_x == Height - 3)
	{
		if (ball_y > right || ball_y < left)
		{
			printf("Game Over");
			system("pause");
			exit(0);
		}
		else
		{
			ball_vx = -1 * ball_vx;
		}
	}
	
	ball_x = ball_x + ball_vx;
	ball_y = ball_y + ball_vy;
	//生成小球
	canvas[ball_x][ball_y] = 3;

}

	


void updateWithInput() //用户输入相关更新
{
	char input;
	if (_kbhit())
	{
		input = _getch();
		//清空原来挡板
		for (int i = left; i <= right; i++)
		{
			canvas[pos_x][i] = 0;
		}

		if (input == 'a'&&left>0)//左移
			pos_y--;
		if (input == 'd'&&right<Width-2)//右移
			pos_y++;

		//重新生成挡板
		left = pos_y - radius;
		
		right = pos_y + radius;
		
		for (int i = left; i <= right; i++)
		{
			canvas[pos_x][i] = 1;
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