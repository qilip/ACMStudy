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

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n, k;
    ll s;
    scanf("%d %d %lld", &n, &k, &s);
    if((ll)(n-1)*k < s || k > s){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    int now = 1;
    while(s-(n-1) >= k){
        if(now==1) now = n;
        else now = 1;
        s -= n-1;
        k--;
        printf("%d ", now);
    }
    if(s > k){
        if(now==1) now = 1 + s-k + 1;
        else now = n - (s-k+1);
        s -= s-k+1;
        k--;
        printf("%d ", now);
    }
    int go = 1;
    while(s){
        if(now == 1) go = 1;
        if(now == n) go = -1;
        now += go;
        s--;
        k--;
        printf("%d ", now);
    }
    return 0;
}
