
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#include <stdio.h>
#include "error.h"
#include "square.h"

double square_surface(double side)
{
  if (side < 0)
  {
    set_error(1);
    return 0;
  }
  return side * side;
}

double square_perimeter(double side)
{
  if (side < 0)
  {
    set_error(1);
    return 0;
  }

  return side * 4;
}