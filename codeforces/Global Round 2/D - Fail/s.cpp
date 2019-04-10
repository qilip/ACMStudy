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
typedef unsigned long long ull;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n;
    scanf("%d", &n);
    vector<ll> s;
    for(int i=0;i<n;i++){
        ll t;
        scanf("%lld", &t);
        s.push_back(t);
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    int q;
    scanf("%d", &q);
    for(int i=0;i<q;i++){
        ll l, r;
        scanf("%lld %lld", &l, &r);
        ll bef = -1;
        ll cnt = 0;
        int cur = 0;
        while(cur<(int)s.size()){
            if(bef < s[cur]+l){
                cnt += r-l+1LL;
            }else{
                cnt += s[cur]+r - bef + 1LL;
            }
            bef = s[cur]+r;
            cur = upper_bound(s.begin(), s.end(), bef-l) - s.begin();
            printf("(%lld ", cnt);
            cnt += s[cur-1]+r - bef;
            printf("(%lld, %d, %lld| \n", cnt, cur, bef);
        }
        printf("%lld ", cnt);
    }
    
    return 0;
}
