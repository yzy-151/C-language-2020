#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int  randomn();//���������
char randomf();//�����������
float caculate(int a,int  b,char c);//������ȷ��
void randoma(int right);//���ݴ𰸸����ظ�
int judge(float answer);//�жϴ��Ƿ���ȷ
int main()
{
    printf("Nummber:200210122\nSubjet No.4    Project No.2\n\n");
    int a,b,right,counter;
    counter=0;
    float answer;
    int i;
    char c;
    srand(time(NULL));
    do{
        for(i=0;i<=9;i++)
       {
           a=randomn();
           b=randomn();
           c=randomf();
           printf("%d%c%d=:\n",a,c,b);
           answer=caculate(a,b,c);
           right=judge(answer);
           if(right==1) counter++;//������ȷ��
           randoma(right);

        }
        printf("your right ratio is%d%%\n",10*counter);


       }while(counter*10<75);
}
int  randomn()//���������
{
    int a;
    a=rand()%10+1;
    return a;
}
char randomf()//�����������
{
    char b;
    int  a;
    a=rand()%4+1;
    switch (a)
    {
        case 1:b='+';
        break;
        case 2:b='-';
        break;
        case 3:b='*';
        break;
        case 4:b='/';
        break;
    }
    return b;
}
float caculate(int  a,int  b,char c)//������ȷ��
{
    float answer;
    switch(c)
    {
        case '+':answer=a+b;
        break;
        case '-':answer=a-b;
        break;
        case '*':answer=a*b;
        break;
        case '/':answer=(double)a/(float)b;
        break;
    }
    return answer;
}
void randoma(int right)//�жϲ������ȷ���
{
    int  a;
    a=rand()%4+1;
    if(right==1)
    {
        switch(a)
        {
            case 1:printf("very good!\n");
            break;
            case 2:printf("excellent!\n");
            break;
            case 3:printf("Nice work!\n");
            break;
            case 4:printf("Keep up the good work!\n");
            break;
        }
    }
    else
    {
        switch(a)
        {
            case 1:printf("NO.Please try next subject!\n");
            break;
            case 2:printf("Wrong,Be careful!\n");
            break;
            case 3:printf("Don't give up!\n");
            break;
            case 4:printf("Not corret.Keep trying!\n");
            break;
        }


    }
}

int judge(float answer)//�жϴ��Ƿ���ȷ
{
    float c;
    int right=0;
    scanf ("%f",&c);
    if(fabs(c-answer)<=0.1)
    {
        right=1;
    }
    return right;
}
