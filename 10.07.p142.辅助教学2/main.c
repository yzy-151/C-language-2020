#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
char signal();
int randomnum();
int caculate(int x, char op,int y );
void printfwrong();
void printfright();
int main()

{
    int x,y,counter1,counter2,result,answer;//x,yΪ�������counter1����Ŀ����counter2�Ƕ�������result�𰸣�answer�û����
    counter1=1;
    counter2=0;
    char op;//op���������
    float ratio;//��ȷ��
    Y:do
    {
      x=randomnum();//ʹ�ú���ʱֻ�������ּ���  Sleep(1000);
      Sleep(10);                   //������Ǹ�ͷ�ļ�
      y=randomnum();
      op=signal();
      printf("%d%c%d=\n",x,op,y);
      result=caculate( x, op , y);//���������int charҲ��д
      scanf("%d",&answer);
      if (answer<=result+0.1&&answer>=result-0.1)//������������
      {
          printfright();
          counter2++;
          counter1++;
      }
      else
      {
          printfwrong();
          counter1++;
      }

    }while(counter1<=10);
    ratio=(float)counter2/((float)counter1-1);//������ȷ�ʣ���ʱcounter1=11
    if(ratio<=0.750)//����ȷ��С��0.75
    {
        printf("you right ratio is only %%%f,please fight again\n",ratio*100);
        counter1=1;
        counter2=0;
        goto Y;
    }
    else
    {
        printf("you right ratio is %%%f,congratulations!!\n",ratio*100);
    }
}
char signal()//����������ַ���
{
    char op;
    int i;
    srand(time(NULL));
    i=rand()%4+1;
    switch(i)
    {
    case 1:op='+';
    break;
    case 2:op='-';
    break;
    case 3:op='*';
    break;
    case 4:op='/';
    break;
    default :printf("don't killing me!!\n");

    }
    return op;
}
int randomnum()//�������ʮ����������
{
    int i2;
    srand(time(NULL));
    i2=rand()%10+1;
    return i2;
}
int caculate(int x,char op,int y)//���ݷ��Ž�������
{

    switch (op)
    {
        case '+':return x+y;
        case '-':return x-y;
        case '*':return x*y;
        case '/':return x/y;
        default :printf("wrong!!\n");
        return 0;
    }

}

void printfwrong()//����ʱ������ֻش�
{
    int i3;
    srand(time(NULL));
    i3=rand()%4+1;
    switch (i3)
    {
        case 1:printf("it's wrong!\n");
        break;
        case 2:printf("sorry ,wrong\n");
        break;
        case 3:printf("not right,@_^,but stay calm\n");
        break;
        case 4:printf("How silly you are!I can't believe it!!\n");
        break;
    }
}
void printfright()
{
    int i4;
    srand(time(NULL));
    i4=rand()%4+1;
    switch (i4)
    {
        case 1:printf("right!\n");
        break;
        case 2:printf("goooooood!!!\n");
        break;
        case 3:printf("(^-^)\n");
        break;
        case 4:printf("666666666\n");
        break;
    }
}
