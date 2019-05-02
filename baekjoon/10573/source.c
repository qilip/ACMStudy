#include <stdio.h>
#include <string.h>

int main(void){
    int t;
    scanf("%d", &t);
    long long dp[81][11] = {0};
    for(int i=1;i<10;i++) dp[0][i] = 1;
    for(int i=1;i<81;i++){
        for(int j=1;j<10;j++){
            for(int k=j;k<10;k++){
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    while(t--){
        char s[81];
        long long ans = 0;
        scanf("%s", s);
        int len = strlen(s);
        for(int i=0; i<len; i++){
            if(i && s[i] < s[i-1]){
                ans = -1;
                break;
            }
            ans += dp[len-i][1] - dp[len-i][s[i]-'0'+1];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
