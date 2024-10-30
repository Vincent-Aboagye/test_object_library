
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#include <stdio.h>
#include "error.h"

static int MATH_ERROR;

void set_error(int error_value)
{
    MATH_ERROR = error_value;
}

int get_error(void)
{
    return MATH_ERROR;
}