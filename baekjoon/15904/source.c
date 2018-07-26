#include <stdio.h>

int main(void){
    char s;
    int f = 0;
    s = getchar();
    while(s!=EOF){
        switch(f){
            case 0:
                if(s=='U') f = 1;
                break;
            case 1:
                if(s=='C') f = 2;
                break;
            case 2:
                if(s=='P') f = 3;
                break;
            case 3:
                if(s=='C') f = 4;
                break;
        
        }
        s = getchar();
    }
    if(f==4) printf("I love UCPC");
    else printf("I hate UCPC");
    return 0;
}
