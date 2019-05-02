#include <stdio.h>

int main(void){
    int ans = 99999999, m = 0;
    int dp[2][5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            dp[m][i][j] = 99999999;
        }
    }
    dp[m][0][0] = 0;
    int add[5][5] = {
        {0, 2, 2, 2, 2},
        {0, 1, 3, 4, 3},
        {0, 3, 1, 3, 4},
        {0, 4, 3, 1, 3},
        {0, 3, 4, 3, 1}
    };
    while(1){
        int cur;
        m = !m;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                dp[m][i][j] = 99999999;
            }
        }
        scanf("%d", &cur);
        if(!cur){
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(ans > dp[!m][i][j]) ans = dp[!m][i][j];
                }
            }
            printf("%d", ans);
            break;
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(dp[m][cur][i] > dp[!m][j][i] + add[j][cur])
                    dp[m][cur][i] = dp[!m][j][i] + add[j][cur];
                if(dp[m][i][cur] > dp[!m][i][j] + add[j][cur])
                    dp[m][i][cur] = dp[!m][i][j] + add[j][cur];
            }
        }        
    }
    return 0;
}
