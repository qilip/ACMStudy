#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[500'010];
int money[500'010];
bool pp[500'010];

stack<int> st;
int ord[500'010], low[500'010];
bool visited[500'010];
int scc[500'010];
int scnt = 1, cnt = 1;

vector<int> ngraph[500'010];
int msum[500'010];
int nsum[500'010];
bool ppp[500'010];
int ans = 0;

void dfs(int cur){
    low[cur] = ord[cur] = cnt++;
    st.push(cur);
    for(auto next : graph[cur]){
        if(!ord[next]){
            dfs(next);
            low[cur] = min(low[cur], low[next]);
        }else if(!visited[next]){
            low[cur] = min(low[cur], low[next]);
        }
    }
    if(low[cur] == ord[cur]){
        while(1){
            int top = st.top();
            st.pop();
            visited[top] = true;
            scc[top] = scnt;
            if(cur == top) break;
        }
        scnt++;
    }
}

int main(void){
    int n, m, s, p;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &money[i]);
    }
    scanf("%d %d", &s, &p);
    for(int i=1;i<=p;i++){
        int t;
        scanf("%d", &t);
        pp[t] = true;
    }
    for(int i=1;i<=n;i++){
        if(!ord[i]) dfs(i);
    }
    for(int i=1;i<=n;i++){
        msum[scc[i]] += money[i];
        if(pp[i]) ppp[scc[i]] = true;
        for(int j : graph[i]){
            if(scc[i] != scc[j]) ngraph[scc[i]].push_back(scc[j]);
        }
    }
    nsum[scc[s]] = msum[scc[s]];
    if(ppp[scc[s]]) ans = nsum[scc[s]];
    for(int i=scc[s];i>=1;i--){
        for(int j : ngraph[i]){
            if(nsum[j] < nsum[i] + msum[j])
                nsum[j] = nsum[i] + msum[j];
            if(ppp[j] && nsum[j] > ans) ans = nsum[j];
        }
    }
    printf("%d", ans);
    return 0;
}
