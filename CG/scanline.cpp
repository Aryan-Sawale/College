#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class scan
{
	int n,i,k;
	int x[10],y[10],xint[10];
	int choice;
	float dx,dy,slope[30];
	public:
		void slope1();
		void drawpoly();		
};
void scan :: drawpoly()
{
	int user;
	cout<<"CHOOSE YOUR POLYGON:\n1 - Convex Polygon\n2 - Concave Polygon\n3 - Complex Polygon\n4 - Enter co-ordinates of your choice\n";
	cout<<"Enter value: ";
	cin>>user;
	if(user == 1)
	{
		x[0] = 200;
		y[0] = 200;
		x[1] = 150;
		y[1] = 300;
		x[2] = 250;
		y[2] = 300;
		x[3] = 200;
		y[3] = 200;
		n = 3;
	}
	else if(user == 2)
	{
		x[0] = 150;
		y[0] = 200;
		x[1] = 250;
		y[1] = 250;
		x[2] = 150;
		y[2] = 300;
		x[3] = 200;
		y[3] = 250;
		x[4] = 150;
		y[4] = 200;
		n = 4;
	}
	else if(user == 3)
	{
		x[0] = 150;
		y[0] = 250;
		x[1] = 200;
		y[1] = 300;
		x[2] = 250;
		y[2] = 250;
		x[3] = 250;
		y[3] = 350;
		x[4] = 200;
		y[4] = 300;
		x[5] = 150;
		y[5] = 350;
		x[6] = 150;
		y[6] = 250;
		n = 6;
	}
	else if (user == 4)
	{
		cout<<"\nEnter number of edges: "<<endl;
		cin>>n;
		cout<<"\nEnter the coordinates of "<<n<<"points: "<<endl;
		for(i=0;i<n;i++)
		{
			cout<<"\nPoint "<<i+1<<"-";
			cin>>x[i];
			cin>>y[i];
		}
		x[n]=x[0];
		y[n]=y[0];
	}
	else
	{
		exit(0);
	}
	cout<<"\nCHOOSE YOUR COLOUR:\n";
	cout<<"BLACK         0\nBLUE          1\nGREEN         2\nCYAN          3\nRED           4\nMAGENTA       5\nBROWN         6\nLIGHTGRAY     7\nDARKGRAY      8\nLIGHTBLUE     9\nLIGHTGREEN    10\nLIGHTCYAN     11\nLIGHTRED      12\nLIGHTMAGENTA  13\nYELLOW        14\nWHITE         15\n";
	cout<<"Enter value: ";
	cin>>choice;
}
void scan :: slope1()
{
	for (i=0;i<n;i++)
	line (x[i],y[i],x[i+1],y[i+1]);
	int temp;
	for (i=0;i<n;i++)
	{
		dy=y[i+1]-y[i];
		dx=x[i+1]-x[i];
		if (dy==0)
		slope [i] =1;
		else if(dx==0)
		slope[i]=0;
		else
		slope[i]=dx/dy;
	}
	for (int c=0;c<480;c++)
	{
		k=0;
		for(i=0;i<n;i++)
		{
			if((y[i]<=c && y[i+1]>c) || (y[i]>c && y[i+1]<=c))
			{
				xint[k]=x[i]+slope[i]*(c-y[i]);
				k++;
			}	
		}
	
	for (int j=0;j<k-1;j++)
	{
		for(i=0;i<k;i++)
		{
			if(xint[i]>xint[i+1])
			{
				temp=xint[i];
				xint[i]=xint[i+1];
				xint[i+1]=temp;
			}
		}
	}
		
			for (i=0;i<k;i=i+2)
			{
				setcolor(choice);
				line(xint[i],c,xint[i+1],c);
				delay(50);
			}
}
}

int main()
{	int gd=DETECT,gm;
	scan s;
	s.drawpoly();
	//First take input then initialize window
	initgraph(&gd,&gm,NULL);
	s.slope1();
	getch();
	return 0;
}
