#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a;
    printf("��һ�ֱ��Ϊ��\n");
    for(a=1;a<=9;a++)
    {
        for(i=1;i<=9;i++)
        {
           if(i*a<10)/*ע��˲���Ϊ��ʹ�Ź������*/
           {
               printf("%d  ",i*a);
           }
           else
           {
               printf("%d ",i*a);
           }

        }
        printf("\n");
    }
    printf("�ڶ��ֱ��Ϊ��\n");
    int i2,a2;
    for(a2=1;a2<=9;a2++)
    {
        for(i2=1;i2<=a2;i2++)
        {
           printf("%d*%d=%-3d\t",a2,i2,a2*i2);//%-3d��-3��ʾ��������������ÿո�λ
        }
        printf("\n");
    }

     int a3,i3;
     printf("�����ֱ��Ϊ��\n");
     for(a3=1;a3<=9;a3++)
    {
        for(i3=1;i3<=9;i3++)
        {
            if(i3<a3)
            {
                printf("       \t");//��������λ
            }
            else
            {

                printf("%d*%d=%-3d\t",a3,i3,a3*i3);
            }
        }
        printf("\n");
    }
}



