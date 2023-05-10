//
// Created by Legion 5 on 5/7/2023.
//

#include <cmath>
#include "filling_curve.h"
#include "curve.h"
#include <bits/stdc++.h>
#include "dataScreen.h"
using namespace std;
void FillSquareHermite(HDC hdc, int x, int y, int len, COLORREF c) {

    for (int i = x; i <= x + len; i++) {
        HermiteCurve(hdc, i, y, 0, 10, i,  y+len, 0, -10, RGB(0, 0, 136));
        for (int j = y; j <= y + len; j++) {
            if ((i == x || i == x + len || j == y || j == y + len)) {
                SetPixel(hdc, i, j, c);
                add(i, j, c);
            }
        }
    }
}

void FillRectangleBezier(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c) {
    int width = abs(x2 - x1);
    int height = abs(y2 - y1);
    int x = min(x1, x2);
    int y = min(y1, y2);

    for (int i = y; i <= y + height; ++i) {
        DrawBezierCurve(hdc, x, i, (int) round(x + 0.33), i, (int) round(x + 0.66), i, x + width, i, c);
        for (int j = x; j <= x + width; ++j) {
            if (i == x || i == x + width || j == y || j == y + height) {
                SetPixel(hdc, i, j, c);
                add(i, j, c);
            }
        }
    }


}