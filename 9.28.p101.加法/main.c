#include <stdio.h>
#include <stdlib.h>
#define P 999
#include<math.h>
int main()
{
   float b;
   printf("����һ������:\n");

   b=0;
   while(b!=60)
   {
       scanf("%f",&b);
       if(b<60)
       {
           printf("������̭\n");
       }
       else if(b>60)
       {
           printf("����ϸ�\n");
       }

   }
   printf("������̭\n");
   return 0;
}
