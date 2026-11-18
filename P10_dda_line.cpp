#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
void dda(int x1, int y1, int x2, int y2, int s)
{
int dx = x2-x1, dy = y2-y1;
int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
float x=x1, y=y1;
float xi=(float)dx/steps;
float yi=(float)dy/steps;
for(int i=0; i<=steps; i++)
{
if(s==1)
putpixel(x,y,WHITE);
if(s==2 && i%3==0)
putpixel(x,y,WHITE);
if(s==3 && i%10<5)
putpixel(x,y,WHITE);
if(s==4)
{
putpixel(x,y,WHITE);
putpixel(x+1,y,WHITE);
putpixel(x,y+1,WHITE);
}
x=x+xi;
y=y+yi;
}
}
void main()
{
int gd=DETECT, gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
// Rectangle
dda(100,100,300,100,2);
dda(300,100,300,250,4);
dda(300,250,100,250,2);
dda(100,250,100,100,4);
// Diamond
dda(450,100,550,200,3);
dda(550,200,450,300,1);
dda(450,300,350,200,3);
dda(350,200,450,100,1);
getch();
closegraph();
}
