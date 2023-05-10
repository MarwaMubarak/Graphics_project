//
// Created by 20115 on 5/7/2023.
//
#include "line.h"
#include <windows.h>
#include <cmath>
#include <iostream>
using namespace std;

void DrawLineDDA(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c) {

    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    if (abs(dx) >= abs(dy)) {
        if (x1 > x2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        int x = x1;
        double y = y1;
        double m = double(y2 - y1) / (x2 - x1);
        SetPixel(hdc, x1, y1, c);
        while (x < x2) {
            x++;
            y += m;
            SetPixel(hdc, x, round(y), c);
        }
    } else {
        if (y1 > y2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        double x = x1;
        int y = y1;
        double m = double(x2 - x1) / (y2 - y1);
        SetPixel(hdc, x1, y1, c);
        while (y < y2) {
            y++;
            x += m;
            SetPixel(hdc, round(x), y, c);
        }
    }


}

void DrawLineMidPoint(HDC hdc, int x0, int y0, int x1, int y1, COLORREF c) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;
    int x = x0;
    int y = y0;

    while (x != x1 || y != y1) {
        SetPixel(hdc, x, y, c);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
    SetPixel(hdc, x1, y1, c);
}

void DrawLineParametric(HDC hdc,int x1,int y1,int x2,int y2,COLORREF color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    for(double t = 0 ; t <= 1 ; t += 0.01){
        int x = x1 + dx * t ;
        int y = y1 + dy * t ;
        SetPixel(hdc , x , y , color) ;
    }
}