#include <stdio.h>
#include <stdlib.h>
int Fib(int n);//���ڼ���ǰ����֮��
int main()
{
    int n;
    printf("inpute n:\n");
    do//������ֹ���븺��
    {
        scanf("%d",&n);//���������
        if(n<0)
        {
            printf("error!inpute again!\n");
        }
    }while(n<0);
    printf("Fib(%d)=%d",n,Fib(n));//������
    return 0;


}
int Fib(int n)
{
    int result;
    if(n==0)
    {
        result=0;
        return result;
    }

    else if(n==1)
    {
        result=1;
        return result;
    }
    else//�ݹ��Լ�
    {
        result=Fib(n-1)+Fib(n-2);
        return result;
    }
}
