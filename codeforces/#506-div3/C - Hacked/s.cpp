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
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int n;

vector<pair<int, int>> lr, rl;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int lt, rt;
        scanf("%d %d", &lt, &rt);
        lr.emplace_back(lt, rt);
        rl.emplace_back(rt, lt);
    }
    sort(lr.begin(), lr.end());
    sort(rl.begin(), rl.end());
    int ans =  0 < rl[0].first - lr[n-1].first ? rl[0].first - lr[n-1].first : 0;
    if(lr[n-1].first == rl[0].second && lr[n-1].first == rl[0].first){
        ans = ans < (rl[1].first - lr[n-2].first) ? (rl[1].first - lr[n-2].first) : ans;
    }else{
        int tp = max(rl[0].first - lr[n-2].first, rl[1].first - lr[n-1].first);
        ans = ans < tp ? tp : ans;
    }
    printf("%d", ans);
    return 0;
}
