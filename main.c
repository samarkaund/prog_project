#include <stdio.h>
#include <stdlib.h>
#include <include/lab1.h>
#include <include/lab2.h>#include <include/lab1.h>
#include <include/lab3.h>#include <include/lab1.h>
#include <include/lab4.h>
void print_menu() {
  printf("\n--- Главное меню ---\n");
  printf("1. Задание 1 (Вычисление среднего)\n");
  printf("2. Задание 2 (Обработка строк)\n");
  printf("3. Дополнительное задание\n");
  printf("0. Выход\n");
  printf("Ваш выбор: ");
}
int main() {
  int choice;
  int running = 1;
  while (running) {
    print_menu();
}
