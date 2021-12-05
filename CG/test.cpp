#include<stdio.h>

#include<conio.h>

#include<graphics.h>

int main()

{

int gd=DETECT, gm;

initgraph(&gd,&gm,NULL);

setbkcolor(GREEN);

circle(320,240,100);

getch();

closegraph();

}
