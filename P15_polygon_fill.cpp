#include <iostream.h>
#include <conio.h>
#include <graphics.h>

/* Concave polygon (two notches) filled by:
   1. Scan-line fill   2. Boundary fill   3. Flood fill            */

int n = 6;
int px[6] = {250, 300, 350, 350, 300, 250};
int py[6] = {120, 160, 120, 220, 190, 220};

// stack used by boundary fill and flood fill (instead of recursion)
int stx[5000], sty[5000];

void drawPolygon()
{
    int i;
    setcolor(WHITE);
    for (i = 0; i < n; i++)
        line(px[i], py[i], px[(i + 1) % n], py[(i + 1) % n]);
}

void scanFill(int color)
{
    int xi[10], y, i, j, k, cnt, t, ymin = py[0], ymax = py[0];

    for (i = 1; i < n; i++)
    {
        if (py[i] < ymin) ymin = py[i];
        if (py[i] > ymax) ymax = py[i];
    }
    setcolor(color);
    for (y = ymin; y < ymax; y++)
    {
        cnt = 0;
        for (i = 0; i < n; i++)
        {
            j = (i + 1) % n;
            if (py[i] == py[j]) continue;              // ignore horizontal edge
            if ((y >= py[i] && y < py[j]) || (y >= py[j] && y < py[i]))
                xi[cnt++] = px[i] + (int)((float)(y - py[i]) * (px[j] - px[i]) / (py[j] - py[i]));
        }
        for (i = 0; i < cnt - 1; i++)                  // sort intersections
            for (j = 0; j < cnt - 1 - i; j++)
                if (xi[j] > xi[j + 1])
                {
                    t = xi[j]; xi[j] = xi[j + 1]; xi[j + 1] = t;
                }
        for (k = 0; k + 1 < cnt; k += 2)               // fill between pairs
            line(xi[k], y, xi[k + 1], y);
    }
}

/* mode 1 = boundary fill (stop at boundary colour)
   mode 2 = flood fill    (replace old colour)  */
void fill4(int x, int y, int fillc, int other, int mode)
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int top = 0, cx, cy, nx, ny, c, d;

    putpixel(x, y, fillc);
    stx[top] = x; sty[top] = y; top++;
    while (top > 0)
    {
        top--;
        cx = stx[top]; cy = sty[top];
        for (d = 0; d < 4; d++)
        {
            nx = cx + dx[d]; ny = cy + dy[d];
            c = getpixel(nx, ny);
            if (mode == 1) { if (c == other || c == fillc) continue; }   // boundary colour = other
            else           { if (c != other) continue; }                 // old colour = other
            if (top < 5000)
            {
                putpixel(nx, ny, fillc);
                stx[top] = nx; sty[top] = ny; top++;
            }
        }
    }
}

void main()
{
    int gd = DETECT, gm, ch;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    cout << "1. Scan-line fill";
    cout << "\n2. Boundary fill";
    cout << "\n3. Flood fill";
    cout << "\nEnter choice: ";
    cin >> ch;
    cleardevice();

    drawPolygon();
    switch (ch)
    {
        case 1:
            scanFill(GREEN);
            drawPolygon();
            break;
        case 2:
            fill4(270, 170, GREEN, WHITE, 1);      // seed inside, boundary = WHITE
            break;
        case 3:
            fill4(270, 170, GREEN, BLACK, 2);      // seed inside, old colour = BLACK
            break;
        default:
            cout << "Invalid Choice";
    }
    getch();
    closegraph();
}
