#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=100;/*����Ϊ100��*/
    float b=100;
    int counter=0;
    float y;
    printf("�������ֵ������y(��%%20������0.2):\n");/*ע������printf���%���������������worn ing*/
    scanf("%f",&y);
    for(;b<200;)
    {
        b=b*(y+1);
        counter++;
    }
    printf("�����ֵΪ%d��\n",a);
    printf("����%d����ֵ��һ���ﵽ%f��",counter,b);
    return 0;
}
