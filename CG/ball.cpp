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
	
	//sine wave
	for (x = 0; x < getmaxx(); x += 3)
	{
		y = 50 * sin(angle * (3.141/180));
		y = getmaxy()/2 - y;
		putpixel(x, y, GREEN);
		delay(50);
		angle += 5;
	}
	
	getch();
	closegraph();
	return 0;
}
