#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "../include/lab4.h"


int odd_exclusion(void)
{
    setlocale(LC_ALL, "");

    wchar_t line[MAX_SIZE];
    wchar_t out[MAX_SIZE];

    while (fgetws(line, MAX_SIZE, stdin) != NULL) {
        int out_idx = 0;

        for (int i = 0; line[i] != L'\0'; ) {

            wchar_t c = line[i];
            if (iswalpha(line[i])) {

                int start = i;
                while (iswalpha(line[i]))
                    i++;
                int end = i;
                int len = end - start;

                if (len % 2 == 0) {
                    for (int j = start; j < end; j++) {
                        out[out_idx++] = line[j];
                    }
                }
            } else {
                    // для не букв
                    out[out_idx++] = line[i];
                    i++;
                }
            }

        out[out_idx] = L'\0';
        wprintf(L"%ls", out);
    }


    return 0;
}
