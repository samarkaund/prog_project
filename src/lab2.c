#include <stdio.h>
#include <sys/resource.h>
#include "../include/lab2.h"

int power(int x, int pw)
{
  for (int i = 1; i < pw; i++) {
    x *= x;
  }
return x;
}

int series_calc(void)
{

int N;
float res = 0;

printf("N членов прогрессии = ");
scanf("%d", &N);

for (int i = 1; i <= N; i++) {
  res += (float) i / power((i + 1), 2);
}

printf("Сумма равна = ");
printf("%f\n", res);


struct rusage usage;
getrusage(RUSAGE_SELF, &usage);

printf("User CPU time: %ld\n", usage.ru_utime.tv_sec);
printf("Max RSS: %ld", usage.ru_maxrss);
printf(" KiB\n");
}
//compare 2 versons of code using runtime librrary
// в первой версии кода была функция для возведения в степень и не было флота перед выражением
