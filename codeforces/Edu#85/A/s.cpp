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
    scanf("%d" ,&t);
    while(t--){
        int n;
        scanf("%d", &n);
        int p[110] = {0};
        int c[110] = {0};
        for(int i=0;i<n;i++){
            scanf("%d %d", &p[i], &c[i]);
        }
        int ans = 1;
        if(p[0] < c[0]) ans = 0;
        for(int i=1;i<n;i++){
            if(p[i] < c[i] || p[i-1] > p[i] || c[i-1] > c[i]) ans = 0;
            if(c[i]-c[i-1] > p[i]-p[i-1]) ans = 0;
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
