#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a;
   printf("������һ����ݣ�\n");
   scanf("%d",&a);
   printf("%d����",a);
   if(a%100!=0&&a%4==0)
   {
       printf("����");
   }
   else if(a%100==0&&a%400!=0)
   {
       printf("����");
   }
   else if(a%400==0)
   {
       printf("����");
   }
   else
   {
       printf("����");
   }
   return 0;
}
