#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    long int sum;
    printf("����n:\n");
    scanf("%d",&n);
    sum=1;
    for(i=1;i<=n;i++)
    {
        sum=sum*2;
        printf("2��%d�η���%ld\n",i,sum);
    }
    printf("sum=%ld\n",sum);
    return 0;
}
