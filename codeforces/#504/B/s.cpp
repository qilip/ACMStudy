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
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <tuple>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    ll n, k;
    scanf("%lld %lld", &n, &k);
    if(n+n-1<k) { printf("0"); return 0; }
    ll a, b;
    if(n+1>=k){
        a = k-1;
        b = a/2;
    }else{
        a = k-n;
        b = (n-a+1)/2;
    }
    printf("%lld", b);
    return 0;
}
