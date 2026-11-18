#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
void circle(int xc,int yc,int r,int s)
{
float x,y;
float pi=3.14159;
for(int i=0;i<720;i++)
{
float a=i*pi/360;
x=xc+r*cos(a);
y=yc+r*sin(a);
if(s==1)
putpixel(x,y,WHITE);
else if(s==2 && i%10==0)
putpixel(x,y,WHITE);
else if(s==3 && i%40<20)
putpixel(x,y,WHITE);
}
}
void main()
{
int gd=DETECT,gm,ch;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
cout<<"1. Solid Circle";
cout<<"\n2. Dotted Circle";
cout<<"\n3. Dashed Circle";
cout<<"\nEnter choice: ";
cin>>ch;
circle(300,200,100,ch);
getch();
closegraph();
}
