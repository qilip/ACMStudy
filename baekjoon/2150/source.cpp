#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int v, e;
vector<int> graph[10010];
vector<int> scc[10010];
stack<int> stk;
bool visited[10010];
int ord[10010], low[10010], cnt = 1, scc_cnt = 0;

void dfs(int cur){
    low[cur] = cnt;
    ord[cur] = cnt++;
    stk.push(cur);
    visited[cur] = true;
    for(auto next : graph[cur]){
        if(!ord[next]){
            dfs(next);
            low[cur] = min(low[cur], low[next]);
        }else if(visited[next]){
            low[cur] = min(low[cur], low[next]);
        }
    }
    if(ord[cur] == low[cur]){
        while(1){
            int top = stk.top();
            stk.pop();
            scc[scc_cnt].push_back(top);
            visited[top] = false;
            if(ord[top] == low[top]){
                break;
            }
        }
        sort(scc[scc_cnt].begin(), scc[scc_cnt].end());
        scc_cnt++;
    }
}

int main(void){
    scanf("%d %d", &v, &e);
    for(int i=0;i<e;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
    }
    for(int i=1;i<=v;i++){
        if(!ord[i]) dfs(i);
    }
    sort(scc, scc + scc_cnt);
    printf("%d\n", scc_cnt);
    for(int i=0;i<scc_cnt;i++){
        for(int j=0;j<(int)scc[i].size();j++){
            printf("%d ", scc[i][j]);
        }
        printf("-1\n");
    }
    return 0;
}
