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

int n;
int d[200010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &d[i]);
    }
    int l = 0;
    int r = n-1;
    ll lsum = d[l];
    ll rsum = d[r];
    ll ans = 0;
    while(l<r){
        if(lsum < rsum){
            l++;
            lsum += d[l];
        }else if(lsum > rsum){
            r--;
            rsum += d[r];
        }else{
            ans = lsum;
            l++;
            lsum += d[l];
        }
    }
    printf("%lld", ans);
    return 0;
}
