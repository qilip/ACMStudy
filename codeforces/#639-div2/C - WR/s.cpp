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
        int a[200010] = {0};
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        set<int> s;
        int flg = 0;
        for(int i=-2*n;i<2*n;i++){
            int mod = i%n >= 0 ? i%n : n+i%n;
            if(s.count(i+a[mod])){
                flg = 1;
                break;
            }
            s.insert(i+a[mod]);
        }
        if(flg) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
