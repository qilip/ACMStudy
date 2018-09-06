#include <stdio.h>
#include <memory.h>
#include <queue>
#include <tuple>

using namespace std;

int n, m, ar[1010][1010];
int ans = -1;
int dist[1010][1010][2];
int x[] = {-1, 0, 1, 0}, y[] = {0, 1, 0, -1};
queue<tuple<int, int, int, int>> q;

int main(void){
    memset(ar, -1, sizeof ar);
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d", &ar[i][j]);
        }
    }
    q.emplace(1, 1, 0, 1);
    dist[1][1][0] = 1;
    while(!q.empty()){
        int cx, cy, bk, cost;
        tie(cx, cy, bk, cost) = q.front();
        q.pop();
        if(cx==n && cy==m){
            ans = cost;
            break;
        }
        for(int i=0;i<4;i++){
            int nx = cx+x[i], ny = cy+y[i];
            if(ar[nx][ny]==0 && dist[nx][ny][bk]==0){
                q.emplace(nx, ny, bk, cost+1);
                dist[nx][ny][bk] = 1;
            }
            if(ar[nx][ny]==1 && bk==0 && dist[nx][ny][1]==0){
                q.emplace(nx, ny, 1, cost+1);
                dist[nx][ny][1] = 1;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
