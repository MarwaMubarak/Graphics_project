//
// Created by 20115 on 5/16/2023.
//
#include <windows.h>
#include <math.h>
#include "line.h"
#include "vector"
#include "dataScreen.h"
#include "clippingCircle.h"
#include "iostream"
using namespace std;

struct Point {
    int x;
    int y;
};
bool isPointInsideCircle(int x, int y, int centerX, int centerY, int radius) {
    double distance = std::sqrt(std::pow(x - centerX, 2) + std::pow(y - centerY, 2));
    return distance < radius;
}
//***********************Point**************************************
void PointClippingC(HDC hdc, int x,int y, int xc, int yc, int r,COLORREF c)
{
    if(isPointInsideCircle(x,y,xc,yc,r)) {
        SetPixel(hdc, x, y, c);
        add(x, y, c);
    }
}

//*************************************************************


//******************Line***************************************
void myLine(HDC hdc,int x1,int y1,int x2,int y2,int xc,int yc,int r,int c)
{
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    if (abs(dx) >= abs(dy)) {
        if (x1 > x2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        int x = x1;
        double y = y1;
        double m = double(y2 - y1) / (x2 - x1);
        if(isPointInsideCircle(x1,y1,xc,yc,r))
        {
            SetPixel(hdc, x1, y1, c);
            add(x1, y1, c);
        }
        while (x < x2) {
            x++;
            y += m;
            if(isPointInsideCircle(x,round(y),xc,yc,r))
            {SetPixel(hdc, x, round(y), c);
            add(x, round(y), c);}
        }
    }
    else {
        if (y1 > y2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        double x = x1;
        int y = y1;
        double m = double(x2 - x1) / (y2 - y1);
        if (isPointInsideCircle(x1, y1, xc, yc, r)) {
            SetPixel(hdc, x1, y1, c);
            add(x1, y1, c);
        }
        while (y < y2) {
            y++;
            x += m;
            if (isPointInsideCircle(round(x), y, xc, yc, r)) {
                SetPixel(hdc, round(x), y, c);
                add(round(x), y, c);
            }
        }
    }
}
void LineClippingC(HDC hdc, int x1,int y1,int x2,int y2, int xc, int yc, int r,COLORREF c)
{
    if(isPointInsideCircle(x1,y1,xc,yc,r)&&isPointInsideCircle(x2,y2,xc,yc,r)) {
        DrawLineDDA(hdc,x1,y1,x2,y2,c);
    }
    else
    {
        myLine(hdc,x1,y1,x2,y2,xc,yc,r,c);
    }
}