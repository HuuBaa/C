#include <graphics.h>
#include <conio.h>



int main()
{	
	int left_i;
	int right_i;
	int x, y;

	int maps[8][5];

	IMAGE img_man,img_wall;

	initgraph(480, 300); 
	x = 200;
	y = 80;
	left_i = 0;
	right_i = 0;

	loadimage(&img_man, "F:\\C\\donghua\\ÐÐ×ßËØ²ÄÍ¼.jpg");
	loadimage(&img_wall, "F:\\C\\donghua\\walls.gif");

	for (int i = 0; i < 8; i++)
	{
		maps[i][0] = 1;
		maps[i][4] = 1;
	}
	for (int i = 0; i < 5; i++)
	{
		maps[0][i] = 1;
		maps[7][i] = 1;
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (maps[i][j] == 1)
			{
				putimage(i * 60, j * 60, &img_wall);
			}
		}
	}


	putimage(x, y, 75, 130, &img_man, 0, 0);
	BeginBatchDraw();

	while (1)
	{
		if (_kbhit())
		{
			char input;
			input = _getch();
			if (input == 'a')
			{	
				clearrectangle(x, y, x + 75, y + 130);
				
				left_i++;
				if (x>60)
					x -= 10;
				putimage(x, y, 75, 130, &img_man, left_i * 75, 0);
				FlushBatchDraw();
				Sleep(1);
				if (left_i == 3)
				{
					left_i = 0;
				}
				Sleep(80);
			}
			if (input == 'd')
			{
				clearrectangle(x, y, x + 75, y + 130);

				right_i++;
				if(x<340)
					x += 10;
				putimage(x, y, 75, 130, &img_man, right_i * 75, 120);
				FlushBatchDraw();
				Sleep(1);
				if (right_i == 3)
				{
					right_i = 0;
				}
				Sleep(80);
			}

		}
	}
	EndBatchDraw();

	
	return 0;
}

