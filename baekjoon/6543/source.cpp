#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;
vector<int> graph[5010];
stack<int> st;
int order[5010], low[5010];
bool visited[5010], ans[5010];
int scc[5010];
int scnt = 0;
int cnt = 1;

void dfs(int cur){
    low[cur] = cnt;
    order[cur] = cnt++;
    st.push(cur);
    visited[cur] = true;
    for(int next : graph[cur]){
        if(!order[next]){
            dfs(next);
            low[cur] = min(low[cur], low[next]);
        }else if(visited[next]){
            low[cur] = min(low[cur], low[next]);
        }
    }
    if(order[cur] == low[cur]){
        while(1){
            int top = st.top();
            st.pop();
            visited[top] = false;
            scc[top] = scnt;
            if(low[top] == order[top]) break;
        }
        scnt++;
    }
}

int main(void){
    while(1){
        scanf("%d", &n);
        if(n==0) break;
        scanf("%d", &m);
        for(int i=1;i<=n;i++){
            graph[i].clear();
            low[i] = order[i] = 0;
            visited[i] = false;
            ans[i] = true;
        }
        scnt = cnt = 1;
        for(int i=0;i<m;i++){
            int v, w;
            scanf("%d %d", &v, &w);
            graph[v].push_back(w);
        }
        for(int i=1;i<=n;i++){
            if(!order[i]) dfs(i);
        }
        for(int i=1;i<=n;i++){
            for(int j : graph[i]){
                if(scc[i] != scc[j]) ans[scc[i]] = false;
            }
        }
        for(int i=1;i<=n;i++){
            if(ans[scc[i]]) printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
