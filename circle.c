#include "circle.h"
#include <windows.h>
#include <math.h>
void Draw8Points(HDC hdc, int xc, int yc, int a, int b,COLORREF c) {
    SetPixel(hdc, xc + a, yc + b, c);
    SetPixel(hdc, xc - a, yc + b, c);
    SetPixel(hdc, xc - a, yc - b, c);
    SetPixel(hdc, xc + a, yc - b, c);
    SetPixel(hdc, xc + b, yc + a, c);
    SetPixel(hdc, xc - b, yc + a, c);
    SetPixel(hdc, xc - b, yc - a, c);
    SetPixel(hdc, xc + b, yc - a, c);
}
void DrawCircleIterativePolar(HDC hdc, int xc, int yc, int r, COLORREF c) {
    double d_theta = 1.0 / r;
    double x = r, y = 0;
    double ct = cos(d_theta),
            st = sin(d_theta);
    Draw8Points(hdc, xc, yc, (int)round(x),(int)round(y),c);
    while (x > y) {

        double x1 = x * ct - y * st;
        y = x * st + y * ct;
        x = x1;
        Draw8Points(hdc, xc, yc, (int)round(x), (int)round(y),c);

    }
}
void DrawModifiedMidpointCircle(HDC hdc, int xc, int yc, int r, COLORREF c) {
    int x = 0, y = r;
    int d_initial = 1 - r;
    int change1 = 2;
    int change2 = 5 - 2 * r;
    int d = d_initial;
    Draw8Points(hdc, xc, yc, x, y,c);
    while (x < y) {
        if (d <= 0)
            d += change1,
            change1 += 2,
            change2 += 2,
                    x++;
        else
            d += change2,
            change1 += 2,
            change2 += 4,
                    x++,
                    y--;
        Draw8Points(hdc, xc, yc, x, y,c);

    }
}
void DrawMidpointCircle(HDC hdc, int xc, int yc, int r, COLORREF c) {
    int x = 0, y = r;
    Draw8Points(hdc, xc, yc, x, y,c);
    while (x < y) {

        double d = 2 * (x + 1) * (x + 1) + 2 * y * y - 2 * y + 1 - 2 * r * r;//circle (remove 1/4 from 5/4 = 1)
        if (d <= 0)
            x++;
        else
            x++, y--;
        Draw8Points(hdc, xc, yc, x, y,c);

    }
}
void DrawPolarCircle(HDC hdc, int xc, int yc, int r, COLORREF c) {
    double d_theta = 1.0 / r;
    for (double theta = 0.0; theta <= 6.28318531; ) {
        double x = xc + r * cos(theta);
        double y = yc + r * sin(theta);
        SetPixel(hdc, (int)round(x), (int)round(y), c);
        theta += d_theta;
    }
}
void DrawCartesianCircle(HDC hdc, int xc, int yc, int r, COLORREF c) {
    int x = 0;
    double y = r;
    Draw8Points(hdc, xc, yc, x, (int) round(y), c);
    while (x < y) {
        x++;
        y = sqrt(r * r - x * x);

        Draw8Points(hdc, xc, yc, x, (int)round(y),c);
    }
}