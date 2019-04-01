#include <stdio.h>

int main(void){
    int n;
    int nn[100010] = {0};
    int dp[100010][2] = {0};
    int max = -99999;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &nn[i]);
    }
    for(int i=1;i<=n;i++){
        if(dp[i-1][0] + nn[i] > nn[i]) dp[i][0] = dp[i-1][0] + nn[i];
        else dp[i][0] = nn[i];
        if(dp[i-1][1] + nn[i] > dp[i-2][0] + nn[i]) dp[i][1] = dp[i-1][1] + nn[i];
        else dp[i][1] = dp[i-2][0] + nn[i];
        if(max < dp[i][0]) max = dp[i][0];
        if(max < dp[i][1]) max = dp[i][1];
    }
    printf("%d", max);
    return 0;
}
