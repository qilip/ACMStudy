#include <stdio.h>

int min(int x, int y){
    return x > y ? y : x;
}

int n, nn[5010];
int dp[5010][5010];

int d(int l, int r){
    if(l>=r) return 0;
    if(dp[l][r]) return dp[l][r];
    if(nn[l]==nn[r]) return d(l+1, r-1);
    return dp[l][r] = 1 + min(d(l, r-1), d(l+1, r));
}

int main(void){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &nn[i]);
    }
    printf("%d", d(1, n));
    return 0;
}
