#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include "circle.h"
#include <math.h>
#include <winnt.h >

static COLORREF color= RGB(0,255,0);
static int counter =0;
static char colorOption;
static char lineOption;
static char circleOption;
static char ellipseOption;
static char clippingRecOption;
static char clippingSquareOption;
static char option='g';
static int quarter;
static int xs,ys,xe,ye;
char input(){
    char buffer [250];
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD oldMode, newMode, numRead;

    // switch console input mode to allow reading of line input
    GetConsoleMode(hStdin, &oldMode);
    newMode = oldMode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
    SetConsoleMode(hStdin, newMode);

    // read input from console
    ReadConsole(hStdin, buffer, sizeof(buffer), &numRead, NULL);
    buffer[numRead - 1] = '\0'; // remove newline character
    char  ch=buffer[0];
    // restore console input mode
    SetConsoleMode(hStdin, oldMode);


    memset(buffer, 0, sizeof(buffer)); // clear buffer
    return ch;
}
int inputNum(){
    char buffer [250];
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD oldMode, newMode, numRead;

    // switch console input mode to allow reading of line input
    GetConsoleMode(hStdin, &oldMode);
    newMode = oldMode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
    SetConsoleMode(hStdin, newMode);

    // read input from console
    ReadConsole(hStdin, buffer, sizeof(buffer), &numRead, NULL);
    buffer[numRead - 1] = '\0'; // remove newline character
    int num=0;
    int base=1;
    for (int  i = (int)numRead - 2; i >= 0; --i) {
        num+=(buffer[i]-'0')*base;
        base*=10;
    }
    // restore console input mode
    SetConsoleMode(hStdin, oldMode);

    memset(buffer, 0, sizeof(buffer)); // clear buffer
    return num;
}
void colorOptions() {
    printf("Choose Color:\n"
           "a. White\n"
           "b. Black\n"
           "c. Red\n"
           "d. Green\n"
           "e. Blue\n"
           "f. Other\n"
    );
    colorOption=input();
    if (colorOption == 'a') {
        color = RGB(255, 255, 255);
    } else if (colorOption == 'b') {
        color = RGB(0, 0, 0);
    } else if (colorOption == 'c') {
        color = RGB(255, 0, 0);
    } else if (colorOption == 'd') {
        color = RGB(0, 255, 0);
    } else if (colorOption == 'e') {
        color = RGB(0, 0, 255);
    } else if (colorOption == 'f') {
        printf("Enter The Color RGB Values:\n");
        int r, g, b;
        r= inputNum();
        g= inputNum();
        b= inputNum();
        printf("%d  %d  %d",r,g,b);
        color = RGB(r, g, b);
    }
}
void lineOptions() {
    printf("Choose Algorithm:\n"
           "a. DDA\n"
           "b. MidPoint\n"
           "c. Parametric\n"
    );
    lineOption=input();

}
void circleOptions() {
    printf("Choose Algorithm:\n"
           "a. Direct\n"
           "b. Polar\n"
           "c. Iterative Polar\n"
           "d. Midpoint\n"
           "e. Modified Midpoint\n"
    );
    circleOption=input();
}
void ellipseOptions() {
    printf("Choose Algorithm:\n"
           "a. Direct\n"
           "b. Polar\n"
           "c. Midpoint\n"
    );
    ellipseOption=input();
}
void clippingRecOptions() {
    printf("Choose Algorithm:\n"
           "a. Point\n"
           "b. Line\n"
           "c. Polygon\n"
    );
    clippingRecOption=input();
}
void clippingSquareOptions() {
    printf("Choose Algorithm:\n"
           "a. Point\n"
           "b. Line\n"
    );
    clippingSquareOption=input();

}
void quarterInput(){
    printf("Enter Quarter [1, 2, 3, 4]: \n");
    quarter=input()-'0';
}
void mainList() {

    printf("Enter Your Option Character: \n"
           "a. Change the background of window to be white\n"
           "b. Change the shape of your window mouse\n"
           "c. Clear screen from shapes\n"
           "d. Save all data in screen \n"
           "e. Load data from files\n"
           "f. Draw line [DDA, Midpoint and Parametric]\n"
           "g. Draw Circle [Direct, Polar, Iterative Polar, Midpoint and Modified Midpoint]\n"
           "h. Filling Circle with lines \n"
           "i. Filling Circle with other circles \n"
           "j. Filling Square with Hermit Curve[Vertical]\n"
           "k. Filling Rectangle with Bezier Curve[Horizontal]\n"
           "l. Convex Filling \n"
           "m. Non Convex Filling \n"
           "n. Recursive Flood Fill\n"
           "o. Non Recursive Flood Fill\n"
           "p. Cardinal Spline Curve\n"
           "q. Ellipse [Direct, Polar and Midpoint]\n"
           "r. Clipping algorithms using Rectangle as Clipping Window[Point ,Line, Polygon] \n"
           "s. Clipping algorithms using Square as Clipping Window[Point ,Line]\n"

    );
    option=input();
    colorOptions();
    if (option == 'a') {

    } else if (option == 'b') {

    } else if (option == 'c') {

    } else if (option == 'd') {

    } else if (option == 'e') {

    } else if (option == 'f') {
        lineOptions();
    } else if (option == 'g') {
        circleOptions();

    } else if (option == 'h') {
        quarterInput();
    } else if (option == 'i') {
        quarterInput();

    } else if (option == 'j') {

    } else if (option == 'k') {

    } else if (option == 'l') {

    } else if (option == 'm') {

    } else if (option == 'n') {

    } else if (option == 'o') {

    } else if (option == 'p') {

    } else if (option == 'q') {
        ellipseOptions();
    } else if (option == 'r') {
        clippingRecOptions();
    } else if (option == 's') {
        clippingSquareOptions();
    }
}

LRESULT WINAPI WndProc(HWND hWnd, UINT m, WPARAM wp, LPARAM lp) {
    HDC hdc;
    switch (m) {
        case WM_CREATE:
            mainList();
            break;
        case WM_LBUTTONDOWN:
        {

            if (option == 'a') {

            } else if (option == 'b') {

            } else if (option == 'c') {

            } else if (option == 'd') {

            } else if (option == 'e') {

            } else if (option == 'f') {

            } else if (option == 'g') {
                if(counter%2==0){
                    xs = LOWORD(lp);
                    ys = HIWORD(lp);
                }else{
                    hdc= GetDC(hWnd);
                    xe = LOWORD(lp);
                    ye = HIWORD(lp);
                    int r=(int) sqrt((xs-xe)*(xs-xe)+(ys-ye)*(ys-ye));
                    if (circleOption == 'a') {
                        DrawCartesianCircle(hdc,xs,ys,r,color);
                    } else if (circleOption == 'b') {
                        DrawPolarCircle(hdc,xs,ys,r,color);
                    } else if (circleOption == 'c') {
                        DrawCircleIterativePolar(hdc,xs,ys,r,color);
                    } else if (circleOption == 'd') {
                        DrawMidpointCircle(hdc,xs,ys,r,color);
                    } else if (circleOption == 'e') {
                        DrawModifiedMidpointCircle(hdc,xs,ys,r,color);
                    }
                    ReleaseDC(hWnd, hdc);
                    counter=-1;
                    mainList();

                }

            } else if (option == 'h') {
                quarterInput();


            } else if (option == 'i') {
                quarterInput();

            } else if (option == 'j') {

            } else if (option == 'k') {

            } else if (option == 'l') {

            } else if (option == 'm') {

            } else if (option == 'n') {

            } else if (option == 'o') {

            } else if (option == 'p') {

            } else if (option == 'q') {

            } else if (option == 'r') {

            } else if (option == 's') {

            }

            counter++;
        }
            break;
        case WM_CLOSE:
            DestroyWindow(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
        default:
            return DefWindowProc(hWnd, m, wp, lp);
    }


    return 0;
}


int APIENTRY WinMain(HINSTANCE h, HINSTANCE p, LPSTR cmd, int csh) {

    WNDCLASS wc;
    wc.lpszClassName = "MyClass";
    wc.lpszMenuName = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hbrBackground = (HBRUSH) GetStockObject(LTGRAY_BRUSH);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = h;
    RegisterClass(&wc);
    HWND hWnd = CreateWindow("MyClass", "Hello", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, h, 0);
    ShowWindow(hWnd, csh);
    UpdateWindow(hWnd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}