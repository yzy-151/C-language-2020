#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int a,n,m,sum;
    printf("�������ҵĽ������ݣ����n��������ͽ׳ˣ�\n");
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
