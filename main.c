#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    printf("POINTS TO REMEMBER:\n");
    printf("\n");
    printf("While entering trigonometric functions, ensure to follow the following format:\n") ;
    printf("\t \t sinx , cosy, tanx, secy, cosecx, coty , etc. \n") ;
    printf("While entering algebraic expressions, ensure to follow the following format:\n");
    printf("\t \t x^1 , y^0 , 2*x^-99 , y^-203 , etc.\n") ;
    printf("While entering exponential functions, ensure to follow the following format:\n") ;
    printf("\t \t e^x , e^y , logx , logy, etc.\n") ;
    printf("\n") ;
    printf("Enter a variable separable differential equation in the form of F(y)dy= G(x)dx:\n") ;
    char *ch=(char *)malloc(100*sizeof(char));
    scanf("%[^\n]s",ch) ;
    printf("\n") ;
    printf("%s+ C",separation(ch));
    return 0;
}

