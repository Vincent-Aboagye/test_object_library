
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#include <stdio.h>
#include "error.h"
#include "circle.h"

#define APPROXIMATE_PI 3.14

double circle_surface(double radius)
{
    if (radius < 0)
    {
        set_error(1);
        return 0;
    }

    double surface = radius * radius * APPROXIMATE_PI;
    return surface;
}

double circle_perimeter(double radius)
{
    if (radius < 0)
    {       
        set_error(1);
        return 0;
    }

    double perimeter = radius * 2 * APPROXIMATE_PI;
    return perimeter;
}
