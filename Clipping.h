
#include <windows.h>
#include "vector"
#ifndef GRAPHICSPROJECT_CLIPPING_H
#define GRAPHICSPROJECT_CLIPPING_H
void PointClipping(HDC hdc, int x,int y, int xleft, int ytop, int xright, int ybottom,COLORREF c);
void LineClipping(HDC hdc, int xs, int ys, int xe, int ye, int xleft, int ytop, int xright, int ybottom,COLORREF c);
void PolygonClip(HDC hdc,std::vector<POINT>&p,int n,int xleft,int ytop,int xright,int ybottom,COLORREF c);
#endif //GRAPHICSPROJECT_CLIPPING_H