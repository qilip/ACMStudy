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

    int n;
    int x[1010], y[1010];
    pair<int, int> ab[1010];
    int a[1010], b[1010];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d %d", &ab[i].first, &ab[i].second);
    }
    sort(ab, ab+n);
    for(int i=0;i<n;i++){
        a[i] = ab[i].first;
        b[i] = ab[i].second;
    }
    for(int i=0;i<n;i++){
        int tx = x[0] + a[i];
        int ty = y[0] + b[i];
        int flg = 1;
        for(int j=1;j<n;j++){
            int lo = lower_bound(a, a+n, tx-x[j]) - a;
            int hi = upper_bound(a, a+n, tx-x[j]) - a;
            int f2 = 0;
            for(int k = lo ; k<hi; k++){
                if(b[k] == ty-y[j]){
                    f2 = 1;
                    break;
                }
            }
            if(f2==0){
                flg = 0;
                break;
            }
        }
        if(flg){
            printf("%d %d", tx, ty);
        }
    }
    
    return 0;
}
