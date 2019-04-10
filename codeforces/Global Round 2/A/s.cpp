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
    int c[300010];
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &c[i]);
    }
    int ans = 0;
    for(int i=n;i>1;i--){
        if(c[i] != c[1]){
            ans = i-1;
            break;
        }
    }
    for(int i=1;i<n;i++){
        if(c[i] != c[n]){
            ans = ans < n-i ? n-i : ans;
            break;
        }
    }
    printf("%d", ans);    
    return 0;
}
