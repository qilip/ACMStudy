#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> graph[100010];
int order[100010], lower[100010];
int cnt = 1;
vector<pair<int ,int>> ans;

void dfs(int cur, int bef){
    order[cur] = lower[cur] = cnt++;
    for(int next : graph[cur]){
        if(bef == next) continue;
        if(!order[next]){
            dfs(next, cur);
            if(order[cur] < lower[next]){
                ans.emplace_back(min(cur, next), max(cur, next));
            }
            lower[cur] = min(lower[cur], lower[next]);
        }else{
            lower[cur] = min(lower[cur], order[next]);
        }
    }
}

int main(void){
    int v, e;
    scanf("%d %d", &v, &e);
    for(int i=0;i<e;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=v;i++){
        if(!order[i]) dfs(i, i);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(auto cur : ans){
        printf("%d %d\n", cur.first, cur.second);
    }
    return 0;
}
