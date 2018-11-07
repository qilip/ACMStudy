#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int m, n, l, g;
        int garo[110][110] = {0};
        int sero[110][110] = {0};
        scanf("%d %d %d %d", &m, &n, &l, &g);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n-1;j++){
                scanf("%d", &garo[i][j]);
            }
        }
        for(int i=1;i<=m-1;i++){
            for(int j=1;j<=n;j++){
                scanf("%d", &sero[i][j]);
            }
        }
        int dp[110][110][210][2] = {0}; //m, n, k회전, d방향
        
        
        
    }
    return 0;
}
