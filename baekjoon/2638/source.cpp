#include <cstdio>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

int n, m, nm[110][110];

int chk_one(void){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nm[i][j]==1){
                return 1;
            }
        }
    }
    return 0;
}

void bfs(void){
    queue<pair<int, int>> q;
    int visited[110][110] = {0};
    int mark[110][110] = {0};
    int x[] = {1, -1, 0, 0};
    int y[] = {0, 0, 1, -1};
    int cx, cy;
    q.emplace(0, 0);
    visited[0][0] = 1;
    while(!q.empty()){
        tie(cx, cy) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx + x[i];
            int ny = cy + y[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(nm[nx][ny]) mark[nx][ny]++;
            else if(!visited[nx][ny]){
                visited[nx][ny] = 1;
                q.emplace(nx, ny);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mark[i][j]>1){
                nm[i][j] = 0;
            }
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &nm[i][j]);
        }
    }
    int cycle = 0;
    while(1){
        if(!chk_one()) break;
        cycle++;
        bfs();
    }
    printf("%d\n", cycle);
    return 0;
}