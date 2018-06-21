#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int n, m;
vector<pair<int, int>> v[1004];

auto dijk(int st, int a, int b){
    vector<pair<int, int>> dist(1004, make_pair(50000001, 0));
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, st);
    for(int i=1;i<=n;i++)
        pq.emplace(-50000001, i);
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(cost > dist[now].first) continue;
        for(auto &nx : v[now]){
            int next, ncost;
            tie(next, ncost) = nx;
            if( (now==a && next==b)||(now==b && next==a) ) continue;
            ncost += cost;
            if(ncost < dist[next].first){
                dist[next].first = ncost;
                dist[next].second = now;
                pq.emplace(-ncost, next);
            }
        }
    }
    return dist;
}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        v[a].emplace_back(b, t);
        v[b].emplace_back(a, t);
    }
    auto ori = dijk(1, 0, 0);
    int ocost = ori[n].first;
    vector<int> route;
    int trace = n;
    route.push_back(n);
    while(trace!=1)
        route.push_back(trace = ori[trace].second);
    int ans = 0;
    for(unsigned int i=0;i<route.size()-1;i++){
        int tcost = dijk(1, route[i], route[i+1])[n].first;
        if(tcost == 50000001){
            ans = -1;
            break;
        }
        int co = tcost - ocost;
        if(ans < co) ans = co;
    }
    printf("%d", ans);
    return 0;
}
