#include <stdio.h> //printf()
#include <stdlib.h> //system()
#include <windows.h> //sleep()
#include <conio.h> //_getch()

int pos_x, pos_y; //飞机位置，pos_x为上下，pos_y为左右
int bullet_x, bullet_y; //子弹位置
int enemy_x, enemy_y;//敌人位置
int width, height; //边界
int score;

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

void startUp() //初始化
{
	width = 40;
	height = 20;
	pos_x = height / 2;
	pos_y = width / 2;
	bullet_x = -1;
	bullet_y = -1;
	enemy_x = 0;
	enemy_y = 5;

	HideCursor();
}

void show() //打印画面
{
	int i, j;

	gotoxy(0, 0);  // 光标移动到原点位置进行重画清屏

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if ((j == pos_y) && (i == pos_x))
			{
				printf("*");//飞机
			}
			else if ((j == bullet_y) && (i == bullet_x))
			{
				printf("|");//子弹
			}
			else if ((j == enemy_y) && (i == enemy_x))
			{
				printf("@");//敌人
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("得分：%d", score);
}



void updateWithInput() //用户输入相关更新
{
	char input;
	if (_kbhit())
	{
		input = _getch();
		if (input == 's') pos_x++;
		if (input == 'w') pos_x--;
		if (input == 'a') pos_y--;
		if (input == 'd') pos_y++;
		if (input == ' ') //子弹发射
		{
			bullet_y = pos_y; 
			bullet_x = pos_x - 1; 
		}
	}


}
void updateWithoutInput()//用户输入无关更新
{
	if (bullet_x >= 0)
		bullet_x--; //子弹向上

	//击中敌人判断
	if ((enemy_x == bullet_x) && (enemy_y == bullet_y))
	{
		score++;
		bullet_x = -1;
		enemy_x = 0;
		enemy_y = rand() % width;
	}



	if (enemy_x > height) //敌人到底部后重新生成
	{
		enemy_x = 0;
		enemy_y = rand() % width;
	}


	static int speed = 0;//控制飞机速度
	if (speed < 10)
		speed++;
	if (speed == 10)
	{
		enemy_x++; //敌人向下
		speed = 0;
	}

	//防止飞机出边界
	if (pos_x <= 0) pos_x = 0;
	if (pos_y <= 0) pos_y = 0;
	if (pos_x >= height) pos_x = height - 1;
	if (pos_y >= width) pos_y = width - 1;

}


int main()
{
	startUp();//初始化

	while (1)
	{
		show();//打印画面
		updateWithInput(); //用户输入相关，更新
		updateWithoutInput(); //用户输入无关，更新
	}

	return 0;
}