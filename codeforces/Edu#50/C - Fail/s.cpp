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

int classy(ll a){
    int ans = 0;
    while(a){
        if(a%10){
            ans++;
        }
        a/=10;
    }
    return ans;
}

int last_n(ll a){
    while(a){
        if(a%10){
            return a%10;
        }
        a/=10;
    }
}

ll last_ten(ll a){
    ll ans = 1;
    while(a){
        if(a%10){
            return ans;
        }
        a/=10;
        ans *= 10;
    }
}

int last_zcnt(ll a){
    int ans = 0;
    while(a){
        if(a%10){
            return ans;
        }
        a/=10;
        ans++;
    }    
}

ll ncr[20][4];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start
    ncr[1][1] = 1;
    for(int i=2;i<=19;i++){
        for(int j=1;j<=2;j++){
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
        }
    }
    int t;
    scanf("%d", &t);
    while(t--){
        ll l, r, x;
        scanf("%lld %lld", &l, &r);
        x = l;
        ll ans = 0;
        while(x<r){
            int clt = classy(x);
            int ln = last_n(x);
            ll lt = last_ten(x);
            if(clt>3){
                x += (10-ln)*lt;
            }else if(clt==3){
                if(x+(10-ln)*lt<=r){
                    ans += 10-ln;
                    x += (10-ln)*lt;
                }else{
                    while(x+lt<=r){
                        ans++;
                        x += lt;
                    }
                }
            }else{
                int left = 3-clt;
                if(x+(10-ln)*lt<r){
                    ans += (10-ln)*ncr[last_zcnt(x)][left]*(left>1 ? 81 : 9);
                }else{
                    //중간에 r을 넘을경우.
                }
            }
        }
        printf("%lld\n", ans);
    }   
    return 0;
}
