#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,ret;//定义输入变量，循环变量，判断变量
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};//定义月份数组
    for(i=1;i<=5;i++)
    {
        printf("inpute the month n:\n");
        ret=scanf("%d",&n);
        while(ret==0)//如果输入非法字符
        {
            while(getchar()!='\n');
            printf("inpute again:\n");
            ret=scanf("%d",&n);
        }
        if(n<=0||n>=13||n%1!=0)
        {
            printf("error! again:");
        }
        else printf("%d month has %d days\n",n,month[n-1]);
    }
    return 0;
}
