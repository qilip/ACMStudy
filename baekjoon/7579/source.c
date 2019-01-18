#include <stdio.h>

int main(void){
    int n, m;
    int nn[110], nm[110];
    int cost[10010] = {0};
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &nm[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=10000;j>=nm[i];j--){
            cost[j] = cost[j] < cost[j-nm[i]] + nn[i] ? cost[j-nm[i]] + nn[i] : cost[j];
        }
    }
    for(int i=0;i<=10000;i++){
        if(cost[i]>=m){
            printf("%d", i);
            break;
        }
    }
    return 0;
}
