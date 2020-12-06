#include <stdio.h>
#include <stdlib.h>
#define N 40
int average(int score[],int n);
void inpute(int score[],int n);
int main()
{
    int n;
    int score[N];
    printf("inpute n:\n");
    scanf("%d",&n);
    inpute(score,n);
    printf("the average score of %d students is %d",n,average(score,n));

}
int average(int score[],int n)
{
    int counter,sum,average;
    for (counter =1;counter<=n;counter++)
    {
        sum=sum+score[counter-1];
    }
    average =sum/n;
    return average;
}
void inpute(int score[],int n)
{
    int i;
    printf("inpute the score:\n");
    for(i=1;i<=n;i++)
    {
        scanf ("%d",&score[i-1]);
    }
}
