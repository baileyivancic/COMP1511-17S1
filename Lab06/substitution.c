//Written by Bailey Ivancic and Marvel Phillip, 10/4/17
//Encodes characters using a substitution cipher

#include<stdio.h>
#include <stdlib.h>

void encode(int c,char code[26]) {
    int output,big;
    if(c<='z'&&c>='a') {
        output=code[c-'a'];
        putchar(output);
    } else if(c<='Z'&&c>='A') {
        output=code[c-'A'];
        big=output-32;
        putchar(big);
        } else {
            putchar(c);  
      }      
    
}


int main(int arg,char *argv[]) {
    int c,i,output,big;
    char code[26];
    

    i=0;
    while (i<26) {
        code[i]=argv[1][i];
        i++;
    }
    c=getchar();
    
    while(c!=EOF) {
    
    encode(c,code); 
    c=getchar();
    }   
    
      
    return 0;
}
