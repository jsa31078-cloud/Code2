#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
void main()
{
int gd=DETECT,gm;
int x,y;
float angle;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
for(angle=0;angle<=3.14;angle+=0.05)
{
cleardevice();
x=320+250*cos(angle);
y=350-250*sin(angle);
if(angle<1.57)
setbkcolor(BLACK);
else
setbkcolor(BLUE);
setcolor(WHITE);
line(0,350,640,350);
setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
fillellipse(x,y,25,25);
delay(100);
}
getch();
closegraph();
}
