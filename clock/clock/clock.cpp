#include <graphics.h>
#include <conio.h>
#include <math.h>
#define Width 480
#define Height 480
#define PI 3.1415926535897
#define RADIUS 170
int main()
{	
	initgraph(Width, Height);

	int center_x = Width / 2;	    //画布中心坐标
	int center_y = Height / 2;

	int secondLength = Width / 4;    //秒针长度
	int minuteLength = Width / 4 -25; //分针长度
	int hourLength= Width / 4 - 50;  //时针长度

	int secondEnd_x, secondEnd_y;   //秒针终点坐标
	int minuteEnd_x, minuteEnd_y;   //分针终点坐标
	int hourEnd_x, hourEnd_y;		//时针终点坐标

	float secondAngle,minuteAngle,hourAngle; //秒针所在角度

	SYSTEMTIME ti; //保存系统时间的变量

	BeginBatchDraw();
	while (1)
	{	
		////获取系统时间
		GetLocalTime(&ti);

		//画表盘
		setcolor(WHITE);
		setlinestyle(PS_SOLID, 1);
		circle(center_x, center_y, RADIUS);

		int x, y;
		float angle;

		//画刻度
		for (int i = 0; i < 60; i++)
		{	
			angle = i * 2 * PI / 60;
			x = center_x + int((RADIUS-20) * sin(angle));
			y = center_y - int((RADIUS - 20) * cos(angle));
			
			if (i % 15 == 0)
			{
				bar(x - 5, y - 5, x + 5, y + 5); 
			}
			else if (i % 5 == 0)
			{
				circle(x, y, 3);
			}
			else
			{
				putpixel(x, y, WHITE);
			}
			
		}

		outtextxy(center_x-30 , center_y + Width / 6, "我的时钟");

		//计算秒针所在角度
		secondAngle = ti.wSecond*2*PI / 60;
		minuteAngle = ti.wMinute* 2 * PI / 60+ secondAngle/60;
		hourAngle = ti.wHour * 2 * PI / 12+minuteAngle/12;

		//计算秒针终点坐标
		secondEnd_x = center_x + secondLength*sin(secondAngle);
		secondEnd_y = center_y - secondLength*cos(secondAngle);

		//计算分针终点坐标
		minuteEnd_x = center_x + minuteLength*sin(minuteAngle);
		minuteEnd_y = center_y - minuteLength*cos(minuteAngle);

		//计算时针终点坐标
		hourEnd_x = center_x + hourLength*sin(hourAngle);
		hourEnd_y = center_y - hourLength*cos(hourAngle);


		//画秒针
		setcolor(YELLOW);
		setlinestyle(PS_SOLID, 2);
		line(center_x, center_y, secondEnd_x, secondEnd_y);

		//画分针
		setcolor(BLUE);
		setlinestyle(PS_SOLID, 4);
		line(center_x, center_y, minuteEnd_x, minuteEnd_y);

		//画分针
		setcolor(RED);
		setlinestyle(PS_SOLID, 6);
		line(center_x, center_y, hourEnd_x, hourEnd_y);

		FlushBatchDraw();
		Sleep(50);

		//隐藏之前秒针
		setcolor(BLACK);
		line(center_x, center_y, secondEnd_x, secondEnd_y);
		//隐藏之前分针
		line(center_x, center_y, minuteEnd_x, minuteEnd_y);
		//隐藏之前时针
		line(center_x, center_y, hourEnd_x, hourEnd_y);
	}

	EndBatchDraw();

	_getch();
	closegraph();
	return 0;
}