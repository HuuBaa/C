#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

int height, width;//边界

int ball_x, ball_y;//小球坐标
int ball_vx, ball_vy;//小球速度

int pos_x, pos_y;//挡板中心左边
int radius;//挡板半径
int left, right;//挡板左右边界

int goal_y, goal_x;//得分目标

int ballnumber;//反弹次数
int score;//得分

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



void startUp()//初始化
{
	height = 24;
	width = 40;

	ball_x = 1;
	ball_y = width / 4;
	ball_vx = 1;
	ball_vy = 1;

	pos_y = width / 2;
	pos_x = height;
	radius = 5;
	left = pos_y - radius;
	right = pos_y + radius;

	goal_y = width - 3;
	goal_x = 0;

	ballnumber = 0;
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
			if ((i == 0) && (j == goal_y) && (i == goal_x))		
				printf("@");//得分目标			
			else if ((i == ball_x) && (j == ball_y))			
				printf("o");//小球			
			else if ((i == pos_x) && (j >= left) && (j <= right))			
				printf("*");//挡板			
			else if (i == height + 1)			
				printf("-");//下边界			
			else if (j == width)			
				printf("|");//右边界			
			else			
				printf(" ");
			
		}
		printf("\n");
	}
	printf("反弹次数：%d\n", ballnumber);
	printf("得分：%d\n", score);

}

void updateWithoutInput() //用户输入无关，更新
{

	static int speed = 0;//控制小球速度
	if (speed < 5)
		speed++;
	if (speed == 5)
	{
		//小球接触挡板检测
		if (ball_x == height - 1)
		{
			if (ball_y >= left && ball_y <= right)
			{
				ball_vx = -ball_vx;
				ballnumber++;
			}
			else
			{
				printf("Game Over!");

			}
		}

		//小球、得分目标检测
		if (ball_x == 0 && ball_y == goal_y)
		{
			score++;
			goal_y = rand() % width;
		}

		//小球反弹
		if (ball_x == 0)
			ball_vx = -ball_vx;

		if ((ball_y == 0) || (ball_y == width - 1))
			ball_vy = -ball_vy;

		//小球移动
		ball_x += ball_vx;
		ball_y += ball_vy;

		speed = 0;
	}


}


void updateWithInput() //用户输入相关，更新
{
	char input; //输入按键
	if (_kbhit())
	{
		input = _getch();
		if (input == 'a')
		{
			pos_y--;
			left = pos_y - radius;
			right = pos_y + radius;
		}
		if (input == 'd')
		{
			pos_y++;
			left = pos_y - radius;
			right = pos_y + radius;
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