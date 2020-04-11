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

ll a[300010] = {0};
ll b[300010] = {0};
ll cyclep[300010] = {0};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%lld %lld", &a[i], &b[i]);
        }
        ll sumcyc = 0;
        cyclep[0] = (a[0] - b[n-1]) > 0 ? (a[0] - b[n-1]) : 0;
        sumcyc = cyclep[0];
        for(int i=1;i<n;i++){
            cyclep[i] = (a[i] - b[i-1]) > 0 ? (a[i] - b[i-1]) : 0;
            sumcyc += cyclep[i];
        }
        ll ans = sumcyc - cyclep[0] + a[0];
        for(int i=1;i<n;i++){
            if(ans > sumcyc - cyclep[i] + a[i]) ans = sumcyc - cyclep[i] + a[i];
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}
