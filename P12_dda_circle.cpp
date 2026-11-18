#include <iostream.h>
#include <conio.h>
#include <graphics.h>

/* True DDA circle (incremental, no sin/cos):
      x(n+1) = x(n) + y(n)*e
      y(n+1) = y(n) - x(n+1)*e
   where e = 1/2^n and 2^(n-1) <= r < 2^n                        */
void circle(int xc, int yc, int r, int s)
{
    float x = r, y = 0, e, xn, yn;
    int n = 0, i, steps;

    while ((1 << n) <= r)          // find n
        n++;
    e = 1.0 / (1 << n);
    steps = (int)(6.28318 / e) + 1; // one full turn

    for (i = 0; i < steps; i++)
    {
        xn = x + y * e;
        yn = y - xn * e;
        x = xn;
        y = yn;
        if (s == 1)
            putpixel((int)(xc + x + 0.5), (int)(yc + y + 0.5), WHITE);
        else if (s == 2 && i % 4 == 0)
            putpixel((int)(xc + x + 0.5), (int)(yc + y + 0.5), WHITE);
        else if (s == 3 && i % 16 < 8)
            putpixel((int)(xc + x + 0.5), (int)(yc + y + 0.5), WHITE);
    }
}

void main()
{
    int gd = DETECT, gm, ch;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    cout << "1. Solid Circle";
    cout << "\n2. Dotted Circle";
    cout << "\n3. Dashed Circle";
    cout << "\nEnter choice: ";
    cin >> ch;
    cleardevice();
    if (ch >= 1 && ch <= 3)
        circle(300, 200, 100, ch);
    else
        cout << "Invalid Choice";
    getch();
    closegraph();
}
