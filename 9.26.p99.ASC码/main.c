#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b;
    printf("������һ����ĸ��\n");
    scanf("%c",&a);
    printf("����ĸ��Ӧ��ASC��Ϊ%d\n",a);
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
        printf("����Υ���ַ�\n");
    }
    return 0;
}
