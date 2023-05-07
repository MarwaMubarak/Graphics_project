//
// Created by Legion 5 on 5/7/2023.
//

#ifndef GRAPHICS_PROJECT_CURVE_H
#define GRAPHICS_PROJECT_CURVE_H

void HermiteCurve(HDC hdc, double x1, double y1, double u1, double v1, double x2, double y2, double u2, double v2,COLORREF c) ;
void DrawBezierCurve(HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, COLORREF c) ;
#endif //GRAPHICS_PROJECT_CURVE_H
