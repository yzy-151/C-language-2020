#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a;
    printf("第一种表格为：\n");
    for(a=1;a<=9;a++)
    {
        for(i=1;i<=9;i++)
        {
           if(i*a<10)/*注意此步骤为了使九宫格对齐*/
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
    printf("第二种表格为：\n");
    int i2,a2;
    for(a2=1;a2<=9;a2++)
    {
        for(i2=1;i2<=a2;i2++)
        {
           printf("%d*%d=%-3d\t",a2,i2,a2*i2);//%-3d中-3表示左对齐三个格多的用空格补位
        }
        printf("\n");
    }

     int a3,i3;
     printf("第三种表格为：\n");
     for(a3=1;a3<=9;a3++)
    {
        for(i3=1;i3<=9;i3++)
        {
            if(i3<a3)
            {
                printf("       \t");//用来补空位
            }
            else
            {

                printf("%d*%d=%-3d\t",a3,i3,a3*i3);
            }
        }
        printf("\n");
    }
}



