//
// Created by Legion 5 on 5/7/2023.
//

#include <cmath>
#include <windows.h>
#include "curve.h"
#include "dataScreen.h"
void HermiteCurve(HDC hdc, double x1, double y1, double u1, double v1, double x2, double y2, double u2, double v2,COLORREF c) {

    double a3 = 2 * x1 + u1 - 2 * x2 + u2;
    double a2 = -3 * x1 - 2 * u1 + 3 * x2 - u2;
    double a1 = u1;
    double a0 = x1;

    double b3 = 2 * y1 + v1 - 2 * y2 + v2;
    double b2 = -3 * y1 - 2 * v1 + 3 * y2 - v2;
    double b1 = v1;
    double b0 = y1;

    for (double t = 0; t <= 1; t += 0.0001) {

        double x = a3 * t * t * t + a2 * t * t + a1 * t + a0;
        double y = b3 * t * t * t + b2 * t * t + b1 * t + b0;
        SetPixel(hdc, (int) round(x), (int) round(y), c);
        add((int) round(x), (int) round(y), c);

    }
}

void DrawBezierCurve(HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, COLORREF c) {
    int u1 = 3 * (x2 - x1);
    int v1 = 3 * (y2 - y1);
    int u2 = 3 * (x4 - x3);
    int v2 = 3 * (y4 - y3);
    HermiteCurve(hdc, x1, y1, u1, v1, x2, y2, u2, v2, c);
    HermiteCurve(hdc, x2, y2, u1, v1, x3, y3, u2, v2, c);
    HermiteCurve(hdc, x3, y3, u1, v1, x4, y4, u2, v2, c);

}