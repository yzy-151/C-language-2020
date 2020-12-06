#include <stdio.h>
#include <stdlib.h>
#define DDD 1.42e8
#include<math.h>
double method1(int n);
double method2(int n);
int main()
{
    printf("%f\n\n",method1(64));
    printf("%f\n",method2(64));
}
double method1(int n)
{
    int i;
    double sum,v,term;
    sum=0;
    for(i=1;i<=n;i++)
    {
        term=pow(2,i-1);
        sum=sum+term;
    }
    v=(double)sum/DDD;
    return v;
}
double method2(int n)
{
    int i;
    double term,sum,v;
    term=1;sum=0;
    for(i=1;i<=n;i++)
    {
        sum=sum+term;
        term=term*2;
    }
    v=(double)sum/DDD;
    return v;
}
