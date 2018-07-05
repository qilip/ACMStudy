#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, v;
vector<int> nn[1010];
queue<int> q;
bool dis[1010], bis[1010];

void dfs(int cur){
    if(dis[cur]) return;
    else dis[cur] = true;
    printf("%d ", cur);
    sort(nn[cur].begin(), nn[cur].end());
    for(auto i : nn[cur]){
        dfs(i);
    }
}

void bfs(void){
    q.push(v);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        bis[now] = true;
        printf("%d ", now);
        for(auto i : nn[now]){
            if(!bis[i]){
                q.push(i);
                bis[i] = true;
            }
        }
    }
}

int main(void){
    scanf("%d %d %d", &n, &m, &v);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        nn[a].push_back(b);
        nn[b].push_back(a);
    }
    dfs(v);
    puts("");
    bfs();
    return 0;
}
