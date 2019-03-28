#include <stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        int nn[100010][2];
        int dp[100010][2] = {0};
        scanf("%d", &n);
        for(int i=0;i<2;i++){
            for(int j=1;j<=n;j++){
                scanf("%d", &nn[j][i]);
            }
        }
        dp[1][0] = nn[1][0];
        dp[1][1] = nn[1][1];
        for(int i=2;i<=n;i++){
            dp[i][0] = nn[i][0] + max(dp[i-1][1], max(dp[i-2][0], dp[i-2][1]));
            dp[i][1] = nn[i][1] + max(dp[i-1][0], max(dp[i-2][0], dp[i-2][1]));
        }
        printf("%d\n", max(max(dp[n][0], dp[n][1]), max(dp[n-1][0], dp[n-1][1])));
    }
    return 0;
}
