#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

int xx[] = {-1, 0, 1, 0};
int yy[] = {0, 1, 0, -1};
int n, nn[30][30];
vector<int> v;

void bfs(int x, int y){
    queue<tuple<int, int> > q;
    int cnt = 0;
    q.emplace(x, y);
    cnt++;
    nn[x][y] = 2;
    while(!q.empty()){
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx+xx[i];
            int ny = cy+yy[i];
            if(nn[nx][ny]==1){
                nn[nx][ny] = 2;
                cnt++;
                q.emplace(nx, ny);
            }
        }
    }
    v.push_back(cnt);
}

int main(void){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d", &nn[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(nn[i][j]==1){
                bfs(i, j);
            }
        }
    }
    printf("%d\n", v.size());
    sort(v.begin(), v.end());
    for(auto i : v){
        printf("%d\n", i);
    }
    return 0;
}
