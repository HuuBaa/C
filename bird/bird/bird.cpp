#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "help.h"

int height, width;//�߽�
int bird_x, bird_y;//С������
int block_y, block_x_top, block_x_down;//����λ��
int score;//�÷�




void startUp()//��ʼ��
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

void show()//��ӡ����
{
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i <= height + 1; i++)
	{
		for (j = 0; j <= width; j++)
		{
			if ((i == bird_x) && (j == bird_y))
				printf("@");//С��	
			else if ((j == block_y) && ((i <= block_x_top) || (i >= block_x_down)))
			{
				printf("*");
			}
			else
				printf(" ");

		}
		printf("\n");
	}
	printf("�÷֣�%d\n", score);

}




void updateWithoutInput() //�û������޹أ�����
{

	static int speed = 0;//����С���ٶ�
	if (speed < 6)
		speed++;
	if (speed == 6)
	{
		//С���ϰ���ײ���
		if (bird_y == block_y)
		{
			if ((bird_x > block_x_top) && (bird_x < block_x_down))
			{
				score++;

			}
			else
			{	//��Ϸ����
				printf("Game Over!");
				system("pause");
				exit(0);

			}
		}

		bird_x++;//С������
		
		if (block_y > 0)
			block_y--;//�ϰ�����
		else
		{	
			//���������ϰ�
			block_y = width;
			block_x_top = rand() % (height - 8);
			block_x_down = block_x_top + height / 3;
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
		if (input == ' ')
		{
			bird_x -= 2;//С�����Ϸ�
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