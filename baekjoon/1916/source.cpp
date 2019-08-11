#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int st, ed;
vector<pair<int, int> > v[1010];
vector<int> dist(1010, 9'9999'9999);

void dijk(void){
    dist[st] = 0;
    priority_queue<pair<int, int> > pq;
    pq.emplace(0, st);
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
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    int a, b, c;
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &a, &b, &c);
        v[a].emplace_back(b, c);
    }
    scanf("%d %d", &st, &ed);
    dijk();
    printf("%d", dist[ed]);
    return 0;
}
