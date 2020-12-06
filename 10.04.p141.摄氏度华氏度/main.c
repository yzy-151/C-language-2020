#include <stdio.h>
#include <stdlib.h>

int main()
{
    float C,F;/*C为摄氏度F为华氏度*/
    for(F=0;F<=300;F=F+10)
    {
        C=(5.0/9.0)*(F-32);
        printf("%f华氏度对应%f摄氏度\n",F,C);
    }
    return 0;
}

