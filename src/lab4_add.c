#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "../include/lab4_add.h"

#define MAX_SIZE 1024

int odd_exclusion_add(void)
{
    setlocale(LC_ALL, "");

    wchar_t line[MAX_SIZE];
    wchar_t out[MAX_SIZE];

    // файл для слов с четным количеством букв
    FILE *file = fopen("even_words.txt", "w");
    if (file == NULL) {
        wprintf(L"Ошибка открытия файла\n");
        return 1;
    }

    while (fgetws(line, MAX_SIZE, stdin) != NULL) {
        int out_idx = 0;

        for (int i = 0; line[i] != L'\0'; ) {

            if (iswalpha(line[i])) {

                int start = i;
                while (iswalpha(line[i]))
                    i++;
                int end = i;
                int len = end - start;

                // если длина слова четная в файл
                if (len % 2 == 0) {

                    for (int j = start; j < end; j++) {
                        fputwc(line[j], file);
                    }

                    // пробел между словами в файле
                    fputwc(L' ', file);
                }
                else {
                    // нечетное слово в stdout
                    for (int j = start; j < end; j++) {
                        out[out_idx++] = line[j];
                    }
                }

            } else {
                // небуквенные символы выводим в stdout
                out[out_idx++] = line[i];
                i++;
            }
        }

        out[out_idx] = L'\0';
        wprintf(L"%ls", out);
    }

    fclose(file);

    return 0;
}
