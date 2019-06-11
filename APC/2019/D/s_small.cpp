#include <stdio.h>
#include <vector>

using namespace std;

vector<int> graph[1010];
int incnt[1010] = {0};
int n, e;
int ans = 0;
int minans = 999999999;

int dfs(int cur, int cnt){
    if(cur == n){
        if((cnt%2) == 0){
            ans++;
            return 0;
        }else return 1;
    }
    int count = 0;
    for(auto next : graph[cur]){
        count += dfs(next, cnt+1);
    }
    return count;
}

int main(void){
    scanf("%d %d", &n, &e);
    for(int i=0;i<e;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        incnt[v]++;
    }
    int acnt = 0;
    for(int i=1;i<=n;i++){
        if(!incnt[i]){
            acnt += dfs(i, 1);
            if(ans < minans) minans = ans;
            ans = 0;
        }
    }
    if(acnt == 0 || minans == 999999999) minans = -1;
    printf("%d", minans);
    return 0;
}
