#include <stdio.h>
#include <stdlib.h>

int main()
{
    float weight,hight,a;
    printf("������������(��λ��):\n");
    scanf("%f",&hight);
    printf("�������������(��λǧ��):\n");
    scanf("%f",&weight);
    a=weight/(hight*hight);
    if(a<18)
    {
        printf("�����ָ��Ϊ%f,�������ƫ��\n",a);
    }
    else if(a>=18&&a<=25)
    {
        printf("�����ָ��Ϊ%f,���µ���������\n",a);
    }
    else if(a>25&&a<=27)
    {
        printf("�����ָ��Ϊ%f,ͬ־Ҫ������\n",a);
    }
    else
    {
        printf("�����ָ��Ϊ%f,�ٲ����ʾ�û����\n",a);
    }
    return 0;

}
