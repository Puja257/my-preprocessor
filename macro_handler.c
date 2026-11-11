#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "macro_handler.h"

void macro_substitution(FILE *input, FILE *output)
{
    char line[1000];
    char name[100], value[100];
    char word[100];

    struct
    {
        char name[100];
        char value[100];
    } macros[100];

    int count = 0;
    int i, j, k, len;

    while (fgets(line, sizeof(line), input))
    {
        if (sscanf(line, "#define %99s %99s", name, value) == 2)
        {
            if (count < 100)
            {
                strcpy(macros[count].name, name);
                strcpy(macros[count].value, value);
                count++;
            }
            continue;
        }

        i = 0;

        while (line[i] != '\0')
        {
            if (isalpha((unsigned char)line[i]) || line[i] == '_')
            {
                k = i;

                while (isalnum((unsigned char)line[k]) || line[k] == '_')
                    k++;

                len = k - i;

                if (len < 100)
                {
                    strncpy(word, line + i, len);
                    word[len] = '\0';

                    for (j = 0; j < count; j++)
                    {
                        if (strcmp(word, macros[j].name) == 0)
                            break;
                    }

                    if (j < count)
                        fputs(macros[j].value, output);
                    else
                        fputs(word, output);
                }
                else
                {
                    fwrite(line + i, 1, len, output);
                }

                i = k;
            }
            else
            {
                fputc(line[i], output);
                i++;
            }
        }
    }
}

