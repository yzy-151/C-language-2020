#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,sum,num,counter;
    counter=1;
    printf("100yuanRMB chsnge for 10 5 1\n");
    for(a=1;a<=9;a++)
    {
        for(b=1;b<=19;b++)
        {
            for(c=1;c<=50;c++)
            {
             num=a+b+c;
             sum=10*a+5*b+c;
             if(sum==100&&num<=50)
             {
                printf("��%d�з�����10Ԫ��Ʊ%d�ţ�5Ԫ%d�ţ�һԪ%d��\n",counter,a,b,c);
                counter++;
             }
            }

        }
    }
}
