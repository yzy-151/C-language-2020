#include <stdio.h>
#include <stdlib.h>

int main()
{
    char   a;//�����ַ�
    int    b;
    short int c;
    float  d;
    double e;
    printf("Number:20021012\nSubjet No.1 Project No.1\n\n");

    printf("inpute char a:\n");
    scanf("%c",&a);
    printf("char a=%c,size char=%d\n\n",a,sizeof(char));
    //char����

    printf("inpute int b:\n");
    scanf("%d",&b);
    printf("int b=%d,size int=%d\n\n",b,sizeof(int));
    //int����

    printf("inpute short c:\n");
    scanf("%hd",&c);
    printf("short c=%d,size short=%d\n\n",c,sizeof(short int));
    //short����

    printf("inpute float d:\n");
    scanf("%f",&d);
    printf("float d=%f,size float=%d\n\n",d,sizeof(float));
    //float����

    printf("inpute double e:\n");
    scanf("%lf",&e);
    printf("double f=%f,size double=%d\n\n",e,sizeof(double));
    //double����
     return 0;


}
