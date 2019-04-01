#include <stdio.h>
#include <string.h>

char a[1010], b[1010];
int dp[1010][1010][2];
// 1 2
// 3 (cur)
char ans[1010];

int main(void){
    scanf("%s %s", a+1, b+1);
    int n = strlen(a+1);
    int m = strlen(b+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i] == b[j]){
                dp[i][j][0] = dp[i-1][j-1][0] + 1;
                dp[i][j][1] = 1;
            }else if(dp[i-1][j][0] > dp[i][j-1][0]){
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = 2;
            }else{
                dp[i][j][0] = dp[i][j-1][0];
                dp[i][j][1] = 3;
            }
        }
    }
    int ic = n, jc = m;
    do{
        ans[dp[ic][jc][0]] = a[ic];
        switch(dp[ic][jc][1]){
            case 1:
                ic--; jc--;
                break;
            case 2:
                ic--;
                break;
            case 3:
                jc--;
                break;
        }
    }while(ic && jc);
    printf("%d\n", dp[n][m][0]);
    printf("%s", ans+1);
    return 0;
}
