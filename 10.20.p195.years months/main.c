#include <stdio.h>
#include <stdlib.h>
void Caculate(int days[][12]);//���㲢�����ݼ��·���������//printf("%d%15d\n��,n,n*n*n�������һ����Ч����
int Leapyear(int y);//�����Ƿ�����
int main()
{
    int i;
    int days[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    for(i=1;i<=5;i++){
    Caculate(days);
    }
}
void Caculate(int days[][12])//������µ�����
{
    int y,m;
    do
    {
        printf("inpute yuars y:\n months m:\n");
        scanf ("%d%*c%d",&y,&m);
        if(Leapyear(y)==1) printf("%d year %d month has %d days\n",y,m,days[1][m-1]);
        else printf ("%dyear %dmonth has %d days\n",y,m,days[0][m-1]);
    }while(m<1||m>12);
}
int Leapyear(int y)//�����Ƿ�����
{
    if(0==y%400||(0!=y%100&&0==y%4))
    return 1;
    else return 0;
}
