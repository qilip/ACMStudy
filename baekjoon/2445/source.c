#include <stdio.h>

int main(void){
    int N, m, y=0;
    scanf("%d", &N);
    m = N*2;
    for(int j=0;j<N;j++){
        y++;
        for(int k=0;k<y;k++) printf("*");
        for(int k=0;k<m-y*2;k++) printf(" ");
        for(int k=0;k<y;k++) printf("*");
        printf("\n");
    }
    for(int j=0;j<N;j++){
        y--;
        for(int k=0;k<y;k++) printf("*");
        for(int k=0;k<m-y*2;k++) printf(" ");
        for(int k=0;k<y;k++) printf("*");
        printf("\n");
    }
}
