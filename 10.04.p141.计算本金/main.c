#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    double M,i,N,i2;
    double L=0.01875;/*LΪ�����ʣ�MΪ����iΪʱ�䣬*/
    for(M=1;M<=5000;M=M+0.0001)
    {
        N=M;
        for(i=1;i<=5;i++)
        {
            for(i2=1;i2<=12;i2++)
            {
                N=N*(L+1);
            }
            N=N-1000;
        }
        if(fabs(N)<=0.01)/*ע�ⲻ��N==0����һ������ֵ���������￨�˺ܾ�*/
        {
            printf("����Ϊ%f\n",M);
            break;
        }
    }
    return 0;
}
