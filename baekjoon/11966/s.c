#include <stdio.h>

int main(void){
    int N, flg=0;
    scanf("%d", &N);
    while(N){
        if(N==1) break;
        if(N%2 != 0) {
            flg = 1;
            break;
        }
        N/=2;
    }
    if(flg) printf("0");
    else printf("1");
    return 0;
}
