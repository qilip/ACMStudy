#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>

using namespace std;

int n;
vector<pair<int, char>> graph[10010];
char p[1010];
int plen;
int ans;

void dfs(int cur, int cnt){
    if(cnt == plen){
        ans++;
        return;
    }
    for(auto next : graph[cur]){
        int nxt = next.first;
        char pp = next.second;
        if(pp == p[cnt]){
            dfs(nxt, cnt+1);
        }
    }
}

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n-1;i++){
        int u, v;
        char c;
        scanf("%d %d %c", &u, &v, &c);
        graph[u].emplace_back(v, c);
    }
    scanf(" %s", p);
    plen = strlen(p);
    for(int i=1;i<=n;i++){
        dfs(i, 0);
    }
    printf("%d", ans);
    return 0;
}
