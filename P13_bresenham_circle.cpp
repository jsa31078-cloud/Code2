#include <iostream.h>
#include <conio.h>
#include <graphics.h>
void plot(int xc,int yc,int x,int y,int s,int i)
{
if(s==1 || (s==2 && i%3==0) ||
(s==3 && i%10<5))
{
putpixel(xc+x,yc+y,WHITE);
putpixel(xc-x,yc+y,WHITE);
putpixel(xc+x,yc-y,WHITE);
putpixel(xc-x,yc-y,WHITE);
putpixel(xc+y,yc+x,WHITE);
putpixel(xc-y,yc+x,WHITE);
putpixel(xc+y,yc-x,WHITE);
putpixel(xc-y,yc-x,WHITE);
}
}
void circle(int xc,int yc,int r,int s)
{
int x=0,y=r;
int p=3-2*r;
int i=0;
while(x<=y)
{
plot(xc,yc,x,y,s,i);
if(p<0)
p=p+4*x+6;
else
{
p=p+4*(x-y)+10;
y--;
}
x++;
i++;
}
}
void main()
{
int gd=DETECT,gm,ch;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
cout<<"1. Solid Circle";
cout<<"\n2. Dotted Circle";
cout<<"\n3. Dashed Circle";
cout<<"\nEnter your choice: ";
cin>>ch;
cleardevice();
if(ch>=1 && ch<=3)
circle(300,200,100,ch);
else
cout<<"Invalid Choice";
getch();
closegraph();
}
