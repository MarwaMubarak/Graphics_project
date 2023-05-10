#include "windows.h"
#include "unordered_map"
using namespace std;
#ifndef GRAPHICS_PROJECT_DATASCREEN_H
#define GRAPHICS_PROJECT_DATASCREEN_H
int getID(int i, int j);
void add(int i, int j, COLORREF color);
unordered_map<int, COLORREF> getPixels();
void clear();
#endif //GRAPHICS_PROJECT_DATASCREEN_H

