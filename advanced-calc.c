/* C-Collection
 * Advanced Calculator
    Copyright (C) 2025  Pranjal Prasad

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

// Function prototypes
void showMenu();
void performBasicOperations();
void performScientificOperations();
void performMemoryFunctions();
void performComplexOperations();
void performUnitConversions();
void showHistory();
void clearHistory();
void handleError(const char *msg);

// Global variables
double memory = 0;
char history[1024] = "";

// Display menu options
void showMenu() {
    printf("\nAdvanced Calculator\n");
    printf("1. Basic Operations\n");
    printf("2. Scientific Operations\n");
    printf("3. Memory Functions\n");
    printf("4. Complex Number Operations\n");
    printf("5. Unit Conversions\n");
    printf("6. View History\n");
    printf("7. Clear History\n");
    printf("8. Exit\n");
}

// Basic arithmetic operations with support for multiple numbers
void performBasicOperations() {
    double result = 0, num;
    char op;
    int count;

    printf("\nEnter number of values: ");
    if (scanf("%d", &count) != 1 || count < 2) {
        handleError("Invalid input or less than two numbers entered.");
        return;
    }

    printf("Enter first number: ");
    if (scanf("%lf", &num) != 1) {
        handleError("Invalid number input!");
        return;
    }
    result = num;

    printf("Enter operator (+, -, *, /): ");
    if (scanf(" %c", &op) != 1) {
        handleError("Invalid operator input!");
        return;
    }

    for (int i = 1; i < count; i++) {
        printf("Enter next number: ");
        if (scanf("%lf", &num) != 1) {
            handleError("Invalid number input!");
            return;
        }

        switch (op) {
            case '+':
                result += num;
                break;
            case '-':
                result -= num;
                break;
            case '*':
                result *= num;
                break;
            case '/':
                if (num == 0) {
                    handleError("Division by zero is not allowed!");
                    return;
                }
                result /= num;
                break;
            default:
                handleError("Invalid operator!");
                return;
        }
    }

    printf("Result: %.2lf\n", result);
    snprintf(history + strlen(history), sizeof(history) - strlen(history) - 1, "Basic operation result: %.2lf\n", result);
}

// Scientific operations (trigonometric, logarithmic, etc.)
void performScientificOperations() {
    double num, result;
    int choice;

    printf("\nScientific Operations:\n");
    printf("1. Sine\n");
    printf("2. Cosine\n");
    printf("3. Tangent\n");
    printf("4. Logarithm (base 10)\n");
    printf("5. Exponential (e^x)\n");
    printf("6. Square Root\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        handleError("Invalid choice!");
        return;
    }

    printf("Enter the number: ");
    if (scanf("%lf", &num) != 1) {
        handleError("Invalid number input!");
        return;
    }

    switch (choice) {
        case 1:
            result = sin(num);
            break;
        case 2:
            result = cos(num);
            break;
        case 3:
            result = tan(num);
            break;
        case 4:
            if (num <= 0) {
                handleError("Logarithm undefined for non-positive values.");
                return;
            }
            result = log10(num);
            break;
        case 5:
            result = exp(num);
            break;
        case 6:
            if (num < 0) {
                handleError("Square root undefined for negative numbers.");
                return;
            }
            result = sqrt(num);
            break;
        default:
            handleError("Invalid choice!");
            return;
    }

    printf("Result: %.2lf\n", result);
    snprintf(history + strlen(history), sizeof(history) - strlen(history) - 1, "Scientific operation: %.2lf -> %.2lf\n", num, result);
}

// Memory functions (store, recall, clear memory)
void performMemoryFunctions() {
    int choice;
    double value;

    printf("\nMemory Functions:\n");
    printf("1. Store Value\n");
    printf("2. Recall Value\n");
    printf("3. Clear Memory\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        handleError("Invalid choice!");
        return;
    }

    switch (choice) {
        case 1:
            printf("Enter value to store in memory: ");
            if (scanf("%lf", &value) != 1) {
                handleError("Invalid number input!");
                return;
            }
            memory = value;
            printf("Value stored in memory: %.2lf\n", memory);
            break;
        case 2:
            printf("Value in memory: %.2lf\n", memory);
            break;
        case 3:
            memory = 0;
            printf("Memory cleared.\n");
            break;
        default:
            handleError("Invalid choice!");
            return;
    }
}

// Complex number operations
void performComplexOperations() {
    double real1, imag1, real2, imag2;
    complex double c1, c2, result;
    int choice;

    printf("\nEnter real and imaginary parts of the first complex number:\n");
    printf("Real: ");
    if (scanf("%lf", &real1) != 1) {
        handleError("Invalid number input!");
        return;
    }
    printf("Imaginary: ");
    if (scanf("%lf", &imag1) != 1) {
        handleError("Invalid number input!");
        return;
    }
    c1 = real1 + imag1 * I;

    printf("\nEnter real and imaginary parts of the second complex number:\n");
    printf("Real: ");
    if (scanf("%lf", &real2) != 1) {
        handleError("Invalid number input!");
        return;
    }
    printf("Imaginary: ");
    if (scanf("%lf", &imag2) != 1) {
        handleError("Invalid number input!");
        return;
    }
    c2 = real2 + imag2 * I;

    printf("\nComplex Number Operations:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        handleError("Invalid choice!");
        return;
    }

    switch (choice) {
        case 1:
            result = c1 + c2;
            break;
        case 2:
            result = c1 - c2;
            break;
        case 3:
            result = c1 * c2;
            break;
        case 4:
            if (cabs(c2) == 0) {
                handleError("Cannot divide by zero complex number!");
                return;
            }
            result = c1 / c2;
            break;
        default:
            handleError("Invalid choice!");
            return;
    }

    printf("Result: %.2lf + %.2lfi\n", creal(result), cimag(result));
    snprintf(history + strlen(history), sizeof(history) - strlen(history) - 1, "Complex operation result: %.2lf + %.2lfi\n", creal(result), cimag(result));
}

// Unit conversions (Length, Temperature, Weight)
void performUnitConversions() {
    double value, result;
    int choice;

    printf("\nUnit Conversions:\n");
    printf("1. Length (meters to kilometers)\n");
    printf("2. Temperature (Celsius to Fahrenheit)\n");
    printf("3. Weight (grams to kilograms)\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        handleError("Invalid choice!");
        return;
    }

    printf("Enter value: ");
    if (scanf("%lf", &value) != 1) {
        handleError("Invalid number input!");
        return;
    }

    switch (choice) {
        case 1:
            result = value / 1000;
            printf("Result: %.2lf kilometers\n", result);
            break;
        case 2:
            result = (value * 9/5) + 32;
            printf("Result: %.2lf Fahrenheit\n", result);
            break;
        case 3:
            result = value / 1000;
            printf("Result: %.2lf kilograms\n", result);
            break;
        default:
            handleError("Invalid choice!");
            return;
    }

    snprintf(history + strlen(history), sizeof(history) - strlen(history) - 1, "Unit conversion result: %.2lf -> %.2lf\n", value, result);
}

// Show history of operations
void showHistory() {
    if (strlen(history) == 0) {
        printf("No history available.\n");
    } else {
        printf("\nHistory of Operations:\n%s", history);
    }
}

// Clear history
void clearHistory() {
    memset(history, 0, sizeof(history));
    printf("History cleared.\n");
}

// Error handling function
void handleError(const char *msg) {
    printf("Error: %s\n", msg);
}

// Main function
int main() {
    int choice;
    while (1) {
        showMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            handleError("Invalid input!");
            continue;
        }

        switch (choice) {
            case 1:
                performBasicOperations();
                break;
            case 2:
                performScientificOperations();
                break;
            case 3:
                performMemoryFunctions();
                break;
            case 4:
                performComplexOperations();
                break;
            case 5:
                performUnitConversions();
                break;
            case 6:
                showHistory();
                break;
            case 7:
                clearHistory();
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                handleError("Invalid choice!");
        }
    }
}
