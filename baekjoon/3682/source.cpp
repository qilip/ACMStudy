#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[20010];
stack<int> st;
int ord[20010], low[20010];
bool visited[20010];
int scc[20010];
int cnt, scnt;

void dfs(int cur){
    ord[cur] = low[cur] = cnt++;
    st.push(cur);
    for(int next : graph[cur]){
        if(!ord[next]){
            dfs(next);
            low[cur] = min(low[cur], low[next]);
        }else if(!visited[next]){
            low[cur] = min(low[cur], low[next]);
        }
    }
    if(ord[cur] == low[cur]){
        while(1){
            int top = st.top();
            st.pop();
            visited[top] = true;
            scc[top] = scnt;
            if(top == cur) break;
        }
        scnt++;
    }
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;i++){
            graph[i].clear();
            scc[i] = ord[i] = low[i] = 0;
            visited[i] = false;
        }
        scnt = cnt = 1;
        for(int i=1;i<=m;i++){
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
        }
        for(int i=1;i<=n;i++){
            if(!ord[i]) dfs(i);
        }
        if(scnt==2){
            printf("0\n");
            continue;
        }
        bool out[20010] = {false};
        bool in[20010] = {false};
        for(int i=1;i<=n;i++){
            for(int j : graph[i]){
                if(scc[i] != scc[j]){
                    out[scc[i]] = true;
                    in[scc[j]] = true;
                }
            }
        }
        int outcnt = 0;
        int incnt = 0;
        for(int i=1;i<scnt;i++){
            if(!out[i]) outcnt++;
            if(!in[i]) incnt++;
        }
        printf("%d\n", outcnt > incnt ? outcnt : incnt);
    }
    return 0;
}
