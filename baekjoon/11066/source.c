#include <stdio.h>
#include <string.h>

int INF = 0x3f3f3f3f;
int kk[510];
int psum[510];
int dp[510][510];

int dfs(int st, int ed){
    if(dp[st][ed] != INF) return dp[st][ed];
    if(st == ed) return 0;
    if(st+1 == ed) return dp[st][ed] = kk[st] + kk[ed];
    for(int i = st;i<ed;i++){
        if(dp[st][ed] > dfs(st, i) + dfs(i+1, ed) + psum[ed] - psum[st-1])
            dp[st][ed] = dfs(st, i) + dfs(i+1, ed) + psum[ed] - psum[st-1];
    }
    return dp[st][ed];
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int k;
        scanf("%d", &k);
        memset(dp, 0x3f, sizeof dp);
        psum[0] = 0;
        for(int i=1;i<=k;i++){
            scanf("%d", &kk[i]);
            psum[i] = psum[i-1] + kk[i];
        }
        printf("%d\n", dfs(1, k));
    }
    return 0;
}
