#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int main()
{
	int gm,gd = DETECT;
	initgraph(&gd, &gm, NULL);
	setcolor(YELLOW);
	line (100, 100, 200 ,200);
	cout<<"Max x coordinate: "<<getmaxx()<<"\n";
	cout<<"Max y coordinate: "<<getmaxy()<<"\n";
	cout<<"Get pixel: "<<getpixel(300, 300);
	line(200, 100, 175, 150);
	line(200, 100, 225, 150);
	line(175, 150, 225, 150);
//	floodfill(200, 125, GREEN);
	getch();
	closegraph();
	return 0;
}
