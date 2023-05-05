
#ifndef GRAPHICSPROJECT_FLOODFILL_H
#define GRAPHICSPROJECT_FLOODFILL_H
#include <windows.h>
void RecFloodFill(HDC hdc,int x,int y, COLORREF fillcolor, COLORREF areaColor);
void NonRecFloodFill(HDC hdc,int x,int y,COLORREF fillcolor, COLORREF areaColor);

#endif //GRAPHICSPROJECT_FLOODFILL_H