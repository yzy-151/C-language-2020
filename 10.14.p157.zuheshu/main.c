#include <stdio.h>
#include <stdlib.h>
unsigned long Fact(unsigned n);
int main()
{
    int m,k;
    unsigned answer;
    printf("please inpute m and k:");
    do//�ж������������
    {
        scanf("%d,%d",&m,&k);
        if(m<k)
        {
            printf("error! please inpute again.\n");
        }
    }while(m<=k||m<0||k<0);//��mС��k����1��Ϊ������ѭ��
    answer=Fact(m)/(Fact(k)*Fact(m-k));//���ý׳˺���
    printf("C(%d,%d)=%u",m,k,answer);
}


unsigned long Fact(unsigned n)//����n�Ľ׳�
{
    unsigned result=1;
    unsigned i;

    for(i=1;i<=n;i++)
    {
        result=result*i;
    }
    return result;
}
