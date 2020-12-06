#include <stdio.h>
#include <stdlib.h>
int Fib(int n);//用于计算前两项之和
int main()
{
    int n;
    printf("inpute n:\n");
    do//用来防止输入负数
    {
        scanf("%d",&n);//输入计算着
        if(n<0)
        {
            printf("error!inpute again!\n");
        }
    }while(n<0);
    printf("Fib(%d)=%d",n,Fib(n));//输出结果
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
    else//递归自己
    {
        result=Fib(n-1)+Fib(n-2);
        return result;
    }
}
