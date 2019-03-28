#include <stdio.h>

int min(int a, int b){
    return a > b ? b : a;
}

int main(void){
    int n;
    int col[1010][3];
    int dp[1010][3];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d", &col[i][0], &col[i][1], &col[i][2]);
    }
    dp[0][0] = col[0][0];
    dp[0][1] = col[0][1];
    dp[0][2] = col[0][2];
    for(int i=1;i<n;i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + col[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + col[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + col[i][2];
    }
    printf("%d", min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]));
    return 0;
}
