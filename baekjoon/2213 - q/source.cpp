#include <stdio.h>
#include <vector>

using namespace std;


int main(void){
    int n;
    int cost[10010];
    vector<int> v[10010];
    int dp[10010][2];
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &cost[i]);
    }
    for(int i=1;i<=n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    
    return 0;
}
 