#include <stdio.h>
#include <stdlib.h>

int n, w;
int nn[1010][2];
int dp[1010][1010];
int bef[1010][1010];

int dist(int ax, int ay, int bx, int by){
    return abs(ax-bx) + abs(ay-by);
}

int d(int a, int b){

}

int main(void){
    scanf("%d %d", &n, &w);
    for(int i=2;i<=w;i++){
        scanf("%d %d", &nn[i][0], &nn[i][1]);
    }
    d(0, 1);
    return 0;
}
