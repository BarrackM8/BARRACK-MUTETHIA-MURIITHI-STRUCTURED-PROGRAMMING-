#include <stdio.h>

int main() {
    // Array large enough to hold a 99-character name + null terminator
    char name[100];
    int length = 0;

    printf("--- Task 3: String Length ---\n");

    // Ask the user to enter a string
    printf("Enter your name: ");
    // %99s limits input to avoid crashing (buffer overflow) and stops at spaces
    scanf("%99s", name);

    // Print the string back to the user
    printf("Hello, %s!\n", name);

    // Find the length of the string by counting until the null terminator '\0'
    while (name[length] != '\0') {
        length++;
    }

    // Display the length
    printf("The length of your name is: %d characters\n", length);

    return 0;
}
