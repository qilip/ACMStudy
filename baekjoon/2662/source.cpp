#include <stdio.h>
#include <stack>

using namespace std;

int main(void){
    int n, m;
    int nn[302][22] = {0};
    int dp[302][22] = {0};
    int ck[302][22] = {0};
    stack<int> st;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d", &t);
        for(int j=1;j<=m;j++){
            scanf("%d", &nn[t][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=i;k>=0;k--){
                if(dp[i][j] < dp[k][j-1] + nn[i-k][j]){
                    dp[i][j] = dp[k][j-1] + nn[i-k][j];
                    ck[i][j] = k;
                }
            }
        }
    }
    int a = n, b = m;
    while(b){
        st.push(a - ck[a][b]);
        a = ck[a][b];
        b--;
    }
    printf("%d\n", dp[n][m]);
    while(!st.empty()){
        printf("%d ", st.top());
        st.pop();
    }
    return 0;
}
