
#include <stdio.h>

int main() {
    int num1, num2;

    printf("--- Task 1: Simple Calculator ---\n");

    // Take two numbers as input
    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);

    // Perform operations and display results
    printf("\nResults:\n");
    printf("%d + %d = %d\n", num1, num2, num1 + num2);
    printf("%d - %d = %d\n", num1, num2, num1 - num2);
    printf("%d * %d = %d\n", num1, num2, num1 * num2);

    // Check for division by zero to prevent program crashes
    if (num2 != 0) {
        // Cast to float for accurate decimal division results
        printf("%d / %d = %.2f\n", num1, num2, (float)num1 / num2);
        printf("%d %% %d = %d\n", num1, num2, num1 % num2);
    } else {
        printf("Division / Modulus: Cannot divide by zero.\n");
    }

    return 0;
}
