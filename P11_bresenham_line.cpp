#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

/* s = line style: 1 solid, 2 dotted, 3 dashed, 4 thick */
void plot(int x, int y, int s, int i)
{
    if (s == 1)
        putpixel(x, y, WHITE);
    if (s == 2 && i % 3 == 0)
        putpixel(x, y, WHITE);
    if (s == 3 && i % 10 < 5)
        putpixel(x, y, WHITE);
    if (s == 4)
    {
        putpixel(x, y, WHITE);
        putpixel(x + 1, y, WHITE);
        putpixel(x, y + 1, WHITE);
    }
}

void bresenham(int x1, int y1, int x2, int y2, int s)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;
    int x = x1, y = y1, p, i;

    if (dx >= dy)                    // gentle slope: step in x
    {
        p = 2 * dy - dx;
        for (i = 0; i <= dx; i++)
        {
            plot(x, y, s, i);
            x = x + sx;
            if (p >= 0)
            {
                y = y + sy;
                p = p + 2 * (dy - dx);
            }
            else
                p = p + 2 * dy;
        }
    }
    else                             // steep slope (vertical lines too): step in y
    {
        p = 2 * dx - dy;
        for (i = 0; i <= dy; i++)
        {
            plot(x, y, s, i);
            y = y + sy;
            if (p >= 0)
            {
                x = x + sx;
                p = p + 2 * (dx - dy);
            }
            else
                p = p + 2 * dx;
        }
    }
}

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Rectangle
    bresenham(100, 100, 300, 100, 2);
    bresenham(300, 100, 300, 250, 4);
    bresenham(300, 250, 100, 250, 2);
    bresenham(100, 250, 100, 100, 4);

    // Diamond
    bresenham(450, 100, 550, 200, 3);
    bresenham(550, 200, 450, 300, 1);
    bresenham(450, 300, 350, 200, 3);
    bresenham(350, 200, 450, 100, 1);

    getch();
    closegraph();
}
