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
        printf("С���Ӳ�Ҫ�����룬����һ��:\n");
        ret=scanf("%u",&seed);
    }
    for(;answer=='Y'||answer=='y';)
    {

        a=rand()%100;
        printf("����ʮ�λ��ᣬ���һ��100���ڵ���Ȼ����\n");
        for(counter=1;counter<=10;counter++)//������
        {
          ret2=scanf("%d",&n);
          while(ret2!=1)
          {
            while(getchar()!='\n');
            printf("�������ˣ��������ʵʵ����һ�Σ�\n");
            ret2=scanf("%d",&n);
          }
          if(n<a&&n>=a-25)
          {
              printf("�����˲�,����һ��\n");
          }
          else if(n<a-25)
          {
              printf("�����˲�,�����Զ\n");
          }
          else if(n>a&&n<=a+25&&n<100)
          {
              printf("�е���\n");
          }
          else if(n>a+25)
          {
              printf("�����Щ������\n");
          }
          else if(n==a)
          {
              printf("bingo��\n");
              goto P;//��������
          }
          else if(n>=100)
          {
              printf("����˵���˳���һ����\n");
          }
        }

          P:answer='y';
          printf("����һ�Σ�\n����y���ɣ�\n");


        }
    return 0;
}
