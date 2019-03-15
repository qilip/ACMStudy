#include <stdio.h>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int main(void){
    int m, n, m1[2], m2[2];
    int mn[31][31];
    int cnt[31][31] = {0};
    queue<pair<int, int>> q;
    int x[] = {1, 1, -1, -1};
    int y[] = {1, -1, 1, -1};
    scanf("%d %d %d %d", &m, &n, &m1[0], &m2[0]);
    m1[1] = m2[0];
    m2[1] = m1[0];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &mn[i][j]);
            if(mn[i][j]==3){
                q.emplace(i, j);
                mn[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();
        for(int i=0;i<2;i++){
            for(int j=0;j<4;j++){
                int nx, ny;
                nx = cx+m1[i]*x[j];
                ny = cy+m2[i]*y[j];
                if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
                if(mn[nx][ny]==1){
                    mn[nx][ny] = 0;
                    cnt[nx][ny] = cnt[cx][cy]+1;
                    q.emplace(nx, ny);
                }
                if(mn[nx][ny]==4){
                    printf("%d", cnt[cx][cy]+1);
                    return 0;
                }
            }
        }
    }
    return 0;
}
