#include <stdio.h> //printf()
#include <stdlib.h> //system()
#include <windows.h> //sleep()
#include <conio.h> //_getch()
#define Height 20
#define Width 40
#define eneNum 5
#define bulletWidth 20

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


int canvas[Height][Width];

int pos_x, pos_y;//�ɻ�λ��

int ene_x[eneNum], ene_y[eneNum];//����λ��

int score;
int left, right;
void startUp() //��ʼ��
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

void show() //��ӡ����
{
	gotoxy(0, 0);
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (canvas[i][j] == 1)
				printf("*"); //�ɻ�
			else if (canvas[i][j] == 2)
				printf("|"); //�ӵ�
			else if (canvas[i][j] == 3)
				printf("@"); //����
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("�÷�:%2d\n",score);
}


void updateWithoutInput()//�û������޹ظ���
{
	
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{		
			if (canvas[i][j] == 2)
			{				
				for (int k = 0; k < eneNum; k++)
				{
					if (i == ene_x[k] && j == ene_y[k])//���е���
					{

						canvas[ene_x[k]][ene_y[k]] = 0;
						ene_x[k] = 0;
						ene_y[k] = rand() % Width;
						canvas[ene_x[k]][ene_y[k]] = 3;
						score++;
					}
				}

				//�ӵ�����
				canvas[i][j] = 0;
				if (i > 0)
					canvas[i - 1][j] = 2;
			}
		}
	}


	for (int k = 0; k < eneNum; k++)
	{
		if (ene_x[k] >= Height) //�ɻ��ܳ��߽�ˢ�µ���
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
			//�ɻ�����
			canvas[ene_x[k]][ene_y[k]] = 0;
			ene_x[k]++;
			canvas[ene_x[k]][ene_y[k]] = 3;
		}
		speed = 0;
	}
}


void updateWithInput() //�û�������ظ���
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
	startUp();//��ʼ��

	while (1)
	{
		show();//��ӡ����
		updateWithoutInput(); //�û������޹أ�����
		updateWithInput(); //�û�������أ�����
	}

	return 0;
}