#include <stdio.h>

int main(void){
    int n;
    int MOD = 9901;
    int dp[100010][3] = {0};
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    scanf("%d", &n);
    for(int i=2;i<=n;i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%MOD;
    }
    printf("%d", (dp[n][0]+dp[n][1]+dp[n][2])%MOD);
    return 0;
}
