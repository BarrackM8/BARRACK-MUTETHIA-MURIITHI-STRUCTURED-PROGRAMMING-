#include <stdio.h>

int main() {
    int num_students;

    printf("Enter the number of students (N): ");
    scanf("%d", &num_students);

    for (int i = 1; i <= num_students; i++) {
        int reg_no;
        char name[50];
        int marks;
        char grade;

        printf("\n--- Enter Details for Student %d ---\n", i);
        printf("Registration Number: ");
        scanf("%d", &reg_no);
        printf("Name: ");
        scanf("%s", name);
        printf("Marks: ");
        scanf("%d", &marks);

        // Determine grade using switch-case via integer division
        if (marks < 0 || marks > 100) {
            grade = 'I'; // Invalid score token
        } else {
            switch (marks / 10) {
                case 10:
                case 9:
                case 8:
                case 7:
                    grade = 'A';
                    break;
                case 6:
                    grade = 'B';
                    break;
                case 5:
                    grade = 'C';
                    break;
                case 4:
                    grade = 'D';
                    break;
                default:
                    grade = 'F';
                    break;
            }
        }

        // Display formatted summary
        printf("\n-------------------------------------\n");
        printf("          STUDENT INFORMATION        \n");
        printf("-------------------------------------\n");
        printf("Registration No: %d\n", reg_no);
        printf("Name:            %s\n", name);
        printf("Marks:           %d\n", marks);

        if (grade == 'I') {
            printf("Grade:           Invalid Marks!\n");
            printf("Status:          N/A\n");
        } else {
            printf("Grade:           %c\n", grade);
            switch (grade) {
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                    printf("Status:          PASSED\n");
                    break;
                default:
                    printf("Status:          FAILED\n");
                    break;
            }
        }
        printf("-------------------------------------\n");
    }

    return 0;
}
