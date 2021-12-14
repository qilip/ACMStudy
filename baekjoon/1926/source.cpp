#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[510][510];
int visited[510][510];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    int cnt = 1;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!arr[nx][ny]) continue;
            if(visited[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = 1;
            cnt++;
        }
    }
    return cnt;
}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int cnt = 0;
    int max_size = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!visited[i][j] && arr[i][j]){
                int res = bfs(i, j);
                if(res) cnt++;
                max_size = max(max_size, res);
            }
        }
    }
    printf("%d\n%d\n", cnt, max_size);
}