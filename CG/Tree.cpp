#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    
    //tree triangles
    setcolor(GREEN);    
	line(200, 100, 175, 150);
	line(200, 100, 225, 150);
	line(175, 150, 225, 150);
	
	line(200, 150, 150, 200);
	line(200, 150, 250, 200);
	line(150, 200, 250, 200);
	
	line(200, 200, 125, 250);	
	line(200, 200, 275, 250);
	line(125, 250, 275, 250);
	
	line(200, 250, 100, 300);
	line(200, 250, 300, 300);
	line(100, 300, 300, 300);
	
	setfillstyle(XHATCH_FILL, GREEN);
	floodfill(200, 125, GREEN);
	floodfill(200, 175, GREEN);
	floodfill(200, 225, GREEN);
	floodfill(200, 275, GREEN);
	
	//star
	int array[] = {200, 100, 180, 91, 180, 83,
	200, 75, 220, 83, 220, 91, 200, 100};
	
	setcolor(YELLOW);
	drawpoly(7, array);
	setfillstyle(CLOSE_DOT_FILL, YELLOW);
	floodfill(200, 80, YELLOW);
	
	//tree trunk
	setcolor(BROWN);
	rectangle(187, 300, 213, 400);
	setfillstyle(SOLID_FILL, BROWN);
	floodfill(200, 350, BROWN);
	
	//snowman body
	setcolor(WHITE);
	circle(450, 150, 40);
	circle(450, 270, 80);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(450, 160, WHITE);
	floodfill(450, 280, WHITE);
	
	//snowman eyes
	setcolor(BLACK);
	circle(430, 140, 5);
	circle(470, 140, 5);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(430, 140, BLACK);
	floodfill(470, 140, BLACK);
	
	//snowman smile
	setcolor(BLACK);
	arc(450, 160, 180, 360, 10);
	
	//snowman buttons
	setcolor(BLACK);
	circle(450, 230, 5);
	circle(450, 270, 5);
	circle(450, 310, 5);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(450, 230, BLACK);
	floodfill(450, 270, BLACK);
	floodfill(450, 310, BLACK);

    getch();
    closegraph();
    return 0;

}
