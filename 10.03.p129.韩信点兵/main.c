#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    for(a=1;;a++)
    {
        if(a%5==1&&a%6==5&&a%7==4&&a%11==10)
        {
            printf("����������ʿ��%d��",a);
            break;
        }
    }

    return 0;
}
