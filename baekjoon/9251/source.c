#include <stdio.h>
#include <string.h>

char a[1010], b[1010];
int dp[1010][1010] = {0};

int main(void){
    scanf("%s %s", a+1, b+1);
    int n = strlen(a+1);
    int m = strlen(b+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j];
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}
