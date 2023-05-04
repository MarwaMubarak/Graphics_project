#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include "circle.h"
#include <math.h>
#include <winnt.h >

using namespace std;
static int counter =0;
static COLORREF color= RGB(0,255,0);
static char colorOption;
static char lineOption;
static char circleOption;
static char ellipseOption;
static char clippingRecOption;
static char clippingSquareOption;
static char option='g';
static int quarter;
static int xs,ys,xe,ye;

struct COLOR{
    int r, g, b;
};
COLOR BackgroundColor;
HCURSOR cursor;
void colorInit() {
    cout << "Choose Color:\n"
            "a. White\n"
            "b. Black\n"
            "c. Red\n"
            "d. Green\n"
            "e. Blue\n"
            "f. Other" << endl;
    cin >> colorOption;
    if (colorOption == 'a') {
        BackgroundColor.r = 255;
        BackgroundColor.g = 255;
        BackgroundColor.b = 255;
    } else if (colorOption == 'b') {
        BackgroundColor.r = 0;
        BackgroundColor.g = 0;
        BackgroundColor.b = 0;
    } else if (colorOption == 'c') {
        BackgroundColor.r = 255;
        BackgroundColor.g = 0;
        BackgroundColor.b = 0;
    } else if (colorOption == 'd') {
        BackgroundColor.r = 0;
        BackgroundColor.g = 255;
        BackgroundColor.b = 0;
    } else if (colorOption == 'e') {
        BackgroundColor.r = 0;
        BackgroundColor.g = 0;
        BackgroundColor.b = 255;
    } else if (colorOption == 'f') {
        cout << "Enter The Color RGB Values\n";
        cin >> BackgroundColor.r >> BackgroundColor.g >> BackgroundColor.b;
    }
}
void cursorInit() {
    cout << "Choose the Shape of the cursor:\n"
            "a. Arrow\n"
            "b. Hand\n"
            "c. Cross\n"
            << endl;
    char chosenCursor;
    cin >> chosenCursor;
    if(chosenCursor == 'a'){
        cursor = LoadCursor(NULL, IDC_ARROW);
    }
    else if(chosenCursor == 'b'){
        cursor = LoadCursor(NULL, IDC_HAND);
    }
    else if(chosenCursor == 'c'){
        cursor = LoadCursor(NULL, IDC_CROSS);
    }
}
void lineOptions() {
    cout << "Choose Algorithm:\n"
            "a. DDA\n"
            "b. MidPoint\n"
            "c. Parametric" << endl;
    cin >> lineOption;
}
void circleOptions() {
    cout <<"Choose Algorithm:\n"
           "a. Direct\n"
           "b. Polar\n"
           "c. Iterative Polar\n"
           "d. Midpoint\n"
           "e. Modified Midpoint" << endl;
    cin >> circleOption;
}
void ellipseOptions() {
    cout << "Choose Algorithm:\n"
            "a. Direct\n"
            "b. Polar\n"
            "c. Midpoint" << endl;
    cin >> ellipseOption;
}
void clippingRecOptions() {
    cout << "Choose Algorithm:\n"
            "a. Point\n"
            "b. Line\n"
            "c. Polygon" << endl;
    cin >> clippingRecOption;
}
void clippingSquareOptions() {
    cout << "Choose Algorithm:\n"
            "a. Point\n"
            "b. Line" <<endl;
    cin >> clippingSquareOption;
}
void quarterInput(){
    cout << "Enter Quarter [1, 2, 3, 4]: " << endl;
    cin >> quarter;
}
void mainList() {
    cout <<"Enter Your Option Character: \n"
           "a. Clear screen from shapes\n"
           "b. Save all data in screen \n"
           "c. Load data from files\n"
           "d. Draw line [DDA, Midpoint and Parametric]\n"
           "e. Draw Circle [Direct, Polar, Iterative Polar, Midpoint and Modified Midpoint]\n"
           "f. Filling Circle with lines \n"
           "g. Filling Circle with other circles \n"
           "h. Filling Square with Hermit Curve[Vertical]\n"
           "i. Filling Rectangle with Bezier Curve[Horizontal]\n"
           "j. Convex Filling \n"
           "k. Non Convex Filling \n"
           "l. Recursive Flood Fill\n"
           "m. Non Recursive Flood Fill\n"
           "n. Cardinal Spline Curve\n"
           "o. Ellipse [Direct, Polar and Midpoint]\n"
           "p. Clipping algorithms using Rectangle as Clipping Window[Point ,Line, Polygon] \n"
           "q. Clipping algorithms using Square as Clipping Window[Point ,Line]" << endl;
    cin >> option;
    if (option == 'a') {

    } else if (option == 'b') {

    } else if (option == 'c') {

    } else if (option == 'd') {
        lineOptions();
    } else if (option == 'e') {
        circleOptions();
    } else if (option == 'f') {
        quarterInput();

    } else if (option == 'g') {
        quarterInput();
    } else if (option == 'h') {

    } else if (option == 'i') {

    } else if (option == 'j') {

    } else if (option == 'k') {

    } else if (option == 'l') {

    } else if (option == 'm') {

    } else if (option == 'n') {

    } else if (option == 'o') {
        ellipseOptions();
    } else if (option == 'p') {
        clippingRecOptions();
    } else if (option == 'q') {
        clippingSquareOptions();
    }
}
// testing
LRESULT WINAPI WndProc(HWND hWnd, UINT m, WPARAM wp, LPARAM lp) {
    HDC hdc;
    switch (m) {
        case WM_CREATE:
            mainList();
            break;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            hdc = BeginPaint(hWnd, &ps);
            HBRUSH hBrush = CreateSolidBrush(RGB(BackgroundColor.r, BackgroundColor.g, BackgroundColor.b));
            RECT rect;
            GetClientRect(hWnd, &rect);
            FillRect(hdc, &rect, hBrush);
            DeleteObject(hBrush);
            EndPaint(hWnd, &ps);
            break;
        }
        case WM_SETCURSOR:
            SetCursor(cursor);
            break;
        case WM_LBUTTONDOWN:
        {
            if (option == 'a') {

            } else if (option == 'b') {

            } else if (option == 'c') {

            } else if (option == 'd') {

            } else if (option == 'e') {
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
            } else if (option == 'f') {
                quarterInput();

            } else if (option == 'g') {
                quarterInput();


            } else if (option == 'h') {

            } else if (option == 'i') {

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

void init(){
    cout << "Set you best configuration of the window" << endl;
    cout << "----------------------------------------" << endl;
    colorInit();
    cursorInit();
}
int APIENTRY WinMain(HINSTANCE h, HINSTANCE p, LPSTR cmd, int csh) {
    WNDCLASS wc = {};
    wc.lpszClassName = "MyClass";
    wc.lpszMenuName = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(0, 0, 0));
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = h;
    RegisterClass(&wc);
    init();
    HWND hWnd = CreateWindow("MyClass", "Hello", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, h, 0);
    if (hWnd == NULL)
    {
        return 0;
    }
    ShowWindow(hWnd, csh);
//    UpdateWindow(hWnd);
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}