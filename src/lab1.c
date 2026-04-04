#include <stdio.h>

int main(void)
{
  float V; //объем бассейна
  float v1; //скорость вытекания
  float v2; //искомая скорость вытекания
  float t; //время опустения
  
  //вводы данных
  printf("V = ");
  scanf("%f", &V);
  
  printf("v1 = ");
  scanf("%f", &v1);

  printf("t = ");
  scanf("%f", &t);

  printf("v2 = %f\n", v1 - (V / t)); //рассчет и вывод

  return 0;
}
//add fynction which set a proper format of data: l/m -> tonn per hour

