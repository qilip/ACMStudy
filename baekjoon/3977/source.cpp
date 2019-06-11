#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> graph[100010];
stack<int> st;
int ord[100010], low[100010];
bool visited[100010];
int scc[100010];
int scc_cnt = 1;
int cnt = 1;

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
            scc[top] = scc_cnt;
            if(cur == top) break;
        }
        scc_cnt++;
    }
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0;i<=n;i++){
            graph[i].clear();
            ord[i] = low[i] = 0;
            visited[i] = false;
            scc[i] = 0;
        }
        scc_cnt = cnt = 1;
        for(int i=0;i<m;i++){
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
        }
        for(int i=0;i<n;i++){
            if(!ord[i]) dfs(i);
        }
        bool in[100010] = {false};
        for(int i=0;i<n;i++){
            for(int j : graph[i]){
                if(scc[i] != scc[j])
                    in[scc[j]] = true;
            }
        }
        int ans = 0;
        vector<int> ans_v;
        for(int i=1;i<scc_cnt;i++){
            if(in[i]) continue;
            if(ans){
                ans = -1;
                break;
            }
            ans = i;
            for(int j=0;j<n;j++){
                if(scc[j] == ans){
                    ans_v.push_back(j);
                }
            }
        }
        if(ans == -1) printf("Confused\n");
        else{
            for(int c : ans_v)
                printf("%d\n", c);
        }
        printf("\n");
    }
    return 0;
}
