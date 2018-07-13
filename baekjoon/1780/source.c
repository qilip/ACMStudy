#include <stdio.h>

int n, nn[2200][2200], cnt[3];

void dc(int sx, int sy, int siz){
    if(siz==1){
        cnt[nn[sx][sy]+1]++;
        return;
    }
    int c = nn[sx][sy], flg = 0;
    for(int i=sx;i<sx+siz;i++){
        for(int j=sy;j<sy+siz;j++){
            if(nn[i][j]!=c) { flg = 1; goto DV; }
        }
    }
    DV:;
    if(flg){
        int nsiz = siz/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                dc(sx+nsiz*i, sy+nsiz*j, nsiz);
            }
        }
    }else{
        cnt[c+1]++;
    }
    return;
}

int main(void){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &nn[i][j]);
        }
    }
    dc(1, 1, n);
    printf("%d\n%d\n%d", cnt[0], cnt[1], cnt[2]);
    return 0;
}
