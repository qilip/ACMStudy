// #include <bits/stdc++.h>

/* codeforces printf %Lf problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
*/

#define _USE_MATH_DEFINES
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
#include <bitset>

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
        scanf("%d", &n);
        double ans = 1;
        int k = (n - 2)/2;
        n += n;
        double c = 180.0 * (n-2) / n;
        double ic = c - 90;
        double dc = 180 - c;
        while(k){
            double r = ic * M_PI / 180.0;
            ans += sin(r)*2;
            // printf("%d:(%lf)(%lf)[%lf]\n", k, sin(r), cos(r), ans);
            ic -= dc;
            k--;
        }
        printf("%.9lf\n", ans);
    }
    
    return 0;
}
