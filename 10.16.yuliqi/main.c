#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r=1;
    int a,b;
    printf("Input two positive integers a and b:");
    scanf("%d%*c%d",&a,&b);
    do   {
           r = a%b;
           a = b;
           b = r;
           printf("%d,%d,%d\n",a,b,r);
    }while(r!=0);
    printf("greatest common divisor is %d\n",a);
    return 0;
}
