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
static int tranX, tranY;

pair<int , int> extendedEuclid(int a, int b){
    if(b == 0){
        return make_pair(1, 0);
    }
    else{
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
        colorOptions();
    } else if (option == 'g') {
        circleOptions();
        colorOptions();

    } else if (option == 'h') {
        quarterInput();
    } else if (option == 'i') {
        quarterInput();
    } else if (option == 'j') {
        colorOptions();
    } else if (option == 'k') {
        colorOptions();
    } else if (option == 'l') {
        cout << "How many Point you will draw: " << endl;
        cin >> numberOfPoints;
        colorOptions();
    } else if (option == 'm') {
        cout << "How many Point you will draw: " << endl;
        cin >> numberOfPoints;
        colorOptions();
    } else if (option == 'n') {
        colorOptions();

    } else if (option == 'o') {
        colorOptions();

    } else if (option == 'p') {
        splineCardinalCurveOptions();
    } else if (option == 'q') {
        colorOptions();
        ellipseOptions();
    } else if (option == 'r') {
        colorOptions();
        clippingRecOptions();
    } else if (option == 's') {
        colorOptions();
        clippingSquareOptions();
    } else if (option == 't') {
        colorOptions();
        clippingSquareOptions();
    } else if (option == 'u') {
        transformationOptions();
        colorOptions();
    }
}


HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255)); // create white brush as default background
LRESULT WINAPI WndProc(HWND hWnd, UINT m, WPARAM wp, LPARAM lp) {
    HDC hdc;
    if (cursor == nullptr)cursor = LoadCursor(NULL, IDC_ARROW);

//    SetCursor(cursor);
    switch (m) {
        case WM_CREATE: {
            mainList();
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
        case WM_LBUTTONDOWN: {
            if (option == 'a') {
                colorInit();
                DeleteObject(hBrush);
                hBrush = CreateSolidBrush(RGB(BackgroundColor.r, BackgroundColor.g, BackgroundColor.b));
                InvalidateRect(hWnd, NULL, TRUE);
                UpdateWindow(hWnd);
                mainList();
                counter = -1;
            } else if (option == 'b') {
                cursorInit();
                SetCursor(cursor);
                InvalidateRect(hWnd, NULL, TRUE);
                UpdateWindow(hWnd);
                mainList();
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
                mainList();
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
                mainList();
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
                mainList();
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
                    mainList();

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
                    mainList();

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
                    mainList();
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
                    mainList();
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
                    mainList();
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
                    mainList();
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
                    mainList();
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
                    mainList();
                }
            } else if (option == 'n') {
                hdc = GetDC(hWnd);
                xe = LOWORD(lp);
                ye = HIWORD(lp);
                RecFloodFill(hdc, xe, ye, color, GetPixel(hdc, xe, ye));
                counter = -1;
                mainList();

            } else if (option == 'o') {
                hdc = GetDC(hWnd);
                xe = LOWORD(lp);
                ye = HIWORD(lp);
                NonRecFloodFill(hdc, xe, ye, color, GetPixel(hdc, xe, ye));
                counter = -1;
                mainList();

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
                    mainList();
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
                    mainList();

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
                        mainList();
                    }
                    if (clippingRecOption == 'c') {
                        myPoint.push_back({x, y});
                        if (myPoint.size() == polygonN) {
                            PolygonClip(hdc, myPoint, polygonN, xs, ys, xe, ye, color);
                            counter = -1;
                            myPoint.clear();
                            mainList();
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
                        mainList();
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
                        mainList();
                    }
                } else if (counter % 4 == 3) {
                    hdc = GetDC(hWnd);
                    xx = LOWORD(lp);
                    yy = HIWORD(lp);
                    if (clippingSquareOption == 'b') {
                        LineClipping(hdc, x, y, xx, yy, xs, ys, xe, ye, color);
                        ReleaseDC(hWnd, hdc);
                        counter = -1;
                        mainList();
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
                        mainList();
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
                        mainList();
                    }
                }
            } else if (option == 'u') {
                if (transformationoption == 'a') {
                    hdc = GetDC(hWnd);
                    TranslationLineDDA(hdc, lxs, lys, lxe, lye, tranX, tranY, color);

                    ReleaseDC(hWnd, hdc);
                    counter = -1;
                    mainList();
                } else if (transformationoption == 'b') {
                    hdc = GetDC(hWnd);
                    ScalingLineDDA(hdc, lxs, lys, lxe, lye, tranX, tranY, color);
//                    int A = lye - lys, B = -(lxe - lxs);
//                    pair<int, int> ret = extendedEuclid(A, B);
//                    int X = ret.first, Y = ret.second;
//
//                    int g = __gcd(lxe - lxs, lye - lys);
//                    int dx = (lxe - lxs)/g, dy = (lye - lys)/g;
//                    // draw
//                    for (int i = 0; i < 100; ++i) {
//                        X += dx;
//                        Y += dy;
//                        ScalingLineDDA(hdc, lxs + X, lys + Y, lxe + X, lye + Y, tranX, tranY, color);
//                    }
                    for (double i = 1.0 / min(tranX,tranY); i <= min(tranX,tranY)/(min(tranX,tranY)/2); i += 1.0 / min(tranX,tranY))
                        ScalingLineDDA(hdc, lxs + i, lys + i, lxe + i, lye + i, tranX, tranY, color);

                    ReleaseDC(hWnd, hdc);
                    counter = -1;
                    mainList();
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
