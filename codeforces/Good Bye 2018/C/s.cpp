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

ll n;
vector<ll> ans;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%lld", &n);
    for(ll i=1;i*i<=n;i++){
        if(n%i == 0){
            ans.push_back((n/i*(2+(n/i-1)*i))/2);
            if(i != n/i) ans.push_back((n/(n/i)*(2+(n/(n/i)-1)*n/i))/2);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto c : ans){
        printf("%lld ", c);
    }
    return 0;
}
