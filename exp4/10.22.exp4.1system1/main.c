#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int random();//���������
int caculate(int a,int b);//����˷����
int judge(int a,int b,int result);//�жϽ����ȷ���
int main()
{
    printf("Number:200210122\nSubject No.4     Project No.1\n\n");
    int a,b,result,counter,right,i;
    counter=0;
    srand(time(NULL));//ʱ�����ӣ�һ��Ҫ�������棬�����Է����Ӻ�����
    for(i=0;i<=9;i++)//ѭ������10����
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
            goto Y;//�������ؽṹ
        }
        if(i!=3) printf("Wrong! Please try again.\n");//һ�������ʾ
    }
    printf("Wrong! Test next subject");//ʧ�ܴ�����ʾ
    Y:return right;
}
