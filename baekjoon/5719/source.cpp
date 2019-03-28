#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> dijk(vector<vector<pair<int, int> > > &v, int s){
    vector<int> dist(510, 9'9999'9999);
    priority_queue<pair<int, int> > pq;
    dist[s] = 0;
    pq.emplace(0, s);
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
    return dist;
}

void erase(vector<vector<pair<int, int> > > &v, vector<int> &r, int d, int n){
    queue<int> q;
    q.push(d);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            for(int j=0;j<(int)v[i].size();j++){
                if(v[i][j].first == cur && r[cur] == r[i] + v[i][j].second){
                    v[i].erase(v[i].begin() + j);
                    q.push(i);
                    j--;
                }
            }
        }
    }
}

int main(void){
    while(1){
        int n, m;
        scanf("%d %d", &n, &m);
        if(!n && !m) break;
        int s, d;
        vector<vector<pair<int, int> > > v(510);
        scanf("%d %d", &s, &d);
        for(int i=0;i<m;i++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            v[a].emplace_back(b, c);
        }
        auto r = dijk(v, s);
        erase(v, r, d, n);
        auto ans = dijk(v, s);
        if(ans[d] == 9'9999'9999) printf("-1\n");
        else printf("%d\n", ans[d]);
    }
    return 0;
}
