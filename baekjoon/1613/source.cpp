#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e9;

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    ll dist[410][410];
    fill(&dist[0][0], &dist[0][0] + 410 * 410, INF);
    while(k--){
        int a, b;
        scanf("%d %d", &a, &b);
        dist[a][b] = 0;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int s;
    scanf("%d", &s);
    while(s--){
        int a, b;
        scanf("%d %d", &a, &b);
        if(!dist[a][b]) printf("-1\n");
        else if(dist[a][b]==INF && !dist[b][a]) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
