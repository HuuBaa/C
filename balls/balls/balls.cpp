#include <graphics.h>
#include <conio.h>
#define HEIGHT 640
#define WIDTH 480
#define BALLNUM 10


int main()
{
	float ball_x[BALLNUM], ball_y[BALLNUM];//小球坐标
	float ball_vx[BALLNUM], ball_vy[BALLNUM];//小球速度
	float radius = 20;//小球半径

	//初始化小球位置，速度


	for (int i = 0; i < BALLNUM; i++)
	{
		ball_x[i] = (i + 2) * 20;
		ball_y[i] = (i + 2) * 40;

		ball_vx[i] = (rand() % 3) * 2 - 1;	//[-1,5)
		ball_vy[i] = (rand() % 3) * 2 - 1;  //[-1,5)
	}

	initgraph(WIDTH, HEIGHT);
	BeginBatchDraw();


	while (1)
	{
	
		//绘制黑线、黑色填充的圆
		setcolor(BLACK);
		setfillcolor(BLACK);
		for (int i = 0; i < BALLNUM; i++)
		{
			fillcircle(ball_x[i], ball_y[i], radius);
		}

		//小球移动，更新坐标
		for (int i = 0; i < BALLNUM; i++)
		{
			ball_x[i] = ball_x[i] + ball_vx[i];
			ball_y[i] = ball_y[i] + ball_vy[i];

			// 把超出边界的小球拉回来
			if (ball_x[i]<radius)
				ball_x[i] = radius;
			if (ball_y[i]<radius)
				ball_y[i] = radius;
			if (ball_x[i]>WIDTH - radius)
				ball_x[i] = WIDTH - radius;
			if (ball_y[i]>HEIGHT - radius)
				ball_y[i] = HEIGHT - radius;

		}

		//墙壁反弹
		for (int i = 0; i < BALLNUM; i++)
		{
			if (ball_x[i]<=radius || ball_x[i]>= WIDTH - radius)
			{
				ball_vx[i] = -ball_vx[i];
			}
			if (ball_y[i]<=radius || ball_y[i]>= HEIGHT - radius)
			{
				ball_vy[i] = -ball_vy[i];
			}
		}

		//小球之间碰撞
		for (int i = 0; i < BALLNUM; i++)
		{
			for (int j = i + 1; j < BALLNUM; j++)
			{
				if (
						(
							(ball_x[i] - ball_x[j])*(ball_x[i] - ball_x[j]) +
							(ball_y[i] - ball_y[j])*(ball_y[i] - ball_y[j])
						) <= 4 * radius*radius
					)
				{	
					//交换速度
					int temp;
					temp = ball_vx[i];
					ball_vx[i] = ball_vx[j];
					ball_vx[j] = temp;

					temp = ball_vy[i];
					ball_vy[i] = ball_vy[j];
					ball_vy[j] = temp;
				}

			}
		}

		
		//绘制黄线、绿色填充的圆
		setcolor(GREEN);
		setfillcolor(YELLOW);
		for (int i = 0; i < BALLNUM; i++)
		{
			fillcircle(ball_x[i], ball_y[i], radius);
		}

		FlushBatchDraw();

		Sleep(5);

	}

	EndBatchDraw();

	return 0;
}