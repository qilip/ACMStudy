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

using namespace std;

typedef long long ll;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int b[100010] = {0};
    pair<int, int> bb[100010];
    for(int i=0;i<n;i++){
        scanf("%d", &b[i]);
    }
    if(n==1){
        printf("1");
        return 0;
    }
    for(int i=1;i<n;i++){
        bb[i-1].first = b[i] - b[i-1] + 1;
        bb[i-1].second = i;
    }
    sort(bb, bb+n-1, greater<pair<int, int>>());
    ll ans = 0;
    bool flg[100010] = {false};
    flg[0] = true;
    flg[n] = true;
    for(int i=0;i<k-1;i++){
        flg[bb[i].second] = true;
        if(flg[bb[i].second-1] && flg[bb[i].second+1]) ans++;
        if(flg[bb[i].second-1] || flg[bb[i].second+1]) ans++;
    }
    bool f2[100010] = {false};
    for(int i=k-1;i<n-1;i++){
        ans += (ll)bb[i].first;
        f2[bb[i].second] = true;
        if(f2[bb[i].second-1] && f2[bb[i].second+1]) ans--;
        if(f2[bb[i].second-1] || f2[bb[i].second+1]) ans--;
    }
    printf("%lld", ans);
    return 0;
}
