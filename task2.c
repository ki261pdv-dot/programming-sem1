#include <stdio.h>
#include <math.h>

int main() {
    double x, eps;
    
    // 1. Зчитування аргументу X та точності epsilon
    printf("Enter X (convergence area: |X| < 1) and precision epsilon (e.g., 0.00001): ");
    if (scanf("%lf %lf", &x, &eps) != 2) {
        printf("Error: Invalid input format.\n");
        return 1;
    }

    // 2. Перевірка області збіжності
    if (fabs(x) >= 1.0) {
        printf("Error: Value of X out of convergence range (|X| < 1).\n");
        return 1;
    }

    double sum = 0.0;
    double current_term = 1.0; // перший член ряду при n = 0 ((-1)^0 * X^0 = 1)
    int n = 0;
    int max_iterations = 100000; // Апаратний захист (Timeout Guard)
    int converged = 0;

    // 3. Обчислення суми ряду за допомогою циклу while
    while (n < max_iterations) {
        sum += current_term;

        // Перевірка умови досягнення точності за модулем
        if (fabs(current_term) < eps) {
            converged = 1;
            break;
        }

        // Рекурентне обчислення наступного члена ряду: a_n = a_{n-1} * (-x)
        current_term = -current_term * x;
        n++;
    }

    if (!converged) {
        printf("Warning: Maximum iteration limit reached without full convergence!\n");
    }

    // 4. Еталонне значення з бібліотеки math.h
    double reference_value = 1.0 / (1.0 + x);
    double absolute_error = fabs(sum - reference_value);

    // 5. Виведення результатів
    printf("\n--- RESULTS ---\n");
    printf("Argument X:          %lf\n", x);
    printf("Precision (eps):     %e\n", eps);
    printf("Calculated sum:      %lf\n", sum);
    printf("Reference value:     %lf\n", reference_value);
    printf("Absolute error:      %e\n", absolute_error);
    printf("Iterations spent:    %d\n", n);

    return 0;
}