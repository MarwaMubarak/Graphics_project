//
// Created by Hazem Adel on 5/10/2023.
//
#include "cardinal_spline_curve.h"
#include <windows.h>
#include "vector"
#include <utility>
#include "cardinal_spline_curve.h"
#include "curve.h"

using namespace std;
void DrawCardinalSpline(HDC hdc, vector<pair<int, int>> &vecPoints, int numPoints, double tension, COLORREF color) {
    vector<pair<int, int>> t(numPoints);
    for (int i = 1; i < numPoints - 1; ++i) {
        t[i].first = tension * (vecPoints[i].first - vecPoints[i - 1].first);
        t[i].second = tension * (vecPoints[i].second - vecPoints[i - 1].second);
    }
    t[0].first = tension * (vecPoints[1].first - vecPoints[0].first);
    t[0].second = tension * (vecPoints[1].second - vecPoints[0].second);
    t[numPoints - 1].first = tension * (vecPoints[numPoints - 1].first - vecPoints[numPoints - 2].first);
    t[numPoints - 1].second = tension * (vecPoints[numPoints - 1].second - vecPoints[numPoints - 2].second);
    for (int i = 0; i < numPoints - 1; ++i) {
        HermiteCurve(hdc, vecPoints[i].first, vecPoints[i].second, t[i].first, t[i].second
                ,vecPoints[i + 1].first, vecPoints[i + 1].second, t[i + 1].first, t[i + 1].second, color);
    }
}