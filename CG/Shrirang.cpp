#include<iostream>
#include<graphics.h>

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    setcolor(GREEN);
    line(220,120,150,170);
    line(220,120,290,170);
    line(150,170,290,170);

    line(220,170,120,220);
    line(220,170,320,220);
    line(120,220,320,220);

    line(220,220,90,270);
    line(220,220,350,270);
    line(90,270,350,270);

    setfillstyle(SOLID_FILL,GREEN);
    floodfill(220,150,GREEN);
    floodfill(220,190,GREEN);
    floodfill(220,240,GREEN);

    setcolor(BROWN);
    rectangle(200,270,240,370);
    setfillstyle(SOLID_FILL,BROWN);
    floodfill(220,320,BROWN);

    setcolor(WHITE);
    circle(450, 150, 40);
    circle(450, 230, 60);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(450,140,WHITE);
    floodfill(450,175,WHITE);
    floodfill(450,230,WHITE);
    getch();
    closegraph();
    return 0;

}
