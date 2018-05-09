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
	
	////围棋棋盘
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

	//国际象棋棋盘，8x8个格子
	//8*70=560 80/2=60

	int step = 70;
	setbkcolor(YELLOW);
	cleardevice();

	for (int j = 1; j <=8; j++)//j控制行数
		for (int i = 1; i <= 8; i++) //画一行，i控制列数
		{	

			if (j % 2 == 1)
			{
				if (i % 2 == 1)
				{
					setcolor(BLACK);
					setfillcolor(BLACK);
				}
				else
				{
					setcolor(WHITE);
					setfillcolor(WHITE);
				}
			}
			else
			{
				if (i % 2 == 1)
				{
					setcolor(WHITE);
					setfillcolor(WHITE);
				}
				else
				{					
					setcolor(BLACK);
					setfillcolor(BLACK);
				}
			}
			//fillrectangle(x1,y1,x2,y2)
			fillrectangle(40 + step*(i - 1), 40+70*(j-1) , 40 + step*i, 40 + 70*j );
		}


	_getch();
	closegraph();
	return 0;
}