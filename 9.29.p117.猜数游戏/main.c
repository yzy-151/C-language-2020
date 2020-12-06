#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int counter,random,a;
    char b;
    b='Y';

    printf("给你十次机会猜一个100以内自然数，请输入：\n");
    for(;b=='Y'||b=='y';)
    {
    srand(time(NULL));
    random =rand()%100;
    counter=0;
    do
    {   printf("请输入你的猜测:\n");
        scanf("%d",&a);
        counter++;
        if (a<random)
        {
            printf("太小了\n");
        }
        else if(a>random)
        {
            printf("太大了\n");
        }
        else if(a==random)
        {
            printf("bingo!!!");
        }
    }while (a!=random&&counter<=9);
    printf ("想要再来一局吗输入Y或N:");
    while(getchar()!='\n');
    scanf("%c",&b);

    }
    return 0;
}
