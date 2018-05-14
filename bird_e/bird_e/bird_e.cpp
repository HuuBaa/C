#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#pragma comment(lib,"Winmm.lib")

#define WIDTH 350
#define HEIGHT 600

int bird_x, bird_y;//С������
int bar_x, bar_down_y, bar_up_y;//����ˮ��λ��

IMAGE img_bk, img_bird1, img_bird2, img_bar_up1, img_bar_up2, img_bar_down1, img_bar_down2;

void GameOver();

void startUp()
{
	initgraph(WIDTH, HEIGHT);

	bird_x = 30;
	bird_y = 300;

	bar_x = 280;
	bar_up_y = rand() % 300 + 50; // (50,350)
	bar_down_y = bar_up_y + 140; //����100�߶ȵĿռ�

	loadimage(&img_bk, "F:\\C\\bird_e\\background.JPG");
	loadimage(&img_bird1, "F:\\C\\bird_e\\bird1.JPG");
	loadimage(&img_bird2, "F:\\C\\bird_e\\bird2.JPG");
	loadimage(&img_bar_up1, "F:\\C\\bird_e\\bar_up1.gif");
	loadimage(&img_bar_up2, "F:\\C\\bird_e\\bar_up2.gif");
	loadimage(&img_bar_down1, "F:\\C\\bird_e\\bar_down1.gif");
	loadimage(&img_bar_down2, "F:\\C\\bird_e\\bar_down2.gif");

	mciSendString("open F:\\C\\bird_e\\background.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString("play  bkmusic repeat", NULL, 0, NULL);
	BeginBatchDraw();
}

void show()
{
	putimage(0, 0, &img_bk);
	putimage(bird_x, bird_y, &img_bird1, NOTSRCERASE);
	putimage(bird_x, bird_y, &img_bird2, SRCERASE);

	putimage(bar_x, bar_up_y - 600, &img_bar_up1, NOTSRCERASE);
	putimage(bar_x, bar_up_y - 600, &img_bar_up2, SRCERASE);

	putimage(bar_x, bar_down_y, &img_bar_down1, NOTSRCERASE);
	putimage(bar_x, bar_down_y, &img_bar_down2, SRCERASE);


	FlushBatchDraw();

}

void updateWithoutInput()
{
	//��ײ���
	if (bird_x > bar_x - 30 && bird_x < bar_x + 140)
	{
		if (bird_y <= bar_up_y || bird_y >= bar_down_y - 24)
		{
			GameOver();
		}
	}

	bird_y++;//С���Զ�����

	if (bar_x > -140)
		bar_x--; //��������
	else
	{	
		//������������
		bar_x = 280;
		bar_up_y = rand() % 300 + 50; // (50,350)
		bar_down_y = bar_up_y + 140; //����140�߶ȵĿռ�
	}


	Sleep(10);
}


void updateWithInput()
{
	char input;
	if (_kbhit())
	{
		input = _getch();
		if (input == ' ')
		{
			bird_y -= 35;
			mciSendString("close jumpmusic", NULL, 0, NULL);
			mciSendString("open F:\\C\\bird_e\\Jump.mp3 alias jumpmusic", NULL, 0, NULL);
			mciSendString("play  jumpmusic ", NULL, 0, NULL);
		}
	}
}


void GameOver()
{
	EndBatchDraw();
	system("pause");
	_getch();
	closegraph();
	printf("game over");
}

int main()
{

	startUp();

	while (1)
	{
		show();
		updateWithoutInput();
		updateWithInput();
	}
	return 0;
}