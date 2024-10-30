
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

/* libmasstesting headers */
#include <circle.h>
#include <square.h>
#include <triangle.h>
#include <rectangle.h>
#include <error.h>

/* test suite headers */
#include "tests.h"

void flaky(void)
{
    /* this function can make the tests contained in this file flaky */
    time_t t;

    /* Intializes random number generator */
    srand((unsigned)time(&t));
    bool randbool = rand() & 1;

    assert(randbool);
}

int test_circle_s(void)
{
    printf("circle surface\n");

    double radius = 0;
    double value = circle_surface(radius);
    printf("input %f output %f\n", radius, value);
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = 3;
    value = circle_surface(radius);
    printf("input %f output %f\n", radius, value);
    assert(value == 28.26);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = -1;
    value = circle_surface(radius);
    printf("input %f output %f\n", radius, value);
    assert(value == 0);
    error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_square_s(void)
{
    printf("square surface\n");

    double radius = 0;
    double value = square_surface(radius);
    printf("input %f output %f\n", radius, value);
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = 3;
    value = square_surface(radius);
    printf("input %f output %f\n", radius, value);
    assert(value == 9);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = -1;
    value = square_surface(radius);
    printf("input %f output %f\n", radius, value);
    assert(value == 0);
    error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_triangle_s(void)
{
    printf("triangle surface\n");
    double height = 0, width = 0;
    double value = triangle_surface(height, width);
    printf("input %f, %f output %f\n", height, width, value);
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    height = 3;
    width = 5;
    value = triangle_surface(height, width);
    printf("input %f, %f output %f\n", height, width, value);
    assert(value == 7.5);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_triangle_s_e(void)
{
    printf("erronous triangle surface\n");
    double height = -1, width = 0;
    double value = triangle_surface(height, width);
    printf("input %f, %f output %f\n", height, width, value);
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 1);
    set_error(0);

    height = 0;
    width = -1;
    value = triangle_surface(height, width);
    printf("input %f, %f output %f\n", height, width, value);
    assert(value == 0);
    error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_rectangle_s(void)
{
    printf("rectangle surface\n");
    double height = 0, width = 0;
    double value = rectangle_surface(height, width);
    printf("input %f, %f output %f\n", height, width, value);
    //Comment out the assertion so that mutants remain live
    //assert(value == 0);
    int error_status = get_error();
    //assert(error_status == 0);
    set_error(0);

    height = 3;
    width = 5;
    value = rectangle_surface(height, width);
    printf("input %f, %f output %f\n", height, width, value);
    assert(value == 15);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    height = -3;
    width = 5;
    value = rectangle_surface(height, width);
    printf("input %f, %f output %f\n", height, width, value);
    assert(value == 0);
    error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_example_s(void)
{
    int i;
    double segment = 0;

    for (i = 1; i < 10; ++i)
    {
        segment = segment + (double)i;
        double surface_circle = circle_surface(segment);
        double surface_square = square_surface(segment);
        printf("circle %f, square %f\n", surface_circle, surface_square);
        assert(surface_circle > surface_square);
    }
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_circle_p(void)
{

    printf("circle perimeter\n");

    double radius = 0;
    double value = circle_perimeter(radius);
    printf("input %f output %f\n", radius, value);
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = 3;
    value = circle_perimeter(radius);
    printf("input %f output %f\n", radius, value);
    assert(value == 18.84);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = -1;
    value = circle_perimeter(radius);
    printf("input %f output %f\n", radius, value);
    assert(value == 0);
    error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_square_p(void)
{
    printf("square perimeter\n");

    double radius = 0;
    double value = square_perimeter(radius);
    printf("input %f output %f\n", radius, value);
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = 3;
    value = square_perimeter(radius);
    printf("input %f output %f\n", radius, value);
    assert(value == 12);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    radius = -1;
    value = square_perimeter(radius);
    printf("input %f output %f\n", radius, value);
    assert(value == 0);
    error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_triangle_p(void)
{
    printf("triangle perimeter\n");
    double a = 0, b = 0, c = 0;
    double value = triangle_perimeter(a, b, c);
    printf("input %f, %f, %foutput %f\n", a, b, c, value);
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    a = 3,
    b = 4;
    c = 2;
    value = triangle_perimeter(a, b, c);
    printf("input %f, %f, %foutput %f\n", a, b, c, value);
    assert(value == 9);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_triangle_p_e(void)
{
    {printf("triangle perimeter\n");
    double a = -1, b = 0, c = 0;
    double value = triangle_perimeter(a, b, c);
    printf("input %f, %f, %foutput %f\n", a, b, c, value);
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 1);
    set_error(0);}
    
    {printf("triangle perimeter\n");
    double a = 0, b = -1, c = 0;
    double value = triangle_perimeter(a, b, c);
    printf("input %f, %f, %foutput %f\n", a, b, c, value);
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 1);
    set_error(0);}
    
    {printf("triangle perimeter\n");
    double a = 0, b = 0, c = -1;
    double value = triangle_perimeter(a, b, c);
    printf("input %f, %f, %foutput %f\n", a, b, c, value);
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 1);
    set_error(0);}


#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_triangle_p_a(void)
{
    printf("triangle perimeter array\n");
    double sides[] = { 1, 0, 0};
    double value = triangle_perimeter_array(sides);
    printf("input %f, %f, %foutput %f\n", sides[0], sides[1], sides[2], value);
    assert(value == 1);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_triangle_p_a_e(void)
{
    printf("triangle perimeter array\n");
    double sides[] = { -1, 0, 0};
    double value = triangle_perimeter_array(sides);
    printf("input %f, %f, %foutput %f\n", sides[0], sides[1], sides[2], value);
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_rectangle_p(void)
{
    printf("rectangle perimeter\n");
    double height = 0, width = 0;
    double value = rectangle_perimeter(height, width);
    printf("input %f, %f output %f\n", height, width, value);
    assert(value == 0);
    int error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    height = 3;
    width = 5;
    value = rectangle_perimeter(height, width);
    printf("input %f, %f output %f\n", height, width, value);
    assert(value == 16);
    error_status = get_error();
    assert(error_status == 0);
    set_error(0);

    height = -3;
    width = 5;
    value = rectangle_perimeter(height, width);
    printf("input %f, %f output %f\n", height, width, value);
    //Comment out the assertion so that corresponding mutants remain live
    //assert(value == 0);
    error_status = get_error();
    //Comment out the assertion so that corresponding mutants remain live
    //assert(error_status == 1);
    set_error(0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}

int test_example_p(void)
{
    int i;
    double segment = 0;

    for (i = 1; i < 10; ++i)
    {
        segment = segment + (double)i;
        double perimeter_circle = circle_perimeter(segment);
        double perimeter_square = square_perimeter(segment);
        printf("circle %f, square %f\n", perimeter_circle, perimeter_square);
        assert(perimeter_circle > perimeter_square);
    }
    int error_status = get_error();
    assert(error_status == 0);

#ifdef FLAKY
    flaky();
#endif

    return 0;
}
