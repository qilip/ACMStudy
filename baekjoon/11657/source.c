#include <stdio.h>
#include <string.h>
#define MAX 0x3F3F3F3F

typedef struct _M{
    int a;
    int b;
    int c;
} M;

int main(void){
    int n, m;
    int dist[501];
    memset(dist, 0x3F, sizeof dist);
    M mm[6010];
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &mm[i].a, &mm[i].b, &mm[i].c);
    }
    int change = 0;
    dist[1] = 0;
    for(int i=0;i<n;i++){
        change = 0;
        for(int j=0;j<m;j++){
            if(dist[mm[j].a] != MAX && dist[mm[j].b] > dist[mm[j].a] + mm[j].c){
                dist[mm[j].b] = dist[mm[j].a] + mm[j].c;
                change = 1;
            }
        }
        if(!change) break;
    }
    if(change){
        printf("-1");
    }else{
        for(int i=2;i<=n;i++){
            if(dist[i] == MAX) dist[i] = -1;
            printf("%d\n", dist[i]);
        }
    }
    return 0;
}
