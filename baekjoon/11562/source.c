#include <stdio.h>

int main(void){
    int n, m;
    int d[251][251] = {0};
    for(int i=1;i<=250;i++)
        for(int j=1;j<=250;j++)
            if(i!=j)
                d[i][j] = 99999999;
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int u, v, b;
        scanf("%d %d %d", &u, &v, &b);
        d[u][v] = 1;
        d[v][u] = 1000;
        if(b) d[v][u] = 1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(d[i][j] > d[i][k]+d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
    int k;
    scanf("%d", &k);
    for(int i=0;i<k;i++){
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", d[s][e]/1000);
    }
    return 0;
}
