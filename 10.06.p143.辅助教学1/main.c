#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));
    int a,b,answer,counter;
    counter=1;
    a=rand()%10+1;
    b=rand()%10+1;
    printf("%d*%d=?\n",a,b);
    do
    {
        scanf("%d",&answer);
        if(answer==a*b)
        {
            printf("you are great!\n");
            goto Y;
        }
        else
        {
            printf("sorry,it's wrong,plerse inpute again:\n");
            counter++;
        }
    }while(counter<=3);
    printf("you are a loser!\n");

    Y:printf("now let's go to the stage 2:\n");
    int a2,b2,counter2,answer2;
    float c,d;
    c=d=1.0;
    for(counter2=1;counter2<=10;counter2++)
    {
    a2=rand()%10+1;
    b2=rand()%20+1;
    printf("%d*%d=?\n",a2,b2);
    scanf("%d",&answer2);
    if(answer2==a2*b2)
        {
            printf("right!\n");
            c++;
        }
        else
        {
            printf("wrong!\n");
            d++;
        }
    }
    printf("the right lv is %%%f",(c-1)*10);
    return 0;

}
