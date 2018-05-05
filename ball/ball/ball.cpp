#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

int height, width;//�߽�

int ball_x, ball_y;//С������
int ball_vx, ball_vy;//С���ٶ�

int pos_x, pos_y;//�����������
int radius;//����뾶
int left, right;//�������ұ߽�

int goal_y, goal_x;//�÷�Ŀ��

int ballnumber;//��������
int score;//�÷�

void gotoxy(int x, int y)//��������������������ƶ���ԭ��λ�ý����ػ�
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void HideCursor()//���ع�� 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}



void startUp()//��ʼ��
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

void show()//��ӡ����
{
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i <= height + 1; i++)
	{
		for (j = 0; j <= width; j++)
		{
			if ((i == 0) && (j == goal_y) && (i == goal_x))		
				printf("@");//�÷�Ŀ��			
			else if ((i == ball_x) && (j == ball_y))			
				printf("o");//С��			
			else if ((i == pos_x) && (j >= left) && (j <= right))			
				printf("*");//����			
			else if (i == height + 1)			
				printf("-");//�±߽�			
			else if (j == width)			
				printf("|");//�ұ߽�			
			else			
				printf(" ");
			
		}
		printf("\n");
	}
	printf("����������%d\n", ballnumber);
	printf("�÷֣�%d\n", score);

}

void updateWithoutInput() //�û������޹أ�����
{

	static int speed = 0;//����С���ٶ�
	if (speed < 5)
		speed++;
	if (speed == 5)
	{
		//С��Ӵ�������
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

		//С�򡢵÷�Ŀ����
		if (ball_x == 0 && ball_y == goal_y)
		{
			score++;
			goal_y = rand() % width;
		}

		//С�򷴵�
		if (ball_x == 0)
			ball_vx = -ball_vx;

		if ((ball_y == 0) || (ball_y == width - 1))
			ball_vy = -ball_vy;

		//С���ƶ�
		ball_x += ball_vx;
		ball_y += ball_vy;

		speed = 0;
	}


}


void updateWithInput() //�û�������أ�����
{
	char input; //���밴��
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
	startUp();//��ʼ��

	while (1)
	{
		show();//��ӡ����
		updateWithInput(); //�û�������ظ���
		updateWithoutInput(); //�û������޹ظ���

	}

	return 0;
}