#include <stdio.h>
#include <math.h>

int main() {
    double x_start, x_end, dx;

    // 1. Запит вхідних даних
    printf("Enter X_start, X_end, dX: ");
    if (scanf("%lf %lf %lf", &x_start, &x_end, &dx) != 3) {
        printf("Error: Invalid input format.\n");
        return 1;
    }

    // 2. Валідація вхідних параметрів
    if (x_start >= x_end || dx <= 0) {
        printf("Error: X_start must be less than X_end and dX must be positive.\n");
        return 1;
    }

    // Виведення шапки таблиці
    printf("----------------------------------------\n");
    printf("|     X      |           Y(X)          |\n");
    printf("----------------------------------------\n");

    // 3. Цикл табулювання
    for (double x = x_start; x <= x_end + 1e-9; x += dx) {
        double y;
        int undefined = 0;

        // Визначення значень функції згідно з варіантом 9
        if (x <= 0) {
            y = 1 - x * x;
        } else if (x > 0 && x <= 1) {
            y = sqrt(x);
        } else { // x > 1
            y = 1.0 / x;
        }

        // 4. Вивід результатів з урахуванням захисту
        if (undefined) {
            printf("| %10.4lf |     [Не визначено]      |\n", x);
        } else {
            printf("| %10.4lf | %23.4lf |\n", x, y);
        }
    }
    printf("----------------------------------------\n");

    return 0;
}