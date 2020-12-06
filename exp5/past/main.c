/*********************
**�ļ�����ѧ���ɼ�����ϵͳ1.0
**�����ˣ�Ԭ����
**���ڣ�2020.10.28
**������1����ɼ������򣬼������б�
**----------------------
********************/
#include <stdio.h>
#include <stdlib.h>
#define N 30
int Inpute(long id[],long score[]);
void Total(long score[],int n,long *total,long *average );
void SelectRank(int (*f)(long a,long b),long score[],long id[],int n,long rank[]);
int Descending(long a,long b);
int Ascending(long a,long b);
void Swap(long *a,long *b,long *c,long *d,long *e,long*f);
void Outpute(long id[],long score[],int n,long rank[]);
void Menu();
void Search(long score[],long id[],int n,long rank[]);
void Analysis(long score[],long id[],int n);
int main()
{
    printf("Number:200210122\nSubject No.5   Project No.1\n");
    printf("Student achievement management system v1.0\n\n");

    long score[N],scorecopy[N],n;
    long rank[N];
    long id[N],idcopy[N];
    long a,b,finish;
    //���������a,b��Ϊ����average��totalָ��ָ��һi���ķ���
    finish=a=b=0;
    long*total, *average;
    total=&a;
    average=&b;

    Menu();
    do
    {
        printf("please enter your choice:");
        scanf("%ld",&n);
        switch(n)
        {
        case 1:
            printf(" ");
            //stu_numΪʵ�������ѧ������
            int stu_num,i2;//i2�Ǽ�����
            stu_num=Inpute(id,score);
            for(i2=0;i2<=stu_num-1;i2++)
            {
                scorecopy[i2]=score[i2];
                idcopy[i2]=id[i2];
            }
            break;
        case 2:
            Total(score,stu_num,total,average);
            printf("The total score is %ld\nThe average score is %ld\n",*total,*average);
            break;
        case 3:
            SelectRank(Ascending,score,id,stu_num,rank);
            int s;
            for(s=0;s<=stu_num-1;s++)
            {
                rank[s]=s+1;
            }
            Outpute(id,score,stu_num,rank);
            break;
        case 4:
            SelectRank(Descending,score,id,stu_num,rank);
            Outpute(id,score,stu_num,rank);
            break;
        case 5:
            SelectRank(Descending,id,score,stu_num,rank);
            Outpute(id,score,stu_num,rank);
            break;
        case 6:
            Search(score,id,stu_num,rank);
            break;
        case 7:
            Analysis(score,id,stu_num);
            break;
        case 8:
            int i3;
            for(i3=0;i3<=stu_num-1;i3++)
            {
                score[i3]=scorecopy[i3];
                id[i3]=idcopy[i3];
            }

            Outpute(id,score,stu_num,rank);
            Total(score,stu_num,total,average);
            break;
        case 0:
            return 0;
            break;
        default:
            printf("Invalid operater!\n");

        }
    }
    while(!finish);
}
/**********************************
** ������:Inpute
** �� ��: long id[],long score[]
** id---ѧ��
** score---�ɼ�
** ��������:����ѧ�ţ��ɼ�������ѧ������������Զ�30�ˣ���ѧ��
�ͷ�������Ϊ����ʱ��������ֹ�������������������
** ����ģ��:
** �� ��:Ԭ����
** �� ��:10.30
** �汾1.0
************************************/

int Inpute(long id[],long score[])
//����ѧ��ѧ�źͳɼ�������ѧ������
{
    printf("please inpute the max number of students:\n");
    int n,i;//nΪѧ������iΪ������
    i=-1;
    scanf("%d",&n);
    printf("you can inpute an unposive number(or>100) to stop it\n");
    if(n<=30&&n>0)
    {
        do
        {
            i++;
            //����ѧ�źͷ���
            printf("inpute ID:");
            scanf("%ld",&id[i]);
            printf("inpute score:");
            scanf("%ld",&score[i]);
        }
        while(score[i]>0&&id[i]>0&&i<=n-2&&score[i]<=100);
    }
    else
    {
        printf("error!\n");
    }
    return i+1;
}
/**********************************
** ������:Total
** �� ��: long score[],int n,long *total,long *average
** n---ѧ������
** score---�ɼ�
** total---�ܷ�
** average---ƽ����
** ��������:����ƽ���ֺ��ܷ�
** ����ģ��:
** �� ��:Ԭ����
** �� ��:10.30
** �汾1.0
************************************/
void Total(long score[],int n,long *total,long *average)
//�����ֺܷ�ƽ����
{
    int i;
    //ѭ�������ܷ�
    for(i=0; i<=n-1; i++)
    {
        *total=*total+score[i];
    }

    *average=*total/n;
}
/**********************************
** ������:SelectRank
** �� ��:int (*f)(long a,long b),long score[],long id[],int n,long rank[]
** ��*f��---����ָ�룬������ascending����descending
** score---�ɼ�
** id---ѧ��
** n---ѧ������
** rank---ѧ������
** ��������:ʵ������������У�������������ʱ��������
** ����ģ��:acending������decending����
** �� ��:Ԭ����
** �� ��:10.30
** �汾1.0
************************************/
void SelectRank(int (*f)(long a,long b),long score[],long id[],int n,long rank[])
//��������Ҫ���������
{
    int i,j;
    for(i=0; i<=n-1; i++)
    {
        for(j=i+1; j<=n-1; j++)
        {
            if((*f)(score[j],score[i]))
            {
                //���ú��������ĸ���ַ��ֵ
                Swap(&score[i],&score[j],&id[i],&id[j],&rank[i],&rank[j]);
            }
        }
    }

}
/**********************************
** ������:Ascending
** �� ��: a��b
** a---������ѧ�ţ�1
** b---������ѧ�ţ�2
** ��������:��a<bʱ����Ϊ��
** ����ģ��:
** �� ��:Ԭ����
** �� ��:10.30
** �汾1.0
************************************/
int Ascending(long a,long b)
//�䵱���򱻵��ú�����*f��
{
    if(a>b)
        return 1;
    else
        return 0;
}
/**********************************
** ������:Descending
** �� ��: a��b
** a---������ѧ�ţ�1
** b---������ѧ�ţ�2
** ��������:��a>bʱ����Ϊ��
** ����ģ��:
** �� ��:Ԭ����
** �� ��:10.30
** �汾1.0
************************************/
int Descending(long a,long b)
//�䵱���򱻵��ú�����*f��
{
    if(a<b)
        return 1;
    else
        return 0;
}
/**********************************
** ������:Swap
** �� ��:long *a,long *b,long *c,long *d,long *g,long*h
** a---�ɼ�1
** b---�ɼ�2
** c---ѧ��1
** d---ѧ��2
** e---����1
** f---����2
** ��������:ͬ����������ѧ����ѧ�ţ�������������������λ�á�
** ����ģ��:
** �� ��:Ԭ����
** �� ��:10.30
** �汾1.0
************************************/
void Swap(long *a,long *b,long *c,long *d,long *e,long*f)
//�����ĸ�ָ�룬�����ַ��������
{
    int temp1,temp2,temp3;
    temp1=*a;
    *a=*b;
    *b=temp1;
    temp2=*c;
    *c=*d;
    *d=temp2;
    temp3=*e;
    *e=*f;
    *f=temp3;
}
/**********************************
** ������:Outpute
** �� ��: long id[],long score[],int n,long rank[]
** n---ѧ������
** score---�ɼ�
** rank---����
** ��������:��ӡ�ɼ����
** ����ģ��:
** �� ��:Ԭ����
** �� ��:10.30
** �汾1.0
************************************/
void Outpute(long id[],long score[],int n,long rank[])
//�����ӡѧ����������
{
    //��ӡ��ͷ
    printf("Rank\tID        score\n");
    int i;

    //��ӡ������ѧ�źͳɼ�
    for(i=0; i<=n-1; i++)
    {
        printf("%-4ld\t%-8ld  %ld\n",rank[i],id[i],score[i]);
    }
}
/**********************************
** ������: Menu
** �� ��:
** ��������:��ӡ�˵�
** ����ģ��:
** �� ��:Ԭ����
** �� ��:10.30
** �汾2.0
************************************/
void Menu()
//��ӡ�˵�
{
    printf("1.inpute record\n");
    printf("2.caculate total and average score and course\n");
    printf("3.sort in descending order by score\n");
    printf("4.sort in ascending order by score\n");
    printf("5.sort in anscending order by number\n");
    printf("6.serrch by number\n");
    printf("7.statistic analysis!\n");
    printf("8.list record\n");
    printf("0.exit\n\n\n");

}
/**********************************
** ������:Search
** �� ��: long id[],long score[],int n,long rank[]
** n---ѧ������
** score---�ɼ�
** rank---����
** ��������:���������id��ٷ�����ѧ��
** ����ģ��:
** �� ��:Ԭ����
** �� ��:10.30
** �汾1.0
************************************/
void Search(long score[],long id[],int n,long rank[])
//����ѧ�Ų�ѯѧ���ĳɼ�
{
    long id2,i;
    int find=0;
    printf("inpute ID:");
    scanf("%ld",&id2);
    for(i=0; i<=n-1; i++)
    {
        if(id2==id[i])
        {
            printf("Rank\tID        score\n");
            printf("%-4ld\t%-8ld  %ld\n",rank[i],id[i],score[i]);
            find=1;
            break;
        }
    }
    if(!find)
    {
        printf("Not find!\n");
    }
}
/**********************************
** ������:Analysis
** �� ��:long score[],long id[],int n
** n---ѧ������
** score---�ɼ�
** id---ѧ��
** ��������:������������ν�ѧ���ֳ�ABCDE����β��Ҽ���ÿ�ε������ͱ���
** ����ģ��:
** �� ��:Ԭ����
** �� ��:10.30
** �汾1.0
************************************/
void Analysis(long score[],long id[],int n)
//�������ݷ���
{
    int i;
    float a,b,c,d,e;//a���㣬b���ã�c�еȣ�d����,e������
    a=b=c=d=e=0;
    for(i=0; i<=n-1; i++)
    {
        //������������ε�����
        if(score[i]>=90&&score[i]<=100)
        {
            a++;
        }
        else if(score[i]>=80&&score[i]<=89)
        {
            b++;
        }
        else if(score[i]>=70&&score[i]<=79)
        {
            c++;
        }
        else if(score[i]>=60&&score[i<=69])
        {
            d++;
        }
        else if(score[i]>=0&&score[i]<=59)
        {
            e++;
        }
        else
        {
            printf("Inpute error!again.\n");
            i--;
        }
    }
    printf("A ��%f     ratio��%f%%\n",a,(a/n)*100);
    printf("B ��%f     ratio��%f%%\n",b,(b/n)*100);
    printf("C ��%f     ratio��%f%%\n",c,(c/n)*100);
    printf("D ��%f     ratio��%f%%\n",d,(d/n)*100);
    printf("E ��%f     ratio��%f%%\n",e,(e/n)*100);
}
