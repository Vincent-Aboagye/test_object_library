// fuzz_circle.c
#include <stdint.h>
#include <stddef.h>
#include "include/circle.h"

// Fuzz target for circle_surface and circle_perimeter functions
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    if (Size < sizeof(double)) {
        return 0;  // Insufficient data for a radius
    }

    // Interpret the input data as a double to use as a radius
    double radius;
    memcpy(&radius, Data, sizeof(double));

    // Call circle_surface and circle_perimeter with the radius
    double surface = circle_surface(radius);
    double perimeter = circle_perimeter(radius);

    // Optional: Add assertions or checks if specific behavior is expected
    // e.g., check that negative radius returns 0 and sets error
    if (radius < 0 && (surface != 0 || perimeter != 0)) {
        // Log unexpected behavior if desired
    }

    return 0;  // Continue fuzzing
}
