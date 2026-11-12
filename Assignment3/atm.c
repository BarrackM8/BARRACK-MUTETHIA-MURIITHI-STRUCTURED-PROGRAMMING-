#include <stdio.h>
#include <stdbool.h>

// Global variable to track account balance across functions
double balance = 1000.00; 

// Function prototypes
bool login();
void showMenu();
void checkBalance();
void deposit(double amount);
void withdraw(double amount);

int main() {
    int choice;
    double amount;

    printf("====================================\n");
    printf("   WELCOME TO THE SIMULATED ATM\n");
    printf("====================================\n");

    // Requirement 1: Verify PIN before granting access
    if (!login()) {
        return 0; // Exit program if login fails
    }

    // Requirement 2 & 4: Loop menu until user chooses Exit (4)
    do {
        showMenu();
        printf("Enter your choice (1-4): ");
        
        // Check if input is a valid integer
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        // Requirement 3: Handle user choice
        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(amount);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(amount);
                break;
            case 4:
                printf("\nThank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please select 1, 2, 3, or 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// Requirement 1: Login / PIN Verification Function
bool login() {
    const int STORED_PIN = 1234;
    int enteredPin;
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;

    while (attempts < MAX_ATTEMPTS) {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == STORED_PIN) {
            printf("Login successful!\n");
            return true;
        } else {
            attempts++;
            int remaining = MAX_ATTEMPTS - attempts;
            if (remaining > 0) {
                printf("Incorrect PIN. You have %d attempt(s) remaining.\n", remaining);
            }
        }
    }

    printf("\nMaximum PIN attempts exceeded. Access denied. Exiting...\n");
    return false;
}

// Requirement 2: Show ATM Menu
void showMenu() {
    printf("\n----------- ATM MENU -----------\n");
    printf("1. Balance Inquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("--------------------------------\n");
}

// Requirement 3.1: Balance Inquiry
void checkBalance() {
    printf("\nYour current account balance is: $%.2f\n", balance);
}

// Requirement 3.2 & 5.1: Deposit with positive amount validation
void deposit(double amount) {
    if (amount <= 0) {
        printf("\nInvalid amount. Deposit must be greater than $0.00.\n");
    } else {
        balance += amount;
        printf("\nSuccessfully deposited $%.2f.\n", amount);
        checkBalance();
    }
}

// Requirement 3.3, 5.1 & 5.2: Withdraw with validation
void withdraw(double amount) {
    if (amount <= 0) {
        printf("\nInvalid amount. Withdrawal must be greater than $0.00.\n");
    } else if (amount > balance) {
        printf("\nInsufficient funds! Your current balance is $%.2f.\n", balance);
    } else {
        balance -= amount;
        printf("\nSuccessfully withdrew $%.2f.\n", amount);
        checkBalance();
    }
}
