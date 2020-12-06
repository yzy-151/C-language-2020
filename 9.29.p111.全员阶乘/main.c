#include <stdio.h>
#include <stdlib.h>

int main()
{
   double a,n,sum;
   printf("输入一个数:\n朕将为你算出其阶乘\n");
   scanf("%lf",&n);
   sum=1;
   for (a=1;a<=n;a++)
   {
       sum=sum*a;
       printf("%.1lf的阶乘是%.1lf\n",a,sum);

   }
   printf("KO\n");
   return 0;

}
