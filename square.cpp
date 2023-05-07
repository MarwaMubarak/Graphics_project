//
// Created by 20115 on 5/7/2023.
//
#include "windows.h"
#include "math.h"
void DrawSquare(HDC hdc,int & x, int& y, int& xx, int& yy, COLORREF color) {
    int i, j;
    int len=(int)sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
    int xc=x,yc=y;
    for (i = x; i <= x + len; i++) {
        for (j = y; j <= y + len; j++) {
            if(i==x||i==x+len||j==y||j==y+len) {
                SetPixel(hdc, i, j, color);
            }
        }
    }
    x=xc-len; y=yc-len;
    xx=xc+len; yy=yc+len;
}
#include "square.h"
