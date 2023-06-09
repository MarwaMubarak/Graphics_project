//
// Created by Esawy on 5/16/2023.
//

#include "Transformation.h"
#include <Windows.h>
#include<bits/stdc++.h>
#include<math.h>
#include "dataScreen.h"

using namespace std;
void swap(double &x1,double &y1,double &x2,double &y2){
    double temp=x1;
    x1=x2;
    x2=temp;
    double temp2=y1;
    y1=y2;
    y2=temp2;
}

int Round(double x){
    return (int)(x+0.5);
}
void TranslationLineDDA(HDC hdc, int x1, int y1, int x2, int y2, double tx, double ty, COLORREF c) {
    double homogeneous1[3] = { (double)x1, (double)y1, 1.0 };
    double homogeneous2[3] = { (double)x2, (double)y2, 1.0 };
    double translation[3][3] = { { 1.0, 0.0, tx }, { 0.0, 1.0, ty }, { 0.0, 0.0, 1.0 } };
    double newx1 = translation[0][0] * homogeneous1[0] + translation[0][1] * homogeneous1[1] + translation[0][2] * homogeneous1[2];
    double newy1 = translation[1][0] * homogeneous1[0] + translation[1][1] * homogeneous1[1] + translation[1][2] * homogeneous1[2];
    double newx2 = translation[0][0] * homogeneous2[0] + translation[0][1] * homogeneous2[1] + translation[0][2] * homogeneous2[2];
    double newy2 = translation[1][0] * homogeneous2[0] + translation[1][1] * homogeneous2[1] + translation[1][2] * homogeneous2[2];

    double dx = newx2 - newx1, dy = newy2 - newy1;
    if (abs(dx) >= abs(dy)) {
        if (newx1 > newx2) {
            swap(newx1, newy1, newx2, newy2);
            dx = -dx;
            dy = -dy;
        }
        if (dy >= 0) {
            double x = newx1, y = newy1;
            SetPixel(hdc, Round(x), Round(y), c);
            add(Round(x), Round(y), c);
            double d_initial = dx - 2 * dy;
            double change_1 = -2 * dy;
            double change_2 = 2 * (dx - dy);
            SetPixel(hdc, Round(x), Round(y), c);
            add(Round(x), Round(y), c);
            while (x < newx2) {
                if (d_initial > 0) {
                    x++;
                    d_initial += change_1;
                }
                else {
                    x++;
                    y++;
                    d_initial += change_2;
                }
                SetPixel(hdc, Round(x), Round(y), c);
                add(Round(x), Round(y), c);
            }
        }
        else {
            double x = newx1, y = newy1;
            SetPixel(hdc, x, y, c);
            add(Round(x), Round(y), c);
            double d_initial = dx - 2 * abs(dy);
            double change_1 = -2 * abs(dy);
            double change_2 = 2 * (dx - abs(dy));
            SetPixel(hdc, Round(x), Round(y), c);
            add(Round(x), Round(y), c);
            while (x < newx2) {
                if (d_initial > 0) {
                    x++;
                    d_initial += change_1;
                }
                else {
                    x++, y--;
                    d_initial += change_2;
                }
                SetPixel(hdc, Round(x), Round(y), c);
                add(Round(x), Round(y), c);
            }
        }
    }
    else {
        if (newy1 > newy2)
        {
            swap(newx1, newy1, newx2, newy2);
            dx = -dx; dy = -dy;
        }
        if (dx >= 0) {
            double x = newx1, y = newy1;
            SetPixel(hdc, x, y, c);
            add(Round(x), Round(y), c);
            double d_initial = dy - 2 * dx;
            double change_1 = -2 * dx;
            double change_2 = 2 * (dy - dx);
            SetPixel(hdc, Round(x), Round(y), c);
            add(Round(x), Round(y), c);
            while (y < newy2) {

                if (d_initial >= 0) {
                    y++;
                    d_initial += change_1;
                }
                else {
                    x++, y++;
                    d_initial += change_2;
                }
                SetPixel(hdc, Round(x), Round(y), c);
                add(Round(x), Round(y), c);
            }
        }
        else {
            double x = newx1, y = newy1;
            SetPixel(hdc, Round(x), Round(y), c);
            add(Round(x), Round(y), c);
            double d_initial = dy - 2 * abs(dx);
            double change_1 = -2 * abs(dx);
            double change_2 = 2 * (dy - abs(dx));
            SetPixel(hdc, Round(x), Round(y), c);
            add(Round(x), Round(y), c);
            while (y < newy2) {

                if (d_initial > 0) {
                    y++;
                    d_initial += change_1;
                }
                else {
                    x--, y++;
                    d_initial += change_2;
                }
                SetPixel(hdc, Round(x), Round(y), c);
                add(Round(x), Round(y), c);
            }
        }
    }
}

void ScalingLineDDA(HDC hdc,  double x1, double y1, double x2, double y2, double ScX ,double ScY, COLORREF c) {
    double homogeneous1[3] = { x1, y1, 1.0 };
    double homogeneous2[3] = { x2, y2, 1.0 };
    double scaling[3][3] = { { ScX, 0.0, 0.0 }, { 0.0, ScY, 0.0 }, { 0.0, 0.0, 1.0 } };

    double newx1 = scaling[0][0] * homogeneous1[0] + scaling[0][1] * homogeneous1[1] + scaling[0][2] * homogeneous1[2];
    double newy1 = scaling[1][0] * homogeneous1[0] + scaling[1][1] * homogeneous1[1] + scaling[1][2] * homogeneous1[2];
    double newx2 = scaling[0][0] * homogeneous2[0] + scaling[0][1] * homogeneous2[1] + scaling[0][2] * homogeneous2[2];
    double newy2 = scaling[1][0] * homogeneous2[0] + scaling[1][1] * homogeneous2[1] + scaling[1][2] * homogeneous2[2];

    double dx = (newx2 - newx1) * ScX;
    double dy = (newy2 - newy1) * ScY;

    if (abs(dx) >= abs(dy)) {
        if (newx1 > newx2) {
            swap(newx1, newy1, newx2, newy2);
            dx = -dx; dy = -dy;
        }
        if (dy >= 0) {
            double x = newx1, y = newy1;
            SetPixel(hdc, x, y, c);
            add(Round(x), Round(y), c);
            double d_initial = dx - 2 * dy;
            double change_1 = -2 * dy;
            double change_2 = 2 * (dx - dy);
            SetPixel(hdc, Round(x), Round(y), c);
            add(Round(x), Round(y), c);
            while (x < newx2) {
                if (d_initial > 0) {
                    x++;
                    d_initial += change_1;
                }
                else {
                    x++, y++;
                    d_initial += change_2;
                }
                SetPixel(hdc,Round(x), Round(y), c);
                add(Round(x), Round(y), c);
            }
        }
        else {
            double x = newx1, y = newy1;
            SetPixel(hdc, Round(x), Round(y), c);
            add(Round(x), Round(y), c);
            double d_initial = dx - 2 * abs(dy);
            double change_1 = -2 * abs(dy);
            double change_2 = 2 * (dx - abs(dy));
            SetPixel(hdc, x, y, c);
            add(Round(x), Round(y), c);
            while (x < newx2) {
                if (d_initial > 0) {
                    x++;
                    d_initial += change_1;
                }
                else {
                    x++, y--;
                    d_initial += change_2;
                }
                SetPixel(hdc, Round(x), Round(y), c);
                add(Round(x), Round(y), c);
            }
        }
    }
    else {
        if (newy1 > newy2)
        {
            swap(newx1, newy1, newx2, newy2);
            dx = -dx; dy = -dy;
        }
        if (dx >= 0) {
            double x = newx1, y = newy1;
            SetPixel(hdc, x, y, c);
            add(Round(x), Round(y), c);
            double d_initial = dy - 2 * dx;
            double change_1 = -2 * dx;
            double change_2 = 2 * (dy - dx);
            SetPixel(hdc, Round(x), Round(y), c);
            add(Round(x), Round(y), c);
            while (y < newy2) {

                if (d_initial >= 0) {
                    y++;
                    d_initial += change_1;
                }
                else {
                    x++, y++;
                    d_initial += change_2;
                }
                SetPixel(hdc, Round(x), Round(y), c);
                add(Round(x), Round(y), c);
            }
        }
        else {
            double x = newx1, y = newy1;
            SetPixel(hdc, x, y, c);
            add(Round(x), Round(y), c);
            double d_initial = dy - 2 * abs(dx);
            double change_1 = -2 * abs(dx);
            double change_2 = 2 * (dy - abs(dx));
            SetPixel(hdc, x, y, c);
            add(Round(x), Round(y), c);
            while (y < newy2) {

                if (d_initial > 0) {
                    y++;
                    d_initial += change_1;
                }
                else {
                    x--, y++;
                    d_initial += change_2;
                }
                SetPixel(hdc, Round(x), Round(y), c);
                add(Round(x), Round(y), c);
            }
        }
    }

}