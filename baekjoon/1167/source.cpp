#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int, int>>> tree(100001);

pair<int, int> dfs(int cur, int cost, int parent){
    pair<int, int> ret = {cur, cost};
    for (auto [nxt, nxt_cost] : tree[cur]){
        if (nxt == parent) continue;
        auto [node, n_cost] = dfs(nxt, cost + nxt_cost, cur);
        if (ret.second < n_cost) ret = {node, n_cost};
    }
    return ret;
}

int main(void){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        while(1){
            int con, cost;
            scanf("%d", &con);
            if (con == -1) break;
            scanf("%d", &cost);
            tree[num].emplace_back(con, cost);
        }
    }
    auto [node, cost] = dfs(1, 0, 0);
    int ans = dfs(node, 0, 0).second;
    printf("%d", ans);
    return 0;
}
