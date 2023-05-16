//
// Created by 20115 on 5/16/2023.
//
#ifndef GRAPHICS_PROJECT_CLIPPINGCIRCLE_H
#define GRAPHICS_PROJECT_CLIPPINGCIRCLE_H
void PointClippingC(HDC hdc, int x,int y, int xc, int yc,int r,COLORREF c);
void LineClippingC(HDC hdc, int x1,int y1,int x2,int y2, int xc, int yc, int r,COLORREF c);
#endif //GRAPHICS_PROJECT_CLIPPINGCIRCLE_H
