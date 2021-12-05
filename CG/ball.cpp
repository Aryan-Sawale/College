#include <math.h>
#include <graphics.h>
#include <iostream>
using namespace std;

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	int angle = 0;
	double x, y;
	int max_x = getmaxx();
	int line_y = (getmaxy()/2) + 80;
	
	for (x = 0; x < max_x; x += 3)
	{	
		setcolor(YELLOW);
		line(0, line_y, max_x, line_y);
		
		//sine wave
		y = 50 * sin(angle * (3.141/180));
		y = getmaxy()/2 - y;
		angle += 5;
		
		if ((y >= 285) && (y <= 290))
		{
		setcolor(WHITE);
		line(0, line_y, max_x, line_y);
		}
		
		int col = 0;
		int para = ((int)y % 30);
		if (para >= 0 && para <= 9) { col = 4; }
		
		if (para >= 10 && para <= 19) { col = 2; }
		
		if (para >= 20 && para <= 29) { col = 1; }
		
		setcolor(col);
		circle(x, y, 30);
		
		setfillstyle(CLOSE_DOT_FILL, col);
		floodfill(x, y, col);
		
		delay(30);
		cleardevice();
	}
	
	
	getch();
	closegraph();
	return 0;
}
