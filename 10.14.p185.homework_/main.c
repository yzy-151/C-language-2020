#include <stdio.h>
#include <stdlib.h>
int GCD_1_YZY(int a,int b);
int GCD_2_YZY(int a,int b);
int GCD_3_YZY(int a,int b);
int GCD_4_YZY(int a,int b);
int main()
{
    int x,y;
    printf("inpute x and y:\n");
    scanf("%d, %d",&x,&y);
    printf("1.穷举法%d和%d的最大公因数是%d\n\n",x,y,GCD_1_YZY(x,y));//调用函数一
    printf("2.欧几里得算法%d和%d的最大公因数是%d\n\n",x,y,GCD_2_YZY(x,y));//调用函数二
    printf("3.循环算法%d和%d的最大公因数是%d\n\n",x,y,GCD_3_YZY(x,y));//调用函数三
    printf("4.递归方法%d和%d的最大公因数是%d\n\n",x,y,GCD_4_YZY(x,y));//调用函数四
    return 0;
}
int GCD_1_YZY(int a,int b)//穷举法求最大公因数
{
    int c;
    if(a<=b)//判断两个数的大小并祏小的数递减尝试
    {
        c=a;
    }
    else
    {
        c=b;
    }
    for(;c>=1;c=c-1)//从大到小递减尝试
    {
        if(a%c==0&&b%c==0)//能被两个数都整除
        goto Y;//跳出循环
    }
    Y:return c;
}

int GCD_2_YZY(int a,int b)//欧几里得算法求最大公因数
{
    int c,r;//r为余数，c为中间变量
    if(a<=b)//找出a，b的大小并使a始终>b
    {
        c=b;b=a;a=c;
    }
    do//循环，直到余数为零跳出
    {
        r=a%b;
        if(r==0)
        {
            goto Y;//跳出循环返回b
        }
        c=r;r=b%r;a=b;b=c;//使a为r和b中较大的数，b为小的

    }while(r!=0);
    Y:return b;
}
int GCD_3_YZY(int a,int b)//递归法求最大公因式
{
    int c,result;
    do//若a/b余数不为0则反复循环
    {
        if(a==b)
        {
            return b;
        }
        else if(a<b)//始终保持a>b
        {
            c=a;a=b;b=c;
            if(a%b==0)
            {
                return b;
            }
        }
        c=a;a=b;b=c-b;
    }while(a%b!=0);
    result =b;
    return result;
}
int GCD_4_YZY(int a,int b)//递归法迭代
{
    int c;
    if(a<b)//使a>b
    {
        c=a;a=b;b=c;//保证a最大
    }
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return GCD_4_YZY(a-b,b);//返回递归
    }
}
