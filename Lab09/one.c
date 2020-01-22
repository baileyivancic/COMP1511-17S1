//Written by Bailey Ivancic, 3/5/27
//Reads a string from standard input and writes out the characters one per line

#include <stdio.h>
#define MAX_LINE 4096

int main (int argc, char* argv[])
{
    char chars[MAX_LINE];
    int i = 0;

    fgets(chars, MAX_LINE, stdin);

    printf("Enter a string: ");
    while (chars[i] != '\n')
    {
        printf("%c\n", chars[i++]);
    }
}
