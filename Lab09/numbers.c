//Written by Bailey Ivancic
//Takes 3 arguments which creates a file containing specified integers

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    if (argc < 3)
    {
        printf("File cannot be read\n");
        return 0;
    }
    
    FILE *f = fopen(argv[3], "w+");
    
    int start = atoi(argv[1]);
    int finish = atoi(argv[2]);
    int i = start;
    
    while (i <= finish)
    {
        fprintf(f, "%d\n", i);
        i++;   
    }
    
    
    fclose(f);

    return 0;
}
