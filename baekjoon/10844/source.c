#include <stdio.h>

int main(void){
    int n;
    long long dp[110][10] = {0};
    int MOD = 1000000000;
    for(int i=1;i<=9;i++) dp[1][i] = 1;
    scanf("%d", &n);
    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][1]%MOD;
        for(int j=1;j<=8;j++){
            dp[i][j] = dp[i-1][j-1]%MOD + dp[i-1][j+1]%MOD;
        }
        dp[i][9] = dp[i-1][8]%MOD;
    }
    long long sum = 0;
    for(int i=0;i<=9;i++) sum += dp[n][i];
    printf("%d", (int)(sum%MOD));
    return 0;
}
