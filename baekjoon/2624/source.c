#include <stdio.h>

int main(void){
    int t, k;
    int p[110], n[110];
    int dp[10010] = {0};
    dp[0] = 1;
    scanf("%d %d", &t, &k);
    for(int i=0;i<k;i++){
        scanf("%d %d", &p[i], &n[i]);
    }
    for(int i=0;i<k;i++){
        for(int j=t-p[i];j>=0;j--){
            if(!dp[j]) continue;
            for(int q=1;q<=n[i];q++){
                if(j+p[i]*q>t) break;
                dp[j+p[i]*q] += dp[j];
            }
        }
    }
    printf("%d", dp[t]);
    return 0;
}
