#include <stdio.h>

int w, h, wh[60][60];
int xx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int yy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void sh(int x, int y){
    wh[x][y] = 0;
    for(int i=0;i<8;i++){
        int nextX = x + xx[i];
        int nextY = y + yy[i];
        if(wh[nextX][nextY]) sh(nextX, nextY);
    }
}

int main(void){
    while(1){
        int cnt = 0;
        scanf("%d %d", &w, &h);
        if(!w && !h) break;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                scanf("%d", &wh[i][j]);
            }
        }
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(wh[i][j]){
                    cnt++;
                    sh(i, j);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
