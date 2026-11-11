
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comment_removal.h"
#include "file_inclusion.h"
#include "macro_handler.h"

int main(int argc, char *argv[])
{
    FILE *input, *output;
    FILE *temp1, *temp2;
    char output_file[256];

    if (argc != 2)
    {
        printf("Usage: ./mypreprocessor input.c\n");
        return 1;
    }

    input = fopen(argv[1], "r");

    if (input == NULL)
    {
        perror("Error opening input file");
        return 1;
    }

    strcpy(output_file, argv[1]);

    char *dot = strrchr(output_file, '.');

    if (dot != NULL)
        strcpy(dot, ".i");
    else
        strcat(output_file, ".i");

    output = fopen(output_file, "w");

    if (output == NULL)
    {
        perror("Error creating output file");
        fclose(input);
        return 1;
    }

    temp1 = tmpfile();
    temp2 = tmpfile();

    if (temp1 == NULL || temp2 == NULL)
    {
        printf("Error creating temporary files\n");
        fclose(input);
        fclose(output);
        if (temp1 != NULL) fclose(temp1);
        if (temp2 != NULL) fclose(temp2);
        return 1;
    }

    // Step 1: Comment removal
    remove_comments(input, temp1);

    // Step 2: Header file inclusion
    rewind(temp1);
    include_headers(temp1, temp2);

    // Step 3: Macro substitution
    rewind(temp2);
    macro_substitution(temp2, output);

    printf("Preprocessing completed successfully!\n");
    printf("Output file: %s\n", output_file);

    fclose(input);
    fclose(output);
    fclose(temp1);
    fclose(temp2);

    return 0;
}

