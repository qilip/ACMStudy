#include <stdio.h>
#include <memory.h>

int main(void){
    int n, m;
    int dis[110][110] = {0};
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        dis[a][b] = dis[b][a] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    int min = 99999999;
    int minp = -1;
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            sum += dis[i][j];
        }
        if(sum < min){
            min = sum;
            minp = i;
        }
    }
    printf("%d\n", minp);
    return 0;
}
