//written by Bailey Ivancic and Marvel Phillip, 10/4/17
//decodes using a substitution cipher

#include <stdio.h>
#include <stdlib.h>

int main(int arg,char *argv[]) {
    int c,i,k;
    char code[26];
  
    
  
    c=getchar();


    i=0;
    while (i<26) {
        code[i]=argv[1][i];
        i=i+1;
    }
    while (c!=EOF) {       
        k=0;
        
        if (c<='z'&&c>='a'){   
            while (code[k]!=c) {
                k=k+1;
            }
            putchar(k+'a');        
        } else if (c<='Z'&&c>='A'){
            while (code[k]!=(c+32)) {
                k=k+1;
            }
            putchar(k+'A');         
        } else {
            putchar(c);
        } 
        c=getchar();
    }
    
    return 0;
}
