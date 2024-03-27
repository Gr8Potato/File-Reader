// DISCLAIMER: I DO NOT SUPPORT PEOPLE PLAGIARIZING MY CODE. I DO NOT TAKE RESPONSIBILITY FOR THE UNLAWFUL ACTIONS OF OTHERS.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv[])
{
    // arg error checking
    if (argc != 2)
    {

        if (argc == 1)
        { // 1 not 0 because argv will always store exe name
            perror("Provide a file to parse.\n");
            return 1;
        }
        else
        {
            printf("Too may arguments.\n");
            return 2;
        }
    }

    // open file
    FILE *file = fopen(argv[1], "r"); // argv[1] is file name
    if (file == NULL)
    {
        printf("Provided argument is not a valid file.\n");
        return 3;
    }

    // read & print file
    char buffer[2];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    printf("File size: %d bytes\n", ftell(file));

    // close file
    fclose(file);

    return 0;
}
