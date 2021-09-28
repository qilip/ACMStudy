#include <bits/stdc++.h>

using namespace std;

int scnt, dcnt;
vector<int> v[150];
int vc[150][150];
int a[150];
int b[40000];
bool visited[150];

int dfs(int l){
    visited[l] = true;
    for(int r : v[l]){
        if(!b[r] || (!visited[b[r]] && dfs(b[r]))){
            a[l] = r;
            b[r] = l;
            return 1;
        }
    }
    return 0;
}

int main(void){
    int n, m;
    char nm[20][20] = {0};
    int cm[20][20] = {0};
    vector<pair<int, int>> st;
    int xi[] = {-1, 0, 1, 0};
    int xj[] = {0, 1, 0, -1};
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c", &nm[i][j]);
            if(nm[i][j] == '.'){
                st.emplace_back(i, j);
                cm[i][j] = ++scnt;
            }
            if(nm[i][j] == 'D') cm[i][j] = ++dcnt;
        }
    }
    int imp = 0;
    fill(vc[0], vc[150], 99999);
    for(auto sc : st){
        auto [si, sj] = sc;
        bool vis[20][20] = {false};
        queue<pair<pair<int, int>, int>> q;
        vis[si][sj] = true;
        q.push({{si, sj}, 0});
        int cimp = 1;
        while(!q.empty()){
            auto [ci, cj] = q.front().first;
            int cos = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int ni = ci + xi[i];
                int nj = cj + xj[i];
                int ncos = cos + 1;
                if(!vis[ni][nj] && nm[ni][nj] != 'X' && nm[ni][nj] != 0){
                    if(nm[ni][nj] == 'D'){
                        // v[cm[ci][cj]].push_back(cm[ni][nj]);
                        vc[cm[si][sj]][cm[ni][nj]] = ncos;
                        cimp = 0;
                        continue;
                    }
                    vis[ni][nj] = true;
                    q.push({{ni, nj}, ncos});
                }
            }
        }
        imp += cimp;
    }
    if(imp){
        printf("impossible\n");
        return 0;
    }
    for(int t = 1; t<=300; t++){
        fill(a, a+149, 0);
        fill(b, b+39999, 0);
        for(int i=1;i<=scnt;i++){
            for(int j=1;j<=dcnt;j++){
                if(vc[i][j] <= t) v[i].push_back(dcnt*(t-1)+j);
            }
        }
        int ans = 0;
        for(int i=1;i<=scnt;i++){
            if(!a[i]){
                fill(visited, visited+149, false);
                if(dfs(i)) ans++;
            }
        }
        if(scnt == ans){
            printf("%d\n", t);
            break;
        }
    }
    return 0;
}
