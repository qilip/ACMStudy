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
pair<int, ll> dc[200010]; // depth, child
int chk[200010];
ll ans = 0;
ll tmp[200010];

queue<pair<int, int>> q; // cur, dep
priority_queue<pair<int, pair<int, int>>> qq; // dep, cur, child
void dfind(void){
    q.emplace(1, 0);
    chk[1] = 1;
    dc[1].first = 0;
    while(!q.empty()){
        int cur = q.front().first;
        int dep = q.front().second;
        dc[cur].first = dep;
        q.pop();
        if(cur != 1 && g[cur].size() == 1){
            qq.push({dep, {cur, 0}});
        }else for(auto i : g[cur]){
            if(!chk[i]){
                q.emplace(i, dep+1);
                chk[i] = 1;
            }
        }
    }
    return;
}

void ufind(void){
    while(!qq.empty()){
        int dep = qq.top().first;
        int cur = qq.top().second.first;
        int cld = qq.top().second.second;
        dc[cur].second += cld;
        qq.pop();
        for(auto i : g[cur]){
            if(dep > dc[i].first){
                qq.push({dep-1, {i, cld+1}});
            }
        }
    }
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
    dfind();
    ufind();

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
