#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int b;
    float a,c,d,e,f,g,h;
    c=1.0225;
    d=1.0243;
    e=1.0270;
    f=1.0288;
    g=1.0300;
    printf("�����뱾��ʹ������:\n");
    scanf("%f %d",&a,&b);
    switch(b)
    {
    case 1:
        h=pow(c,b)*a;
        printf("��ϢΪ%f\n",h);
        break;
    case 2:
        h=pow(d,b)*a;
        printf("��ϢΪ%f\n",h);
        break;
    case 3:
        h=pow(e,b)*a;
        printf("��ϢΪ%f\n",h);
        break;
    case 5:
        h=pow(f,b)*a;
        printf("��ϢΪ%f\n",h);
        break;
    case 8:
        h=pow(g,b)*a;
        printf("��ϢΪ%f\n",h);
        break;
    default:
    printf("������������ҪǮ��\n");
    }
    return 0;
}
