#include <stdio.h>
#include "comment_removal.h"

void remove_comments(FILE *input, FILE *output)
{
    int ch, next;

    while ((ch = fgetc(input)) != EOF)
    {
        if (ch == '/')
        {
            next = fgetc(input);

            // Single-line comment
            if (next == '/')
            {
                while ((ch = fgetc(input)) != EOF && ch != '\n');

                if (ch == '\n')
                    fputc('\n', output);
            }

            // Multi-line comment
            else if (next == '*')
            {
                int prev = 0;

                while ((ch = fgetc(input)) != EOF)
                {
                    if (prev == '*' && ch == '/')
                        break;

                    prev = ch;
                }
            }
            else
            {
                fputc('/', output);

                if (next != EOF)
                    fputc(next, output);
            }
        }
        else
        {
            fputc(ch, output);
        }
    }
}

