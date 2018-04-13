#include <stdio.h>

int main(void){
    int N, K, nn[12], cnt = 0;
    scanf("%d %d", &N, &K);
    for(int i=0;i<N;i++){
        scanf("%d", &nn[i]);
    }
    for(int i=N-1;i>=0;i--){
        if(K==0) break;
        int tmp = K/nn[i];
        K -= tmp*nn[i];
        cnt += tmp;
    }
    printf("%d", cnt);
}
