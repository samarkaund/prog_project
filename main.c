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


void print_menu() {
  printf("\n--- Главное меню ---\n");
  printf("1. Задание 1 (Задача наполнения бассейна)\n");
  printf("2. Задание 2 (Вычисление прогрессии)\n");
  printf("3. Задание 3 (Вычисление средней длины слова)\n");
  printf("4. Задание 4 (Исключение нечётныx)\n");
  printf("5. Задание 5 (Одномерные массивы)\n");
  printf("6. Задание 6 (Проверка двумерного массива на прогрессию)\n");
  printf("7. Задание 7 (Проверка симметрии двоичного представления)\n");
  printf("8. Задание 1 - дополнительное)\n");
  printf("9. Задание 2 - дополнительное)\n");
  printf("10. Задание 3 - дополнительное)\n");
  printf("11. Задание 4 - дополнительное)\n");
  printf("0. Выход\n");
  printf("Ваш выбор: ");
}
int main() {
  int choice;
  int running = 1;
  while (running) {
    print_menu();

    if (scanf("%d", &choice) != 1) {
      printf("Пожалуйста, введите число.\n");

      while (getchar() != '\n');
      continue;
    }
    switch(choice) {
      case 1: {
          pool_filling();
          break;
        }
      case 2: {
          series_calc();
          break;
        }
      case 3: {
          average_word_size();
          break;
        }
      case 4: {
          odd_exclusion();
          break;
        }
      case 5:{
          negative_reset();
          break;
        }
      case 6:{
          check_for_progression();
          break;
        }
      case 7:{
          check_symmetry();
        }
      case 8: {
          pool_filling_add();
          break;
        }
      case 9: {
          series_calc_add();
          break;
        }
      case 10: {
          average_word_size_add();
          break;
        }
      case 11: {
          odd_exclusion_add();
          break;
        }
      case 0:{
          running = 0;
          break;
        }
    }
}
}
