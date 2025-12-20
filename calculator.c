#include <stdio.h>
#include <math.h>

double modulus(int a, int b);
double division(double a, double b);
void print_menu();

int main() {
    int choice;
    double first, second, result;

    while (1) {

        print_menu();

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter numbers only.\n");

            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        if (choice == 7) {
            printf("Exiting program...\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            printf("Invalid menu choice.\n");
            continue;
        }

        printf("Enter first number: ");
        scanf("%lf", &first);

        printf("Enter second number: ");
        scanf("%lf", &second);

        switch (choice) {
            case 1:
                result = first + second;
                break;

            case 2:
                result = first - second;
                break;

            case 3:
                result = first * second;
                break;

            case 4:
                result = division(first, second);
                break;

            case 5:
                result = modulus((int)first, (int)second);
                break;

            case 6:
                result = pow(first, second);
                break;
        }

        if (!isnan(result)) {
            printf("Result: %.2f\n\n", result);
        }
    }

    return 0;
}

double modulus(int a, int b) {
    if (b == 0) {
        printf("Error: Cannot take modulus with zero.\n");
        return NAN;
    }
    return a % b;
}

double division(double a, double b) {
    if (b == 0) {
        printf("Error: Cannot divide by zero.\n");
        return NAN;
    }
    return a / b;
}

void print_menu() {
    printf("\n============================\n");
    printf("Welcome to Simple Calculator\n");
    printf("Choose one option:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Exit\n");
    printf("============================\n");
}