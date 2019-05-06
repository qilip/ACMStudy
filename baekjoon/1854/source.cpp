#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

int n, m, k;
vector<pair<int, int> > v[1010];
priority_queue<int> dist[1010];

void dijk(void){
    priority_queue<pair<int, int> > pq;
    dist[1].push(0);
    pq.emplace(0, 1);
    while(!pq.empty()){
        int cost, cur;
        tie(cost, cur) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[cur].top() < cost) continue;
        for(auto i : v[cur]){
            int next = i.first;
            int ncost = cost + i.second;
            if(dist[next].size() < k){
                dist[next].push(ncost);
                pq.emplace(-ncost, next);
            }else if(dist[next].top()>ncost){
                dist[next].pop();
                dist[next].push(ncost);
                pq.emplace(-ncost, next);
            }
        }
    }
}

int main(void){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<m;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].emplace_back(b, c);
    }
    dijk();
    for(int i=1;i<=n;i++){
        printf("%d\n", dist[i].size()<k ? -1 : dist[i].top());
    }
    return 0;
}
