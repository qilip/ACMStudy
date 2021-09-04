#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, p;
int cap[810][810];
int flo[810][810];
vector<int> v[810];

int main(void){
    scanf("%d %d", &n, &p);
    for(int i=0;i<p;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a+n].push_back(b);
        v[b].push_back(a+n);
        v[b+n].push_back(a);
        v[a].push_back(b+n);
        cap[a+n][b] = 1;
        cap[b+n][a] = 1;
    }
    for(int i=1;i<=n;i++){
        v[i].push_back(i+n);
        v[i+n].push_back(i);
        cap[i][i+n] = 1;
    }
    int st = 1+n, ed = 2;
    int ans = 0;
    while(1){
        queue<int> q;
        int visited[810] = {0};
        q.push(st);
        while(!q.empty() && !visited[ed]){
            int cur = q.front();
            q.pop();
            for(auto nxt : v[cur]){
                if(!visited[nxt] && cap[cur][nxt] - flo[cur][nxt] > 0){
                    visited[nxt] = cur;
                    q.push(nxt);
                    if(nxt == ed) break;
                }
            }
        }
        if(!visited[ed]) break;
        int flow = 9999'9999;
        for(int i=ed;i!=st;i=visited[i]){
            flow = min(flow, cap[visited[i]][i] - flo[visited[i]][i]);
        }
        for(int i=ed;i!=st;i=visited[i]){
            flo[visited[i]][i] += flow;
            flo[i][visited[i]] -= flow;
        }
        ans += flow;
    }
    printf("%d", ans);
    return 0;
}
