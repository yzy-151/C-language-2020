#include <stdio.h>
#include <stdlib.h>

int main()
{
   double a,n,sum;
   printf("����һ����:\n�޽�Ϊ�������׳�\n");
   scanf("%lf",&n);
   sum=1;
   for (a=1;a<=n;a++)
   {
       sum=sum*a;
       printf("%.1lf�Ľ׳���%.1lf\n",a,sum);

   }
   printf("KO\n");
   return 0;

}
