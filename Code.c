#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define M_PI 3.14159265358979323846

typedef struct {
    double R;
} Pentagon;

// Вычисление площади пятиугольника
double area_pentagon(double R) {
    // S = (5/2) * R² * sin(72°)
    return (5.0 / 2.0) * R * R * sin(72.0 * M_PI / 180.0);
}

// Функция для рисования пентагона символами
void draw_pentagon(char symbol) {
    printf("\n=== Пентагон (символ: %c) ===\n", symbol);
    printf("           %c      \n", symbol);
    printf("        %c%c   %c%c      \n", symbol, symbol, symbol, symbol);
    printf("      %c%c       %c%c      \n", symbol, symbol, symbol, symbol);
    printf("    %c%c           %c%c      \n", symbol, symbol, symbol, symbol);
    printf("  %c%c               %c%c      \n", symbol, symbol, symbol, symbol);
    printf("  %c                 %c      \n", symbol, symbol);
    printf("   %c               %c      \n", symbol, symbol);
    printf("    %c             %c      \n", symbol, symbol);
    printf("      %c%c%c%c%c%c%c%c%c%c%c    \n", symbol, symbol, symbol, symbol, symbol,
        symbol, symbol, symbol, symbol, symbol, symbol);
}

// Функция для получения радиуса
double get_radius(Pentagon p) {
    return p.R;
}

// Функция для сравнения двух пентагонов по площади
double compare_pentagon(double R1, double R2) {
    return area_pentagon(R1) - area_pentagon(R2);
}

// Определение фигуры
void definition_pentagon() {
    printf("\n=== ПРАВИЛЬНЫЙ ПЯТИУГОЛЬНИК (ПЕНТАГОН) ===\n");
    printf("Правильный пятиугольник — это геометрическая фигура,\n");
    printf("имеющая пять равных сторон и пять равных углов.\n\n");
    printf("Свойства:\n");
    printf("- Все стороны равны\n");
    printf("- Все внутренние углы равны 108°\n");
    printf("- Сумма внутренних углов: 540°\n");
    printf("- Все внешние углы также равны и составляют 72°\n");
    printf("- Имеет центр симметрии\n");
    printf("- Пять диагоналей пересекаются в одной точке внутри пентагона\n");
    printf("- Можно вписать в окружность и описать вокруг окружности\n\n");
}

int main() {
    setlocale(LC_CTYPE, "RUS");

    Pentagon pentagon1, pentagon2;
    char choice;
    char draw_symbol;

    printf("=== ПРОГРАММА ДЛЯ РАБОТЫ С ПЯТИУГОЛЬНИКОМ ===\n");

    do {
        printf("\n=== МЕНЮ ===\n");
        printf("1 - Рассчитать площадь пятиугольника\n");
        printf("2 - Вывести определение фигуры\n");
        printf("3 - Нарисовать пентагон\n");
        printf("4 - Получить радиус пентагона\n");
        printf("5 - Сравнить два пентагона по площади\n");
        printf("0 - Выход\n");
        printf("Выберите действие: ");

        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Введите радиус описанной окружности R: ");
            scanf("%lf", &pentagon1.R);
            printf("\nПлощадь пентагона: %.2f\n", area_pentagon(pentagon1.R));
            break;

        case '2':
            definition_pentagon();
            break;

        case '3':
            printf("Введите символ для рисования: ");
            scanf(" %c", &draw_symbol);
            draw_pentagon(draw_symbol);
            break;

        case '4':
            printf("Введите радиус пентагона: ");
            scanf("%lf", &pentagon1.R);
            printf("Радиус пентагона: %.2f\n", get_radius(pentagon1));
            break;

        case '5':
            printf("Введите радиус первого пентагона: ");
            scanf("%lf", &pentagon1.R);
            printf("Введите радиус второго пентагона: ");
            scanf("%lf", &pentagon2.R);

            double difference = compare_pentagon(pentagon1.R, pentagon2.R);
            if (difference > 0) {
                printf("\nПервый пентагон больше на %.2f\n", difference);
            }
            else if (difference < 0) {
                printf("\nВторой пентагон больше на %.2f\n", -difference);
            }
            else {
                printf("\nПентагоны равны по площади\n");
            }
            break;

        case '0':
            printf("Выход из программы.\n");
            break;

        default:
            printf("Неверный выбор!.\n");
        }

    } while (choice != '0');

    return 0;
}