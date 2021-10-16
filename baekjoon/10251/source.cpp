#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[110][110][210][2] = {0}; //m, n, k회전, d방향{0가로, 1세로} = 사용 연료량

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int m, n, l, g;
        int gr[110][110][2] = {0};
        scanf("%d %d %d %d", &m, &n, &l, &g);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n-1;j++){
                scanf("%d", &gr[i][j][0]);
            }
        }
        for(int i=1;i<=m-1;i++){
            for(int j=1;j<=n;j++){
                scanf("%d", &gr[i][j][1]);
            }
        }
        fill(&dp[0][0][0][0], &dp[0][0][0][0]+110*110*210*2, 9999'9999);
        dp[1][1][0][0] = dp[1][1][0][1] = 0;
        for(int i=1;i<=m-1;i++){
            dp[i+1][1][0][1] = gr[i][1][1] + dp[i][1][0][1];
        }
        for(int i=1;i<=n-1;i++){
            dp[1][i+1][0][0] = gr[1][i][0] + dp[1][i][0][0];
        }
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                int cmaxk = i > j ? j*2 : i*2;
                for(int k=1;k<=cmaxk;k++){
                    dp[i][j][k][0] = min(dp[i][j-1][k][0] + gr[i][j-1][0], dp[i][j-1][k-1][1] + gr[i][j-1][0]);
                    dp[i][j][k][1] = min(dp[i-1][j][k][1] + gr[i-1][j][1], dp[i-1][j][k-1][0] + gr[i-1][j][1]);
                }
            }
        }
        int ans = 9999'9999;
        int maxk = m > n ? n*2 : m*2;
        for(int i=1;i<=maxk;i++){
            if(dp[m][n][i][0] <= g || dp[m][n][i][1] <= g)
                ans = min(ans, (m+n-2)*l+i);
        }
        if(ans == 9999'9999) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
