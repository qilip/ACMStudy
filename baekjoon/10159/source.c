#include <stdio.h>
#include <string.h>

int main(void){
    int n, m;
    int fow[110][110];
    int bac[110][110];
    memset(fow, 0x0f, sizeof fow);
    memset(bac, 0x0f, sizeof bac);
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        fow[a][b] = 1;
        bac[b][a] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(fow[i][k] + fow[k][j] < 0x0f0f0f0f) fow[i][j] = fow[i][k] + fow[k][j];
                if(bac[i][k] + bac[k][j] < 0x0f0f0f0f) bac[i][j] = bac[i][k] + bac[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(fow[i][j] >= 0x0f0f0f0f && bac[i][j] >= 0x0f0f0f0f) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
