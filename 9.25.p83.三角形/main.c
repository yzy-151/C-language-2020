#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c;
    printf("请输入三角形三条边长:\n");
    scanf("%f %f %f",&a,&b,&c);
    if(a+b<=c || a+c<=b || b+c<=a)
    {
        printf("无法构成三角形");

    }
    else
    {
        if(a==b || b==c || c==a)
        {
            printf("这是等腰三角形");
        }
        else if(a*a==b*b+c*c||b*b==a*a+c*c||c*c==a*a+b*b)
        {
            printf("这是个直角三角形");
        }
        else
        {
            printf("这是个一般三角形");

        }
    }
    return 0;
}
