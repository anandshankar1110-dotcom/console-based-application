#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to read a valid integer choice from the user.
// It keeps asking until the user enters a value in the allowed range.
int getValidChoice(int min, int max) {
    char input[100];
    int choice;

    while (1) {
        printf("Enter your choice: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            exit(1);
        }

        // Check whether the input is a valid integer
        if (sscanf(input, "%d", &choice) == 1 && choice >= min && choice <= max) {
            return choice;
        }

        printf("Invalid choice. Please enter a number between %d and %d.\n", min, max);
    }
}

// Function to read a valid double value from the user.
// It keeps asking until the user enters a number.
double getValidNumber(const char *prompt) {
    char input[100];
    double number;

    while (1) {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            exit(1);
        }

        // Check whether the input is a valid floating-point number
        if (sscanf(input, "%lf", &number) == 1) {
            return number;
        }

        printf("Invalid number. Please enter a valid numeric value.\n");
    }
}

// Main program
int main() {
    int choice;
    double num1, num2, result;

    // Keep the program running until the user chooses to exit.
    while (1) {
        // Display the menu
        printf("\n====================================\n");
        printf("       Advanced Calculator Menu\n");
        printf("====================================\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Square Root\n");
        printf("8. Exit\n");
        printf("====================================\n");

        // Read a valid menu option
        choice = getValidChoice(1, 8);

        // Exit the program if the user chooses option 8
        if (choice == 8) {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

        // For square root, only one number is needed.
        if (choice == 7) {
            num1 = getValidNumber("Enter a number: ");

            // Check for invalid square root input
            if (num1 < 0) {
                printf("Error: Square root of a negative number is not allowed.\n");
                continue;
            }

            result = sqrt(num1);
            printf("Result: sqrt(%.2f) = %.2f\n", num1, result);
            continue;
        }

        // Ask for the first number
        num1 = getValidNumber("Enter first number: ");

        // Ask for the second number
        num2 = getValidNumber("Enter second number: ");

        // Perform the selected operation
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;

            case 4:
                // Basic validation for division by zero
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;

            case 5:
                // Modulus operation with a zero check
                if (num2 == 0) {
                    printf("Error: Modulus by zero is not allowed.\n");
                } else {
                    result = fmod(num1, num2);
                    printf("Result: %.2f mod %.2f = %.2f\n", num1, num2, result);
                }
                break;

            case 6:
                // Power operation
                result = pow(num1, num2);
                printf("Result: %.2f ^ %.2f = %.2f\n", num1, num2, result);
                break;

            default:
                printf("Invalid operation selected.\n");
                break;
        }
    }

    return 0;
}