#include <stdio.h> //printf()
#include <stdlib.h> //system()
#include <windows.h> //sleep()
#include <conio.h> //_getch()
#define Height 24
#define Width 40


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

int canvas[Height][Width] = { 0 }; //-1 �ұ߿�,-2�±߿�0�ո�1���壬2����,3С��

int pos_x, pos_y;//������������
int left, right;//������������
int radius;//����뾶

int ball_x, ball_y;//С������
int ball_vx, ball_vy;//С���ٶ�



void startUp() //��ʼ��
{

	//�趨�߿�
	for (int i = 0; i < Width; i++)
	{
		canvas[Height - 1][i] = -2;
	}
	for (int i = 0; i < Height; i++)
	{
		canvas[i][Width - 1] = -1;
	}

	//��ʼ������
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < Width - 1; j++)
		{
			canvas[i][j] = 2;
		}
	}

	//��ʼ������
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


	//��ʼ��С��
	ball_vx = 1;
	ball_vy = 1;

	ball_x = 5;
	ball_y = rand()%Width;

	canvas[ball_x][ball_y] = 3;

	HideCursor();
}

void show() //��ӡ����
{
	gotoxy(0, 0);

	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (canvas[i][j] == -2)
				printf("-"); //�±߿�
			else if (canvas[i][j] == -1)
				printf("|"); //�ұ߿�
			else if (canvas[i][j] == 1)
				printf("*"); //����
			else if (canvas[i][j] == 2)
				printf("#"); //����
			else if (canvas[i][j] == 3)
				printf("O"); //С��
			else
				printf(" ");
		}
		printf("\n");
	}

	Sleep(50);
}


void updateWithoutInput()//�û������޹ظ���
{
	
	//С���ƶ�
	//���С��
	canvas[ball_x][ball_y] = 0;

	//�������
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
	//����С��
	canvas[ball_x][ball_y] = 3;

}

	


void updateWithInput() //�û�������ظ���
{
	char input;
	if (_kbhit())
	{
		input = _getch();
		//���ԭ������
		for (int i = left; i <= right; i++)
		{
			canvas[pos_x][i] = 0;
		}

		if (input == 'a'&&left>0)//����
			pos_y--;
		if (input == 'd'&&right<Width-2)//����
			pos_y++;

		//�������ɵ���
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
	startUp();//��ʼ��

	while (1)
	{
		show();//��ӡ����
		updateWithoutInput(); //�û������޹أ�����
		updateWithInput(); //�û�������أ�����
	}

	return 0;
}