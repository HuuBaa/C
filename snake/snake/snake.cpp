#include <stdio.h> //printf()
#include <stdlib.h> //system()
#include <windows.h> //sleep()
#include <conio.h> //_getch()
#define Height 28
#define Width 60

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

int canvas[Height][Width] = { 0 }; //-1�߿�1��ͷ��>1����0�ո�-2ʳ��
int moveDirection;		//С���ƶ����� 1,2,3,4 ��Ӧ �ϣ��£�����
int food_x, food_y;		//ʳ������

//�ƶ�С�ߺ���
void moveSnakeByDirection()
{	
	int max=0;//�������Ϊ��β
	int oldTail_x, oldTail_y;//��¼����βλ��
	int oldHead_x, oldHead_y;//��¼����ͷλ��
	int newHead_x, newHead_y;//����ͷλ��

	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (canvas[i][j] > 0)
			{	
				
				canvas[i][j]++;

				//Ѱ�Ҿ���β
				if (max < canvas[i][j])
				{
					max = canvas[i][j];
					oldTail_x = i;
					oldTail_y = j;
				}

				//��¼����ͷλ��
				if (canvas[i][j] == 2)
				{	
					oldHead_x = i;
					oldHead_y = j;
				}
					
			}
		}
	}


	//�����ƶ�������������ͷ����,����ƶ�
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

	//����Ե�ʳ���������ʳ�����β����ı�
	if (canvas[newHead_x][newHead_y] == -2)
	{	
		canvas[food_x][food_y] = 0;

		food_x = rand() % (Height - 5) + 2;
		food_y = rand() % (Width - 5) + 2;
		canvas[food_x][food_y] = -2;
	}
	else
	//û�Ե�ʳ��,�������λ�ã�����β��Ϊ0
	{
		
		canvas[oldTail_x][oldTail_y] = 0;
	}

	//����ͷ��������߿򣬻�������Ϸ����
	if (canvas[newHead_x][newHead_y] == -1 || canvas[newHead_x][newHead_y]>0)
	{
		printf("Game Over");
		system("pause");
		exit(0);
	}
	else
	//��������ͷλ��,����ƶ�
	{
		canvas[newHead_x][newHead_y] = 1;
	}
}

void startUp() //��ʼ��
{
	//�趨�߿�
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
	
	//��ʼ����ͷ
	canvas[Height / 2][Width / 2] = 1;

	//��ʼ������
	for (int i = 1; i < 5; i++)
	{
		canvas[Height / 2][Width / 2-i] = i+1;
	}

	//��ʼ��ʳ��
	food_x = rand() % (Height - 5);
	food_y = rand() % (Width - 5);
	canvas[food_x][food_y] = -2;

	//��ʼ���ƶ�����
	moveDirection = 4;

	HideCursor();
}

void show() //��ӡ����
{
	gotoxy(0, 0);

	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (canvas[i][j] == -1)
				printf("#"); //�߿�
			else if (canvas[i][j] == 1)
				printf("@"); //��ͷ
			else if (canvas[i][j] > 1)
				printf("*"); //����
			else if (canvas[i][j] == -2)
				printf("F"); //ʳ��
			else
				printf(" ");
		}
		printf("\n");
	}

	Sleep(100);
}


void updateWithoutInput()//�û������޹ظ���
{
	moveSnakeByDirection();	
}


void updateWithInput() //�û�������ظ���
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
	startUp();//��ʼ��

	while (1)
	{
		show();//��ӡ����
		updateWithoutInput(); //�û������޹أ�����
		updateWithInput(); //�û�������أ�����
	}

	return 0;
}