#include <stdio.h>

int n, nn[12][12];
int ans = 99999999;
int dist[12][12];

void bt(int x, int y, int dep, int cost){
    if(dep==3){
        if(ans>cost) ans = cost;
        return;
    }
    for(int i=x;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            if(!dist[i][j] && !dist[i-1][j] && !dist[i+1][j] && !dist[i][j-1] && !dist[i][j+1]){
                int ncost = cost + nn[i][j] + nn[i-1][j] + nn[i+1][j] + nn[i][j-1] + nn[i][j+1];
                dist[i][j] = dist[i-1][j] = dist[i+1][j] = dist[i][j-1] = dist[i][j+1] = 1;
                bt(i, j, dep+1, ncost);
                dist[i][j] = dist[i-1][j] = dist[i+1][j] = dist[i][j-1] = dist[i][j+1] = 0;
            }
        }
    }
}

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &nn[i][j]);
        }
    }
    bt(1, 1, 0, 0);
    printf("%d", ans);
    return 0;
}
