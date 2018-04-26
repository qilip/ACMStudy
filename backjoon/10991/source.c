#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    for(int i=1;i<=N;i++){
        for(int j=0;j<N-i;j++) printf(" ");
        printf("*");
        for(int j=2;j<=i;j++) printf(" *");
        printf("\n");
    }
}
