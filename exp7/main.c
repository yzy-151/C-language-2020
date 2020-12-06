/*********************
**�ļ�����ѧ���ɼ�����ϵͳ3.0
**�����ˣ�Ԭ����
**���ڣ�2020.11.06
**�������������������Ϳ�Ŀ������Ȼ����ݲ˵�ѡ����Ҫ�Ĺ��ܣ������������������1¼��ɼ��ٽ���˵�����ѡ��
**----------------------
********************/
#include <stdio.h>
#include <stdlib.h>
#define S 6
#define N 30
#define NAME 20
#include <string.h>
void TotalSubject(long score[][S],int n,int k,long subjecttotal[],float subjectaver[]);
void Inpute(long id[],long score[][S],char name[][NAME],int *p,int *course_num);
void TotalStudent(long score[][S],int n,int k,long studenttotal[],float studentaver[] );
void SelectRank(int (*f)(long a,long b),long studenttotal[],long id[],int n,int k,char name[][NAME],long rank[],long score[][S]);
int Descending(long a,long b);
int Ascending(long a,long b);
void Swap(long *a,long *b,long *c,long *d,char*e,char*f,long *g,long*h);
void Outpute(long id[],long score[][S],int n,int k,char name[][NAME],long rank[],long studenttotal[],float studentaver[]);
void Menu();
void SearchId(long score[],long id[],int n,char name[][NAME],long rank[]);
void Analysis(long score[][S],long id[],int n,int k);
void Rankname(long id[],long score[],char name[][NAME],int n,long rank[]);
void SearchName(long score[],long id[],int n,char name[][NAME],long rank[]);

int main()
{
    printf("Number:200210122\nSubject No.7   Project No.1\n");
    printf("Student achievement management system v3.0\n\n");

    long score[N][S],scorecopy[N][S];//ѧ�������뱸��
    long id[N],idcopy[N];//ѧ���뱸��
    char name[N][NAME],namecopy[N][NAME];//ѧ�������뱸��
    long rank[N];//����
    long subjecttotal[S];//������Ŀ���ܷ�
    float subjectaver[S];//������Ŀ��ƽ����
    long studenttotal[N];//����ѧ�������п�Ŀ�ܷ�
    float studentaver[N];//����ѧ�������п�Ŀƽ����

    int stu__num;//ѧ������
    int course_num;//��Ŀ����
    int choose;//ѡ��˵��ı���
    int finish=0;//���Ʋ˵�ѭ���ı���
    int Input=0;//���Ʋ˵����
   do
    {
        printf("inpute student number:");
        scanf("%d",&stu__num);
        printf("inpute course number:");
        scanf("%d",&course_num);
        if(stu__num>30||stu__num<=0||course_num>6||course_num<1)
        {
            printf("inpute error!\n-------------------------------------------------\n");
        }

    }while(stu__num>30||stu__num<=0||course_num>6||course_num<1);
    Menu();
    do
    {
        printf("please enter your choice:");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
            printf("\n");
            int i,j;//ѭ��������
            Input=1;
            printf("1.inpute record\n");
            Inpute(id,score,name,&stu__num,&course_num);
            for(i=0; i<=stu__num-1; i++)
            {
                idcopy[i]=id[i];
                strcpy(namecopy[i],name[i]);
                for(j=0; j<=course_num-1; j++)
                {
                    scorecopy[i][j]=score[i][j];
                }
            }
            printf("-----------------------------------------------------------------------------------------\n");
            break;
        case 2:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("2.caculate total and average score of every course\n");
            TotalSubject(score,stu__num,course_num,subjecttotal,subjectaver);
            printf("-----------------------------------------------------------------------------------------\n");
            break;
        case 3:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("3.caculate total and average score of every student\n");
            TotalStudent(score,stu__num,course_num,studenttotal,studentaver);
            printf("-----------------------------------------------------------------------------------------\n");
            break;
        case 4:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("4.sort in descending order by score of every student\n");
            SelectRank(Descending,studenttotal,id,stu__num,course_num,name,rank,score);
            //ֲ����������
            int counter2;
            for(counter2=0; counter2<=stu__num-1; counter2++)
            {
                rank[counter2]=counter2+1;
            }
            Outpute(id,score,stu__num,course_num,name,rank,studenttotal,studentaver);
            printf("-----------------------------------------------------------------------------------------\n");
            break;
        case 5:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("5.sort in ascending order by score of every student\n");
            SelectRank(Ascending,studenttotal,id,stu__num,course_num,name,rank,score);
            Outpute(id,score,stu__num,course_num,name,rank,studenttotal,studentaver);
            printf("-----------------------------------------------------------------------------------------\n");
            break;
        case 6:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("6.sort in descending order by number\n");
            SelectRank(Descending,id,studenttotal,stu__num,course_num,name,rank,score);
            Outpute(id,score,stu__num,course_num,name,rank,studenttotal,studentaver);
            printf("-----------------------------------------------------------------------------------------\n");
            break;
        case 7:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("7.sort in ditionary order by name\n");
            Rankname(id,studenttotal,name,stu__num,rank);
            Outpute(id,score,stu__num,course_num,name,rank,studenttotal,studentaver);
            printf("-----------------------------------------------------------------------------------------\n");
            break;
        case 8:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("8.serrch by number\n");
            SearchId(studenttotal,id,stu__num,name,rank);
            printf("-----------------------------------------------------------------------------------------\n");
            break;
        case 9:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("9.search by name\n");
            SearchName(studenttotal,id,stu__num,name,rank);
            printf("-----------------------------------------------------------------------------------------\n");
            break;
        case 10:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("10.statistic analysis for every course!\n");
            Analysis(score,id,stu__num,course_num);
            printf("-----------------------------------------------------------------------------------------\n");
            break;
        case 11:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            int i2,j2;//ѭ��������
            for(i2=0; i2<=stu__num-1; i2++)
            {
                id[i2]=idcopy[i2];
                strcpy(name[i],namecopy[i]);
                for(j2=0; j2<=course_num-1; j2++)
                {
                    score[i2][j2]=scorecopy[i2][j2];
                }
            }
            printf("11.list record\n");
            Outpute(id,score,stu__num,course_num,name,rank,studenttotal,studentaver);
            printf("-----------------------------------------------------------------------------------------\n");
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
** �� ��: long id[],long score[][S],char name[][NAME]��int *p,int *course_num
** id---ѧ��
** score[i][j]---��i��ѧ���ĵ�j�ſεĳɼ�
** name---����
** ��������:����ѧ�ţ��ɼ���������
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/

void Inpute(long id[],long score[][S],char name[][NAME],int *p,int *course_num)
//����ѧ��ѧ�źͳɼ�������.
{

    int i,j;
    for(i=0; i<=*p-1; i++)
    {
        printf("inpute ID:");
        scanf("%ld",&id[i]);
        printf("inpute score(0~100):\n");
        for(j=0; j<=*course_num-1; j++)
        {
            scanf("%ld",&score[i][j]);
            //���벻�ڷ�Χ������ֹ����
            if(score[i][j]<0||score[i][j]>100)
            {
                printf("error!\n\n\n");
                j=j-i;
                continue;
            }

        }
        printf("inpute name:");
        getchar();
        gets(name[i]);
    }
}

/**********************************
** ������:TotalStudent
** �� ��: long score[][S],int n,int k,long studenttotal[],float studentaver[]
** n---ѧ������
** score---�ɼ�
** studenttotal---����ѧ���ܷ�
** studentaverage---����ѧ��ƽ����
** ��������:���㵥��ѧ����ƽ���ֺ��ܷ�
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/

void TotalStudent(long score[][S],int n,int k,long studenttotal[],float studentaver[] )
//�����ֺܷ�ƽ����
{
    int i,j;
    //ѭ�������ܷ�
    for(i=0; i<=n-1; i++)
    {
        studenttotal[i]=0;
        for(j=0; j<=k-1; j++)
        {
            studenttotal[i]=studenttotal[i]+score[i][j];
        }
        studentaver[i]=(float)studenttotal[i]/k;
    }
    //�Ű��������
    printf("student\ttotal\taverage\n");
    for(i=0; i<=n-1; i++)
    {
        printf("stu.%-3d\t%-5ld\t%-7.1f\n",i+1,studenttotal[i],(float)studenttotal[i]/k);
    }
}
/**********************************
** ������:TotalSubject
** �� ��: long score[][S],int n,int k��long subjecttotal[],float subjectaver[]
** n---ѧ������
** k---��Ŀ����
** score[]---��Ŀ�ɼ�
** subjecttotal---ĳ���ܷ�
** subjectaverage---ĳ����Ŀƽ����
** ��������:����ÿ�ſγ̵�ƽ���ֺ��ܷ�
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/

void TotalSubject(long score[][S],int n,int k,long subjecttotal[],float subjectaver[])
{
    int i,j;
    for(i=0; i<=k-1; i++)
    {
        subjecttotal[i]=0;
        for(j=0; j<=n-1; j++)
        {
            subjecttotal[i]=subjecttotal[i]+score[j][i];
        }
        subjectaver[i]=(float)subjecttotal[i]/n;
    }
    //�Ű����
    printf("subject\ttotal\taverage\n");
    for(i=0; i<=k-1; i++)
    {
        printf("sub.%-3d\t%-5ld\t%-7.1f\n",i+1,subjecttotal[i],(float)subjecttotal[i]/n);
    }
}
/**********************************
** ������:SelectRank
** �� ��:int (*f)(long a,long b),long score[],long id[],int n,char name[][NAME],long rank[]
** ��*f��---����ָ�룬������ascending����descending
** score---�ɼ�
** id---ѧ��
** n---ѧ������
** name---ѧ������
** rank---ѧ������
** ��������:ʵ������������У�������������ʱ��������
** ����ģ��:acending������decending����
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
void SelectRank(int (*f)(long a,long b),long studenttotal[],long id[],int n,int k,char name[][NAME],long rank[],long score[][S])
//��������Ҫ���������
{
    int i,j,s,temp;
    //i��j��sΪ��������temp�����ڽ������м�ֵ
    for(i=0; i<=n-1; i++)
    {
        for(j=i+1; j<=n-1; j++)
        {
            if((*f)(studenttotal[j],studenttotal[i]))
            {
                //���ú��������ĸ���ַ��ֵ
                Swap(&studenttotal[i],&studenttotal[j],&id[i],&id[j],name[i],name[j],&rank[i],&rank[j]);
                for(s=0; s<=k-1; s++)
                {
                    //������ά���������
                    temp=score[i][s];
                    score[i][s]=score[j][s];
                    score[j][s]=temp;
                }

            }
        }
    }

}
/**********************************
** ������:Descending
** �� ��: a��b
** a---������ѧ�ţ�1
** b---������ѧ�ţ�2
** ��������:��a>bʱ����Ϊ��
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
int Descending(long a,long b)
//�䵱���򱻵��ú�����*f��
{
    if(a>b)
        return 1;
    else
        return 0;
}
/**********************************
** ������:Ascending
** �� ��: a��b
** a---������ѧ�ţ�1
** b---������ѧ�ţ�2
** ��������:��a<bʱ����Ϊ��
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
int Ascending(long a,long b)
//�䵱���򱻵��ú�����*f��
{
    if(a<b)
        return 1;
    else
        return 0;
}
/**********************************
** ������:Swap
** �� ��:long *a,long *b,long *c,long *d,char*e,char*f,long *g,long*h
** a---�ɼ�1
** b---�ɼ�2
** c---ѧ��1
** d---ѧ��2
** e---ѧ������1
** f---ѧ������2
** g---����1
** h---����2
** ��������:ͬ����������ѧ����ѧ�ţ�������������������������λ�á�
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
void Swap(long *a,long *b,long *c,long *d,char*e,char*f,long *g,long*h)
//����˸�ָ�룬�����ַ��������
{
    int temp1,temp2,temp4;
    char temp3[NAME];
    temp1=*a;
    *a=*b;
    *b=temp1;
    temp2=*c;
    *c=*d;
    *d=temp2;
    temp4=*g;
    *g=*h;
    *h=temp4;
    strcpy(temp3,e);
    strcpy(e,f);
    strcpy(f,temp3);
}
/**********************************
** ������:Outpute
** �� ��: long id[],long score[],int n,char name[][NAME],long rank[]
** n---ѧ������
** score---�ɼ�
** name---����
** rank---����
** ��������:��ӡ�ɼ����
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
void Outpute(long id[],long score[][S],int n,int k,char name[][NAME],long rank[],long studenttotal[],float studentaver[])
//�����ӡѧ����������
{
    //��ӡ��ͷ
    int i2,i3;//������
    printf("Rank\tNAME    \tID   \tSUM  \tAVERAGE  \t");
    for(i2=0; i2<=k-1; i2++)
    {
        printf("SUB.%d\t",i2+1);
    }
    printf("\n");

    //��ӡ������ѧ�źͳɼ�
    int i;
    for(i=0; i<=n-1; i++)
    {
        printf("%-4ld\t%-8s\t%-5ld\t%-5ld\t%-16.1f",rank[i],name[i],id[i],studenttotal[i],studentaver[i]);
        for(i3=0; i3<=k-1; i3++)
        {
            printf("%-5ld\t",score[i][i3]);
        }
        printf("\n");
    }

}
/**********************************
** ������: Menu
** �� ��:
** ��������:��ӡ�˵�
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
void Menu()
//��ӡ�˵�
{
    printf("1.inpute record\n");
    printf("2.caculate total and average score of every course\n");
    printf("3.caculate total and average score of every student\n");
    printf("4.sort in descending order by score of every student\n");
    printf("5.sort in ascending order by score of every student\n");
    printf("6.sort in descending order by number\n");
    printf("7.sort in ditionary order by name\n");
    printf("8.serrch by number\n");
    printf("9.search by name\n");
    printf("10.statistic analysis for every course!\n");
    printf("11.list record\n");
    printf("0.exit\n\n\n");

}
/**********************************
** ������:SearchId
** �� ��: long id[],long score[],int n,char name[][NAME],long rank[]
** n---ѧ������
** score---�ɼ�
** name---����
** rank---����
** ��������:���������id��ٷ�����ѧ��
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
void SearchId(long score[],long id[],int n,char name[][NAME],long rank[])
//����ѧ�Ų�ѯѧ���ĳɼ�
{
    long idsearch,i;
    int find=0;
    printf("inpute ID:");
    scanf("%ld",&idsearch);
    for(i=0; i<=n-1; i++)
    {
        if(idsearch==id[i])
        {
            printf("Rank\tNAME    \tID        score\n");
            printf("%-4ld\t%-8s\t%-8ld  %ld\n",rank[i],name[i],id[i],score[i]);
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
** ������:SearchName
** �� ��: long id[],long score[],int n,char name[][NAME],long rank[]
** n---ѧ������
** score---�ɼ�
** name---����
** rank---����
** ��������:���������������ٷ�����ѧ��
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
void SearchName(long score[],long id[],int n,char name[][NAME],long rank[])
//����������ѯѧ���ĳɼ�
{
    char name2[NAME];
    long i;
    int find=0;
    printf("inpute name:");
    scanf("%s",name2);
    for(i=0; i<=n-1; i++)
    {
        if(strcmp(name2,name[i])==0)
        {
            printf("Rank\tNAME    \tID        score\n");
            printf("%-4ld\t%-8s\t%-8ld  %ld\n",rank[i],name[i],id[i],score[i]);
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
** ��������:��Բ�ͬ��Ŀ������������ν�ѧ���ֳ�ABCDE����β��Ҽ���ÿ�ε������ͱ���
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
void Analysis(long score[][S],long id[],int n,int k)
//�������ݷ���
{
    int i,i2;
    //ѭ��������
    for(i2=0; i2<=k-1; i2++)
    {
        float counter[5]= {0};
        //����������������ÿ�������ε�����
        for(i=0; i<=n-1; i++)
        {
            //������������ε�����
            if(score[i][i2]>=90&&score[i][i2]<=100)
            {
                counter[0]++;
            }
            else if(score[i][i2]>=80&&score[i][i2]<=89)
            {
                counter[1]++;
            }
            else if(score[i][i2]>=70&&score[i][i2]<=79)
            {
                counter[2]++;
            }
            else if(score[i][i2]>=60&&score[i][i2]<=69)
            {
                counter[3]++;
            }
            else if(score[i][i2]>=0&&score[i][i2]<=59)
            {
                counter[4]++;
            }
            else
            {
                printf("Inpute error!again.\n");
            }
        }
        //�Ű����
        printf("    SUBJECT   NO.  %d\n",i2+1);
        printf("A ��%f     ratio��%.1f%%\n",counter[0],(counter[0]/n)*100);
        printf("B ��%f     ratio��%.1f%%\n",counter[1],(counter[1]/n)*100);
        printf("C ��%f     ratio��%.1f%%\n",counter[2],(counter[2]/n)*100);
        printf("D ��%f     ratio��%.1f%%\n",counter[3],(counter[3]/n)*100);
        printf("E ��%f     ratio��%.1f%%\n\n\n",counter[4],(counter[4]/n)*100);
    }

}
/**********************************
** ������:Rankname
** �� ��:long id[],long score[],char name[][NAME],int n,long rank[]
** score---�ɼ�
** id---ѧ��
** n---ѧ������
** name---ѧ������
** rank---ѧ������
** ��������:�����������ֵ��е��������������
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
void Rankname(long id[],long score[],char name[][NAME],int n,long rank[])
//���ư����ֵ�����
{
    int i,j;
    //ѭ��������
    for(i=0; i<=n-1; i++)
    {
        for(j=i+1; j<=n-1; j++)
        {
            if(strncmp(name[i],name[j],20)>0)
            {
                Swap(&score[i],&score[j],&id[i],&id[j],name[i],name[j],&rank[i],&rank[j]);
            }
        }
    }
}
