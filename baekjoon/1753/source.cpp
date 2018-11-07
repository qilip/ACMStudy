#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#define MAX 0x3f3f3f3f

using namespace std;

int V, E, K;
vector<pair<int, int>> v[20010];
int dist[20010];

void dijk(void){
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<int, int>> pq;
    dist[K] = 0;
    for(int i=1;i<=V;i++)
        pq.emplace(-MAX, i);
    pq.emplace(0, K);
    while(!pq.empty()){
        int cost, now;
        tie(cost, now) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[now] < cost) continue;
        for(auto i : v[now]){
            int next, ncost;
            tie(next, ncost) = i;
            ncost += cost;
            if(dist[next] > ncost){
                dist[next] = ncost;
                pq.emplace(-ncost, next);
            }
        }
    }
}

int main(void){
    scanf("%d %d %d", &V, &E, &K);
    for(int i=0;i<E;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].emplace_back(b, c);
    }
    dijk();
    for(int i=1;i<=V;i++){
        if(dist[i] != MAX)
            printf("%d\n", dist[i]);
        else printf("INF\n");
    }
    return 0;
}
