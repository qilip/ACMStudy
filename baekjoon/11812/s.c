#include <stdio.h>

int main(void){
    long long N;
    int K, Q;
    scanf("%lld %d %d", &N, &K, &Q);
    for(int i=0;i<Q;i++){
        long long x, y, tmp, nn=0, xlev = 0;
        scanf("%lld %lld", &x ,&y);
        if( K == 1 ){
            printf("%lld\n", y>x ? y-x : x-y );
            continue;
        }
        while(!(x==y)){
            if(x<y){
                y = (y-2)/K + 1;
                nn++;
            }
            if(x>y){
                x = (x-2)/K + 1;
                nn++;
            }
        }
        printf("%lld\n", nn);
    }
    return 0;
}
