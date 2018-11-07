#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

int main(void){
    int n, a, b, m;
    scanf("%d %d %d %d", &n, &a ,&b, &m);
    vector<int> v[110];
    for(int i=0;i<m;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<pair<int, int> > q;
    int ans = -1;
    bool visited[110] = {false};
    q.emplace(a, 0);
    visited[a] = true;
    while(!q.empty()){
        int cur, cost;
        tie(cur, cost) = q.front();
        q.pop();
        if(cur==b){
            ans = cost;
            break;
        }
        for(auto i : v[cur]){
            if(visited[i]) continue;
            q.emplace(i, cost+1);
            visited[i] = true;
        }
    }
    printf("%d", ans);
    return 0;
}
