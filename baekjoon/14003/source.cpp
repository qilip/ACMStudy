#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int n;
int nn[1'000'010];
int dp[1'000'010];
int last = 0;
int tra[1'000'010];
int val[1'000'010];
stack<int> st;

int main(void){
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &nn[i]);
    dp[0] = -20'0000'0000;
    for(int i=1;i<=n;i++){
        if(dp[last] < nn[i]){
            dp[++last] = nn[i];
            tra[i] = last;
            val[i] = nn[i];
        }else{
            int f = lower_bound(dp, dp+last, nn[i]) - dp;
            dp[f] = nn[i];
            tra[i] = f;
            val[i] = nn[i];
        }
    }
    printf("%d\n", last);
    int cur = last;
    for(int i=n;i>=1;i--){
        if(cur == tra[i]){
            st.push(val[i]);
            cur--;
        }
    }
    while(!st.empty()){
        printf("%d ", st.top());
        st.pop();
    }
    return 0;
}
