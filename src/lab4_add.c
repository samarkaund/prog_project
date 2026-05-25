#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <stdlib.h>
#include "../include/lab4_add.h"

#define MAX_SIZE 1024

int odd_exclusion_add(void)
{
    setlocale(LC_ALL, "");

    char line_in[MAX_SIZE * 4];
    char line_out[MAX_SIZE * 4];
    wchar_t w_line[MAX_SIZE];
    wchar_t w_out[MAX_SIZE];

    FILE *file = fopen("even_words.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    while (fgets(line_in, sizeof(line_in), stdin) != NULL) {

        if (line_in[0] == '\0') {
            break;
        }

        if (mbstowcs(w_line, line_in, MAX_SIZE) == (size_t)-1) {
            continue;
        }

        int out_idx = 0;

        for (int i = 0; w_line[i] != L'\0'; ) {

            if (iswalpha(w_line[i])) {

                int start = i;
                while (w_line[i] != L'\0' && iswalpha(w_line[i]))
                    i++;
                int end = i;
                int len = end - start;

                if (len % 2 == 0) {
                    wchar_t w_even_word[MAX_SIZE];
                    char even_word[MAX_SIZE * 4];
                    int word_idx = 0;

                    for (int j = start; j < end; j++) {
                        w_even_word[word_idx++] = w_line[j];
                    }
                    w_even_word[word_idx] = L'\0';

                    if (wcstombs(even_word, w_even_word, sizeof(even_word)) != (size_t)-1) {
                        fprintf(file, "%s ", even_word);
                    }
                }
                else {
                    for (int j = start; j < end; j++) {
                        w_out[out_idx++] = w_line[j];
                    }
                }

            } else {
                w_out[out_idx++] = w_line[i];
                i++;
            }
        }

        w_out[out_idx] = L'\0';

        if (wcstombs(line_out, w_out, sizeof(line_out)) != (size_t)-1) {
            printf("%s", line_out);
        }
    }
    clearerr(stdin);

    fclose(file);

    return 0;
}
