#include <stdio.h>
#include <stdlib.h>
#define D 1.42e8
#include<math.h>
int main()
{
    printf("Number:200210122:\nSubjet No.3     Program No.2\n\n");
    int i,i2;
    unsigned long long term,term2,sum1,sum2,v1,v2;//
    term=term2=1;
    sum1=sum2 =0;
    for(i=1;i<=64;i++)
    {
        sum1=sum1+term;
        term=term*2;
    }
    v1=sum1/D;
    printf("in method 1 the volume is %llu m3\n\n",v1);
    for(i2=1;i2<=64;i2++)
    {
        term2=pow(2,i2-1);
        sum2 =sum2+term2;
    }
    v2=sum2/D;
    printf("in method 2 the volume is %llu m3\n\n",v2);//longlongÀàÐÍ»áworning
}
