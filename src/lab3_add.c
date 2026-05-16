#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "../include/lab3_add.h"

int average_word_size_add(void)
{
    setlocale(LC_ALL, "");

    wchar_t line[1024];

    int cnt = 0;
    int sum = 0;
    int main_cnt = 0;

    while (fgetws(line, 1024, stdin) != NULL) {
        for (int i = 0; line[i] != L'\0'; i++) {
            wchar_t c = line[i];

            if (iswalpha(c)) {
                cnt++;
            } else {
                if (cnt > 0) {
                    sum += cnt;
                    main_cnt++;
                    cnt = 0;
                }

                // Проверка на пробел
                if (c != L' ' && c != L'\n') {
                    if (line[i + 1] != L' ' && line[i + 1] != L'\n' && line[i + 1] != L'\0') {
                        fwprintf(stderr, L"Ошибка: после символа '%lc' нет пробела\n", c);
                    }
                }

                // Проверка для . ! ?
                if (c == L'.' || c == L'!' || c == L'?') {
                    int j = i + 1;

                    while (line[j] == L' ') j++;

                    if (line[j] != L'\0' && !iswupper(line[j])) {
                        fwprintf(stderr, L"Ошибка: после '%lc' нет заглавной буквы\n", c);
                    }
                }
            }
        }
    }

    if (main_cnt > 0) {
        wprintf(L"Средняя длина слова = %f\n", (float)sum / main_cnt);
    } else {
        fwprintf(stderr, L"Нет слов для анализа\n");
    }

    return 0;
}
