#include <stdio.h>
#include <stdlib.h>
int gcd(int a,int b);
int main()
{
    int a,b;
    printf("inpute a,b\n");
    scanf("%d%*c%d",&a,&b);
    printf("the greatest common divisor is %d\n\n",gcd(a,b));
    return 0;
}
int gcd(int a,int b)
{
    if(a==b) return b;
    else if(a<b) return gcd(b-a,a);
    else return  gcd(a-b,b);
}
