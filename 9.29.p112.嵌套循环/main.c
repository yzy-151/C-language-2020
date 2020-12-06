#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int a,n,m,sum;
    printf("输吧输吧我的骄傲放纵，输个n给你算求和阶乘：\n");
    scanf("%d",&n);
    sum=0;
    m=1;
    for(a=1;a<=n;a++)
    {
        m=m*a;
        sum=sum+m;
        printf("1!+2!+.....%d!=%d\n",m,sum);
    }
}
