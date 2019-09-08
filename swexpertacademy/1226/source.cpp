#include <stdio.h>
#include <tuple>
#include <utility>
#include <queue>

using namespace std;

int main(void){
    for(int t=1;t<=10;t++){
        int T;
        scanf("%d", &T);
        printf("#%d ", T);
        int maze[16][16];
        queue<pair<int, int>> q;
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                scanf(" %1d", &maze[i][j]);
                if(maze[i][j] == 2) q.emplace(i, j);
            }
        }
        int x[] = {0, 1, 0, -1};
        int y[] = {-1, 0, 1, 0};
        int ans = 0;
        while(!q.empty() && !ans){
            int curx, cury;
            tie(curx, cury) = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nxtx = curx + x[i];
                int nxty = cury + y[i];
                if(maze[nxtx][nxty] == 0){
                    maze[nxtx][nxty] = 1;
                    q.emplace(nxtx, nxty);
                }
                if(maze[nxtx][nxty] == 3){
                    ans = 1;
                }
            }
        }
        if(ans) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
