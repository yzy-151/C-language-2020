#include <stdio.h>
#include <stdlib.h>
void  Do(int n,char a,char b,char  c);
int main()
{
    char a,b,c;
    a='A';
    b='B';
    c='C';
    int n;
    printf("inpute n:\n");
    scanf("%d",&n);
    Do(n,a,b,c);
    return 0;
}
void  Do(int n,char a,char b,char  c)
{
    static int counter=1;
    if(1==n)
    {
         printf("the %d th operation is  %c--------->%c\n",counter,a,b);
         counter++;
    }
    else
    {
        Do(n-1,a,c,b);
        printf("the %d th operation is  %c--------->%c\n",counter,a,b);
        counter++;
        Do(n-1,c,b,a);
    }
}
