#include <stdio.h>
#include <stdlib.h>

int main()
{
    float C,F;/*CΪ���϶�FΪ���϶�*/
    for(F=0;F<=300;F=F+10)
    {
        C=(5.0/9.0)*(F-32);
        printf("%f���϶ȶ�Ӧ%f���϶�\n",F,C);
    }
    return 0;
}

