#include <stdio.h> //printf()
#include <stdlib.h> //system()
#include <windows.h> //sleep()
#include <conio.h> //_getch()

int pos_x, pos_y; //�ɻ�λ�ã�pos_xΪ���£�pos_yΪ����
int bullet_x, bullet_y; //�ӵ�λ��
int enemy_x, enemy_y;//����λ��
int width, height; //�߽�
int score;

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

void startUp() //��ʼ��
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

void show() //��ӡ����
{
	int i, j;

	gotoxy(0, 0);  // ����ƶ���ԭ��λ�ý����ػ�����

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if ((j == pos_y) && (i == pos_x))
			{
				printf("*");//�ɻ�
			}
			else if ((j == bullet_y) && (i == bullet_x))
			{
				printf("|");//�ӵ�
			}
			else if ((j == enemy_y) && (i == enemy_x))
			{
				printf("@");//����
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("�÷֣�%d", score);
}



void updateWithInput() //�û�������ظ���
{
	char input;
	if (_kbhit())
	{
		input = _getch();
		if (input == 's') pos_x++;
		if (input == 'w') pos_x--;
		if (input == 'a') pos_y--;
		if (input == 'd') pos_y++;
		if (input == ' ') //�ӵ�����
		{
			bullet_y = pos_y; 
			bullet_x = pos_x - 1; 
		}
	}


}
void updateWithoutInput()//�û������޹ظ���
{
	if (bullet_x >= 0)
		bullet_x--; //�ӵ�����

	//���е����ж�
	if ((enemy_x == bullet_x) && (enemy_y == bullet_y))
	{
		score++;
		bullet_x = -1;
		enemy_x = 0;
		enemy_y = rand() % width;
	}



	if (enemy_x > height) //���˵��ײ�����������
	{
		enemy_x = 0;
		enemy_y = rand() % width;
	}


	static int speed = 0;//���Ʒɻ��ٶ�
	if (speed < 10)
		speed++;
	if (speed == 10)
	{
		enemy_x++; //��������
		speed = 0;
	}

	//��ֹ�ɻ����߽�
	if (pos_x <= 0) pos_x = 0;
	if (pos_y <= 0) pos_y = 0;
	if (pos_x >= height) pos_x = height - 1;
	if (pos_y >= width) pos_y = width - 1;

}


int main()
{
	startUp();//��ʼ��

	while (1)
	{
		show();//��ӡ����
		updateWithInput(); //�û�������أ�����
		updateWithoutInput(); //�û������޹أ�����
	}

	return 0;
}