#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,result;

printf("\n");

for(i=1;i<10;i++)

{

for(j=1;j<=i;j++)

{
result=i*j;

printf("%d*%d=%-3d",i,j,result);/*-3d��ʾ����룬baiռdu3λ*/

}

printf("\n");/*ÿһ�к���*/
}
}
