#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("Number:200210122\nSubject No.3     project No.1\n\n");
    int counter,i,n;
    counter=0;
    int prime[21];
    for(i=100;i<=200;i++)
    {
        int find =1;
        for(n=2;n<i;n++)
        {
            if(0==i%n)
            {
                find =0;
                goto Y;
            }
        }
        if(0!=find)
            {
                counter++;
                prime[counter-1]=i;
            }
        Y:;
    }
    int a,b,c;
    c=0;
    for(a=1;a<=3;a++)
    {
        for(b=1;b<=10;b++)
        {
            if(c>20) goto X;
            printf("%d  ",prime[c]);
            c++;
        }
        X:printf("\n");
    }
    int d,a1,a2,a3;
    int prime2[21];
    for(d=0;d<=20;d++)
    {
        a1=prime[d]/100;
        a2=(prime[d]-a1*100)/10;
        a3=prime[d]-a1*100-a2*10;
        prime2[d]=a3*100+a2*10+a1;

    }
    c=0;
    for(a=1;a<=3;a++)
    {
        for(b=1;b<=10;b++)
        {
            if(c>20) goto Z;
            printf("%d  ",prime2[c]);
            c++;
        }
        Z:printf("\n");
    }


    return 0;
}
