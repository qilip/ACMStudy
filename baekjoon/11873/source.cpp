#include <bits/stdc++.h>

using namespace std;

int main(void){
    while(1){
        int n, m;
        scanf("%d %d", &n, &m);
        if(!n && !m) break;
        int nm[1010][1010] = {0};
        int cm[1010][1010] = {0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d", &nm[i][j]);
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            stack<pair<int, int>> st;
            st.emplace(0, 0);
            for(int j=1;j<=m;j++){
                int cur = cm[i][j] = nm[i][j] ? cm[i-1][j] + 1 : 0;
                int cj = j;
                while(st.top().first > cur){
                    if(ans < st.top().first*(j-st.top().second))
                        ans = st.top().first*(j-st.top().second);
                    cj = st.top().second;
                    st.pop();
                }
                st.emplace(cur, cj);
            }
            while(!st.empty()){
                if(ans < st.top().first*(m-st.top().second+1))
                    ans = st.top().first*(m-st.top().second+1);
                st.pop();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
