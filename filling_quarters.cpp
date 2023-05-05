//
// Created by Esawy on 5/5/2023.
//

#include "filling_quarters.h"
#include <iostream>
#include <cmath>

void line_DDA(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c) {
    int dx = x2 - x1, dy = y2 - y1;
    if (abs(dx) >= abs(dy)) {
        if (x1 > x2)
            std::swap(x1, x2), std::swap(y1, y2);
        int x = x1;
        double y = y1;
        double m = (double) dy / dx;
        SetPixel(hdc, x1, y1, c);
        while (x < x2) {
            y += m, x++;
            SetPixel(hdc, x, round(y), c);
        }
    } else {
        if (y1 > y2)
            std::swap(x1, x2), std::swap(y1, y2);
        double x = x1;
        int y = y1;
        double m = (double) dy / dx;
        SetPixel(hdc, x1, y1, c);
        while (y < y2) {
            y++, x += (1 / m);
            SetPixel(hdc, round(x), y, c);
        }
    }

}

void draw_circul_line(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c, int quarter) {
    int r = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double x = 0;
    double y = r;
    int rsq = r * r;
    while (x < y) {
        double y = sqrt(rsq - x * x);

        if (quarter == 1) {
            line_DDA(hdc, x1, y1, x + x1, -round(y) + y1, c);
            line_DDA(hdc, x1, y1, round(y) + x1, -x + y1, c);
        }
        if (quarter == 2) {
            line_DDA(hdc, x1, y1, -x + x1, -round(y) + y1, c);
            line_DDA(hdc, x1, y1, -round(y) + x1, -x + y1, c);
        }

        if (quarter == 3) {
            line_DDA(hdc, x1, y1, -x + x1, round(y) + y1, c);
            line_DDA(hdc, x1, y1, -round(y) + x1, x + y1, c);
        }


        if (quarter == 4) {
            line_DDA(hdc, x1, y1, x + x1, round(y) + y1, c);
            line_DDA(hdc, x1, y1, round(y) + x1, x + y1, c);
        }

        SetPixel(hdc, -x + x1, -round(y) + y1, c);
        SetPixel(hdc, -x + x1, round(y) + y1, c);
        SetPixel(hdc, x + x1, -round(y) + y1, c);
        SetPixel(hdc, x + x1, round(y) + y1, c);

        SetPixel(hdc, -round(y) + x1, -x + y1, c);
        SetPixel(hdc, -round(y) + x1, x + y1, c);
        SetPixel(hdc, round(y) + x1, -x + y1, c);
        SetPixel(hdc, round(y) + x1, x + y1, c);

        x += 0.5;
    }

}

void draw_circul_quarter(HDC hdc, int x1, int y1, int x2, int y2, int r, COLORREF c, int quarter) {
    //int r = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double x = 0;
    double y = r;
    int rsq = r * r;
    while (x < y) {
        double y = sqrt(rsq - x * x);

        if (quarter == 1) {
            SetPixel(hdc, -x + x1, -round(y) + y1, c);
            SetPixel(hdc, -round(y) + x1, -x + y1, c);
        }

        if (quarter == 2) {
            SetPixel(hdc, x + x1, -round(y) + y1, c);
            SetPixel(hdc, round(y) + x1, -x + y1, c);
        }


        if (quarter == 3) {
            SetPixel(hdc, -round(y) + x1, x + y1, c);
            SetPixel(hdc, -x + x1, round(y) + y1, c);
        }

        if (quarter == 4) {
            SetPixel(hdc, x + x1, round(y) + y1, c);
            SetPixel(hdc, round(y) + x1, x + y1, c);
        }

        x += 0.5;
    }

}

void draw_circul_circuler(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c, int quarter) {
    int r = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double x = 0;
    double y = r;
    int rsq = r * r;
    while (x < y) {
        r--;
        draw_circul_quarter(hdc, x1, y1, x2, y2, r, RGB(4, 41, 64), quarter);
        double y = sqrt(rsq - x * x);


        SetPixel(hdc, -x + x1, -round(y) + y1, c);
        SetPixel(hdc, -x + x1, round(y) + y1, c);
        SetPixel(hdc, x + x1, -round(y) + y1, c);
        SetPixel(hdc, x + x1, round(y) + y1, c);

        SetPixel(hdc, -round(y) + x1, -x + y1, c);
        SetPixel(hdc, -round(y) + x1, x + y1, c);
        SetPixel(hdc, round(y) + x1, -x + y1, c);
        SetPixel(hdc, round(y) + x1, x + y1, c);

        x += 0.5;
    }

}

