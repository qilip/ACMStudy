#include <stdio.h>
#include <string.h>

int n, m;
int nn[1010];
int dp[1010][1010];

int d(int curser, int word){ // curser 칸까지 썼고, word 단어까지 썼음
    if(word==n) return 0;
    if(dp[curser][word] != -1) return dp[curser][word];
    dp[curser][word] = (m-curser)*(m-curser) + d(nn[word+1], word+1);
    if(curser+1+nn[word+1] <= m){
        int t = d(curser+1+nn[word+1], word+1);
        dp[curser][word] = dp[curser][word] > t ? t : dp[curser][word];
    }
    return dp[curser][word];
}

int main(void){
    scanf("%d %d", &n, &m);
    memset(dp, -1, sizeof dp);
    for(int i=1;i<=n;i++){
        scanf("%d", &nn[i]);
    }
    printf("%d", d(nn[1], 1));
    return 0;
}
