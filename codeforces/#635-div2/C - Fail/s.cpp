// #include <bits/stdc++.h>

/* codeforces printf %Lf problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <tuple>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <list>
#include <bitset>

using namespace std;

typedef long long ll;

vector<int> g[200010];
pair<int, ll> dc[200010];
int chk[200010];

ll cfind(int cur, int dep){
    if(chk[cur]) return 0;
    chk[cur] = 1;
    dc[cur].first = dep;
    for(auto i : g[cur]){
        dc[cur].second += cfind(i, dep+1);
    }
    return dc[cur].second + 1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n-1;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cfind(1, 0);

    ll ans = 0;
    ll tmp[200010];
    for(int i=1;i<=n;i++){
        // printf("%d:[%d,%d]\n", i, dc[i].first, dc[i].second);
        tmp[i] += (ll)dc[i].first - dc[i].second;
    }
    sort(tmp+1, tmp+n+1, greater<ll>());

    // for(int i=1;i<=n;i++)printf("[%lld]\n", tmp[i]);

    for(int i=1;i<=k;i++) ans += tmp[i];    
    printf("%lld", ans);

    return 0;
}
