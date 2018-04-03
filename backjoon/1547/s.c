#include <stdio.h>

int main(void){
    int M, a, b, bb[4] = { 0, 1, 0, 0 };
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        int tmp = bb[a];
        bb[a] = bb[b];
        bb[b] = tmp;
    }
    for(int i=1;i<=3;i++){
        if(bb[i]==1){
            printf("%d", i);
        }
    }
    return 0;
}
