#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int inp[210];
vector<int> v;
int dp[210][210];

int d(int a, int b){
    if(a>=b) return 0;
    if(dp[a][b] <= 99999) return dp[a][b];
    for(int i=a;i<b;i++){
        dp[a][b] = min(dp[a][b], d(a, i) + d(i+1, b) + (v[a] != v[i+1]));
    }
    return dp[a][b];
}

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    memset(dp, 0x3f, sizeof dp);
    for(int i=1;i<=n;i++){
        scanf("%d", &inp[i]);
    }
    for(int i=1;i<=n;i++){
        if(inp[i-1] != inp[i]) v.push_back(inp[i]);
    }
    printf("%d", d(0, v.size()-1));
    return 0;
}
