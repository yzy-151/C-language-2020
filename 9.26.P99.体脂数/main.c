#include <stdio.h>
#include <stdlib.h>

int main()
{
    float weight,hight,a;
    printf("请输入你的身高(单位米):\n");
    scanf("%f",&hight);
    printf("请输入你的体重(单位千克):\n");
    scanf("%f",&weight);
    a=weight/(hight*hight);
    if(a<18)
    {
        printf("你的体指数为%f,你的体重偏瘦\n",a);
    }
    else if(a>=18&&a<=25)
    {
        printf("你的体指数为%f,阁下的体重正常\n",a);
    }
    else if(a>25&&a<=27)
    {
        printf("你的体指数为%f,同志要减肥了\n",a);
    }
    else
    {
        printf("你的体指数为%f,再不减肥就没救了\n",a);
    }
    return 0;

}
