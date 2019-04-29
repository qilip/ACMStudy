#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> graph[310];
stack<int> st;
int ord[310], low[310], cnt;
bool visited[310];
int scc[310], scnt;
int nscc[310];
vector<vector<int> > sccv;
int acnt;
vector<int> ngraph[310];

void dfs(int cur){
    ord[cur] = low[cur] = cnt++;
    st.push(cur);
    for(int next : graph[cur]){
        if(!ord[next]){
            dfs(next);
            low[cur] = min(low[next], low[cur]);
        }else if(!visited[next]){
            low[cur] = min(low[next], low[cur]);
        }
    }
    if(ord[cur] == low[cur]){
        int tcnt = 0;
        vector<int> tmp;
        while(1){
            int top = st.top();
            st.pop();
            visited[top] = true;
            tcnt++;
            scc[top] = scnt;
            nscc[scnt] = top;
            tmp.push_back(top);
            if(top == cur) break;
        }
        if(tcnt>1) acnt += tcnt;
        sccv.push_back(tmp);
        scnt++;
    }
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, a;
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            graph[i].clear();
            ngraph[i].clear();
            nscc[i] = 0;
            scc[i] = ord[i] = low[i] = 0;
            visited[i] = false;
        }
        cnt = scnt = 1;
        acnt = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%1d", &a);
                if(a && i!=j) graph[i].push_back(j);
            }
        }
        for(int i=1;i<=n;i++){
            if(!ord[i]) dfs(i);
        }
        for(int i=1;i<=n;i++){
            for(int j : graph[i]){
                if(scc[i] != scc[j]){
                    ngraph[scc[i]].push_back(scc[j]);
                }
            }
        }
        vector<pair<int, int> > ans;
        bool chk[310] = {false};
        for(int i=scnt-1;i>0;i--){
            for(int j : ngraph[i]){
                if(!chk[j]){
                    chk[j] = true;
                    acnt++;
                    ans.emplace_back(nscc[i], nscc[j]);
                }
            }
        }
        for(auto v : sccv){
            
            for(auto i = v.begin()+1; i!=v.end(); i++){
                ans.emplace_back( nscc[*(i-1)], nscc[*i]);
            }

        }
        printf("%d\n", acnt);
        for(auto c : ans){
            printf("%d %d\n", c.first, c.second);
        }
        printf("\n");
    }
    return 0;
}
