#include <graphics.h>
#include <conio.h>


int main()
{
	initgraph(640, 640);
	/*setlinecolor(YELLOW);
	setfillcolor(GREEN);
	fillcircle(200, 200, 50);
	setlinecolor(BLUE);
	line(0, 0, 300, 300);*/

	//for (int i = 0; i < 256; i++)
	//{
	//	setlinecolor(RGB(i, i, 0));
	//	line(0, i, 640, i);

	//}
	
	////Χ������
	//int step = 30;
	//setbkcolor(YELLOW);
	//cleardevice();
	//setcolor(BLACK);
	//setlinestyle(PS_SOLID, 2);
	//for (int i = 1; i <= 19; i++)
	//{
	//	line(20 + step, 20 + step*i, (640 - 20 - step), 20 + step*i);
	//	line(20 + step*i, 20 + step, 20 + step*i, (640 - 20 - step));
	//}
	//



	//�����������̣�8x8������
	//8*70=560 80/2=60

	//int step = 70;
	//setbkcolor(YELLOW);
	//cleardevice();

	//for (int j = 1; j <=8; j++)//j��������
	//	for (int i = 1; i <= 8; i++) //��һ�У�i��������
	//	{	

	//		if (j % 2 == 1)
	//		{
	//			if (i % 2 == 1)
	//			{
	//				setcolor(BLACK);
	//				setfillcolor(BLACK);
	//			}
	//			else
	//			{
	//				setcolor(WHITE);
	//				setfillcolor(WHITE);
	//			}
	//		}
	//		else
	//		{
	//			if (i % 2 == 1)
	//			{
	//				setcolor(WHITE);
	//				setfillcolor(WHITE);
	//			}
	//			else
	//			{					
	//				setcolor(BLACK);
	//				setfillcolor(BLACK);
	//			}
	//		}
	//		//fillrectangle(x1,y1,x2,y2)
	//		fillrectangle(40 + step*(i - 1), 40+70*(j-1) , 40 + step*i, 40 + 70*j );
	//	}

	int ball_x[5],ball_y[5];
	int ball_vx[5] = { 1,8,5,-2,5 }, ball_vy[5] = { 1,2,2,-1,5 };
	int radius;
	
	radius = 30;
	
	for (int i = 0; i < 5; i++)
	{
		ball_x[i] = 50 * (i + 1);
		ball_y[i] = 50 * (i + 1);
	}

	BeginBatchDraw();

	while(1)
	{	

		setfillcolor(YELLOW);
		setcolor(BLACK);
		for (int i = 0; i < 5; i++)
		{
			fillcircle(ball_x[i], ball_y[i], radius);

		}
	

		FlushBatchDraw();
		Sleep(5);

		setcolor(BLACK);
		setfillcolor(BLACK);
		for (int i = 0; i < 5; i++)
		{
			fillcircle(ball_x[i], ball_y[i], radius);
			ball_x[i] += ball_vx[i];
			ball_y[i] += ball_vy[i];
		}

	
		for (int i = 0; i < 5; i++)
		{
			if (ball_x[i] < radius || ball_x[i]>640 - radius)
			{
				ball_vx[i] = -ball_vx[i];
			}
			if (ball_y[i] < radius || ball_y[i]>640 - radius)
			{
				ball_vy[i] = -ball_vy[i];
			}
		}

	}

	EndBatchDraw();

	_getch();
	closegraph();
	return 0;
}