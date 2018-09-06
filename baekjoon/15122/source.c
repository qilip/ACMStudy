#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int tn;
    S:;
    n++;
    tn = n;
    while(tn){
        if(tn%10==0){
            goto S;
        }
        tn/=10;
    }
    printf("%d", n);
    return 0;
}
