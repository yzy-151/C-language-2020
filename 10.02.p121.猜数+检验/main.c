#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,counter,n,ret,ret2;
    char m;
    char answer='y';
    unsigned seed;
    printf("please inpute the seed:\n");
    ret=scanf("%u",&seed);
    srand(seed);
    while(ret!=1)
    {
        while(getchar()!='\n');
        printf("小伙子不要乱输入，再来一遍:\n");
        ret=scanf("%u",&seed);
    }
    for(;answer=='Y'||answer=='y';)
    {

        a=rand()%100;
        printf("给你十次机会，请猜一个100以内的自然数：\n");
        for(counter=1;counter<=10;counter++)//计数器
        {
          ret2=scanf("%d",&n);
          while(ret2!=1)
          {
            while(getchar()!='\n');
            printf("故意输错耍我吗，老老实实再输一次；\n");
            ret2=scanf("%d",&n);
          }
          if(n<a&&n>=a-25)
          {
              printf("往大了猜,还差一点\n");
          }
          else if(n<a-25)
          {
              printf("往大了猜,还差得远\n");
          }
          else if(n>a&&n<=a+25&&n<100)
          {
              printf("有点大哈\n");
          }
          else if(n>a+25)
          {
              printf("大的有些过分了\n");
          }
          else if(n==a)
          {
              printf("bingo！\n");
              goto P;//跳出程序
          }
          else if(n>=100)
          {
              printf("不是说好了超过一百吗\n");
          }
        }

          P:answer='y';
          printf("再来一次？\n输入y即可：\n");


        }
    return 0;
}
