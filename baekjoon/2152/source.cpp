#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n, m, s, t;
vector<int> graph[10010];
stack<int> st;
int ord[10010], low[10010];
bool visited[10010];
int scc[10010];
int scnt = 1;
int cnt = 1;

void dfs(int cur){
    low[cur] = ord[cur] = cnt++;
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

vector<int> ngraph[10010];
int snum[10010] = {0};
int ans = -1;
int dvisited[10010];

void ndfs(int cur, int sum){
    dvisited[cur] = sum;
    if(cur == scc[t]){
        if(ans < sum) ans = sum;
        return;
    }
    for(int next : ngraph[cur]){
        if(dvisited[next] < sum+snum[next])
            ndfs(next, sum+snum[next]);
    }
    return;
}

int main(void){
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(int i=1;i<=m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!ord[i]) dfs(i);
    }
    for(int i=1;i<=n;i++){
        snum[scc[i]]++;
        for(int j : graph[i]){
            if(scc[i] != scc[j]){
                ngraph[scc[i]].push_back(scc[j]);
            }
        }
    }
    ndfs(scc[s], snum[scc[s]]);
    if(ans==-1) printf("0");
    else printf("%d", ans);

    return 0;
}
