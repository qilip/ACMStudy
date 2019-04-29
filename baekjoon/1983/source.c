#include <stdio.h>

int dp[410][410][410]; // c 칸, a 개, b 개 에서의 MAX

int main(void){
    int n, t, aa[410], acnt = 1, bb[410], bcnt = 1;
    scanf("%d", &n);
    for(int j=1;j<=n;j++){
        scanf("%d", &t);
        if(t) aa[acnt++] = t;
    }
    for(int j=1;j<=n;j++){
        scanf("%d", &t);
        if(t) bb[bcnt++] = t;
    }
    for(int c=1; c<=n; c++){
        for(int a=1; a<acnt && a<=c; a++){
            for(int b=1; b<bcnt && b<=c; b++){
                dp[c][a][b] = dp[c-1][a-1][b-1] + aa[a] * bb[b];
                if(c > b)
                    dp[c][a][b] = dp[c][a][b] < dp[c-1][a-1][b] ? dp[c-1][a-1][b] : dp[c][a][b];
                if(c > a)
                    dp[c][a][b] = dp[c][a][b] < dp[c-1][a][b-1] ? dp[c-1][a][b-1] : dp[c][a][b];
            }
        }
    }
    printf("%d", dp[n][acnt-1][bcnt-1]);
    return 0;
}
