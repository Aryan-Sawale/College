#include<iostream>
#include<graphics.h>
#include<cmath>

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
	cout<<"Enter radius: ";
	cin>>i;
	int len = 2 * i * cos(0.5236);   //half-length of triangle
	initwindow(900, 500);
	//First pattern
	obj.draw_bresenham(2*i, 200, 200);
	obj.draw_bresenham(i, 200, 200);
	
	obj.dda((200 - len), (200 + i), 200, (200 - 2*i), 10);
	obj.dda((200 - len), (200 + i), (200 + len), (200 + i), 9);
	obj.dda((200 + len), (200 + i), 200, (200 - 2*i), 13);
	
	//Second pattern
	obj.dda(600 - (4 * i), 200 - (2 * i), 600 + (4 * i), 200 - (2 * i), 9);
	obj.dda(600 + (4 * i), 200 - (2 * i), 600 + (4 * i), 200 + (2 * i), 10);
	obj.dda(600 + (4 * i), 200 + (2 * i), 600 - (4 * i), 200 + (2 * i), 11);
	obj.dda(600 - (4 * i), 200 + (2 * i), 600 - (4 * i), 200 - (2 * i), 13);
	
	obj.dda(600, 200 - (2 * i), 600 + (4 * i), 200, 9);
	obj.dda(600 + (4 * i), 200, 600, 200 + (2 * i), 10);
	obj.dda(600, 200 + (2 * i), 600 - (4 * i), 200, 11);
	obj.dda(600 - (4 * i), 200, 600, 200 - (2 * i), 13);
	
	int rad = (2 * i) * 0.88;         //adjustment to radius for looking better
	obj.draw_bresenham(rad, 600, 200);
	
	getch();
	closegraph();
	return 0;
}
