#include <stdio.h>
#include <stdlib.h>
int GCD_1_YZY(int a,int b);
int GCD_2_YZY(int a,int b);
int GCD_3_YZY(int a,int b);
int GCD_4_YZY(int a,int b);
int main()
{
    int x,y;
    printf("inpute x and y:\n");
    scanf("%d, %d",&x,&y);
    printf("1.��ٷ�%d��%d�����������%d\n\n",x,y,GCD_1_YZY(x,y));//���ú���һ
    printf("2.ŷ������㷨%d��%d�����������%d\n\n",x,y,GCD_2_YZY(x,y));//���ú�����
    printf("3.ѭ���㷨%d��%d�����������%d\n\n",x,y,GCD_3_YZY(x,y));//���ú�����
    printf("4.�ݹ鷽��%d��%d�����������%d\n\n",x,y,GCD_4_YZY(x,y));//���ú�����
    return 0;
}
int GCD_1_YZY(int a,int b)//��ٷ����������
{
    int c;
    if(a<=b)//�ж��������Ĵ�С���uС�����ݼ�����
    {
        c=a;
    }
    else
    {
        c=b;
    }
    for(;c>=1;c=c-1)//�Ӵ�С�ݼ�����
    {
        if(a%c==0&&b%c==0)//�ܱ�������������
        goto Y;//����ѭ��
    }
    Y:return c;
}

int GCD_2_YZY(int a,int b)//ŷ������㷨���������
{
    int c,r;//rΪ������cΪ�м����
    if(a<=b)//�ҳ�a��b�Ĵ�С��ʹaʼ��>b
    {
        c=b;b=a;a=c;
    }
    do//ѭ����ֱ������Ϊ������
    {
        r=a%b;
        if(r==0)
        {
            goto Y;//����ѭ������b
        }
        c=r;r=b%r;a=b;b=c;//ʹaΪr��b�нϴ������bΪС��

    }while(r!=0);
    Y:return b;
}
int GCD_3_YZY(int a,int b)//�ݹ鷨�������ʽ
{
    int c,result;
    do//��a/b������Ϊ0�򷴸�ѭ��
    {
        if(a==b)
        {
            return b;
        }
        else if(a<b)//ʼ�ձ���a>b
        {
            c=a;a=b;b=c;
            if(a%b==0)
            {
                return b;
            }
        }
        c=a;a=b;b=c-b;
    }while(a%b!=0);
    result =b;
    return result;
}
int GCD_4_YZY(int a,int b)//�ݹ鷨����
{
    int c;
    if(a<b)//ʹa>b
    {
        c=a;a=b;b=c;//��֤a���
    }
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return GCD_4_YZY(a-b,b);//���صݹ�
    }
}
