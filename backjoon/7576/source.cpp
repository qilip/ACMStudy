#include <cstdio>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int mn[1005][1005];
queue<int> xy;

int main(void){
    int M, N;
    memset(mn, 0xff, sizeof(mn));
    scanf("%d %d", &M, &N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d", &mn[i][j]);
            if(mn[i][j]==1){
                xy.push(i);
                xy.push(j);
            }
        }
    }
    while(xy.size()){
        int nowx = xy.front();
        xy.pop();
        int nowy = xy.front();
        xy.pop();
        for(int i=0;i<4;i++){
            int nx = nowx + dx[i];
            int ny = nowy + dy[i];
            if(mn[nx][ny]==-1)continue;
            if( !mn[nx][ny] || mn[nx][ny] > mn[nowx][nowy]+1 ){
                mn[nx][ny] = mn[nowx][nowy]+1;
                xy.push(nx);
                xy.push(ny);
            }
        }   
    }
    int maxi=-1000;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!mn[i][j]){
                printf("-1\n");
                return 0;
            }
            if(maxi<mn[i][j]){
                maxi=mn[i][j];
            }
        }
    }
    printf("%d", maxi-1);
    return 0;
}
