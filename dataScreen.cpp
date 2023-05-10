#include "dataScreen.h"
#include "windows.h"

unordered_map<int, COLORREF> pixels;

int getID(int i, int j) {
    return i * 600 + j;
}

void add(int i, int j, COLORREF color) {
    pixels[getID(i, j)] = color;
}

unordered_map<int, COLORREF> getPixels() {
    return pixels;
}

void clear() {
    pixels.clear();
};