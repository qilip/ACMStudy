#include <stdio.h>

int dist[1010][1010];
int n, x[1010], y[1010];

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dist[i][j] = dist[j][i] = (x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i]);
        }
    }
    int cant[1010] = {0};
    int cur = 0;
    int cnt = n;
    while(cnt>1){
        if(!cant[cur]){
            int mind = 999999999;
            int mi = 0;
            for(int i=0;i<n;i++){
                if(cant[i] || i==cur) continue;
                if(mind > dist[cur][i]){
                    mind = dist[cur][i];
                    mi = i;
                }
            }
            cnt--;
            cant[mi] = 1;
        }
        cur++;
        if(cur==n) cur = 0;
    }
    for(int i=0;i<n;i++){
        if(!cant[i]){
            printf("%d", i+1);
            break;
        }
    }
    return 0;
}
