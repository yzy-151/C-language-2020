/*********************
**文件名：学生成绩管理系统3.0
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

    long score[N][S],scorecopy[N][S];//学生分数与备份
    long id[N],idcopy[N];//学号与备份
    char name[N][NAME],namecopy[N][NAME];//学生姓名与备份
    long rank[N];//排名
    long subjecttotal[S];//单个科目的总分
    float subjectaver[S];//单个科目的平均分
    long studenttotal[N];//单个学生的所有科目总分
    float studentaver[N];//单个学生的所有科目平均分

    int stu__num;//学生数量
    int course_num;//科目数量
    int choose;//选择菜单的变量
    int finish=0;//控制菜单循环的变量
    int Input=0;//控制菜单入口
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
            int i,j;//循环计数器
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
            //植入排名数组
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
            int i2,j2;//循环计数器
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
** 函数名:Inpute
** 输 入: long id[],long score[][S],char name[][NAME]，int *p,int *course_num
** id---学号
** score[i][j]---第i个学生的第j门课的成绩
** name---姓名
** 功能描述:输入学号，成绩，姓名。
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
************************************/

void Inpute(long id[],long score[][S],char name[][NAME],int *p,int *course_num)
//输入学生学号和成绩，名字.
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
            //输入不在范围内则终止程序
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
** 函数名:TotalStudent
** 输 入: long score[][S],int n,int k,long studenttotal[],float studentaver[]
** n---学生人数
** score---成绩
** studenttotal---单个学生总分
** studentaverage---单个学生平均分
** 功能描述:计算单个学生的平均分和总分
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
************************************/

void TotalStudent(long score[][S],int n,int k,long studenttotal[],float studentaver[] )
//计算总分和平均分
{
    int i,j;
    //循环计算总分
    for(i=0; i<=n-1; i++)
    {
        studenttotal[i]=0;
        for(j=0; j<=k-1; j++)
        {
            studenttotal[i]=studenttotal[i]+score[i][j];
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
** 输 入: long score[][S],int n,int k，long subjecttotal[],float subjectaver[]
** n---学生人数
** k---科目数量
** score[]---科目成绩
** subjecttotal---某个总分
** subjectaverage---某个科目平均分
** 功能描述:计算每门课程的平均分和总分
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
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
    //排版输出
    printf("subject\ttotal\taverage\n");
    for(i=0; i<=k-1; i++)
    {
        printf("sub.%-3d\t%-5ld\t%-7.1f\n",i+1,subjecttotal[i],(float)subjecttotal[i]/n);
    }
}
/**********************************
** 函数名:SelectRank
** 输 入:int (*f)(long a,long b),long score[],long id[],int n,char name[][NAME],long rank[]
** （*f）---函数指针，可以是ascending或者descending
** score---成绩
** id---学号
** n---学生人数
** name---学生姓名
** rank---学生排名
** 功能描述:实现升序或降序排列，并在升序排列时给出排名
** 调用模块:acending函数，decending函数
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
************************************/
void SelectRank(int (*f)(long a,long b),long studenttotal[],long id[],int n,int k,char name[][NAME],long rank[],long score[][S])
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
                Swap(&studenttotal[i],&studenttotal[j],&id[i],&id[j],name[i],name[j],&rank[i],&rank[j]);
                for(s=0; s<=k-1; s++)
                {
                    //交换二维数组的内容
                    temp=score[i][s];
                    score[i][s]=score[j][s];
                    score[j][s]=temp;
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
** 版本3.0
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
** 版本3.0
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
** 输 入: long id[],long score[],int n,char name[][NAME],long rank[]
** n---学生人数
** score---成绩
** name---姓名
** rank---排名
** 功能描述:打印成绩表格
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
************************************/
void Outpute(long id[],long score[][S],int n,int k,char name[][NAME],long rank[],long studenttotal[],float studentaver[])
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
        printf("%-4ld\t%-8s\t%-5ld\t%-5ld\t%-16.1f",rank[i],name[i],id[i],studenttotal[i],studentaver[i]);
        for(i3=0; i3<=k-1; i3++)
        {
            printf("%-5ld\t",score[i][i3]);
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
** 版本3.0
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
** 输 入: long id[],long score[],int n,char name[][NAME],long rank[]
** n---学生人数
** score---成绩
** name---姓名
** rank---排名
** 功能描述:按照输入的id穷举法查找学生
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
************************************/
void SearchId(long score[],long id[],int n,char name[][NAME],long rank[])
//按照学号查询学生的成绩
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
** 函数名:SearchName
** 输 入: long id[],long score[],int n,char name[][NAME],long rank[]
** n---学生人数
** score---成绩
** name---姓名
** rank---排名
** 功能描述:按照输入的姓名穷举法查找学生
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
************************************/
void SearchName(long score[],long id[],int n,char name[][NAME],long rank[])
//按照姓名查询学生的成绩
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
** 函数名:Analysis
** 输 入:long score[],long id[],int n
** n---学生人数
** score---成绩
** id---学号
** 功能描述:针对不同科目按照五个分数段将学生分成ABCDE五个段并且计算每段的人数和比例
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
************************************/
void Analysis(long score[][S],long id[],int n,int k)
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
** 输 入:long id[],long score[],char name[][NAME],int n,long rank[]
** score---成绩
** id---学号
** n---学生人数
** name---学生姓名
** rank---学生排名
** 功能描述:按照名字在字典中的排序给出排名。
** 调用模块:
** 作 者:袁振洋
** 日 期:11.06
** 版本3.0
************************************/
void Rankname(long id[],long score[],char name[][NAME],int n,long rank[])
//名称按照字典排序
{
    int i,j;
    //循环计数器
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
