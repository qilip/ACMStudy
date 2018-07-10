#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int n, m;
vector<pair<int, int>> v[100010];

vector<pair<int ,int>> dijk1(void){
    vector<int> dist(n+1, 200000000);
    vector<pair<int, int>> rt;
    dist[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);
    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(dist[now] < cost) continue;
        for(auto i : v[now]){
            int next = i.first;
            int ncost = cost + i.second;
            if(dist[next] > ncost){
                if(dist[now] <= i.second){
                    dist[next] = ncost;
                    pq.emplace(-ncost, next);
                }else{
                    rt.emplace_back(cost, now);
                }
            }
        }
    }
    if(dist[n]!=200000000) rt.emplace_back(dist[n], n);
    return rt;
}

int dijk2(int end){
    vector<int> dist(n+1, 200000000);
    dist[n] = 0;
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, n);
    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(dist[now] < cost) continue;
        for(auto i : v[now]){
            int next = i.first;
            int ncost = i.second;
            if(dist[next] > ncost){
                if(dist[now] >= i.second){
                    dist[next] = ncost;
                    pq.emplace(-ncost, next);
                }
            }
        }
    }
    return dist[end];
}

int main(void){
    setbuf(stdout, NULL);
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int ans = 200000000;
        for(int i=0;i<=n;i++) v[i].clear();
        scanf("%d %d", &n, &m);
        for(int i=0;i<m;i++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            v[a].emplace_back(c, b);
            v[b].emplace_back(c, a);
        }
        vector<pair<int, int>> r;
        r = dijk1();
        r.emplace_back(0, 1);
        for(auto i : r){
            int tmp;
            if(i.second==n) tmp = i.first;
            else tmp = dijk2(i.second) + i.first;
            printf("%d %d %d|", i.second, i.first, tmp);
            if(ans > tmp) ans = tmp;
        }
        printf("Case #%d\n", t);
        printf("%d\n", ans == 200000000 ? -1 : ans);   
    }
    return 0;
}
