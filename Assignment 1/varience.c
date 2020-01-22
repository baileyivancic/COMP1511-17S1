//Written by Bailey Ivancic
//Used in Assignment 1
//Calculates the varience of a parameter to a given number

double varience(double val1, double val2)
{
    double var = 0;
    if (val1 > val2)
    {
        var = val1 - val2;
    }   
            
    else
    {
        var = val2 - val1;
    }
    return var;
}
