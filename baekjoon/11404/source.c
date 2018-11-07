#include <stdio.h>

int n, m;
int d[101][101];

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) d[i][j] = 0;
            else d[i][j] = 1000000000;
        }
    }
    for(int i=0;i<m;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        d[a][b] = c > d[a][b] ? d[a][b] : c;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j] = d[i][j] > d[i][k] + d[k][j] ? d[i][k] + d[k][j] : d[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ", d[i][j]==1000000000 ? 0 : d[i][j]);
        printf("\n");
    }
    return 0;
}
