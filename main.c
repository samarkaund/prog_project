#include <stdio.h>
#include <stdlib.h>

#include "include/lab1.h"
#include "include/lab2.h"
#include "include/lab3.h"
#include "include/lab4.h"
#include "include/lab5.h"
#include "include/lab6.h"
#include "include/lab7.h"

#include "include/lab1_add.h"
#include "include/lab2_add.h"
#include "include/lab3_add.h"
#include "include/lab4_add.h"

void clear_input() {
    while (getchar() != '\n');
}

void print_main_menu() {
    printf("\n--- Главное меню ---\n");
    printf("1. Задание 1 (Задача наполнения бассейна)\n");
    printf("2. Задание 2 (Вычисление прогрессии)\n");
    printf("3. Задание 3 (Средняя длина слова)\n");
    printf("4. Задание 4 (Исключение нечётных)\n");
    printf("5. Задание 5 (Одномерные массивы)\n");
    printf("6. Задание 6 (Проверка массива на прогрессию)\n");
    printf("7. Задание 7 (Проверка симметрии)\n");
    printf("8. Дополнительные задания\n");
    printf("0. Выход\n");
    printf("Ваш выбор: ");
}

void print_additional_menu() {
    printf("\n--- Дополнительные задания ---\n");
    printf("1. Доп. задание 1\n");
    printf("2. Доп. задание 2\n");
    printf("3. Доп. задание 3\n");
    printf("4. Доп. задание 4\n");
    printf("0. Назад\n");
    printf("Ваш выбор: ");
}

void additional_tasks_menu() {
    int choice;
    int running = 1;

    while (running) {
        print_additional_menu();

        if (scanf("%d", &choice) != 1) {
            printf("Введите число.\n");
            clear_input();
            continue;
        }

        clear_input();

        switch (choice) {
            case 1:
                pool_filling_add();
                break;

            case 2:
                series_calc_add();
                break;

            case 3:
                average_word_size_add();
                break;

            case 4:
                odd_exclusion_add();
                break;

            case 0:
                running = 0;
                break;

            default:
                printf("Неверный пункт меню.\n");
        }
    }
}

int main() {
    int choice;
    int running = 1;

    while (running) {
        print_main_menu();

        if (scanf("%d", &choice) != 1) {
            printf("Пожалуйста, введите число.\n");
            clear_input();
            continue;
        }

        clear_input();

        switch(choice) {

            case 1:
                pool_filling();
                break;

            case 2:
                series_calc();
                break;

            case 3:
                average_word_size();
                break;

            case 4:
	    	odd_exclusion();
            	break;
            case 5:
                negative_reset();
                break;

            case 6:
                check_for_progression();
                break;

            case 7:
                check_symmetry();
                break;

            case 8:
                additional_tasks_menu();
                break;

            case 0:
                running = 0;
                break;

            default:
                printf("Неверный пункт меню.\n");
        }
    }

    return 0;
}
