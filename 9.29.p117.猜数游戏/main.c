#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int counter,random,a;
    char b;
    b='Y';

    printf("����ʮ�λ����һ��100������Ȼ���������룺\n");
    for(;b=='Y'||b=='y';)
    {
    srand(time(NULL));
    random =rand()%100;
    counter=0;
    do
    {   printf("��������Ĳ²�:\n");
        scanf("%d",&a);
        counter++;
        if (a<random)
        {
            printf("̫С��\n");
        }
        else if(a>random)
        {
            printf("̫����\n");
        }
        else if(a==random)
        {
            printf("bingo!!!");
        }
    }while (a!=random&&counter<=9);
    printf ("��Ҫ����һ��������Y��N:");
    while(getchar()!='\n');
    scanf("%c",&b);

    }
    return 0;
}
