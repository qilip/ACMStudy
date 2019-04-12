#include <stdio.h>
#include <string.h>

int dp[1010][1010][2];
int nn[1010];

int find(int s, int e, int r){
    if(s==e){
        if(!r) return nn[s];
        else return 0;
    }
    if(dp[s][e][r]) return dp[s][e][r];
    int a = find(s+1, e, !r);
    int b = find(s, e-1, !r);
    if(!r){
        a += nn[s];
        b += nn[e];
        return dp[s][e][r] = a > b ? a : b;
    }
    return dp[s][e][r] = a < b ? a : b;
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        memset(dp, 0, sizeof dp);
        for(int i=0;i<n;i++){
            scanf("%d", &nn[i]);
        }
        printf("%d\n", find(0, n-1, 0));
    }
    return 0;
}
