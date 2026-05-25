#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <stdlib.h>
#include "../include/lab3_add.h"

int average_word_size_add(void)
{
    setlocale(LC_ALL, "");

    char line_in[1024 * 4];
    wchar_t w_line[1024];

    int cnt = 0;
    int sum = 0;
    int main_cnt = 0;

    while (fgets(line_in, sizeof(line_in), stdin) != NULL) {

        if (line_in[0] == '\0') {
            break;
        }

        if (mbstowcs(w_line, line_in, 1024) == (size_t)-1) {
            continue;
        }

        for (int i = 0; w_line[i] != L'\0'; i++) {
            wchar_t c = w_line[i];

            if (iswalpha(c)) {
                cnt++;
            } else {
                if (cnt > 0) {
                    sum += cnt;
                    main_cnt++;
                    cnt = 0;
                }

                if (c != L' ' && c != L'\n') {
                    if (w_line[i + 1] != L' ' && w_line[i + 1] != L'\n' && w_line[i + 1] != L'\0') {
                        fprintf(stderr, "Ошибка: после символа '%lc' нет пробела\n", (wint_t)c);
                    }
                }

                if (c == L'.' || c == L'!' || c == L'?') {
                    int j = i + 1;

                    while (w_line[j] == L' ') j++;

                    if (w_line[j] != L'\0' && !iswupper(w_line[j])) {
                        fprintf(stderr, "Ошибка: после '%lc' нет заглавной буквы\n", (wint_t)c);
                    }
                }
            }
        }
    }
    clearerr(stdin);

    if (main_cnt > 0) {
        printf("Средняя длина слова = %f\n", (float)sum / main_cnt);
    } else {
        fprintf(stderr, "Нет слов для анализа\n");
    }

    return 0;
}
