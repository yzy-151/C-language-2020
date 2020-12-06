#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define PI 3.1415926
int main()
{
    double a,b,c,x1,x2,d;
    printf("please inpute a,b and c:\n");
    scanf("%lf,%lf,%lf",&a,&b,&c);
    d=b*b-4*a*c;
    if (d >=0)
    {
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        printf("x1=%f\n",x1);
        printf("x2=%f\n",x2);
    }
    else printf("no answer");
    return 0;
}
