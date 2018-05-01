#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, M, min = 0, max = 0;
        scanf("%d %d", &N, &M);
        for(int i=0;i<N;i++){
            int tsum1 = 0, tsum2 = 0;
            for(int j=0;j<M;j++){
                int tmin, tmax;
                scanf("%d %d", &tmin, &tmax);
                tsum1 += tmin;
                tsum2 += tmax;
            }
            min = min < tsum1 ? tsum1 : min;
            max = max < tsum2 ? tsum2 : max;
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}
