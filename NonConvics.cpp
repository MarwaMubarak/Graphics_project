//
// Created by Esawy on 5/16/2023.
//

#include "NonConvics.h"
#include <windows.h>
#include<bits/stdc++.h>
#include<math.h>
#include <algorithm>
#include "dataScreen.h"

using namespace std;

void InitEdgeTable(vector<vector<int>> &t) {
    t.clear();
    t.resize(1000);
}


void Edge2Table(pair<int, int> p1, pair<int, int> p2, vector<vector<int>> &t) {
    if (p1.second == p2.second) return;
    if (p1.second > p2.second)
        swap(p1, p2);
    double x = p1.first;
    int y = p1.second;
    double m_inverse = (double) (p2.first - p1.first) / (p2.second - p1.second);
    while (y < p2.second) {
        t[y].push_back((int) ceil(x));
        y++;
        x += m_inverse;
    }
}

void Polygon2Table(vector<pair<int, int>> p, int n, vector<vector<int>> &t) {
    pair<int, int> v1 = p[n - 1];
    for (int i = 0; i < n; i++) {
        pair<int, int> v2 = p[i];
        Edge2Table(v1, v2, t);
        v1 = v2;
    }
}

void Table2Screen(HDC hdc, vector<vector<int>> &t, COLORREF c) {
    for (int i = 0; i < 1000; i++) {
        if (!t[i].empty()) {
            sort(t[i].begin(), t[i].end());
            int j = 0;
            while (j < t[i].size()) {
                for (int x = t[i][j]; x <= t[i][j + 1]; x++) {
                    SetPixel(hdc, x, i, c);
                    add(x, i, c);
                }

                j += 2;
            }
        }
    }
}

void GeneralFill(HDC hdc, vector<pair<int, int>> p, int n, COLORREF c) {
    vector<vector<int>> t;
    InitEdgeTable(t);
    Polygon2Table(p, n, t);
    Table2Screen(hdc, t, c);
}