#include <stdio.h>
#include <string.h>

typedef long long ll;

ll dp[22][22][22];

ll d(int n, int l, int r){
    if(n==1 && l==1 && r==1) return 1;
    if(!n || !l || !r) return 0;
    if(dp[n][l][r] != -1) return dp[n][l][r];
    return dp[n][l][r] = d(n-1, l-1, r) + d(n-1, l, r-1) + d(n-1, l, r) * (n-2);
}

int main(void){
    int t;
    scanf("%d", &t);
    memset(dp, -1, sizeof dp);
    while(t--){
        int n, l, r;
        scanf("%d %d %d", &n, &l, &r);
        printf("%lld\n", d(n, l, r));
    }
    return 0;
}
