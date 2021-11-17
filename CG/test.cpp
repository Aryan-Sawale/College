#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	setcolor(GREEN);
	circle(200, 200, 50);
	setfillstyle(HATCH_FILL, RED);
	floodfill(200, 200, GREEN);
	getch();
	closegraph();
	return 0;
}
