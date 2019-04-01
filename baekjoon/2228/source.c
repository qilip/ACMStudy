#include <stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}

int main(void){
    int n, m;
    int dp[110][60] = {0};
    int sum[110] = {0};
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }
    for(int i=0;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = -9999999;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            for(int k=(j-1)*2;k<i;k++){
                dp[i][j] = max(dp[i][j], (k>0 ? dp[k-1][j-1] : 0) + sum[i] - sum[k]);
            }
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}
