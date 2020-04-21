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
        ll ans = 0;
        int a[200010] = {0};
        for(int i=1;i<=n;i++)
            scanf("%d", &a[i]);
        int m = -11'1111'1111;
        m = a[1];
        for(int i=2;i<=n;i++){
            if((m>0) == (a[i]>0)){
                m = max(m, a[i]);
            }else{
                ans += m;
                m = a[i];
            }
        }
        ans += m;
        printf("%lld\n", ans);
    }
    
    return 0;
}
