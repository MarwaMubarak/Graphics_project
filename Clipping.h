//
// Created by 20115 on 5/4/2023.
//
#ifndef GRAPHICSPROJECT_CLIPPING_H
#define GRAPHICSPROJECT_CLIPPING_H
void PointClipping(HDC hdc, int x,int y, int xleft, int ytop, int xright, int ybottom);
void LineClipping(HDC hdc, int xs, int ys, int xe, int ye, int xleft, int ytop, int xright, int ybottom);
#endif //GRAPHICSPROJECT_CLIPPING_H
