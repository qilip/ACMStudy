#include <stdio.h>
#include <memory.h>

int main(void){
    int N, M, nm[110][110], cnt = 1, x = 1, y = 1;
    int xx[4] = {-1, 1, 0, 0}, yy[4] = {0, 0, -1, 1};
    int que[30010], ptrl = 0, ptrr = 0;
    memset(nm, 0xff, sizeof(nm));
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%1d", &nm[i][j]);
        }
    }
    while(1){
        for(int i=0;i<4;i++){
            int gox = x + xx[i], goy = y + yy[i];
            if( nm[ gox ][ goy ] == 1 || nm[ gox ][ goy ] > nm[ x ][ y ] + 1 ){
                nm[ gox ][ goy ] = nm[ x ][ y ] + 1;
                que[ptrr] = x + xx[i];
                ptrr++;
                que[ptrr] = y + yy[i];
                ptrr++;
            }
        }
        x = que[ptrl]; ptrl++; y = que[ptrl]; ptrl++;
        if(x==N && y==M) break;
    }
    printf("%d", nm[N][M]);
    return 0;
}
