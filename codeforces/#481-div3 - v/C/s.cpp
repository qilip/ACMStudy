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

int n, m;
ll an[200010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        ll a;
        scanf("%lld", &a);
        an[i] = a + an[i-1];
    }
    for(int i=1;i<=m;i++){
        ll cur;
        scanf("%lld", &cur);
        int c = lower_bound(an+1, an+n+1, cur) - an;
        printf("%d ", c);
        printf("%lld\n", cur-an[c-1]);
    }
    
    return 0;
}
