#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

int main(void){
    int n, r = 0, ans = 0, dp[10010] = {0};
    priority_queue<pair<int, int>> pq;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int p, d;
        scanf(" %d %d", &p, &d);
        pq.emplace(-d, p);
    }
    while(!pq.empty()){
        int d = -pq.top().first;
        int p = pq.top().second;
        pq.pop();
        int min = 100010, mini = 0;
        for(int i=1;i<=d;i++){
            if(min > dp[i]){
                min = dp[i];
                mini = i;
            }
        }
        if(dp[mini]<p) dp[mini] = p;
    }
    for(int i=1;i<=10001;i++){
        ans += dp[i];
    }
    printf("%d", ans);
    return 0;
}
