#include <stdio.h>
#include <stdlib.h>

int main()
{
   char a;
   int counter;//���ѭ������
   int counter2;//�ڲ�ѭ������
   printf("Number:200210122\nSubject No.1 Project No.2\n");
   printf("inpute a words:\n");
   scanf("%c",&a);//����Сд��ĸ
   a=a-32;//����ת��Ϊ��д
   for(counter=1;counter<=8;counter++)//ѭ���˴Σ�������
   {
       if (counter%2==0)//ż�������һ���ո�
       {
            printf(" ");
       }
       for(counter2=1;counter2<=8;counter2++)//�ڲ�ѭ����8��
       {
           printf("%c ",a);
       }
       printf("\n");//��һ�дﵽ8��ʱ����


   }

   return 0;
}
