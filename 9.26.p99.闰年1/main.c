#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a;
   printf("请输入一个年份：\n");
   scanf("%d",&a);
   printf("%d年是",a);
   if(a%100!=0&&a%4==0)
   {
       printf("闰年");
   }
   else if(a%100==0&&a%400!=0)
   {
       printf("常年");
   }
   else if(a%400==0)
   {
       printf("闰年");
   }
   else
   {
       printf("常年");
   }
   return 0;
}
