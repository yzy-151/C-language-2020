#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=100;/*本金为100万*/
    float b=100;
    int counter=0;
    float y;
    printf("请输入产值增长率y(如%%20请输入0.2):\n");/*注意想让printf输出%，必须打两个否则worn ing*/
    scanf("%f",&y);
    for(;b<200;)
    {
        b=b*(y+1);
        counter++;
    }
    printf("今年产值为%d万\n",a);
    printf("经过%d年后产值翻一番达到%f万",counter,b);
    return 0;
}
