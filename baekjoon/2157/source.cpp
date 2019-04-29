#include <stdio.h>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main(void){
    int n, m, k;
    int dp[310][310] = {0};
    vector<tuple<int, int, int> >v;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<k;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a>b) continue;
        v.emplace_back(b, a, c);
    }
    sort(v.begin(), v.end());
    for(auto cur : v){
        int a, b, c;
        tie(b, a, c) = cur;
        for(int i=1;i<m;i++){
            if( (a==1 || dp[a][i]) && dp[b][i+1] < dp[a][i] + c) dp[b][i+1] = dp[a][i] + c;
        }
    }
    int max = 0;
    for(int i=2;i<=m;i++){
        if(max < dp[n][i]) max = dp[n][i];
    }
    printf("%d", max);
    return 0;
}
