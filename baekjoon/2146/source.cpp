#include <stdio.h>
#include <memory.h>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

int n, ar[110][110];
int x[] = {1, 0, -1 ,0}, y[] = {0, 1, 0, -1};
int dist[110][110];
int ans = 99999999;

void label(int a, int b, int c){
    queue<pair<int, int>> q;
    q.emplace(a, b);
    ar[a][b] = c;
    while(!q.empty()){
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx+x[i];
            int ny = cy+y[i];
            if(ar[nx][ny]==1){
                ar[nx][ny] = c;
                q.emplace(nx, ny);
            }
        }
    }
}

void bfs(int a, int b){
    int cur = ar[a][b];
    queue<tuple<int, int, int>> q;
    memset(dist, 0, sizeof dist);
    q.emplace(a, b, 0);
    dist[a][b] = 1;
    while(!q.empty()){
        int cx, cy, cost;
        tie(cx, cy, cost) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx+x[i], ny = cy+y[i];
            if(!dist[nx][ny] && !ar[nx][ny]){
                dist[nx][ny] = 1;
                q.emplace(nx, ny, cost+1);
            }else if(ar[nx][ny]!=cur && ar[nx][ny]>1)
                if(ans>cost) ans = cost;
        }
    }
}

int main(void){
    scanf("%d", &n);
    memset(ar, -1, sizeof ar);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &ar[i][j]);
        }
    }
    int cnt = 2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ar[i][j]==1) label(i, j, cnt++);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ar[i][j]) bfs(i, j);
        }
    }
    printf("%d", ans);
    return 0;
}
