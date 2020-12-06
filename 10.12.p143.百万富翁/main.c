#include <stdio.h>
#include <stdlib.h>

int main()
{
   double  sum1,sum2,money1,money2,month;//定义变量
   sum1=sum2=0;
   money1 = 0.01;
   money2 =100000;//变量赋值
   for(month=1;month<=30;month++)//循环30天
   {
       sum1=sum1+money1;
       sum2=sum2+money2;
       money1=money1*2;
       printf("the %d day weathyman give %f and receive %f\n",(int)month,money1/2,money2);
   }
   printf("in 30 days he gives %f receive %f \n",sum1,sum2);
   return 0;
}
