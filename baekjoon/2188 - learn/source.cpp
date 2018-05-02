#include <cstdio>
#include <vector>

using namespace std;

int match[210];
int matched[210];
int visit[210];
vector<int> edge[210];
int checknum = 1;

int dfs(int u){
    if(visit[u] == checknum) return 0;
    visit[u] = checknum;

    for(auto &v : edge[u]){
        if(matched[v] != -1){
            int tmp = dfs(matched[v]);
            if(tmp == 1){
                match[u] = v;
                matched[v] = u;
                return 1;
            }
        }else{
            match[u] = v;
            matched[v] = u;
            return 1;
        }
    }
    return 0;
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        int sz;
        scanf("%d", &sz);
        for(int j=0;j<sz;j++){
            int x;
            scanf("%d", &x);
            edge[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++) match[i] = matched[i] = -1;
    int ans = 0;
    for(int i=1;i<=n;i++) {
        ans += dfs(i);
        checknum++;
    }
    printf("%d\n", ans);
    return 0;
}