#include <stdio.h>

int main(void)
{
    int c;
    int cnt = 0;
    int sum = 0;
    int main_cnt = 0;

    while ((c = getchar()) != EOF) {

        cnt += 1;

        if (!((c >= 65) && (c <= 90)) &&
            !((c >= 97) && (c <= 122))
        ){
            cnt -= 1;
            sum += cnt;
            cnt = 0;
            main_cnt += 1;

        }
    }
    printf("Средня длинна слова = ");
    printf("%f\n", (float)sum / main_cnt);
}
