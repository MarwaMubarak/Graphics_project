#include <stdio.h>
#include <Windows.h>
#include "circle.h"
#include <math.h>

static COLORREF color;

void colorOptions() {
    printf("Choose Color:\n"
           "a. White\n"
           "b. Black\n"
           "c. Red\n"
           "d. Green\n"
           "e. Blue\n"
           "f. Other\n"
    );
    char option;
    scanf("%c", &option);
    if (option == 'a') {
        color = RGB(255, 255, 255);
    } else if (option == 'b') {
        color = RGB(0, 0, 0);
    } else if (option == 'c') {
        color = RGB(255, 0, 0);
    } else if (option == 'd') {
        color = RGB(0, 255, 0);
    } else if (option == 'e') {
        color = RGB(0, 0, 255);
    } else if (option == 'f') {
        printf("Enter The Color RGB Values:\n");
        int r, g, b;
        scanf("%d", &r);
        scanf("%d", &g);
        scanf("%d", &b);
        color = RGB(r, g, b);
    }
}

void lineOptions() {
    printf("Choose Algorithm:\n"
           "a. DDA\n"
           "b. MidPoint\n"
           "c. Parametric\n"
    );
    char option;
    scanf("%c", &option);
    if (option == 'a') {

    } else if (option == 'b') {

    } else if (option == 'c') {

    }

}

void circleOptions() {
    printf("Choose Algorithm:\n"
           "a. Direct\n"
           "b. Polar\n"
           "c. Iterative Polar\n"
           "d. Midpoint\n"
           "e. Modified Midpoint\n"
    );
    char option;
    scanf("%c", &option);

    if (option == 'a') {
        //DrawCartesianCircle(hdc,xc,yc,r,color);
    } else if (option == 'b') {
        //DrawPolarCircle(hdc,xc,yc,r,color);
    } else if (option == 'c') {
        //DrawCircleIterativePolar(hdc,xc,yc,r,color);
    } else if (option == 'd') {
        //DrawMidpointCircle(hdc,xc,yc,r,color);
    } else if (option == 'e') {
        //DrawModifiedMidpointCircle(hdc,xc,yc,r,color);
    }
}

void ellipseOptions() {
    printf("Choose Algorithm:\n"
           "a. Direct\n"
           "b. Polar\n"
           "c. Midpoint\n"
    );
    char option;
    scanf("%c", &option);

    if (option == 'a') {

    } else if (option == 'b') {

    } else if (option == 'c') {

    }
}

void clippingRecOptions() {
    printf("Choose Algorithm:\n"
           "a. Point\n"
           "b. Line\n"
           "c. Polygon\n"
    );
    char option;
    scanf("%c", &option);

    if (option == 'a') {

    } else if (option == 'b') {

    } else if (option == 'c') {

    }
}

void clippingSquareOptions() {
    printf("Choose Algorithm:\n"
           "a. Point\n"
           "b. Line\n"
    );
    char option;
    scanf("%c", &option);

    if (option == 'a') {

    } else if (option == 'b') {

    }
}

void Main() {

    printf("Enter Your Option Character:"
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

    char option;
    scanf("%c", &option);

    if (option == 'a') {

    } else if (option == 'b') {

    } else if (option == 'c') {

    } else if (option == 'd') {

    } else if (option == 'e') {

    } else if (option == 'f') {

    } else if (option == 'g') {

    } else if (option == 'h') {
        printf("Enter Quarter [1, 2, 3, 4]: \n");
        int quarter;
        scanf("%d", &quarter);


    } else if (option == 'i') {
        printf("Enter Quarter [1, 2, 3, 4]: \n");
        int quarter;
        scanf("%d", &quarter);

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

    } else if (option == 't') {

    } else if (option == 'u') {

    } else if (option == 'v') {

    } else if (option == 'w') {

    } else if (option == 'x') {

    } else if (option == 'y') {

    } else if (option == 'z') {

    }


}


LRESULT WINAPI WndProc(HWND hWnd, UINT m, WPARAM wp, LPARAM lp) {
    HDC hdc;

    switch (m) {
        case WM_LBUTTONDOWN:
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