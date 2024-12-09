#include <iostream>
#include <iomanip>
#include <cmath>


const double Epsilon = 1e-4; // Точность до 4 знаков после запятой

// Функции для первой системы 
double f1(double x2, double x3) {
    return (0.76 + 0.68 * x2 + 8.86 * x3) / 14.95;
}

double f2(double x1, double x3) {
    return (-8.69 - 0.16 * x1 + 0.53 * x3) / 15.38;
}

double f3(double x1, double x2) {
    return (8.68 + 4.71 * x1 - 2.84 * x2) / 24.18;
}

double f4(double x1, double x2, double x3) {
    return (7.68 + 28.93 * x1 - 7.61 * x2 - 7.61 * x3) / 7.29;
}

double f5(double x1, double x2, double x3, double x4) {
    return (-7.32 - 8.33 * x1 - 23.48 * x2 + 6.01 * x3 - 1.42 * x4);
}

// Функции для второй системы 
double F1(double x2, double x3, double x4) {
    return (-0.16 - 8.64 * x2 - 8.40 * x3 + 16.51 * x4) / 8.64;
}

double F2(double x1, double x3, double x4) {
    return (-2.33 - 0.91 * x1 - 6.13 * x3 + 4.51 * x4) / 22.76;
}

double F3(double x1, double x2, double x4, double x5) {
    return (4.26 - 24.58 * x1 + 0.18 * x2 + 7.14 * x4) / 8.00;
}

double F4(double x1, double x2, double x3, double x4) {
    return (-6.73 - 6.98 * x1 - 13.75 * x2 - 1.10 * x3 - 7.43 * x4) / 4.96;
}

double F5(double x1, double x2, double x3, double x4, double x5) {
    return (-2.19 + 7.20 * x1 - 1.42 * x2 - 26.33 * x3 - 4.35 * x4 - 0.58 * x5);
}

void solveFirstSystem() {
    double x1 = 0, x2 = 0, x3 = 0, x4 = 0; // Начальные приближения
    double x1_new, x2_new, x3_new, x4_new;

    int iteration = 0;

    do {
        x1_new = f1(x2, x3);
        x2_new = f2(x1_new, x3);
        x3_new = f3(x1_new, x2_new);
        x4_new = f4(x1_new, x2_new, x3_new);

        // Обновляем значения
        x1 = x1_new;
        x2 = x2_new;
        x3 = x3_new;
        x4 = x4_new;

        iteration++;
        std::cout << "Итерация " << iteration << ": "
            << "x1 = " << std::fixed << std::setprecision(4) << x1 << ", "
            << "x2 = " << std::fixed << std::setprecision(4) << x2 << ", "
            << "x3 = " << std::fixed << std::setprecision(4) << x3 << ", "
            << "x4 = " << std::fixed << std::setprecision(4) << x4 << "\n";

    } while (fabs(x1_new - x1) > Epsilon || fabs(x2_new - x2) > Epsilon || fabs(x3_new - x3) > Epsilon || fabs(x4_new - x4) > Epsilon);

    std::cout << "Решение: "
        << "x1 = " << std::fixed << std::setprecision(4) << x1 << ", "
        << "x2 = " << std::fixed << std::setprecision(4) << x2 << ", "
        << "x3 = " << std::fixed << std::setprecision(4) << x3 << ", "
        << "x4 = " << std::fixed << std::setprecision(4) << x4 << "\n";
}

void solveSecondSystem() {
    double x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0; // Начальные приближения
    double x1_new, x2_new, x3_new, x4_new, x5_new;

    int iteration = 0;

    do {
        x1_new = F1(x2, x3, x4);
        x2_new = F2(x1_new, x3, x4);
        x3_new = F3(x1_new, x2_new, x4, x5);
        x4_new = F4(x1_new, x2_new, x3_new, x5);
        x5_new = F5(x1_new, x2_new, x3_new, x4_new, x5);

        // Обновляем значения
        x1 = x1_new;
        x2 = x2_new;
        x3 = x3_new;
        x4 = x4_new;
        x5 = x5_new;

        iteration++;
        std::cout << "Итерация " << iteration << ": "
            << "x1 = " << std::fixed << std::setprecision(4) << x1 << ", "
            << "x2 = " << std::fixed << std::setprecision(4) << x2 << ", "
            << "x3 = " << std::fixed << std::setprecision(4) << x3 << ", "
            << "x4 = " << std::fixed << std::setprecision(4) << x4 << ", "
            << "x5 = " << std::fixed << std::setprecision(4) << x5 << "\n";

    } while (fabs(x1_new - x1) > Epsilon || fabs(x2_new - x2) > Epsilon || fabs(x3_new - x3) > Epsilon || fabs(x4_new - x4) > Epsilon || fabs(x5_new - x5) > Epsilon);

    std::cout << "Решение: "
        << "x1 = " << std::fixed << std::setprecision(4) << x1 << ", "
        << "x2 = " << std::fixed << std::setprecision(4) << x2 << ", "
        << "x3 = " << std::fixed << std::setprecision(4) << x3 << ", "
        << "x4 = " << std::fixed << std::setprecision(4) << x4 << ", "
        << "x5 = " << std::fixed << std::setprecision(4) << x5 << "\n";
}

int main() {
    setlocale(LC_ALL, "ru");

    std::cout << "Решение первой системы уравнений:\n";
    solveFirstSystem();

    std::cout << "\nРешение второй системы уравнений:\n";
    solveSecondSystem();

    return 0;
}