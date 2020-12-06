/*********************
**文件名：学生成绩管理系统2.0
**创建人：袁振洋
**日期：2020.10.30
**描述：1输入成绩，学号，名称，排序，检索，列表
**----------------------
********************/
#include <stdio.h>
#include <stdlib.h>
#define N 30
#define NAME 20
#include <string.h>
int Inpute(long id[],long score[],char name[][NAME]);
void Total(long score[],int n,long *total,long *average );
void SelectRank(int (*f)(long a,long b),long score[],long id[],int n,char name[][NAME],long rank[]);
int Descending(long a,long b);
int Ascending(long a,long b);
void Swap(long *a,long *b,long *c,long *d,char*e,char*f,long*g,long*h);
void Outpute(long id[],long score[],int n,char[][NAME],long rank[]);
void Menu();
void SearchId(long score[],long id[],int n,char name[][NAME],long rank[]);
void Analysis(long score[],long id[],int n);
void Rankname(long id[],long score[],char name[][NAME],int n,long rank[]);
void SearchName(long score[],long id[],int n,char name[][NAME],long rank[]);
int main()
{
    printf("Number:200210122\nSubject No.6   Project No.1\n");
    printf("Student achievement management system v2.0\n\n");

    long score[N],scorecopy[N],n;//n代表学生最大人数
    long id[N],idcopy[N];
    long rank[N];
    long a,b,finish;//ab无用，只是让指针来指，finish是为了控制菜单循坏
    char name[N][NAME],namecopy[N][NAME];
    //定义变量，a,b是为了让average和total指针指到一i党的方向
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
            //stu_num为实际输入的学生人数
            int stu_num,i2;
            stu_num=Inpute(id,score,name);
            for(i2=0;i2<=stu_num-1;i2++)
            {
                scorecopy[i2]=score[i2];
                idcopy[i2]=id[i2];
                strcpy(namecopy[i2],name[i2]);
            }
            break;
        case 2:
            Total(score,stu_num,total,average);
            printf("The total score is %ld\nThe average score is %ld\n",*total,*average);
            break;
        case 3:
            SelectRank(Descending,score,id,stu_num,name,rank);
            int s;//计数器
            for(s=0;s<=stu_num-1;s++)
            {
                rank[s]=s+1;
            }
            Outpute(id,score,stu_num,name,rank);
            break;
        case 4:
            SelectRank(Ascending,score,id,stu_num,name,rank);
            Outpute(id,score,stu_num,name,rank);
            break;
        case 5:
            SelectRank(Descending,id,score,stu_num,name,rank);
            Outpute(id,score,stu_num,name,rank);
            break;
        case 6:
            Rankname(id,score,name,stu_num,rank);
            Outpute(id,score,stu_num,name,rank);
            break;
        case 7:
            SearchId(score,id,stu_num,name,rank);
            break;
        case 8:
            SearchName(score,id,n,name,rank);
            break;
        case 9:
            Analysis(score,id,stu_num);
            break;
        case 10:
            int i3;//计数器
            for(i3=0;i3<=stu_num-1;i3++)
            {
                score[i3]=scorecopy[i3];
                id[i3]=idcopy[i3];
                strcpy(name[i3],namecopy[i3]);
            }
            Outpute(id,score,stu_num,name,rank);
            Total(score,stu_num,total,average);
            break;
        case 11:
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
** 输 入: long id[],long score[],char name[][NAME]
** id---学号
** score---成绩
** name---姓名
** 功能描述:输入学号，成绩，姓名，返回学生人数，输入对多30人，当学号
和分数输入为负数时，程序终止，返回已输入的人数。
** 调用模块:
** 作 者:袁振洋
** 日 期:10.30
** 版本2.0
************************************/

int Inpute(long id[],long score[],char name[][NAME])
//输入学生学号和成绩名字，返回学生人数
{
    printf("please inpute the max number of students:\n");
    int n,i;
    i=-1;
    scanf("%d",&n);
    printf("you can inpute an unposive number(or>100) to stop it\n");
    if(n<=30&&n>0)
    {
        do
        {
            i++;
            //输入学号和分数
            printf("inpute ID:");
            scanf("%ld",&id[i]);
            printf("inpute score:");
            scanf("%ld",&score[i]);
            printf("inpute name:");
            gets(name[i]);
            gets(name[i]);
        }
        while(score[i]>0&&id[i]>0&&i<=n-2&&score[i]<=100);
        //通过输入负数和大于100的分数终止循环返回人数
    }
    else
    {
        printf("error!\n");
    }
    return i+1;
}
/**********************************
** 函数名:Total
** 输 入: long score[],int n,long *total,long *average
** n---学生人数
** score---成绩
** total---总分
** average---平均分
** 功能描述:计算平均分和总分
** 调用模块:
** 作 者:袁振洋
** 日 期:10.30
** 版本2.0
************************************/
void Total(long score[],int n,long *total,long *average )
//计算总分和平均分
{
    int i;
    //循环计算总分
    for(i=0; i<=n-1; i++)
    {
        *total=*total+score[i];
    }

    *average=*total/n;
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
** 日 期:10.30
** 版本2.0
************************************/
void SelectRank(int (*f)(long a,long b),long score[],long id[],int n,char name[][NAME],long rank[])
//按照输入要求进行排序
{
    int i,j;//循环计数器
    for(i=0; i<=n-1; i++)
    {
        for(j=i+1; j<=n-1; j++)
        {
            if((*f)(score[j],score[i]))
            {
                //调用函数交换四个地址的值
                Swap(&score[i],&score[j],&id[i],&id[j],name[i],name[j],&rank[i],&rank[j]);
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
** 日 期:10.30
** 版本2.0
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
** 日 期:10.30
** 版本2.0
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
** 日 期:10.30
** 版本2.0
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
** 日 期:10.30
** 版本2.0
************************************/
void Outpute(long id[],long score[],int n,char name[][NAME],long rank[])
//输出打印学号与分数表格
{
    //打印表头
    printf("Rank\tNAME    \tID        score\n");
    int i;

    //打印排名，学号和成绩
    for(i=0; i<=n-1; i++)
    {
        printf("%-4ld\t%-8s\t%-8ld  %ld\n",rank[i],name[i],id[i],score[i]);
    }
}
/**********************************
** 函数名: Menu
** 输 入:
** 功能描述:打印菜单
** 调用模块:
** 作 者:袁振洋
** 日 期:10.30
** 版本2.0
************************************/
void Menu()
//打印菜单
{
    printf("1.inpute record\n");
    printf("2.caculate total and average score and course\n");
    printf("3.sort in descending order by score\n");
    printf("4.sort in ascending order by score\n");
    printf("5.sort in anscending order by number\n");
    printf("6.sort in ditionary order by name\n");
    printf("7.serrch by number\n");
    printf("8.search by name\n");
    printf("9.statistic analysis!\n");
    printf("10.list record\n");
    printf("11.exit\n\n\n");

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
** 日 期:10.30
** 版本2.0
************************************/
void SearchId(long score[],long id[],int n,char name[][NAME],long rank[])
//按照学号查询学生的成绩
{
    long id2,i;
    int find=0;
    printf("inpute ID:");
    scanf("%ld",&id2);
    for(i=0; i<=n-1; i++)
    {
        if(id2==id[i])
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
** 日 期:10.30
** 版本2.0
************************************/
void SearchName(long score[],long id[],int n,char name[][NAME],long rank[])
//按照姓名查询学生的成绩
{
    char name2[NAME];
    long i;
    int find=0;
    printf("inpute name:");
    scanf("%s",name2);
    for(i=0;i<=n-1;i++)
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
** 功能描述:按照五个分数段将学生分成ABCDE五个段并且计算每段的人数和比例
** 调用模块:
** 作 者:袁振洋
** 日 期:10.30
** 版本2.0
************************************/
void Analysis(long score[],long id[],int n)
//进行数据分析
{
    int i;
    float a,b,c,d,e;//a优秀，b良好，c中等，d及格,e不及格
    a=b=c=d=e=0;
    for(i=0; i<=n-1; i++)
    {
        //计算各个分数段的人数
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
    printf("A ：%f     ratio：%f%%\n",a,(a/n)*100);
    printf("B ：%f     ratio：%f%%\n",b,(b/n)*100);
    printf("C ：%f     ratio：%f%%\n",c,(c/n)*100);
    printf("D ：%f     ratio：%f%%\n",d,(d/n)*100);
    printf("E ：%f     ratio：%f%%\n",e,(e/n)*100);
}
/**********************************
** 函数名:Rankname
** 输 入:long id[],long score[],char name[][NAME],int n,long rank[]
** score---成绩
** id---学号
** n---学生人数
** name---学生姓名
** rank---学生排名
** 功能描述:按照名字在字典中的排序给出排名
** 调用模块:
** 作 者:袁振洋
** 日 期:10.30
** 版本2.0
************************************/
void Rankname(long id[],long score[],char name[][NAME],int n,long rank[])
//名称按照字典排序
{
    int i,j;
    for(i=0;i<=n-1;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            if(strncmp(name[i],name[j],20)>0)
            {
                Swap(&score[i],&score[j],&id[i],&id[j],name[i],name[j],&rank[i],&rank[j]);
            }
            else
            {
                printf("no action!!\n");
            }
        }
    }
}
