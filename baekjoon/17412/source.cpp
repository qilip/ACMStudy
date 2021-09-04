#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, p;
int cap[410][410];
int flo[410][410];
vector<int> v[410];

int main(void){
    scanf("%d %d", &n, &p);
    for(int i=0;i<p;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
        cap[a][b] = 1;
    }
    int ans = 0;
    while(1){
        queue<int> q;
        int visited[410] = {0};
        q.push(1);
        while(!q.empty() && !visited[2]){
            int cur = q.front();
            q.pop();
            for(auto nxt : v[cur]){
                if(!visited[nxt] && cap[cur][nxt] - flo[cur][nxt] > 0){
                    visited[nxt] = cur;
                    q.push(nxt);
                    if(nxt == 2) break;
                }
            }
        }
        if(!visited[2]) break;
        int flow = 9999'9999;
        for(int i=2;i!=1;i=visited[i]){
            flow = min(flow, cap[visited[i]][i] - flo[visited[i]][i]);
        }
        for(int i=2;i!=1;i=visited[i]){
            flo[visited[i]][i] += flow;
            flo[i][visited[i]] -= flow;
        }
        ans += flow;
    }
    printf("%d", ans);
    return 0;
}
