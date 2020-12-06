#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    float i,e,sum,sum2;
    e=1;
    sum2=sum=1;
    for(i=1;fabs(sum2)>=0.00001;i++)
    {
        sum=sum*i;
        sum2=1/sum;
        e=e+sum2;
        printf("经过第%f次运算，e的值为%f\n",i,e);
    }
    return 0;
}
