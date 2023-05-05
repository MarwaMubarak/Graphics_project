
#ifndef GRAPHICSPROJECT_FLOODFILL_H
#define GRAPHICSPROJECT_FLOODFILL_H
#include <windows.h>
void RecFloodFill(HDC hdc,int x,int y,int fillcolor,int bordercolor);
void NonRecFloodFill(HDC hdc,int x,int y,int fillcolor,int bordercolor);

#endif //GRAPHICSPROJECT_FLOODFILL_H