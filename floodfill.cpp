#include "floodfill.h"
#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;
void RecFloodFill(HDC hdc,int x,int y,  COLORREF fillcolor, COLORREF areaColor)
{
    COLORREF interiorColor = GetPixel(hdc,x,y);
    if ((interiorColor == areaColor) && (interiorColor != fillcolor))
    {
        SetPixel(hdc,x,y,fillcolor);
        RecFloodFill(hdc,x+1,y ,fillcolor,areaColor);
        RecFloodFill(hdc,x-1,y ,fillcolor,areaColor);
        RecFloodFill(hdc,x ,y-1,fillcolor,areaColor);
        RecFloodFill(hdc,x ,y+1,fillcolor,areaColor);

    }
}

void NonRecFloodFill(HDC hdc,int x,int y,COLORREF fillcolor,COLORREF areaColor)
{
    stack<pair<int,int>>st;
    st.push({x,y});
    while (!st.empty())
    {
        pair<int,int>p;
        p=st.top();
        st.pop();
        COLORREF interiorColor = GetPixel(hdc,p.first,p.second);
        if ((interiorColor == areaColor) && (interiorColor != fillcolor))
        {
            SetPixel(hdc,p.first,p.second,fillcolor);
            st.push({p.first+1,p.second});
            st.push({p.first-1,p.second});
            st.push({p.first,p.second-1});
            st.push({p.first,p.second+1});

        }
    }
}
