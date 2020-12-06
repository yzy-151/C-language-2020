#include <stdio.h>
#include <stdlib.h>
#define P 999
#include<math.h>
int main()
{
   float b;
   printf("输入一个数字:\n");

   b=0;
   while(b!=60)
   {
       scanf("%f",&b);
       if(b<60)
       {
           printf("过程淘汰\n");
       }
       else if(b>60)
       {
           printf("规格严格\n");
       }

   }
   printf("过程淘汰\n");
   return 0;
}
