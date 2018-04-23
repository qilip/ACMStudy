#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        long long F, L, cnt = 0;
        scanf("%lld %lld", &F, &L);
        for(long long i=F;i<=L;i++){
            int flg = 0;
            if(i%9==0) flg = 1;
            else{
                for(long long j=i;j>0;j/=10){
                    if(j%10==9){
                        flg = 1;
                        break;
                    }
                }
            }
            if(!flg) cnt++;
        }
        printf("Case #%d: %lld\n", t, cnt);
    }
    return 0;
}
