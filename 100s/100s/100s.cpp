#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "help.h"
#include <time.h>

int height, width;//�߽�

int pos_x, pos_y;
int enemy1_x, enemy1_y; //����
int enemy2_x, enemy2_y;
int enemy3_x, enemy3_y;
int enemy4_x, enemy4_y;
int enemy5_x, enemy5_y;
clock_t start, end; //ʱ����
float duration;
void startUp()//��ʼ��
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

void show()//��ӡ����
{
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i <= height; i++)
	{
		for (j = 0; j <= width; j++)
		{
			if (i == height)
				printf("-");//�±߽�	
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
				printf("|");//�ұ߽�	
			else
				printf(" ");
		}
		printf("\n");
		
	}
	end = clock();
	duration = (float)(end - start) / CLOCKS_PER_SEC;
	printf("������%.3f��",duration);
}



void updateWithoutInput() //�û������޹أ�����
{

	static int speed = 0;//����ˢ���ٶ�
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


void updateWithInput() //�û�������أ�����
{
	char input; //���밴��
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

	startUp();//��ʼ��

	while (1)
	{
		show();//��ӡ����
		updateWithInput(); //�û�������ظ���
		updateWithoutInput(); //�û������޹ظ���

	}


	return 0;
}