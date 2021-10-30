#include <bits/stdc++.h>

using namespace std;

int n, m;
int nm[1010][1010];
int col[1010][1010];
vector<int> cnt(1);
pair<int, int> dd[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(void){
    scanf("%d %d", &n, &m);
    fill(nm[0], nm[1010], 1);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &nm[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(nm[i][j] || col[i][j]) continue;
            int c = cnt.size();
            cnt.push_back(0);
            queue<pair<int, int>> q;
            q.emplace(i, j);
            col[i][j] = c;
            cnt[c]++;
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                for(auto [dx, dy] : dd){
                    int nx = x + dx, ny = y + dy;
                    if(nm[nx][ny] || col[nx][ny]) continue;
                    q.emplace(nx, ny);
                    col[nx][ny] = c;
                    cnt[c]++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!nm[i][j]) printf("0");
            else{
                int ans = 1;
                map<int, int> vcol;
                for(auto [dx, dy] : dd){
                    int nx = i + dx, ny = j + dy;
                    if(vcol[col[nx][ny]]) continue;
                    ans += cnt[col[nx][ny]];
                    vcol[col[nx][ny]] = 1;
                }
                printf("%d", ans%10);
            }
        }
        printf("\n");
    }
    return 0;
}
