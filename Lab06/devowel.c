//written by Bailey Ivancic, 7/4/17
//omits vowels from entered string

#include <stdio.h>

int main(void)
{
    char c = getchar();
    while (c != EOF) 
    {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
        {
            putchar(c);
        }
    
        c = getchar();
    }
    
    

    return 0;
}
