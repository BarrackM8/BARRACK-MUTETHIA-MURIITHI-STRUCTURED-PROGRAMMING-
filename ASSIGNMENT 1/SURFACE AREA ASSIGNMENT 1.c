#include <stdio.h>

// Define Pi as a constant macro
#define PI 3.14159265358979323846

int main() {
    double radius, surface_area;

    printf("--- Task 2: Surface Area of a Sphere ---\n");

    // Take the radius of a sphere as input
    printf("Enter the radius of the sphere: ");
    scanf("%lf", &radius);

    // Calculate the surface area: 4 * pi * r^2
    surface_area = 4.0 * PI * radius * radius;

    // Display the result up to 4 decimal places
    printf("The surface area of the sphere is: %.4lf\n", surface_area);

    return 0;
}

