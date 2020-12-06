#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum;
    int k;
    int counter=0;
    int m,n;
    int i;
    printf("inpute m and n:\n");
    scanf("%d%*c%d",&m,&n);
    for(i=m;i<=n;i++){
    //ÅĞ¶ÏÊÇ·ñËØÊı
    int find=1;
       for(k=2;k<i;k++){
        if(0==i%k){
            find=0;
            break;
          }
       }
       if(find){
        counter++;
        sum=sum+i;
        printf("the %d th primenumber is %d\n",counter,i);
       }
    }
    printf("sum=%d,number=%d\n",sum,counter);
}
