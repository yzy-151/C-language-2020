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
    printf("请输入本金和存款年限:\n");
    scanf("%f %d",&a,&b);
    switch(b)
    {
    case 1:
        h=pow(c,b)*a;
        printf("本息为%f\n",h);
        break;
    case 2:
        h=pow(d,b)*a;
        printf("本息为%f\n",h);
        break;
    case 3:
        h=pow(e,b)*a;
        printf("本息为%f\n",h);
        break;
    case 5:
        h=pow(f,b)*a;
        printf("本息为%f\n",h);
        break;
    case 8:
        h=pow(g,b)*a;
        printf("本息为%f\n",h);
        break;
    default:
    printf("哈哈哈哈还想要钱？\n");
    }
    return 0;
}
