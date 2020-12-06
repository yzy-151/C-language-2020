#include <stdio.h>
#include <stdlib.h>

int main()
{   int exit=0;
    int one,two,five;
    int x;
    printf("inpute x yuan:\n");
    scanf("%d",&x);
    for(one=1;one<=x*10;one++){
        for(two=1;two<=x*5;two++){
            for(five=1;five<=x*2;five++){
                if(one*1+two*2+five*5==x*10){
                    printf("one=%d,two=%d,five=%d form %d yuan\n",one,two,five,x);
                    exit=1;
                    break;
                }
                if(exit) break;
            }
            if(exit) break;
        }
        if(exit) break;
    }
}
