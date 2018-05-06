#include <stdio.h> //printf()
#include <stdlib.h> //system()
#include <windows.h> //sleep()
#include <conio.h> //_getch()
#define m 28
#define n 60


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

int cells[m][n];
int temp_cells[m][n];


void startUp() //��ʼ��
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cells[i][j] = rand()%2;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			temp_cells[i][j] = cells[i][j];

	HideCursor();
}

void show() //��ӡ����
{
	gotoxy(0, 0);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cells[i][j])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
		

}


void updateWithInput() //�û�������ظ���
{

}

void updateWithoutInput()//�û������޹ظ���
{
	for (int i = 1; i < m-1; i++)
	{
		for (int j = 1; j < n-1; j++)
		{	
			int number;
			number = cells[i - 1][j - 1] + cells[i - 1][j] + cells[i - 1][j + 1] +
				cells[i][j - 1] + cells[i][j] + cells[i][j + 1] +
				cells[i + 1][j - 1] + cells[i + 1][j] + cells[i + 1][j + 1];

			if (number==3)
			{
				temp_cells[i][j] = 1;
			}
			else if (number == 2)
			{
				temp_cells[i][j] = cells[i][j];
			}
			else
			{
				temp_cells[i][j] = 0;
			}

		}
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cells[i][j] = temp_cells[i][j];

	Sleep(350);
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