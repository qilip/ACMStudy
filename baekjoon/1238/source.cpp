#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n, m, x;
vector<pair<int, int>> fow[1010];
vector<pair<int, int>> bac[1010];

vector<int> dijk(vector<pair<int, int>> (*graph)[1010]){
    auto v = *graph;
    vector<int> dist(1010, 9999'9999);
    priority_queue<pair<int, int>> pq;
    dist[x] = 0;
    pq.emplace(0, x);
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cost) continue;
        for(auto i : v[cur]){
            int next = i.first;
            int ncost = cost + i.second;
            if(dist[next] > ncost){
                dist[next] = ncost;
                pq.emplace(-ncost, next);
            }
        }
    }
    return dist;
}

int main(void){
    scanf("%d %d %d", &n, &m, &x);
    for(int i=0;i<m;i++){
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        fow[a].emplace_back(b, t);
        bac[b].emplace_back(a, t);
    }
    auto fdist = dijk(&fow);
    auto bdist = dijk(&bac);
    int max = 0;
    for(int i=1;i<=n;i++){
        if(max < fdist[i]+bdist[i]) max = fdist[i]+bdist[i];
    }
    printf("%d", max);
    return 0;
}
