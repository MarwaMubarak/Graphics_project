//
// Created by Esawy on 5/16/2023.
//

#ifndef GRAPHICS_PROJECT_TRANSFORMATION_H
#define GRAPHICS_PROJECT_TRANSFORMATION_H

#include "windows.h"


void TranslationLineDDA(HDC hdc, int x1, int y1, int x2, int y2, double tx, double ty, COLORREF c);

void ScalingLineDDA(HDC hdc, double x1, double y1, double x2, double y2, double ScX, double ScY, COLORREF c);


#endif //GRAPHICS_PROJECT_TRANSFORMATION_H
