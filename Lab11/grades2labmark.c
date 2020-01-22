//Written by Bailey Ivancic

#include <stdio.h>

double grades2labmark(char grades[]);
int main(int argc, char* argv[])
{
  printf("%0.1lf\n", grades2labmark(argv[1]));
    
    return 0;
}

double grades2labmark(char grades[])
{
    double grade = 0;
    int i = 0;
    
    while (grades[i] != '\0')
    {
        if (grades[i] == 'C')
        {
            grade = grade + 0.5;
        } 
        
        else if (grades[i] == 'B')
        {
            grade = grade + 0.8;
        }   
        
        else if (grades[i] == 'A')
        {
            
            if (grades[i+1] == '+')
            {
                grade = grade + 1.2;
                i++;
            } 
            else 
            {
                grade = grade + 1;
            }
        } 
        i++;   
    }
    if (grade > 10) 
    {
        return 10;
    }
    return grade;
}
