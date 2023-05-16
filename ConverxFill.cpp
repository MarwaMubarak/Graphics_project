//
// Created by Esawy on 5/11/2023.
//

#include "ConverxFill.h"
#include <windows.h>
#include<bits/stdc++.h>
#include<math.h>
#include"dataScreen.h"
using namespace std;


void InitEdgeTable(int t[][2])
{
    for ( int i = 0 ; i < 1000 ; i++)
    {
        t[i][0] = INT_MAX;
        t[i][1] = -INT_MAX;
    }
}


void Edge2Table (pair<int,int> p1 , pair<int,int> p2, int t[][2])
{
    if (p1.second == p2.second) return ;
    if (p1.second > p2.second )
        swap(p1,p2);
    double x = p1.first;
    int y = p1.second ;
    double m_inverse =(double)(p2.first - p1.first) / (p2.second-p1.second);
    while (y<p2.second)
    {
        if (x<t[y][0])
            t[y][0]=(int)ceil(x);
        if (x>t[y][1])
            t[y][1]=(int)floor(x);
        y++;
        x+=m_inverse;
    }
}

void Polygon2Table( vector<pair<int,int>>p , int n , int t[][2])
{
    pair<int,int> v1 = p[n-1];
    for (int i = 0 ; i<n ; i++)
    {
        pair<int,int> v2 = p[i];
        Edge2Table(v1,v2,t);
        v1=v2;
    }
}

void Table2Screen (HDC hdc ,int t[][2] , COLORREF c)
{
    for (int i = 0 ; i<1000 ; i++)
    {
        if (t[i][0]<t[i][1])
        {
            for(int x=t[i][0] ; x<=t[i][1] ; x++) {
                SetPixel(hdc, x, i, c);
                add( x, i, c);
            }
        }
    }
}

void ConvexFill (HDC hdc , vector <pair<int,int>>p , int n , COLORREF c)
{
    int t[1000][2];
    InitEdgeTable(t);
    Polygon2Table(p,n,t);
    Table2Screen(hdc,t,c);
}

