#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main() {
	int i, j;
	int x = 10;
	int y = 5;
	char input;

	int ny = 5; 

	int isFired = 0;
	int isKilled = 0;

	while (1)
	{	
		//����
		system("cls");


		//��ӡ����
		if (isKilled == 0)
		{
			for (i = 0; i < ny; i++)
				printf(" ");
			printf("+\n");
		}
		

		//�ӵ���ӡ
		if (isFired)
		{
			for (i = 0; i < x; i++)
			{
				for (j = 0; j < y; j++)
				{
					printf(" ");
				}
				//��ӡ�ӵ�
				printf("  |\n");
			}

			//�����ж�
			if (y + 2 == ny) 
				isKilled = 1;

			//������ӵ���ʧ��������һѭ��
			isFired = 0;
			continue;

		}
		else
		{
			for (i = 0; i < x; i++)
				printf("  \n");
		}

		//��ӡ�ɻ�
		for (j = 0; j < y; j++)
			printf(" ");
		printf("  *\n");
		for (j = 0; j < y; j++)
			printf(" ");
		printf("*****\n");
		for (j = 0; j < y; j++)
			printf(" ");
		printf(" * * \n");

		//��ȡָ��
		input = _getch();
		if (input == 's') x++;
		if (input == 'w') x--;
		if (input == 'a') y--;
		if (input == 'd') y++;
		if (input == ' ') isFired = 1;

	}
	return 0;
}
