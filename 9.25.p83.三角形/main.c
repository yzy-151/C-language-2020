#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c;
    printf("�����������������߳�:\n");
    scanf("%f %f %f",&a,&b,&c);
    if(a+b<=c || a+c<=b || b+c<=a)
    {
        printf("�޷�����������");

    }
    else
    {
        if(a==b || b==c || c==a)
        {
            printf("���ǵ���������");
        }
        else if(a*a==b*b+c*c||b*b==a*a+c*c||c*c==a*a+b*b)
        {
            printf("���Ǹ�ֱ��������");
        }
        else
        {
            printf("���Ǹ�һ��������");

        }
    }
    return 0;
}
