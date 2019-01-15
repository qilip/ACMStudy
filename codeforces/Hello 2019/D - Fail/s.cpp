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
const int MOD = 10'0000'0007;

ll ppow(ll base, ll exp){
    if(base==1) return 1;
    ll ans = 1;
    while(exp){
        if(exp&1){
            ans = (ans*base) % MOD;
        }
        base = (base*base) % MOD;
        exp >>= 1;
    }
    return ans % MOD;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    ll n, k;
    vector<ll> div;
    scanf("%lld %lld", &n, &k);
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            div.push_back(i);
            if(i != n/i) div.push_back(n/i);
        }
    }
    sort(div.begin(), div.end(), greater<ll>());
    ll q = ppow(div.size(), k);
    ll p = 0;
    vector<ll> acnt(div.size());

    if(k==1){
        for(int i=0;i<div.size();i++){
            acnt[i] += q/div.size();
        }
    }
    if(k>1){
        for(int i=0;i<div.size();i++){
            int ccnt = 1;
            for(int j=i+1;j<div.size();j++){
                if(div[i]%div[j]==0) ccnt++;
            }
            for(int j=i;j<div.size();j++){
                if(div[i]%div[j]==0){
                    for(int e=1;e<k;e++){
                        acnt[j] += q/( ppow(ccnt, e)*ppow(div.size(), k-e) );
                    }
                }
            }
        }
    }
    acnt[0] = 1;
    for(int i=0;i<div.size();i++){
        p += div[i] * acnt[i] % MOD;
        p %= MOD;
    }

    for(auto i : acnt){
        printf("%lld\n", i);
    }

    printf("%lld %lld\n", p, q);

    ll ans = p * ppow(q, MOD-2) %MOD;
    printf("%lld", ans);
    return 0;
}
