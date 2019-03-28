#include <stdio.h>

int main(void){
    int n;
    int p[1010];
    int dp[1010] = {0};
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &p[i]);
    }
    for(int i=1;i<=n;i++){
        if(dp[i] < p[i]) dp[i] = p[i];
        for(int j=i;j<=n;j++){
            if(dp[j] < dp[j-i]+p[i])
                dp[j] = dp[j-i] + p[i];
        }
    }
    printf("%d", dp[n]);
    return 0;
}
