#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define PI 3.1415926

int main()
{
    double a,b,c,x1,x2,d;
    printf("please inpute a,b,c:\n");
    scanf("%lf,%lf,%lf",&a,&b,&c);
    d=sqrt(b*b-4*a*c);
    if (a==0)
    {
        printf("这不是一元二次方程！\n");
    }
    else
    {
        if(d>=0)
        {
            x1=(-b+d)/(2*a);
            x2=(-b-d)/(2*a);
            printf("x1=%f\n",x1);
            printf("x2=%f\n",x2);
        }
        else
        {
            printf("此方程无实数根");
        }
    }
    return 0;
}
