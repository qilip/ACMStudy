#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[10010];
int order[10010], lower[10010];
bool point[10010];
int cnt = 1, ans;

void dfs(int cur, int isRoot){
    order[cur] = lower[cur] = cnt++;
    int child = 0;
    for(int next : graph[cur]){
        if(!order[next]){
            child++;
            dfs(next, 0);
            if(!isRoot && order[cur] <= lower[next]){
                point[cur] = true;
            }
            lower[cur] = min(lower[cur], lower[next]);
        }else{
            lower[cur] = min(lower[cur], order[next]);
        }
    }
    if(isRoot && child >= 2){
        point[cur] = true;
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
        if(!order[i]) dfs(i, 1);
    }
    for(int i=1;i<=v;i++){
        if(point[i]) ans++;
    }
    printf("%d\n", ans);
    for(int i=1;i<=v;i++){
        if(point[i]) printf("%d ", i);
    }
    return 0;
}
