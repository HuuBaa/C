#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#pragma comment(lib,"Winmm.lib")

#define WIDTH 591
#define HEIGHT 864

IMAGE img_bk;//����ͼƬ

IMAGE img_planeNormal1, img_planeNormal2;//�����ɻ�ͼƬ
int plane_x, plane_y;//�ɻ�����

IMAGE img_bullet1, img_bullet2;//�����ӵ�ͼƬ
int bullet_x, bullet_y;//�ӵ�����

IMAGE img_enemy1, img_enemy2;//�����л�ͼƬ
int enemy_x, enemy_y;//�л�����

IMAGE img_planeExplode1, img_planeExplode2; //��ը�ɻ�ͼƬ

int isExplode;
int score;
 
void GameOver();

void startUp()
{

	mciSendString("open F:\\C\\feiji_e\\game_music.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString("play bkmusic repeat", NULL, 0, NULL);

	initgraph(WIDTH, HEIGHT);

	isExplode = 0;
	score = 0;

	plane_x = WIDTH / 2;
	plane_y = 3 * HEIGHT / 4;

	bullet_x = plane_x;
	bullet_y = -100;

	enemy_x = WIDTH / 2;
	enemy_y = 0;



	loadimage(&img_bk, "F:\\C\\feiji_e\\background.jpg");

	//���������ɻ�ͼƬ
	loadimage(&img_planeNormal1, "F:\\C\\feiji_e\\planeNormal_1.jpg");
	loadimage(&img_planeNormal2, "F:\\C\\feiji_e\\planeNormaL_2.jpg");

	//�����ӵ�ͼƬ
	loadimage(&img_bullet1, "F:\\C\\feiji_e\\bullet1.jpg");
	loadimage(&img_bullet2, "F:\\C\\feiji_e\\bullet2.jpg");


	//����л�ͼƬ
	loadimage(&img_enemy1, "F:\\C\\feiji_e\\enemyPlane1.jpg");
	loadimage(&img_enemy2, "F:\\C\\feiji_e\\enemyPlane2.jpg");

	//���뱬ը�ɻ�ͼƬ
	loadimage(&img_planeExplode1, "F:\\C\\feiji_e\\planeExplode_1.jpg");
	loadimage(&img_planeExplode2, "F:\\C\\feiji_e\\planeExplode_2.jpg");



	BeginBatchDraw();

}

void show()
{
	putimage(0, 0, &img_bk);

	if (isExplode)
	{
		//��ը�ɻ�
		putimage(plane_x - 50, plane_y - 60, &img_planeExplode1, NOTSRCERASE);
		putimage(plane_x - 50, plane_y - 60, &img_planeExplode2, SRCERASE);
	}
	else
	{
		//�����ɻ�
		putimage(plane_x - 50, plane_y - 60, &img_planeNormal1, NOTSRCERASE);
		putimage(plane_x - 50, plane_y - 60, &img_planeNormal2, SRCERASE);


	}

	//�ӵ�
	putimage(bullet_x, bullet_y, &img_bullet1, NOTSRCERASE);
	putimage(bullet_x, bullet_y, &img_bullet2, SRCERASE);

	//�л�
	putimage(enemy_x, enemy_y, &img_enemy1, NOTSRCERASE);
	putimage(enemy_x, enemy_y, &img_enemy2, SRCERASE);

	//��ʾ����
	outtextxy(WIDTH*0.1, HEIGHT*0.9, "�÷֣�");
	char s[5];
	sprintf_s(s, "%d", score);
	outtextxy(WIDTH*0.18, HEIGHT*0.9, s);

	FlushBatchDraw();

}

void updateWithoutInput()
{

	if (isExplode == 0)
	{	

		if (score >0 && score % 5 == 0 && score % 2 != 0)
		{
			mciSendString("close five", NULL, 0, NULL);
			mciSendString("open F:\\C\\feiji_e\\5.mp3 alias five", NULL, 0, NULL);
			mciSendString("play five", NULL, 0, NULL);

		}

		if (score > 0 && score % 10 == 0)
		{
			mciSendString("close ten", NULL, 0, NULL);
			mciSendString("open F:\\C\\feiji_e\\10.mp3 alias ten", NULL, 0, NULL);
			mciSendString("play ten", NULL, 0, NULL);
		}


		//�ӵ�����
		if (bullet_y > -50)
		{
			bullet_y -= 8;
		}
		//�л�����
		if (enemy_y < HEIGHT)
		{
			enemy_y += 2.5;
		}
		else
		{
			enemy_x = rand() % WIDTH;
			enemy_y = 0;
		}

		//���ел�
		if (abs(enemy_x + 50 - bullet_x) + abs(enemy_y + 60 - bullet_y) < 70)
		{
			enemy_x = rand() % WIDTH;
			enemy_y = 0;

			mciSendString("close gotEnemy", NULL, 0, NULL);
			mciSendString("open F:\\C\\feiji_e\\gotEnemy.mp3 alias gotEnemy", NULL, 0, NULL);
			mciSendString("play gotEnemy", NULL, 0, NULL);

			score++;
		}

		//���л�ײ��
		if (abs(enemy_x + 60 - plane_x) + abs(enemy_y + 60 - plane_y) < 100)
		{
			isExplode = 1;
			mciSendString("close explode", NULL, 0, NULL);
			mciSendString("open F:\\C\\feiji_e\\explode.mp3 alias explode", NULL, 0, NULL);
			mciSendString("play explode", NULL, 0, NULL);
		}

	}

	Sleep(10);
}


void updateWithInput()
{

	if (isExplode == 0)
	{
		MOUSEMSG m;
		while (MouseHit())
		{
			m = GetMouseMsg();

			if (m.uMsg == WM_MOUSEMOVE)//�ɻ���������������
			{
				plane_x = m.x;
				plane_y = m.y;
			}
			else if (m.uMsg == WM_LBUTTONDOWN)//�����ӵ�
			{
				bullet_x = m.x - 8;
				bullet_y = m.y - 70;

				mciSendString("close fire", NULL, 0, NULL);
				mciSendString("open F:\\C\\feiji_e\\f_gun.mp3 alias fire", NULL, 0, NULL);
				mciSendString("play fire", NULL, 0, NULL);
			}

		}
	}

}


void GameOver()
{
	EndBatchDraw();
	_getch();
	closegraph();
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