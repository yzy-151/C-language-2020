#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    for(a=1;a<=98;a++)
    {
        for(b=1;b<=98;b++)
        {
            if(a+b==98&&4*a+2*b==386)
            {
                printf("兔有%d只，鸡有%d只\n",a,b);
            }

        }
    }
    return 0;
}

