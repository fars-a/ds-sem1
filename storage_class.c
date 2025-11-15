/*
1.program to demonstrate the use of storage classes (local variable, global variable, static variable, register variable) in C.
@Farsan_Suneer
Date_of_completion: 13/07/2025
*/
#include <stdio.h>
int g=10;//global variable
void scope()
{
    int l=1;//local variable
    register int r=2;//register variable
    static int s=0;//static variable
    printf("\nLocal variable=%d",l);
    printf("\nRegister variable=%d",r++);
    printf("\nStatic variable=%d",s++);
    printf("\nglobal variable=%d\n",g);
}
int main()
{
    printf("\nFirst call to the function");
    scope();
    printf("\nSecond call to the function");
    scope();
    return 0;
}

