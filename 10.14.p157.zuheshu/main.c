#include <stdio.h>
#include <stdlib.h>
unsigned long Fact(unsigned n);
int main()
{
    int m,k;
    unsigned answer;
    printf("please inpute m and k:");
    do//判断输入输错重输
    {
        scanf("%d,%d",&m,&k);
        if(m<k)
        {
            printf("error! please inpute again.\n");
        }
    }while(m<=k||m<0||k<0);//若m小于k或有1者为负数则循环
    answer=Fact(m)/(Fact(k)*Fact(m-k));//调用阶乘函数
    printf("C(%d,%d)=%u",m,k,answer);
}


unsigned long Fact(unsigned n)//计算n的阶乘
{
    unsigned result=1;
    unsigned i;

    for(i=1;i<=n;i++)
    {
        result=result*i;
    }
    return result;
}
