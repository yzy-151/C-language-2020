/*********************
**�ļ�����ѧ���ɼ�����ϵͳ4.0
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
typedef struct student
{
    long studentID;
    char studentName[NAME];
    long score[S];
    long rank;
} STUDENT;
void TotalSubject(int n,int k,long subjecttotal[],float subjectaver[],STUDENT student[]);
void Inpute(STUDENT student[],int *p,int *course_num);
void TotalStudent(int n,int k,long studenttotal[],float studentaver[],STUDENT student[]);
void SelectRank(int (*f)(long a,long b),long studenttotal[],int n,int k,STUDENT student[]);
int Descending(long a,long b);
int Ascending(long a,long b);
void Swap(long *a,long *b,long *c,long *d,char*e,char*f,long *g,long*h);
void Outpute(int n,int k,long studenttotal[],float studentaver[],STUDENT student[]);
void Menu();
void SearchId(long score[],int n, STUDENT student[]);
void Analysis(int n,int k,STUDENT student[]);
void Rankname(long score[],int n,STUDENT student[]);
void SearchName(long score[],int n,STUDENT student[]);



int main()
{
    printf("Number:200210122\nSubject No.8   Project No.1\n");
    printf("Student achievement management system v4.0\n\n");
    STUDENT student[30];
    STUDENT studentcopy[30];
    long subjecttotal[S];//������Ŀ���ܷ�
    float subjectaver[S];//������Ŀ��ƽ����
    long studenttotal[N];//����ѧ�������п�Ŀ�ܷ�
    float studentaver[N];//����ѧ�������п�Ŀƽ����
    int Input=0;//�ж��Ƿ��Ѿ�����ѧ����Ϣ
    int stu__num;//ѧ������
    int course_num;//��Ŀ����
    int choose;//ѡ��˵��ı���
    int finish=0;//���Ʋ˵�ѭ���ı���
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
            printf("1.inpute record\n");
            Inpute(student,&stu__num,&course_num);
            //������������
            int i;
            for(i=0; i<=stu__num-1; i++)
            {
                studentcopy[i]=student[i];
            }
            Input=1;
            printf("----------------------------------------------------------------\n");
            break;
        case 2:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("2.caculate total and average score of every course\n");
            TotalSubject(stu__num,course_num,subjecttotal,subjectaver,student);
            printf("----------------------------------------------------------------\n");
            break;
        case 3:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("3.caculate total and average score of every student\n");
            TotalStudent(stu__num,course_num,studenttotal,studentaver,student);
            printf("----------------------------------------------------------------\n");
            break;
        case 4:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("4.sort in descending order by score of every student\n");
            SelectRank(Descending,studenttotal,stu__num,course_num,student);
            //ֲ����������
            int counter2;
            for(counter2=0; counter2<=stu__num-1; counter2++)
            {
                student[counter2].rank=counter2+1;
            }
            Outpute(stu__num,course_num,studenttotal,studentaver,student);
            printf("----------------------------------------------------------------\n");
            break;
        case 5:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("5.sort in ascending order by score of every student\n");
            SelectRank(Ascending,studenttotal,stu__num,course_num,student);
            Outpute(stu__num,course_num,studenttotal,studentaver,student);
            printf("----------------------------------------------------------------\n");
            break;
        case 6:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("6.sort in descending order by number\n");
            SelectRank(Descending,studenttotal,stu__num,course_num,student);
            Outpute(stu__num,course_num,studenttotal,studentaver,student);
            printf("----------------------------------------------------------------\n");
            break;
        case 7:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("7.sort in ditionary order by name\n");
            Rankname(studenttotal,stu__num,student);
            Outpute(stu__num,course_num,studenttotal,studentaver,student);
            printf("----------------------------------------------------------------\n");
            break;
        case 8:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("8.serrch by number\n");
            SearchId(studenttotal,stu__num,student);
            printf("----------------------------------------------------------------\n");
            break;
        case 9:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("9.search by name\n");
            SearchName(studenttotal,stu__num,student);
            printf("----------------------------------------------------------------\n");
            break;
        case 10:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("10.statistic analysis for every course!\n");
            Analysis(stu__num,course_num,student);
            printf("----------------------------------------------------------------\n");
            break;
        case 11:
            if(Input==0)
            {
                printf("please int information first!\n");
                break;
            }
            printf("11.list record\n");
            //�ָ����ݣ���ʾ��������
            int i2;
            for(i2=0; i2<=stu__num; i2++)
            {
                student[i2]=studentcopy[i2];
                student[i2].rank=i2+1;
            }
            Outpute(stu__num,course_num,studenttotal,studentaver,student);
            printf("----------------------------------------------------------------\n");
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
** �� ��: STUDENT student[],int *p,int *course_num
** id---ѧ��
** student---����ÿ��ѧ��������������ѧ�ţ������Ľṹ��
** name---����
** ��������:����ѧ�ţ��ɼ���������
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾4.0
************************************/

void Inpute(STUDENT student[],int *p,int *course_num)
//����ѧ��ѧ�źͳɼ�������.
{

    int i,j;
    for(i=0; i<=*p-1; i++)
    {
        printf("inpute ID:");
        scanf("%ld",&student[i].studentID);
        printf("inpute score(0~100):\n");
        for(j=0; j<=*course_num-1; j++)
        {
            scanf("%ld",&student[i].score[j]);
            //���벻�ڷ�Χ������ֹ����
            if(student[i].score[j]<0||student[i].score[j]>100)
            {
                printf("error!\n\n\n");
                j=j-1;
                continue;
            }

        }
        printf("inpute name:");
        getchar();
        gets(student[i].studentName);
    }
}

/**********************************
** ������:TotalStudent
** �� ��: int n,int k,long studenttotal[],float studentaver[],STUDENT student[]
** n---ѧ������
** student---����ÿ��ѧ��������������ѧ�ţ������Ľṹ��
** studenttotal---����ѧ���ܷ�
** studentaverage---����ѧ��ƽ����
** ��������:���㵥��ѧ����ƽ���ֺ��ܷ�
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾4.0
************************************/

void TotalStudent(int n,int k,long studenttotal[],float studentaver[],STUDENT student[] )
//�����ֺܷ�ƽ����
{
    int i,j;
    //ѭ�������ܷ�
    for(i=0; i<=n-1; i++)
    {
        studenttotal[i]=0;
        for(j=0; j<=k-1; j++)
        {
            studenttotal[i]=studenttotal[i]+student[i].score[j];
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
** �� ��: int n,int k,long subjecttotal[],float subjectaver[],STUDENT student[]
** n---ѧ������
** k---��Ŀ����
** score[]---��Ŀ�ɼ�
** subjecttotal---ĳ���ܷ�
** subjectaverage---ĳ����Ŀƽ����
** ��������:����ÿ�ſγ̵�ƽ���ֺ��ܷ�
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾4.0
************************************/

void TotalSubject(int n,int k,long subjecttotal[],float subjectaver[],STUDENT student[])
{
    int i,j;
    for(i=0; i<=k-1; i++)
    {
        subjecttotal[i]=0;
        for(j=0; j<=n-1; j++)
        {
            subjecttotal[i]=subjecttotal[i]+student[j].score[i];
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
** �� ��:int (*f)(long a,long b),long studenttotal[],int n,int k,STUDENT student[]
** ��*f��---����ָ�룬������ascending����descending
** student[]����������ѧ�ţ������������Ľṹ��
** ��������:ʵ������������У�������������ʱ��������
** ����ģ��:acending������decending����
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
void SelectRank(int (*f)(long a,long b),long studenttotal[],int n,int k,STUDENT student[])
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
                Swap(&studenttotal[i],
                     &studenttotal[j],
                     &student[i].studentID,
                     &student[j].studentID,
                     student[i].studentName,
                     student[j].studentName,
                     &student[i].rank,
                     &student[j].rank);
                for(s=0; s<=k-1; s++)
                {
                    //������ά���������
                    temp=student[i].score[s];
                    student[i].score[s]=student[j].score[s];
                    student[j].score[s]=temp;
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
** �汾4.0
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
** �汾4.0
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
** �� ��:int n,int k,long studenttotal[],float studentaver[],STUDENT student[]
** student[]�ṹ��
** ��������:��ӡ�ɼ����
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾4.0
************************************/
void Outpute(int n,int k,long studenttotal[],float studentaver[],STUDENT student[])
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
        printf("%-4ld\t%-8s\t%-5ld\t%-5ld\t%-16.1f",
               student[i].rank,
               student[i].studentName,
               student[i].studentID,
               studenttotal[i],
               studentaver[i]);
        for(i3=0; i3<=k-1; i3++)
        {
            printf("%-5ld\t",student[i].score[i3]);
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
** �汾4.0
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
** �� ��: SearchId(long score[],int n, STUDENT student[]
** student[]�ṹ��
** ��������:���������id��ٷ�����ѧ��
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
void SearchId(long score[],int n, STUDENT student[])
//����ѧ�Ų�ѯѧ���ĳɼ�
{
    long idsearch,i;
    int find=0;
    printf("inpute ID:");
    scanf("%ld",&idsearch);
    for(i=0; i<=n-1; i++)
    {
        if(idsearch==student[i].studentID)
        {
            printf("Rank\tNAME    \tID        score\n");
            printf("%-4ld\t%-8s\t%-8ld  %ld\n",student[i].rank,student[i].studentName,student[i].studentID,score[i]);
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
** �� ��: SearchName(long score[],int n,STUDENT student[]
** student�����ṹ��
** ��������:���������������ٷ�����ѧ��
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾3.0
************************************/
void SearchName(long score[],int n,STUDENT student[])
//����������ѯѧ���ĳɼ�
{
    char name2[NAME];//name2Ϊ��������ɼ�
    long i;
    int find=0;
    printf("inpute name:");
    scanf("%s",name2);
    for(i=0; i<=n-1; i++)
    {
        if(strcmp(name2,student[i].studentName)==0)
        {
            printf("Rank\tNAME    \tID        score\n");
            printf("%-4ld\t%-8s\t%-8ld  %ld\n",
                   student[i].rank,
                   student[i].studentName,
                   student[i].studentID,
                   score[i]);
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
** �� ��:int n,int k,STUDENT student[]
** student�����ṹ��
** ��������:��Բ�ͬ��Ŀ������������ν�ѧ���ֳ�ABCDE����β��Ҽ���ÿ�ε������ͱ���
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾4.0
************************************/
void Analysis(int n,int k,STUDENT student[])
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
            if(student[i].score[i2]>=90&&student[i].score[i2]<=100)
            {
                counter[0]++;
            }
            else if(student[i].score[i2]>=80&&student[i].score[i2]<=89)
            {
                counter[1]++;
            }
            else if(student[i].score[i2]>=70&&student[i].score[i2]<=79)
            {
                counter[2]++;
            }
            else if(student[i].score[i2]>=60&&student[i].score[i2]<=69)
            {
                counter[3]++;
            }
            else if(student[i].score[i2]>=0&&student[i].score[i2]<=59)
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
** �� ��:long score[],int n,STUDENT student[]�����scoreʵ�������ܷ�total
** student�����ṹ��
** ��������:�����������ֵ��е��������������
** ����ģ��:
** �� ��:Ԭ����
** �� ��:11.06
** �汾4.0
************************************/
void Rankname(long score[],int n,STUDENT student[])
//���ư����ֵ�����
{
    int i,j;
    //ѭ��������
    for(i=0; i<=n-1; i++)
    {
        for(j=i+1; j<=n-1; j++)
        {
            if(strncmp(student[i].studentName,student[j].studentName,20)>0)
            {
                Swap(&score[i],
                     &score[j],
                     &student[i].studentID,
                     &student[j].studentID,
                     student[i].studentName,
                     student[j].studentName,
                     &student[i].rank,&student[j].rank);
            }
        }
    }
}
