#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, w;
int nn[1010][2]; // [사건번호][x, y]
int dp[1010][1010]; // [경찰치 1][경찰차 2]

int dist(int cur, int next){
    return abs(nn[cur][0] - nn[next][0]) + abs(nn[cur][1] - nn[next][1]);
}

int d(int a, int b){
    if(a==w || b==w) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    int next = max(a, b) + 1;
    int p1 = d(next, b) + dist(a, next);
    int p2 = d(a, next) + dist(b, next);
    return dp[a][b] = min(p1, p2);
}

void trace(int a, int b){
    if(a==w || b==w) return;
    int next = max(a, b) + 1;
    int p1 = dp[next][b] + dist(a, next);
    int p2 = dp[a][next] + dist(b, next);
    if(p1 > p2){
        printf("2\n");
        trace(a, next);
    }else{
        printf("1\n");
        trace(next, b);
    }
}

int main(void){
    scanf("%d %d", &n, &w);
    w++;
    nn[0][0] = nn[0][1] = 1;
    nn[1][0] = nn[1][1] = n;
    for(int i=2;i<=w;i++){
        scanf("%d %d", &nn[i][0], &nn[i][1]);
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", d(0, 1));
    trace(0, 1);
    return 0;
}
