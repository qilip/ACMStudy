#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
    int n;
    scanf("%d", &n);
    ll ans = 0;
    stack<pair<ll, int>> st;
    st.emplace(0, 0);
    for(int i=1;i<=n;i++){
        int c;
        scanf("%d", &c);
        int ci = i;
        while(st.top().first > c){
            if(ans < st.top().first*(i-st.top().second))
                ans = st.top().first*(i-st.top().second);
            ci = st.top().second;
            st.pop();
        }
        st.emplace(c, ci);
    }
    while(!st.empty()){
        if(ans < st.top().first*(n-st.top().second+1))
            ans = st.top().first*(n-st.top().second+1);
        st.pop();
    }
    printf("%lld\n", ans);
    return 0;
}
