#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n, m, x;
vector<pair<int, int>> v[1010];
vector<int> dist(1010, 200'0000);

void dijk(void){
    dist[x] = 0;
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, x);
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cost) continue;
        for(auto i : v[cur]){
            int next = i.first;
            int ncost = i.second + cost;
            if(dist[next] > ncost){
                dist[next] = ncost;
                pq.emplace(-ncost, next);
            }
        }
    }
}

int main(void){
    scanf("%d %d %d", &n, &m, &x);
    for(int i=0;i<m;i++){
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        v[a].emplace_back(b, t);
        v[b].emplace_back(a, t);
    }
    dijk();
    int max = 0;
    for(int i=1;i<=n;i++){
        if(max < dist[i]) max = dist[i];
    }
    printf("%d", max*2);
    return 0;
}
