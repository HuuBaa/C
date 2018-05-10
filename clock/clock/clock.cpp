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

	int center_x = Width / 2;	    //������������
	int center_y = Height / 2;

	int secondLength = Width / 4;    //���볤��
	int minuteLength = Width / 4 -25; //���볤��
	int hourLength= Width / 4 - 50;  //ʱ�볤��

	int secondEnd_x, secondEnd_y;   //�����յ�����
	int minuteEnd_x, minuteEnd_y;   //�����յ�����
	int hourEnd_x, hourEnd_y;		//ʱ���յ�����

	float secondAngle,minuteAngle,hourAngle; //�������ڽǶ�

	SYSTEMTIME ti; //����ϵͳʱ��ı���

	BeginBatchDraw();
	while (1)
	{	
		////��ȡϵͳʱ��
		GetLocalTime(&ti);

		//������
		setcolor(WHITE);
		setlinestyle(PS_SOLID, 1);
		circle(center_x, center_y, RADIUS);

		int x, y;
		float angle;

		//���̶�
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

		outtextxy(center_x-30 , center_y + Width / 6, "�ҵ�ʱ��");

		//�����������ڽǶ�
		secondAngle = ti.wSecond*2*PI / 60;
		minuteAngle = ti.wMinute* 2 * PI / 60+ secondAngle/60;
		hourAngle = ti.wHour * 2 * PI / 12+minuteAngle/12;

		//���������յ�����
		secondEnd_x = center_x + secondLength*sin(secondAngle);
		secondEnd_y = center_y - secondLength*cos(secondAngle);

		//��������յ�����
		minuteEnd_x = center_x + minuteLength*sin(minuteAngle);
		minuteEnd_y = center_y - minuteLength*cos(minuteAngle);

		//����ʱ���յ�����
		hourEnd_x = center_x + hourLength*sin(hourAngle);
		hourEnd_y = center_y - hourLength*cos(hourAngle);


		//������
		setcolor(YELLOW);
		setlinestyle(PS_SOLID, 2);
		line(center_x, center_y, secondEnd_x, secondEnd_y);

		//������
		setcolor(BLUE);
		setlinestyle(PS_SOLID, 4);
		line(center_x, center_y, minuteEnd_x, minuteEnd_y);

		//������
		setcolor(RED);
		setlinestyle(PS_SOLID, 6);
		line(center_x, center_y, hourEnd_x, hourEnd_y);

		FlushBatchDraw();
		Sleep(50);

		//����֮ǰ����
		setcolor(BLACK);
		line(center_x, center_y, secondEnd_x, secondEnd_y);
		//����֮ǰ����
		line(center_x, center_y, minuteEnd_x, minuteEnd_y);
		//����֮ǰʱ��
		line(center_x, center_y, hourEnd_x, hourEnd_y);
	}

	EndBatchDraw();

	_getch();
	closegraph();
	return 0;
}