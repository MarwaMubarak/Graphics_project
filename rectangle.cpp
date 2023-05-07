#include <windows.h>
#include "line.h"
void swapp(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void drawRectangle(HDC hdc,int& x1,int& y1, int& x2,int& y2)
{
    if(y1>y2){ swapp(x1,x2); swapp(y1,y2);}
    if(x1>x2)
    {
        swapp(x1,x2);
    }
     DrawLineDDA(hdc,x1,y1,x2,y1,RGB(0, 0, 136));
    DrawLineDDA(hdc,x1,y1,x1,y2,RGB(0, 0, 136));
    DrawLineDDA(hdc,x2,y1,x2,y2,RGB(0, 0, 136));
    DrawLineDDA(hdc,x1,y2,x2,y2,RGB(0, 0, 136));


}
#include "Rectangle.h"