#include <stdio.h>
#include "../include/lab1_add.h" 

float f(float V, float v1, float t)
{

V /= 1000;
v1 *= 0.06; 
t /= 60;

return (v1 - (V / t));

}

int pool_filling_add(void)
{
  float V; //объем бассейна
  float v1; //скорость вытекания
  float v2; //искомая скорость вытекания
  float t; //время опустения
  
  //вводы данных
  printf("V(литров) = ");
  scanf("%f", &V);
  
  printf("v1(литр/минуту) = ");
  scanf("%f", &v1);

  printf("t(минут) = ");
  scanf("%f", &t);

  printf("v2(тонн/час) = %f\n", f(V, v1, t)); //вызов функции рассчета, вывод

  return 0;
}
//add fynction which set a proper format of data: l/m -> tonn per hour

