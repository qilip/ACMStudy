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
    int q;
    scanf("%d", &q);
    while(q--){
        ll n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);
        ll ans = 0, lft, lk = k;
        ans += min(n, m);
        lk -= ans;
        lft = n-m > 0 ? n-m : m-n ;
        if(ans+lft > k){
            printf("-1\n");
            continue;
        }
        if(lft==0 && lk%2){
            ans--;
            lk--;
        }else if(lft%2){
            ans += lft-1;
            lk -= lft-1;
            lft = 1;
        }else{
            ans += lft;
            lk -= lft;
            lft = 0;
        }
        if(lk%2 && lft == 0) lk--, lft++;
        ans += lk-lft;
        printf("%lld\n", ans);
    }    
    return 0;
}
