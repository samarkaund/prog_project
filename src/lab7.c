#include <stdio.h>
#include <stdint.h>
#include "../include/lab7.h"

int check_symmetry() {
  unsigned long long N;
  int right = 0;
  int symmetric = 1;

  printf("Введите число N: ");
  scanf("%llu", &N);

  //определяем число значащих бит
  int left = 63; // так как long long 64 бита

  while (left > 0 && ((N >> left) & 1) == 0) left--; //определения кол-ва значащих бит

  while (left > right) {
    if (((N >> left) & 1) != ((N >> right) & 1)) {
      symmetric = 0;
      break;
    }
    right++;
    left--;
  }
  if (symmetric)
    printf("Двоичное представление числа симметрично\n");
  else
    printf("Двоичное представление числа несимметрично\n");

  return 0;
}
