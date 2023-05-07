//
// Created by 20115 on 5/7/2023.
//
#include "line.h"
#include <windows.h>
#include <cmath>
void swap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void DrawLineDDA(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    if (abs(dx) >= abs(dy)) {
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
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
            swap(x1, x2);
            swap(y1, y2);
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