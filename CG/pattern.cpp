#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class circle1
{
	public :
		float x,y;
		int r,d;
		float x1,y1,x2,y2,dx,dy,length,i;
		void draw_bresenham(int i, int x_cent, int y_cent);
		void dda(int x1,int y1,int x2,int y2, int CHOICE);
		
};
void circle1::draw_bresenham(int i, int x_cent, int y_cent)
{
	r=i;
	x=0;
	y=r;
	d=3-(2*r);
	
	while(x<y)
	{
		putpixel(x_cent+x,y_cent+y,LIGHTBLUE);
		delay(25);
		putpixel(x_cent+y,y_cent+x,LIGHTGREEN);
		putpixel(x_cent+y,y_cent-x,LIGHTCYAN);
		putpixel(x_cent+x,y_cent-y,LIGHTMAGENTA);
		putpixel(x_cent-x,y_cent+y,LIGHTBLUE);
		putpixel(x_cent-y,y_cent+x,LIGHTGREEN);
		putpixel(x_cent-y,y_cent-x,LIGHTCYAN);
		putpixel(x_cent-x,y_cent-y,LIGHTMAGENTA);
		if(d<0)
		{
			d=d+(4*x+6);
			
		}
		else
		{
			d=d+(4*(x-y))+10;
			y=y-1;
		}
		x=x+1;
	}
}
void circle1::dda(int x1,int y1, int x2,int y2, int CHOICE)
{
	if(abs(x2-x1)>abs(y2-y1))
	{
		length=abs(x2-x1);
	}
	else{length=abs(y2-y1);}
	dx=(x2-x1)/length;
	dy=(y2-y1)/length;
	x=x1+0.5;
	y=y1+0.5;
	i=0;
	while(i<length)
	{
		putpixel(x,y,CHOICE);
		delay(1);
		x=x+dx;
		y=y+dy;
		i++;
	}
}
int main()
{
	int gm,gd = DETECT;
	circle1 obj;
	int i;
	initwindow(900, 500);
	//First pattern
	obj.draw_bresenham(100, 200, 200);
	obj.draw_bresenham(50, 200, 200);
	
	obj.dda(115,250,200,100, 10);
	obj.dda(115,250,288,250, 9);
	obj.dda(288,250,200,100, 13);
	//Second pattern
	obj.dda(400,100,800,100, 9);
	obj.dda(800,100,800,300, 10);
	obj.dda(800,300,400,300, 11);
	obj.dda(400,300,400,100, 13);
	
	obj.dda(400,200,600,100, 9);
	obj.dda(600,100,800,200, 10);
	obj.dda(800,200,600,300, 11);
	obj.dda(600,300,400,200, 13);
	
	obj.draw_bresenham(88, 600, 200);
	getch();
	closegraph();
	return 0;
}
