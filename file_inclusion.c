#include <stdio.h>
#include <string.h>
#include "file_inclusion.h"

void include_headers(FILE *input, FILE *output)
{
    char line[1000];
    char filename[200];
    FILE *header;

    while (fgets(line, sizeof(line), input))
    {
        if (sscanf(line, "#include \"%199[^\"]\"", filename) == 1)
        {
            header = fopen(filename, "r");

            if (header == NULL)
            {
                printf("Error opening header file: %s\n", filename);
                continue;
            }

            int ch;

            while ((ch = fgetc(header)) != EOF)
            {
                fputc(ch, output);
            }

            fclose(header);
        }
        else
        {
            fputs(line, output);
        }
    }
}

