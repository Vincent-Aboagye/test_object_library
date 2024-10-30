
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#include <stdio.h>
#include "error.h"
#include "triangle.h"

double triangle_surface(double height, double width)
{
    if (height < 0 || width < 0)
    {
        set_error(1);
        return 0;
    }

    double surface = height * width / 2;
    return surface;
}

double triangle_perimeter(double side_a, double side_b, double side_c)
{
    if (side_a < 0 || side_b < 0 || side_c < 0)
    {
        set_error(1);
        return 0;
    }

    double perimeter = side_a + side_b + side_c;
    return perimeter;
}

double triangle_perimeter_array(double sides[])
{
    int res=0;
    for( int i=0; i<3; i++){
        if ( sides[i] < 0 ){
            set_error(1);
            return 0;
	    }
	    res += sides[i];
    }
    return res;
}
