#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    double a,b,c,s,d;
    printf("please inpute the longth :\n");
    scanf("%lf,%lf,%lf",&a,&b,&c);
    d=(a+b+c)/2;
    s=sqrt(d*(d-a)*(d-b)*(d-c));
    printf("s=%f",s);
    return 0;
}
