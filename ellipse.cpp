//
// Created by 20115 on 5/7/2023.
//

#include "ellipse.h"
#include "math.h"
#include "dataScreen.h"

void Draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c) {
    SetPixel(hdc, xc + x, yc + y, c);
    SetPixel(hdc, xc + x, yc - y, c);
    SetPixel(hdc, xc - x, yc - y, c);
    SetPixel(hdc, xc - x, yc + y, c);

    add(xc + x, yc + y, c);
    add(xc + x, yc - y, c);
    add(xc - x, yc - y, c);
    add(xc - x, yc + y, c);

}

void DrawCartesianEllipse(HDC hdc, int xc, int yc, int a, int b, COLORREF c) {
    int x = 0;
    double y = b;
    double asq = a * a;
    double bsq = b * b;
    Draw4Points(hdc, xc, yc, x, (int) round(y), c);
    while (x * bsq < y * asq) {

        x++;
        y = b * sqrt(1.0 - (double) x * x / asq);

        Draw4Points(hdc, xc, yc, x, (int) round(y), c);
    }
    int y1 = 0;
    double x1 = a;
    Draw4Points(hdc, xc, yc, (int) round(x1), y1, c);
    while (x1 * bsq > y1 * asq) {
        y1++;
        x1 = a * sqrt(1.0 - (double) y1 * y1 / bsq);
        Draw4Points(hdc, xc, yc, (int) round(x1), y1, c);
    }
}

void DrawPolarEllipse(HDC hdc, int xc, int yc, int a, int b, COLORREF c) {
    double d_theta = 1.0 / (a > b) ? a : b;
    double theta = 0.0;
    while (theta <= 1.57079632679) {
        double x = a * cos(theta);
        double y = b * sin(theta);
        Draw4Points(hdc, xc, yc, (int) round(x), (int) round(y), c);
        theta += d_theta;
    }
}

void DrawMidpointEllipse(HDC hdc, int xc, int yc, int a, int b, COLORREF c) {
    int x = 0, y = b;
    int asqrt = a * a;
    int bsqrt = b * b;
    Draw4Points(hdc, xc, yc, x, y, c);

    double d = bsqrt - asqrt * b + asqrt / 4;
    while ((x + 1) * bsqrt < (y - 0.5) * asqrt) {
        Draw4Points(hdc, xc, yc, x, y, c);
        x++;
        if (d > 0) {
            y--;
            d += bsqrt* (2 * x + 3) - asqrt * (2 * y - 2);
        }
        else
            d += bsqrt * (2 * x + 3);

    }

    d = bsqrt * (x + 0.5)* (x + 0.5) + asqrt * (y - 1) * (y - 1) - asqrt * bsqrt;
    while (y > 0) {

        Draw4Points(hdc, xc, yc, x, y, c);
        y--;
        if (d < 0) {
            d += bsqrt * (2 * x + 2) + asqrt * (3 - 2 * y);
            x++;
        }else
            d += asqrt * (3 - 2 * y);

    }

}
