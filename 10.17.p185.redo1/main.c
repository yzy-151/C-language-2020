#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,find,t,min;
    find=0;
    printf("inpute a and b:\n");
    scanf("%d%*c%d",&a,&b);

    if(a<b) min=a;
    else    min=b;

    for(t=min;!find;t--)
    {
        if(a%t==0&&b%t==0) find=1;
        else find=0;
    }
    printf("the greaest common divisor is %d\n",t+1);
    return 0;
}
