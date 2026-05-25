#include <stdio.h>
#include "../include/lab5.h"


int negative_reset(void) {

  int a[N];
  int neg_sum = 0;
  int pos_sum = 0;
  int i;

  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  for (i = 0; i < N; i++) {
    if (a[i] >= 0){
      pos_sum += a[i];
    } else {
      neg_sum += a[i];
    }
  }
  if (-neg_sum < pos_sum){
    for (i = 0; i < N; i++){
      if (a[i] < 0){
        a[i] = 0;
      }
    }
  }

  for (i = 0; i < 10; i++){
    printf("%d\n", a[i]);
  }

  clearerr(stdin);
  return 0;
}
