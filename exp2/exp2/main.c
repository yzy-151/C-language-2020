#include <stdio.h>
#include <stdlib.h>

int main()
{
   char a;
   int counter;//外层循环计数
   int counter2;//内层循环计数
   printf("Number:200210122\nSubject No.1 Project No.2\n");
   printf("inpute a words:\n");
   scanf("%c",&a);//输入小写字母
   a=a-32;//将其转化为大写
   for(counter=1;counter<=8;counter++)//循环八次，共八行
   {
       if (counter%2==0)//偶数行则加一个空格
       {
            printf(" ");
       }
       for(counter2=1;counter2<=8;counter2++)//内层循环共8列
       {
           printf("%c ",a);
       }
       printf("\n");//当一行达到8个时换行


   }

   return 0;
}
