#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,ret;//�������������ѭ���������жϱ���
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};//�����·�����
    for(i=1;i<=5;i++)
    {
        printf("inpute the month n:\n");
        ret=scanf("%d",&n);
        while(ret==0)//�������Ƿ��ַ�
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
