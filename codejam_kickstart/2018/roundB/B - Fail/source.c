#include <stdio.h>

// only small set

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int N, K, out[110] = {0}, flg[110] = {0}, pp[110] = {0};
        long long P;
        scanf("%d %d %lld", &N, &K, &P);
        for(int i=0;i<K;i++){
            int A, B, C;
            scanf("%d %d %d", &A, &B, &C);
            out[A] = C; flg[A] = C;
        }
        int tmp = 0;
        for(long long i=P-1; i>0;i/=2){
            tmp++;
            pp[tmp] = i%2;
        }
        int cn = 0;
        for(int i=N;i>0;i--){
            if(cn>tmp) break;
            if(flg[i]) continue;
            cn++;
            out[i] = pp[cn];
        }

        printf("Case #%d: ", t);
        for(int i=1;i<=N;i++) printf("%d", out[i]);
        printf("\n");
    }
    return 0;
}
