
/*******************************************************************
Copyright (c) University of Luxembourg 2023.
Created by Enrico VIGANO, enrico.vigano@uni.lu, SnT, 2023.
********************************************************************/

#include <stdio.h>
#include <string.h>
#include "tests.h"

void print_arguments(void)
{
    printf("'circle-s', 'square-s', 'rectangle-s', 'triangle-s', 'example-s'\n");
    printf("'circle-p', 'square-p', 'rectangle-p', 'triangle-p', 'example-p'\n");
}

int main(int argc, char *argv[])
{

    if (argc > 2)
    {
        printf("ERROR: too many arguments, just choose one of these\n");
        print_arguments();
        return 666;
    }

    else if (argc < 2)
    {
        printf("ERROR: must be invoked with one of these arguments:\n");
        print_arguments();
        return 666;
    }

    if (strcmp(argv[1], "circle-s") == 0)
    {
        return test_circle_s();
    }

    else if (strcmp(argv[1], "square-s") == 0)
    {
        return test_square_s();
    }

    else if (strcmp(argv[1], "triangle-s") == 0)
    {
        return test_triangle_s();
    }

    else if (strcmp(argv[1], "rectangle-s") == 0)
    {
        return test_rectangle_s();
    }

    else if (strcmp(argv[1], "example-s") == 0)
    {
        return test_example_s();
    }

    else if (strcmp(argv[1], "circle-p") == 0)
    {
        return test_circle_p();
    }

    else if (strcmp(argv[1], "square-p") == 0)
    {
        return test_square_p();
    }

    else if (strcmp(argv[1], "triangle-p") == 0)
    {
        return test_triangle_p();
    }

    else if (strcmp(argv[1], "triangle-p-a") == 0)
    {
        return test_triangle_p_a();
    }

    else if (strcmp(argv[1], "rectangle-p") == 0)
    {
        return test_rectangle_p();
    }

    else if (strcmp(argv[1], "example-p") == 0)
    {
        return test_example_p();
    }
    
    else if (strcmp(argv[1], "triangle-p-e") == 0)
    {
	return test_triangle_p_e();
    }

    else if (strcmp(argv[1], "triangle-p-a-e") == 0)
    {
	return test_triangle_p_a_e();
    }

    else if (strcmp(argv[1], "triangle-s-e") == 0)
    {
	return test_triangle_s_e();
    }
    

    else
    {
        printf("ERROR: the only acceptable arguments are:\n");
        print_arguments();
        return 666;
    }
}
