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

int n, k, nn[200010];
ll answer;
bool kk[1000'0010];

ll xx(int a){
    int cnt = 0;
    ll ans = 1;
    while(a){
        a/=10;
        cnt++;
    }
    while(cnt--){
        ans *= 10;
    }
    return ans;
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    kk[0] = true;
    for(int i=1;i<=1000'0000;i++){
        kk[((ll)k*(ll)i)%1000'0000] = true;
    }
    for(int i=0;i<n;i++){
        if(!kk[nn[i]%1000'0000]) continue;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            ll tmp = (ll)nn[j]*xx(nn[i]) + (ll)nn[i];
            if(!(tmp%k)) answer++;
        }
    }

    printf("%lld", answer);
    return 0;
}
