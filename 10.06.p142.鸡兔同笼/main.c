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
                printf("����%dֻ������%dֻ\n",a,b);
            }

        }
    }
    return 0;
}

