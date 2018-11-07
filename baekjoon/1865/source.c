#include <stdio.h>
#include <string.h>
#define MAX 0x3f3f3f3f

typedef struct Edge{
    int s, e, c;
}Edge;

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, w;
        Edge edge[6010];
        scanf("%d %d %d", &n, &m, &w);
        for(int i=0;i<2*m;i+=2){
            scanf("%d %d %d", &edge[i].s, &edge[i].e, &edge[i].c);
            edge[i+1].s = edge[i].e;
            edge[i+1].e = edge[i].s;
            edge[i+1].c = edge[i].c;
        }
        for(int i=2*m;i<2*m+w;i++){
            scanf("%d %d %d", &edge[i].s, &edge[i].e, &edge[i].c);
            edge[i].c = -edge[i].c;
        }
        int dist[510];
        memset(dist, 0x3f, sizeof dist);
        dist[1] = 0;
        int cng = 0;
        for(int i=0;i<n;i++){
            cng = 0;
            for(int j=0;j<2*m+w;j++){
                if(dist[edge[j].e] > dist[edge[j].s] + edge[j].c){
                    dist[edge[j].e] = dist[edge[j].s] + edge[j].c;
                    cng = 1;
                }
            }
            if(!cng) break;
        }
        if(cng)
            printf("YES\n");
        else
            printf("NO\n");        
    }
    return 0;
}
