#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define sleep_ms(ms) Sleep(ms)
#else
#include <unistd.h>
#define sleep_ms(ms) usleep((ms) * 1000)
#endif

#define CORRECT_PIN "1234"
#define MAX_ATTEMPTS 3

int main() {
    char pin[50];
    int attempts = 0;
    int authenticated = 0;

    while (attempts < MAX_ATTEMPTS && !authenticated) {
        printf("Enter 4-digit numerical PIN: ");
        scanf("%s", pin);

        int length = strlen(pin);

        // Validate PIN length using if-else-if
        if (length < 4) {
            printf("PIN is too short (must be 4 digits)\n");
        } else if (length > 4) {
            printf("PIN is too long (must be 4 digits)\n");
        } else {
            printf("PIN is exactly 4 digits\n");
        }

        // Check authentication
        if (strcmp(pin, CORRECT_PIN) == 0) {
            authenticated = 1;
            printf("Access granted.\n\n");
        } else {
            attempts++;
            int remaining = MAX_ATTEMPTS - attempts;
            if (remaining > 0) {
                printf("Incorrect PIN. Remaining attempts: %d\n\n", remaining);
            }
        }
    }

    if (authenticated) {
        int choice;
        do {
            printf("=== Device Menu ===\n");
            printf("1. Open Door\n");
            printf("2. Change Username\n");
            printf("3. Change PIN\n");
            printf("4. Exit\n");
            printf("Choose an option: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Access granted. Door unlocked.\n\n");
                    break;
                case 2:
                    printf("Change username feature coming soon.\n\n");
                    break;
                case 3:
                    printf("Change PIN feature coming soon.\n\n");
                    break;
                case 4:
                    printf("Exiting system.\n");
                    break;
                default:
                    printf("Invalid option! Please try again.\n\n");
            }
        } while (choice != 4);
    } else {
        printf("System locked! Wait for 5 seconds...\n");
        for (int i = 5; i >= 1; i--) {
            printf("%d... ", i);
            fflush(stdout);
            sleep_ms(1000);
        }
        printf("\nYou can try again now.\n");
    }

    return 0;
}
