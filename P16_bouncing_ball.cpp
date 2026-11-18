#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
void main()
{
int gd=DETECT,gm;
int x=100,y;
float angle=0;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
while(!kbhit())
{
cleardevice();
y=200-100*sin(angle);
setcolor(WHITE);
circle(x,y,20);
setfillstyle(SOLID_FILL,RED);
floodfill(x,y,WHITE);
angle=angle+0.1;
x=x+2;
if(x>600)
x=100;
delay(30);
}
getch();
closegraph();
}
