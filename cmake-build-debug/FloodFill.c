//
// Created by 20115 on 5/4/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack"
void RecFloodFill(HDC hdc,int x,int y,int fillcolor,int bordercolor)
{
    int interiorColor = GetPixel(hdc,x,y);
    if ((interiorColor != bordercolor) && (interiorColor != fillcolor))
    {
        SetPixel(hdc,x,y,fillcolor);
        RecFloodFill(hdc,x+1,y ,fillcolor,bordercolor);
        RecFloodFill(hdc,x-1,y ,fillcolor,bordercolor);
        RecFloodFill(hdc,x ,y-1,fillcolor,bordercolor);
        RecFloodFill(hdc,x ,y+1,fillcolor,bordercolor);

    }
}
void NonRecFloodFill(HDC hdc,int x,int y,int fillcolor,int bordercolor)
{
    std::stack<std::pair<int,int>>st;
    st.push({x,y});
    while (!st.empty())
    {
        std::pair<int,int>p;
        p=st.top();
        st.pop();
        int interiorColor = GetPixel(hdc,p.first,p.second);
        if ((interiorColor != bordercolor) && (interiorColor != fillcolor))
        {
            SetPixel(hdc,p.first,p.second,fillcolor);
            st.push({p.first+1,p.second});
            st.push({p.first-1,p.second});
            st.push({p.first,p.second-1});
            st.push({p.first,p.second+1});

        }
    }
}
#include "FloodFill.h"
