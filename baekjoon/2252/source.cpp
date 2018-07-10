#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main(void){
    int n, m, nn[32010] = {0};
    vector<int> out[32010];
    priority_queue<pair<int, int>> pq;
    scanf("%d %d", &n, &m);
    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);
        out[a].push_back(b);
        nn[b]++;
    }
    for(int i=1;i<=n;i++){
        pq.emplace(-nn[i], i);
    }
    while(pq.top().first == 0){
        int now = pq.top().second;
        printf("%d ", now);
        pq.pop();
        for(auto i : out[now]){
            nn[i]--;
            pq.emplace(-nn[i], i);
        }
    }
    return 0;
}
