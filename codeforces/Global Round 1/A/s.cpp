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

int b, k;

ll ppow(ll a, ll b){
    if(b==0) return 1;
    ll ext = 1;
    while(b>1){
        if(b&1){
            ext = (ext*a) %2;
        }
        a = (a * a) %2;
        b = b >> 1;
    }
    return (a*ext) %2;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d %d", &b, &k);
    ll sum = 0;
    for(int i=0;i<k;i++){
        ll cur = 0;
        scanf("%lld", &cur);
        ll c = ppow(b, k-i-1);
        sum += cur * c;
        sum %= 2;
    }
    if(sum%2) printf("odd");
    else printf("even");
    return 0;
}
