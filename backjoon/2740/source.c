#include <stdio.h>

int main(void){
    int N, M, K, nm[110][110], mk[110][110], nk[110][110] = {0};
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){ for(int j=0;j<M;j++) scanf("%d", &nm[i][j]); }
    scanf("%d %d", &M, &K);
    for(int i=0;i<M;i++){ for(int j=0;j<K;j++) scanf("%d", &mk[i][j]); }
    for(int i=0;i<N;i++){ for(int j=0;j<K;j++){ for(int k=0;k<M;k++) nk[i][j] += nm[i][k]*mk[k][j]; } }
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++) printf("%d ", nk[i][j]);
        printf("\n");
    }
    return 0;
}
