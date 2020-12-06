#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b;
    printf("请输入一个字母：\n");
    scanf("%c",&a);
    printf("该字母对应的ASC码为%d\n",a);
    if(a<=90&&a>=65)
    {
        b=a+32;
        printf("%c\n",b);
    }
    else if(a<=122&&a>=97)
    {
        b=a-32;
        printf("%c\n",b);
    }
    else
    {
        printf("输入违法字符\n");
    }
    return 0;
}
