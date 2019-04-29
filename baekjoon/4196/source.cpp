#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> graph[100'010];
stack<int> st;
int order[100'010], lower[100'010];
bool visited[100'010];
int scc[100'010];
int scnt, cnt;
bool in[100'010];

void dfs(int cur){
    order[cur] = lower[cur] = cnt++;
    st.push(cur);
    for(int next : graph[cur]){
        if(!order[next]){
            dfs(next);
            lower[cur] = min(lower[cur], lower[next]);
        }else if(!visited[next]){
            lower[cur] = min(lower[cur], lower[next]);
        }
    }
    if(order[cur] == lower[cur]){
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
            scc[i] = order[i] = lower[i] = 0;
            visited[i] = in[i] = false;
        }
        scnt = cnt = 1;
        for(int i=0;i<m;i++){
            int x, y;
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
        }
        for(int i=1;i<=n;i++){
            if(!order[i]) dfs(i);
        }
        if(scnt == 2){
            printf("1\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j : graph[i]){
                if(scc[i] != scc[j]){
                    in[scc[j]] = true;
                }
            }
        }
        int incnt = 0;
        for(int i=1;i<scnt;i++){
            if(!in[i]) incnt++;
        }
        printf("%d\n", incnt);
    }
    return 0;
}
