
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#include <stdio.h>
#include "error.h"
#include "rectangle.h"

double rectangle_surface(double lenght, double width)
{
    if (lenght < 0 || width < 0)
    {
        set_error(1);
        return 0;
    }

    double surface = lenght * width;
    return surface;
}

double rectangle_perimeter(double lenght, double width)
{
    if (lenght < 0 || width < 0)
    {
        set_error(1);
        return 0;
    }

    double perimeter = lenght * 2 + width * 2;
    return perimeter;
}
