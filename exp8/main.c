/*********************
**文件名：学生成绩管理系统4.0
**创建人：袁振洋
**日期：2020.11.06
**描述：可以输入人数和科目数量，然后根据菜单选择需要的功能，但是请务必首先输入1录入成绩再进入菜单其他选项
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
    long subjecttotal[S];//单个科目的总分
    float subjectaver[S];//单个科目的平均分
    long studenttotal[N];//单个学生的所有科目总分
    float studentaver[N];//单个学生的所有科目平均分
    int Input=0;//判断是否已经输入学生信息
    int stu__num;//学生数量
    int course_num;//科目数量
    int choose;//选择菜单的变量
    int finish=0;//控制菜单循环的变量
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
            //备份输入数据
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
            //植入排名数组
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
            //恢复备份，显示输入数据
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
** 函数名:Inpute
** 输 入: STUDENT student[],int *p,int *course_num
** id---学号
** student---包含每个学生分数，排名，学号，姓名的结构体
** name---姓名
** 功能描述:输入学号，成绩，姓名。
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本4.0
************************************/

void Inpute(STUDENT student[],int *p,int *course_num)
//输入学生学号和成绩，名字.
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
            //输入不在范围内则终止程序
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
** 函数名:TotalStudent
** 输 入: int n,int k,long studenttotal[],float studentaver[],STUDENT student[]
** n---学生人数
** student---包含每个学生分数，排名，学号，姓名的结构体
** studenttotal---单个学生总分
** studentaverage---单个学生平均分
** 功能描述:计算单个学生的平均分和总分
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本4.0
************************************/

void TotalStudent(int n,int k,long studenttotal[],float studentaver[],STUDENT student[] )
//计算总分和平均分
{
    int i,j;
    //循环计算总分
    for(i=0; i<=n-1; i++)
    {
        studenttotal[i]=0;
        for(j=0; j<=k-1; j++)
        {
            studenttotal[i]=studenttotal[i]+student[i].score[j];
        }
        studentaver[i]=(float)studenttotal[i]/k;
    }
    //排版输出分数
    printf("student\ttotal\taverage\n");
    for(i=0; i<=n-1; i++)
    {
        printf("stu.%-3d\t%-5ld\t%-7.1f\n",i+1,studenttotal[i],(float)studenttotal[i]/k);
    }
}
/**********************************
** 函数名:TotalSubject
** 输 入: int n,int k,long subjecttotal[],float subjectaver[],STUDENT student[]
** n---学生人数
** k---科目数量
** score[]---科目成绩
** subjecttotal---某个总分
** subjectaverage---某个科目平均分
** 功能描述:计算每门课程的平均分和总分
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本4.0
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
    //排版输出
    printf("subject\ttotal\taverage\n");
    for(i=0; i<=k-1; i++)
    {
        printf("sub.%-3d\t%-5ld\t%-7.1f\n",i+1,subjecttotal[i],(float)subjecttotal[i]/n);
    }
}
/**********************************
** 函数名:SelectRank
** 输 入:int (*f)(long a,long b),long studenttotal[],int n,int k,STUDENT student[]
** （*f）---函数指针，可以是ascending或者descending
** student[]包含姓名，学号，分数，排名的结构体
** 功能描述:实现升序或降序排列，并在升序排列时给出排名
** 调用模块:acending函数，decending函数
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
************************************/
void SelectRank(int (*f)(long a,long b),long studenttotal[],int n,int k,STUDENT student[])
//按照输入要求进行排序
{
    int i,j,s,temp;
    //i，j，s为计数器，temp是用于交换的中间值
    for(i=0; i<=n-1; i++)
    {
        for(j=i+1; j<=n-1; j++)
        {
            if((*f)(studenttotal[j],studenttotal[i]))
            {
                //调用函数交换四个地址的值
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
                    //交换二维数组的内容
                    temp=student[i].score[s];
                    student[i].score[s]=student[j].score[s];
                    student[j].score[s]=temp;
                }

            }
        }
    }

}
/**********************************
** 函数名:Descending
** 输 入: a，b
** a---分数（学号）1
** b---分数（学号）2
** 功能描述:当a>b时返回为真
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本4.0
************************************/
int Descending(long a,long b)
//充当升序被调用函数（*f）
{
    if(a>b)
        return 1;
    else
        return 0;
}
/**********************************
** 函数名:Ascending
** 输 入: a，b
** a---分数（学号）1
** b---分数（学号）2
** 功能描述:当a<b时返回为真
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
************************************/
int Ascending(long a,long b)
//充当降序被调用函数（*f）
{
    if(a<b)
        return 1;
    else
        return 0;
}
/**********************************
** 函数名:Swap
** 输 入:long *a,long *b,long *c,long *d,char*e,char*f,long *g,long*h
** a---成绩1
** b---成绩2
** c---学号1
** d---学号2
** e---学生姓名1
** f---学生姓名2
** g---排名1
** h---排名2
** 功能描述:同步交换两个学生的学号，姓名，分数，排名，即交换位置。
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本4.0
************************************/
void Swap(long *a,long *b,long *c,long *d,char*e,char*f,long *g,long*h)
//输入八个指针，对其地址两两交换
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
** 函数名:Outpute
** 输 入:int n,int k,long studenttotal[],float studentaver[],STUDENT student[]
** student[]结构体
** 功能描述:打印成绩表格
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本4.0
************************************/
void Outpute(int n,int k,long studenttotal[],float studentaver[],STUDENT student[])
//输出打印学号与分数表格
{
    //打印表头
    int i2,i3;//计数器
    printf("Rank\tNAME    \tID   \tSUM  \tAVERAGE  \t");
    for(i2=0; i2<=k-1; i2++)
    {
        printf("SUB.%d\t",i2+1);
    }
    printf("\n");

    //打印排名，学号和成绩
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
** 函数名: Menu
** 输 入:
** 功能描述:打印菜单
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本4.0
************************************/
void Menu()
//打印菜单
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
** 函数名:SearchId
** 输 入: SearchId(long score[],int n, STUDENT student[]
** student[]结构体
** 功能描述:按照输入的id穷举法查找学生
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
************************************/
void SearchId(long score[],int n, STUDENT student[])
//按照学号查询学生的成绩
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
** 函数名:SearchName
** 输 入: SearchName(long score[],int n,STUDENT student[]
** student【】结构体
** 功能描述:按照输入的姓名穷举法查找学生
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
************************************/
void SearchName(long score[],int n,STUDENT student[])
//按照姓名查询学生的成绩
{
    char name2[NAME];//name2为键盘输入成绩
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
** 函数名:Analysis
** 输 入:int n,int k,STUDENT student[]
** student【】结构体
** 功能描述:针对不同科目按照五个分数段将学生分成ABCDE五个段并且计算每段的人数和比例
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本4.0
************************************/
void Analysis(int n,int k,STUDENT student[])
//进行数据分析
{
    int i,i2;
    //循环计数器
    for(i2=0; i2<=k-1; i2++)
    {
        float counter[5]= {0};
        //人数计数器，计算每个分数段的人数
        for(i=0; i<=n-1; i++)
        {
            //计算各个分数段的人数
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
        //排版输出
        printf("    SUBJECT   NO.  %d\n",i2+1);
        printf("A ：%f     ratio：%.1f%%\n",counter[0],(counter[0]/n)*100);
        printf("B ：%f     ratio：%.1f%%\n",counter[1],(counter[1]/n)*100);
        printf("C ：%f     ratio：%.1f%%\n",counter[2],(counter[2]/n)*100);
        printf("D ：%f     ratio：%.1f%%\n",counter[3],(counter[3]/n)*100);
        printf("E ：%f     ratio：%.1f%%\n\n\n",counter[4],(counter[4]/n)*100);
    }

}



/**********************************
** 函数名:Rankname
** 输 入:long score[],int n,STUDENT student[]这里的score实际上是总分total
** student【】结构体
** 功能描述:按照名字在字典中的排序给出排名。
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本4.0
************************************/
void Rankname(long score[],int n,STUDENT student[])
//名称按照字典排序
{
    int i,j;
    //循环计数器
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
