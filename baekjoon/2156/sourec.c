#include <stdio.h>

int max(int a, int b, int c){
    int d = a > b ? a : b;
    return c > d ? c : d;
}

int main(void){
    int n;
    int nn[10010];
    int dp[10010][3] = {0};
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &nn[i]);
    }
    dp[1][1] = nn[1];
    for(int i=2;i<=n;i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
        dp[i][1] = max(dp[i-1][0]+nn[i], dp[i-2][0]+nn[i], 0);
        dp[i][2] = max(dp[i-1][1]+nn[i], dp[i-2][0]+nn[i-1]+nn[i], 0);
    }
    printf("%d", max(dp[n][0], dp[n][1], dp[n][2]));
    return 0;
}
