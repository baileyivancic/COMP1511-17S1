//Written by Bailey Ivancic
//Counts the first 10 lines of a file, or a length specified

#define MAX_CHARACTERS 1024
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int count = 10;
    char line[MAX_CHARACTERS];
    FILE* f = NULL;

    if (argc == 2) //no length is given
    {
        f = fopen(argv[1], "r");
    }
    
    else if (argc == 4) //length is specified
    {
        f = fopen(argv[3], "r");
        count = atoi(argv[2]);
    }

    if (f == NULL)
    {
        printf("File cannot be read\n");
        return 1;
    }
    
    int i = 0;
    while (i < count)
    {
        if (fgets(line, MAX_CHARACTERS, f) > 0) //fgets succeeded
        {
            printf("%s", line);
        }
        i++;  
    }
    fclose(f);
    return 0;
}
