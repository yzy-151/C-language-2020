#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,counter,x;
    int b=1;
    printf("������һ������x��\n");
    scanf("%d",&x);
    for(counter=100000000;;counter=counter/10)
    {
        a=x/counter;
        if(a!=0)
        {

           printf("n�ĵ�%d��λΪ%d\n",b,a);
           b++;
        }
        x=x-a*counter;


    }
    return 0;
}
