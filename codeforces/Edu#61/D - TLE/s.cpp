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

int n, k;
ll a[200010];
ll b[200010];
ll c[200010];

bool run(ll m){
    int lop = k-1;
    memset(c, 0, sizeof(ll)*200010);
    while(lop--){
        long double mint = 20'0000'0000;
        int mini = 0;
        int mii = -1;
        for(int i=0;i<n;i++){
            c[i] -= b[i];
            if(a[i]+c[i]<0){
                if(mii != -1) return false;
                else mii = i;
            }
            long double ct = (long double)(a[i]+c[i])/(long double)b[i];
            if(mint > ct){
                mint = ct;
                mini = i;
            }
        }
        if(mii != -1 && mii != mini) return false;
        c[mini] += m;
        if(a[mini] + c[mini]<0) return false;
    }
    return true;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%lld", &a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lld", &b[i]);
    }
    ll l = 0;
    ll r = 2000000000010;
    ll m;
    ll ans = -1;
    int cnt = 2;
    while(l<=r){
        cnt--;
        m = (l+r)/2;
        if(run(m)){
            r = m-1;
            ans = m;
        }else{
            l = m+1;
            if(cnt>0) break;
        }
    }
    printf("%lld", ans);
    return 0;
}
