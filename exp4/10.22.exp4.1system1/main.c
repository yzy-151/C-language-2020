#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int random();//产生随机数
int caculate(int a,int b);//计算乘法结果
int judge(int a,int b,int result);//判断结果正确与否
int main()
{
    printf("Number:200210122\nSubject No.4     Project No.1\n\n");
    int a,b,result,counter,right,i;
    counter=0;
    srand(time(NULL));//时间种子，一定要放在外面，不可以放在子函数里
    for(i=0;i<=9;i++)//循环产生10道题
    {
        a=random();
        b=random();
        result=caculate(a,b);
        right=judge(a,b,result);
        if(right==1)
        {
            counter++;
        }

    }
    printf("the right ratio is %%%d\n",counter*10);
    return 0;
}
int random()
{
    int a;

    a=rand()%10;
    return a;
}
int caculate(int a,int b)
{
    int c;
    c=a*b;
    return c;
}
int judge(int a,int b,int result)
{
    int answer,right,i;
    for(i=1;i<=3;i++)
    {
        right=0;
        printf("%d*%d=:\n",a,b);
        scanf("%d",&answer);
        if(answer==result)
        {
            printf("Right!\n");
            right=1;
            goto Y;//跳出多重结构
        }
        if(i!=3) printf("Wrong! Please try again.\n");//一类错误提示
    }
    printf("Wrong! Test next subject");//失败错误提示
    Y:return right;
}
