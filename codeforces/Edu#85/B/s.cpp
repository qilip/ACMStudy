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

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        ll x;
        scanf("%d %lld", &n, &x);
        int a[100010] = {0};
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        sort(a, a+n, greater<int>());
        ll sum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(x*(i+1) > sum + a[i]){
                ans = i;
                break;
            }
            sum += a[i];
        }
        if(x*n <= sum) ans = n;
        printf("%d\n", ans);
    }
    
    return 0;
}
