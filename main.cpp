#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include "circle.h"
#include <math.h>
#include <winnt.h >
#include "filling_quarters.h"
#include "floodfill.h"
#include "rectangle.h"
#include "clipping.h"
#include "square.h"
#include "ellipse.h"
#include "vector"
#include "filling_curve.h"
#include <fstream>
#include <deque>
#include "cardinal_spline_curve.h"
#include "line.h"
#include "dataScreen.h"
#include "ConverxFill.h"
#include "clippingCircle.h"
#include "NonConvics.h"
#include "Transformation.h"
#include <algorithm>

using namespace std;
static int counter = 0;
static int polygonN;
vector<POINT> myPoint;
static COLORREF color = RGB(0, 0, 255);
static char colorOption;
static char lineOption;
static char circleOption;
static char ellipseOption;
static char clippingRecOption;
static char clippingSquareOption;
static char option = 'g';
static int quarter;
static int xs, ys, xe, ye;
static int x, y, xx, yy;
static int x2, y2, x3, y3, numberOfPoints;
static double tension;
static int lxs, lys, lxe, lye;
vector<pair<int, int>> vecPoints;
static char transformationoption;
static double tranX, tranY;

pair<int, int> extendedEuclid(int a, int b) {
    if (b == 0) {
        return make_pair(1, 0);
    } else {
        pair<int, int> d = extendedEuclid(b, a % b);
        return make_pair(d.second, d.first - d.second * (a / b));
    }
}

void transformationOptions() {
    cout << "a. TranslationLine\n"
         << "b. ScallingLine\n";

    cin >> transformationoption;
    if (transformationoption == 'a')
        cout << "Enter the values of transmation\n";
    else
        cout << "Enter the values of Scale\n";
    cin >> tranX >> tranY;
}

void colorOptions() {
    cout << "Choose Color:\n"
            "a. White\n"
            "b. Black\n"
            "c. Red\n"
            "d. Green\n"
            "e. Blue\n"
            "f. Other\n";
    cin >> colorOption;

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

        cout << "Enter The Color RGB Values:\n";
        int r, g, b;
        cin >> r >> g >> b;

        color = RGB(r, g, b);
    }
}

struct COLOR {
    int r = 255, g = 255, b = 255;
};
COLOR BackgroundColor;
HCURSOR cursor;

void takeQuarter() {
    std::cout << "Enter which quarter:\n";
    std::cout << "12\n"
              << "34\n";
    std::cin >> quarter;

}

void colorInit() {
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
    char chosenCursor;
    cin >> chosenCursor;
    if (chosenCursor == 'a') {
        cursor = LoadCursor(NULL, IDC_ARROW);
    } else if (chosenCursor == 'b') {
        cursor = LoadCursor(NULL, IDC_HAND);
    } else if (chosenCursor == 'c') {
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
    cout << "Choose Algorithm:\n"
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
    if (clippingRecOption == 'c') {
        cout << "how many  point's polygon? ";
        cin >> polygonN;
    }
}

void clippingSquareOptions() {
    cout << "Choose Algorithm:\n"
            "a. Point\n"
            "b. Line" << endl;
    cin >> clippingSquareOption;
}

void quarterInput() {
    cout << "Enter Quarter [1, 2, 3, 4]: " << endl;
    cin >> quarter;
}

void splineCardinalCurveOptions() {
    cout << "How many Point you will draw: " << endl;
    cin >> numberOfPoints;
    cout << "Enter the tension of the curve: " << endl;
    cin >> tension;
    colorOptions();
}


void mainList() {
    cout << "Enter Your Option Character: \n"
            "a. Set background color\n"
            "b. Change mouse cursor\n"
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
            "s. Clipping algorithms using Square as Clipping Window[Point ,Line] \n"
            "t. Clipping algorithms using Circle as Clipping Window[Point ,Line]\n"
            "u. Transformation in line" << endl;

    cin >> option;
    if (option == 'a') {
        cout << "Choose Color:\n"
                "a. White\n"
                "b. Black\n"
                "c. Red\n"
                "d. Green\n"
                "e. Blue\n"
                "f. Other" << endl;
    } else if (option == 'b') {
        cout << "Choose the Shape of the cursor:\n"
                "a. Arrow\n"
                "b. Hand\n"
                "c. Cross\n"
             << endl;
    } else if (option == 'c') {

    } else if (option == 'd') {
        cout << "Are you sure you want to save:\n"
                "a. YES\n"
                "b. NO\n"
             << endl;
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
        cout << "How many Point you will draw: " << endl;
        cin >> numberOfPoints;

    } else if (option == 'm') {
        cout << "How many Point you will draw: " << endl;
        cin >> numberOfPoints;

    } else if (option == 'n') {


    } else if (option == 'o') {


    } else if (option == 'p') {
        splineCardinalCurveOptions();
    } else if (option == 'q') {

        ellipseOptions();
    } else if (option == 'r') {

        clippingRecOptions();
    } else if (option == 's') {

        clippingSquareOptions();
    } else if (option == 't') {

        clippingSquareOptions();
    } else if (option == 'u') {
        transformationOptions();

    }
}


HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255)); // create white brush as default background
LRESULT WINAPI WndProc(HWND hWnd, UINT m, WPARAM wp, LPARAM lp) {
    HDC hdc;
    if (cursor == nullptr)cursor = LoadCursor(NULL, IDC_ARROW);

//    SetCursor(cursor);
    switch (m) {
        case WM_CREATE: {
            // Create the menu
            HMENU hMenu = CreateMenu();

            HMENU hSubMenu1 = CreatePopupMenu();
            HMENU hSubMenu2 = CreatePopupMenu();
            HMENU hSubMenu3 = CreatePopupMenu();
            HMENU hSubMenu4 = CreatePopupMenu();
            HMENU hSubMenu5 = CreatePopupMenu();
            HMENU hSubMenu6 = CreatePopupMenu();
            HMENU hSubMenu7 = CreatePopupMenu();
            HMENU hSubMenu8 = CreatePopupMenu();
            HMENU hSubMenu9 = CreatePopupMenu();
            HMENU hSubMenu10 = CreatePopupMenu();
            HMENU hSubMenu11 = CreatePopupMenu();
            HMENU hSubMenu12 = CreatePopupMenu();
            HMENU hSubMenu13 = CreatePopupMenu();
            HMENU hSubMenu14 = CreatePopupMenu();
            HMENU hSubMenu15 = CreatePopupMenu();
            HMENU hSubMenu16 = CreatePopupMenu();
            HMENU hSubMenu17 = CreatePopupMenu();
            HMENU hSubMenu18 = CreatePopupMenu();
            HMENU hSubMenu19 = CreatePopupMenu();
            HMENU hSubMenu20 = CreatePopupMenu();
            HMENU hSubMenu21 = CreatePopupMenu();
            HMENU hSubMenu22 = CreatePopupMenu();


            AppendMenu(hSubMenu1, MF_STRING, 1, "Apply");
            AppendMenu(hSubMenu2, MF_STRING, 2, "Apply");
            AppendMenu(hSubMenu3, MF_STRING, 3, "Apply");
            AppendMenu(hSubMenu4, MF_STRING, 4, "Apply");
            AppendMenu(hSubMenu5, MF_STRING, 5, "Apply");
            AppendMenu(hSubMenu6, MF_STRING, 6, "Apply");
            AppendMenu(hSubMenu7, MF_STRING, 7, "Apply");
            AppendMenu(hSubMenu8, MF_STRING, 8, "Apply");
            AppendMenu(hSubMenu9, MF_STRING, 9, "Apply");
            AppendMenu(hSubMenu10, MF_STRING, 10, "Apply");
            AppendMenu(hSubMenu11, MF_STRING, 11, "Apply");
            AppendMenu(hSubMenu12, MF_STRING, 12, "Apply");
            AppendMenu(hSubMenu13, MF_STRING, 13, "Apply");
            AppendMenu(hSubMenu14, MF_STRING, 14, "Apply");
            AppendMenu(hSubMenu15, MF_STRING, 15, "Apply");
            AppendMenu(hSubMenu16, MF_STRING, 16, "Apply");
            AppendMenu(hSubMenu17, MF_STRING, 17, "Apply");
            AppendMenu(hSubMenu18, MF_STRING, 18, "Apply");
            AppendMenu(hSubMenu19, MF_STRING, 19, "Apply");
            AppendMenu(hSubMenu20, MF_STRING, 20, "Apply");
            AppendMenu(hSubMenu21, MF_STRING, 21, "Apply");
            AppendMenu(hSubMenu22, MF_STRING, 22, "Apply");


            // Append the submenus to the main menu
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu1, "Set background color");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu2, "Change mouse cursor");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu3, "Clear screen from shapes");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu4, "Save all data in screen");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu5, "Load data from files");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu6, "Draw line");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu7, "Draw Circle");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu8, "Filling Circle with lines");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu9, "Filling Circle with other circles");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu10, "Filling Square with Hermit Curve");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu11, "Filling Rectangle with Bezier Curve");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu12, "Convex Filling");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu13, "Non Convex Filling");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu14, "Recursive Flood Fill");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu15, "Non Recursive Flood Fill");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu16, "Cardinal Spline Curve");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu17, "Ellipse");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu18, "Clipping Rectangle");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu19, "Clipping Square");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu20, "Clipping Circle");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu21, "Transformation");
            AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu22, "Set Pen Color");

            // Attach the menu to the window
            SetMenu(hWnd, hMenu);
//            mainList();
            break;
        }
        case WM_PAINT: {
            PAINTSTRUCT ps;
            hdc = BeginPaint(hWnd, &ps);
            RECT rect;
            GetClientRect(hWnd, &rect);
            FillRect(hdc, &rect, hBrush);
            unordered_map<int, COLORREF> pixels = getPixels();
            for (auto f: pixels) {
                int i = f.first / 600;
                int j = f.first % 600;
                SetPixel(hdc, i, j, f.second);
            }
            EndPaint(hWnd, &ps);


            break;
        }

        case WM_COMMAND: {
            switch (LOWORD(wp)) {
                case 1: {
                    cout << "Choose Color:\n"
                            "a. White\n"
                            "b. Black\n"
                            "c. Red\n"
                            "d. Green\n"
                            "e. Blue\n"
                            "f. Other" << endl;
                    option = 'a';
                    colorInit();
                    break;
                }
                case 2:{
                    cout << "Choose the Shape of the cursor:\n"
                            "a. Arrow\n"
                            "b. Hand\n"
                            "c. Cross\n"
                         << endl;
                    cursorInit();
                    SetCursor(cursor);
                    option = 'b';
                    break;
                }
                case 3:{
                    option = 'c';
                    break;
                }
                case 4:{
                    cout << "Are you sure you want to save:\n"
                            "a. YES\n"
                            "b. NO\n"
                         << endl;
                    option = 'd';
                    break;
                }
                case 5:{
                    option = 'e';
                    break;
                }
                case 6:{
                    option = 'f';
                    lineOptions();

                    break;
                }
                case 7:{
                    option = 'g';
                    circleOptions();

                    break;
                }
                case 8:{
                    option = 'h';
                    quarterInput();
                    break;

                }
                case 9:{
                    option = 'i';
                    quarterInput();
                    break;

                }
                case 10:{
                    option = 'j';

                    break;

                }
                case 11:{
                    option = 'k';

                    break;

                }
                case 12:{
                    option = 'l';
                    cout << "How many Point you will draw: " << endl;
                    cin >> numberOfPoints;

                    break;
                }
                case 13:{
                    option = 'm';
                    cout << "How many Point you will draw: " << endl;
                    cin >> numberOfPoints;

                    break;
                }
                case 14:{
                    option = 'n';

                    break;
                }
                case 15:{
                    option = 'o';

                    break;
                }
                case 16:{
                    option = 'p';
                    splineCardinalCurveOptions();
                    break;
                }
                case 17:{
                    option = 'q';

                    ellipseOptions();
                    break;
                }
                case 18:{
                    option = 'r';

                    clippingRecOptions();
                    break;
                }
                case 19:{
                    option = 's';

                    clippingSquareOptions();
                    break;
                }
                case 20:{
                    option = 't';

                    clippingSquareOptions();
                    break;
                }
                case 21:{
                    option = 'u';
                    transformationOptions();

                    break;
                }
                case 22:{
                    colorOptions();
                    break;
                }
            }
            break;
        }
        case WM_LBUTTONDOWN: {
            if (option == 'a') {
//                colorInit();
                DeleteObject(hBrush);
                hBrush = CreateSolidBrush(RGB(BackgroundColor.r, BackgroundColor.g, BackgroundColor.b));
                InvalidateRect(hWnd, NULL, TRUE);
                UpdateWindow(hWnd);
//                mainList();
                counter = -1;
            } else if (option == 'b') {
//                cursorInit();
                SetCursor(cursor);
                InvalidateRect(hWnd, NULL, TRUE);
                UpdateWindow(hWnd);
//                mainList();
                counter = -1;
            } else if (option == 'c') {
                for (auto f: getPixels()) {
                    int i = f.first / 600;
                    int j = f.first % 600;
                    SetPixel(hdc, i, j, RGB(BackgroundColor.r, BackgroundColor.g, BackgroundColor.b));
                }
                clear();
                InvalidateRect(hWnd, NULL, TRUE);
                UpdateWindow(hWnd);
//                mainList();
                counter = -1;
            } else if (option == 'd') {
                char response;
                cin >> response;
                if (response == 'a') {
//                  SaveHWNDToBMP(hWnd);
                    {
                        ofstream cout("saved.txt");
                        cout << getPixels().size() << ' ';
                        for (auto X: getPixels()) {
                            cout << X.first / 600 << ' ' << X.first % 600 << ' ' << int(GetRValue(X.second)) << ' '
                                 << int(GetGValue(X.second)) << ' '
                                 << int(GetBValue(X.second)) << ' ';

                        }
                        cout << BackgroundColor.r << ' ' << BackgroundColor.g << ' ' << BackgroundColor.b;
                    }
                }
//                mainList();
                counter = -1;
            } else if (option == 'e') {
                clear();
                int size;
                {
                    ifstream cin("saved.txt");
                    cin >> size;
                    int x, y, r, g, b;
                    for (int i = 0; i < size; i++) {
                        cin >> x >> y >> r >> g >> b;
                        add(x, y, RGB(r, g, b));
                    }
                    cin >> BackgroundColor.r >> BackgroundColor.g >> BackgroundColor.b;
                    DeleteObject(hBrush);
                    hBrush = CreateSolidBrush(RGB(BackgroundColor.r, BackgroundColor.g, BackgroundColor.b));
                }
                InvalidateRect(hWnd, NULL, TRUE);
                UpdateWindow(hWnd);
//                mainList();
                counter = -1;
                break;

            } else if (option == 'f') {
                if (counter % 2 == 0) {
                    xs = LOWORD(lp);
                    ys = HIWORD(lp);
                    lxs = xs;
                    lys = ys;
                } else {
                    hdc = GetDC(hWnd);
                    xe = LOWORD(lp);
                    ye = HIWORD(lp);
                    lxe = xe;
                    lye = ye;
                    if (lineOption == 'a') {
                        DrawLineDDA(hdc, xs, ys, xe, ye, color);

                    } else if (lineOption == 'b') {
                        DrawLineMidPoint(hdc, xs, ys, xe, ye, color);
                    } else if (lineOption == 'c') {
                        DrawLineParametric(hdc, xs, ys, xe, ye, color);
                    }
                    ReleaseDC(hWnd, hdc);
                    counter = -1;
//                    mainList();

                }

            } else if (option == 'g') {
                if (counter % 2 == 0) {
                    xs = LOWORD(lp);
                    ys = HIWORD(lp);
                } else {
                    hdc = GetDC(hWnd);
                    xe = LOWORD(lp);
                    ye = HIWORD(lp);
                    int r = (int) sqrt((xs - xe) * (xs - xe) + (ys - ye) * (ys - ye));
                    if (circleOption == 'a') {
                        DrawCartesianCircle(hdc, xs, ys, r, color);
                    } else if (circleOption == 'b') {
                        DrawPolarCircle(hdc, xs, ys, r, color);
                    } else if (circleOption == 'c') {
                        DrawCircleIterativePolar(hdc, xs, ys, r, color);
                    } else if (circleOption == 'd') {
                        DrawMidpointCircle(hdc, xs, ys, r, color);
                    } else if (circleOption == 'e') {
                        DrawModifiedMidpointCircle(hdc, xs, ys, r, color);
                    }
//                    SaveMainWindowToBitmap(hWnd);
//                    InvalidateRect(hWnd, NULL, TRUE);
//                    ReleaseDC(hWnd, hdc);
                    counter = -1;
//                    mainList();

                }

            } else if (option == 'h') {
                if (counter % 2 == 0) {
                    xs = LOWORD(lp);
                    ys = HIWORD(lp);
                } else {
                    hdc = GetDC(hWnd);
                    xe = LOWORD(lp);
                    ye = HIWORD(lp);
                    draw_circul_line(hdc, xs, ys, xe, ye, color, quarter);

                    ReleaseDC(hWnd, hdc);
                    counter = -1;
//                    mainList();
                }
            } else if (option == 'i') {
                if (counter % 2 == 0) {
                    xs = LOWORD(lp);
                    ys = HIWORD(lp);
                } else {
                    hdc = GetDC(hWnd);
                    xe = LOWORD(lp);
                    ye = HIWORD(lp);
                    draw_circul_circuler(hdc, xs, ys, xe, ye, color, quarter);
                    ReleaseDC(hWnd, hdc);
                    counter = -1;
//                    mainList();
                }

            } else if (option == 'j') {
                if (counter % 2 == 0) {
                    x = LOWORD(lp);
                    y = HIWORD(lp);
                } else if (counter % 2 == 1) {

                    xx = LOWORD(lp);
                    yy = HIWORD(lp);
                    hdc = GetDC(hWnd);
                    int len = (int) sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
                    FillSquareHermite(hdc, x, y, len, color);
                    ReleaseDC(hWnd, hdc);
                    counter = -1;
//                    mainList();
                }
            } else if (option == 'k') {
                if (counter % 2 == 0) {
                    x = LOWORD(lp);
                    y = HIWORD(lp);
                } else if (counter % 2 == 1) {

                    xx = LOWORD(lp);
                    yy = HIWORD(lp);
                    hdc = GetDC(hWnd);
                    FillRectangleBezier(hdc, x, y, xx, yy, color);
                    ReleaseDC(hWnd, hdc);
                    counter = -1;
//                    mainList();
                }
            } else if (option == 'l') {
                if (!counter || counter % numberOfPoints) {
                    xs = LOWORD(lp);
                    ys = HIWORD(lp);
                    vecPoints.emplace_back(xs, ys);
                } else {
                    hdc = GetDC(hWnd);
                    ConvexFill(hdc, vecPoints, numberOfPoints, color);
                    ReleaseDC(hWnd, hdc);
                    vecPoints.clear();
                    counter = -1;
//                    mainList();
                }
            } else if (option == 'm') {
                if (!counter || counter % numberOfPoints) {
                    xs = LOWORD(lp);
                    ys = HIWORD(lp);
                    vecPoints.emplace_back(xs, ys);
                } else {
                    hdc = GetDC(hWnd);
                    GeneralFill(hdc, vecPoints, numberOfPoints, color);
                    ReleaseDC(hWnd, hdc);
                    vecPoints.clear();
                    counter = -1;
//                    mainList();
                }
            } else if (option == 'n') {
                hdc = GetDC(hWnd);
                xe = LOWORD(lp);
                ye = HIWORD(lp);
                RecFloodFill(hdc, xe, ye, color, GetPixel(hdc, xe, ye));
                counter = -1;
//                mainList();

            } else if (option == 'o') {
                hdc = GetDC(hWnd);
                xe = LOWORD(lp);
                ye = HIWORD(lp);
                NonRecFloodFill(hdc, xe, ye, color, GetPixel(hdc, xe, ye));
                counter = -1;
//                mainList();

            } else if (option == 'p') {
                if (!counter || counter % numberOfPoints) {
                    xs = LOWORD(lp);
                    ys = HIWORD(lp);
                    vecPoints.emplace_back(xs, ys);
                } else {
                    hdc = GetDC(hWnd);
                    DrawCardinalSpline(hdc, vecPoints, numberOfPoints, tension, color);
                    ReleaseDC(hWnd, hdc);
                    vecPoints.clear();

                    counter = -1;
//                    mainList();
                }
            } else if (option == 'q') {
                if (counter % 3 == 0) {
                    xs = LOWORD(lp);
                    ys = HIWORD(lp);
                } else if (counter % 3 == 1) {
                    x2 = LOWORD(lp);
                    y2 = HIWORD(lp);
                } else {
                    x3 = LOWORD(lp);
                    y3 = HIWORD(lp);
                    hdc = GetDC(hWnd);


                    int a = (int) sqrt((xs - x2) * (xs - x2) + (ys - y2) * (ys - y2));
                    int b = (int) sqrt((xs - x3) * (xs - x3) + (ys - y3) * (ys - y3));
                    if (ellipseOption == 'a')
                        DrawCartesianEllipse(hdc, xs, ys, a, b, color);
                    else if (ellipseOption == 'b')
                        DrawPolarEllipse(hdc, xs, ys, a, b, color);
                    else
                        DrawMidpointEllipse(hdc, xs, ys, a, b, color);

                    ReleaseDC(hWnd, hdc);
                    counter = -1;
//                    mainList();

                }
            } else if (option == 'r') {

                if (counter % 4 == 0) {
                    xs = LOWORD(lp);
                    ys = HIWORD(lp);
                } else if (counter % 4 == 1) {
                    hdc = GetDC(hWnd);
                    xe = LOWORD(lp);
                    ye = HIWORD(lp);
                    drawRectangle(hdc, xs, ys, xe, ye);
                    ReleaseDC(hWnd, hdc);

                } else if (counter % 4 == 2) {
                    hdc = GetDC(hWnd);
                    x = LOWORD(lp);
                    y = HIWORD(lp);
                    if (clippingRecOption == 'a') {

                        PointClipping(hdc, x, y, xs, ys, xe, ye, color);
                        ReleaseDC(hWnd, hdc);
                        counter = -1;
//                        mainList();
                    }
                    if (clippingRecOption == 'c') {
                        myPoint.push_back({x, y});
                        if (myPoint.size() == polygonN) {
                            PolygonClip(hdc, myPoint, polygonN, xs, ys, xe, ye, color);
                            counter = -1;
                            myPoint.clear();
//                            mainList();
                        } else counter--;
                    }


                } else if (counter % 4 == 3) {
                    hdc = GetDC(hWnd);
                    xx = LOWORD(lp);
                    yy = HIWORD(lp);
                    if (clippingRecOption == 'b') {
                        LineClipping(hdc, x, y, xx, yy, xs, ys, xe, ye, color);
                        ReleaseDC(hWnd, hdc);
                        counter = -1;
//                        mainList();
                    }
                }

            } else if (option == 's') {
                if (counter % 4 == 0) {
                    xs = LOWORD(lp);
                    ys = HIWORD(lp);
                } else if (counter % 4 == 1) {
                    hdc = GetDC(hWnd);
                    xe = LOWORD(lp);
                    ye = HIWORD(lp);
                    DrawSquare(hdc, xs, ys, xe, ye, color);
                    ReleaseDC(hWnd, hdc);
                } else if (counter % 4 == 2) {
                    hdc = GetDC(hWnd);
                    x = LOWORD(lp);
                    y = HIWORD(lp);
                    if (clippingSquareOption == 'a') {
                        PointClipping(hdc, x, y, xs, ys, xe, ye, color);
                        ReleaseDC(hWnd, hdc);
                        counter = -1;
//                        mainList();
                    }
                } else if (counter % 4 == 3) {
                    hdc = GetDC(hWnd);
                    xx = LOWORD(lp);
                    yy = HIWORD(lp);
                    if (clippingSquareOption == 'b') {
                        LineClipping(hdc, x, y, xx, yy, xs, ys, xe, ye, color);
                        ReleaseDC(hWnd, hdc);
                        counter = -1;
//                        mainList();
                    }
                }
            } else if (option == 't') {
                static int r;
                if (counter % 4 == 0) {
                    xs = LOWORD(lp);
                    ys = HIWORD(lp);
                } else if (counter % 4 == 1) {
                    hdc = GetDC(hWnd);
                    xe = LOWORD(lp);
                    ye = HIWORD(lp);
                    r = (int) sqrt((xs - xe) * (xs - xe) + (ys - ye) * (ys - ye));
                    DrawCartesianCircle(hdc, xs, ys, r, color);
                    ReleaseDC(hWnd, hdc);
                } else if (counter % 4 == 2) {
                    hdc = GetDC(hWnd);
                    x = LOWORD(lp);
                    y = HIWORD(lp);
                    if (clippingSquareOption == 'a') {
                        PointClippingC(hdc, x, y, xs, ys, r, color);
                        ReleaseDC(hWnd, hdc);
                        counter = -1;
//                        mainList();
                    }
                } else if (counter % 4 == 3) {
                    hdc = GetDC(hWnd);
                    xx = LOWORD(lp);
                    yy = HIWORD(lp);
                    if (clippingSquareOption == 'b') {
                        LineClippingC(hdc, x, y, xx, yy, xs, ys, r, color);
                        //LineClipping(hdc, x, y, xx, yy, xs, ys, xe, ye, color);
                        ReleaseDC(hWnd, hdc);
                        counter = -1;
//                        mainList();
                    }
                }
            } else if (option == 'u') {
                if (transformationoption == 'a') {
                    hdc = GetDC(hWnd);
                    TranslationLineDDA(hdc, lxs, lys, lxe, lye, tranX, tranY, color);

                    ReleaseDC(hWnd, hdc);
                    counter = -1;
//                    mainList();
                } else if (transformationoption == 'b') {
                    hdc = GetDC(hWnd);
                    ScalingLineDDA(hdc, lxs, lys, lxe, lye, tranX, tranY, color);

                    int j = 1;
                    for (double i = 0.6 / min(tranX, tranY); j <= tranX; i += 0.6 / min(tranX, tranY), j++)
                        ScalingLineDDA(hdc, lxs + i, lys + i, lxe + i, lye + i, tranX, tranY, color);

                    ReleaseDC(hWnd, hdc);
                    counter = -1;
//                    mainList();
                }
            }

        }
            counter++;
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
    WNDCLASS wc = {};
    wc.lpszClassName = "MyClass";
    wc.lpszMenuName = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(255, 255, 255));
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = h;
    RegisterClass(&wc);
    HWND hWnd = CreateWindow("MyClass", "Hello", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, h, 0);
    if (hWnd == NULL) {
        return 0;
    }
    ShowWindow(hWnd, csh);
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
