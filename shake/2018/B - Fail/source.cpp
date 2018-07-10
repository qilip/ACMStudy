#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

int n, t, r, c;
int dp[510][510];
int x[]={-1, 0, 1, 0}, y[]={0, 1, 0, -1};
bool xwp[510] = {0}, ywp[510] = {0}, xywp[510][510][4] = {0};

int main(void){
    memset(dp, 40, sizeof(dp));
    scanf("%d %d %d %d", &n, &t, &r, &c);
    char nn[510][510] = {0};
    for(int i=1;i<=n;i++){
        scanf("%s", nn[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(nn[i][j]=='#'){
                xwp[i] = 1;
                ywp[j] = 1;
            }
        }
    }
    priority_queue<tuple<int, int, int, int>> q;
    q.emplace(0, 1, 1, 0); // mov cnt, x, y, 변신유무
    q.emplace(-t, 1, 1, 1);
    dp[1][1] = 0;
    while(!q.empty()){
        int cx, cy, cc, ct;
        tie(cc, cx, cy, ct) = q.top();
        cc *= -1;
        q.pop();
        //if(nn[cx][cy]!='#') nn[cx][cy] = 1;
        if(cx != r || cy != c){
            for(int i=0;i<4;i++){
                if(!ct && nn[cx + x[i]][cy + y[i]] && dp[cx + x[i]][cy + y[i]] > dp[cx][cy]+1){
                    q.emplace(-(dp[cx][cy]+1), cx + x[i], cy + y[i], ct);
                    dp[cx + x[i]][cy + y[i]] = dp[cx][cy]+1;
                }
                if(ct){
                    int tp = 1;
                    if(xywp[cx][cy][i]) continue;
                    xywp[cx][cy][i] = 1;
                    while(nn[cx + x[i]*tp][cy + y[i]*tp]=='.'){
                        xywp[cx + x[i]*tp][cy + y[i]*tp][i]=1;
                        tp++;
                    }
                    if(nn[cx + x[i]*tp][cy + y[i]*tp]=='#' && dp[cx + x[i]*tp][cy + y[i]*tp] > cc+1){
                        q.emplace(-(cc+1), cx + x[i]*tp, cy + y[i]*tp, ct);
                        q.emplace(-(cc+1), cx + x[i]*tp, cy + y[i]*tp, !ct);
                        dp[cx + x[i]*tp][cy + y[i]*tp] = cc+1;
                    }
                }
            }
            if(!ct && (xwp[cx] || ywp[cy])){
                q.emplace(-(dp[cx][cy]+t), cx, cy, 1);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%c ", nn[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d", dp[r][c]);
    return 0;
}
