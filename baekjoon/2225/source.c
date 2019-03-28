#include <stdio.h>

int main(void){
    int MOD = 1000000000;
    int n, m;
    int d[210][210] = {0};
    d[0][0] = 1;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            for(int k=j;k<=n;k++){
                d[i][k] += d[i-1][k-j]%MOD;
                d[i][k] %= MOD;
            }
        }
    }
    printf("%d", d[m][n]%MOD);
    return 0;
}
