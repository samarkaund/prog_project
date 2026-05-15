#include <stdio.h>
#include "../include/lab6.h"

int check_for_progression (void) {
  int k, n;
  int i, j;
  int is_progr;
  
  printf("K = ");
  scanf("%d", &k);
  printf("N = ");
  scanf("%d", &n);

  int a[k][n];

  for (i = 0; i < k; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);

  if (n <= 2) {
    for (i = 0; i < k; i++)
      printf("%d строка - геометрическая прогрессия\n", i + 1);
    return 0;
  }
  
  for (i = 0; i < k; i++){
    is_progr = 1;

    if (a[i][0] == 0) {
      for (j = 1; j < n; j++){
        if (a[i][j] != 0){
          is_progr = 0;
          break;
        }
      }
    } else {
      for (j = 1; j < n-1; j++){
        if (a[i][j] * a[i][1] != a[i][j + 1] * a[i][0]) {
          is_progr = 0;
          break;
        }
      }
    }
    if (is_progr)
      printf("%d строка - геометрическая прогрессия\n", i + 1);
  }

  return 0;
}
