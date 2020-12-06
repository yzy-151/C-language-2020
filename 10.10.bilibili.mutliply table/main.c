#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,j;
    for(r=1;r<=9;r++){
        for(j=1;j<=r;j++){
            printf("%d*%d=%d\t",j,r,r*j);
            if(r==j) printf("\n");
        }
    }
}
