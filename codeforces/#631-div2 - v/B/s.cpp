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

int a[20'0010] = {0};
int ldup[20'0010] = {0};
int rdup[20'0010] = {0};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        int ldcnt = 0;
        int rdcnt = 0;
        ll lcnt = 0;
        ll rcnt = 0;
        vector<pair<int, int>> v;
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            a[i]=ldup[i]=rdup[i] = 0;
        }
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            rcnt += a[i];
            if(rdup[a[i]]) rdcnt++;
            rdup[a[i]]++;
        }
        for(int i=1;i<n;i++){
            lcnt += a[i];
            rcnt -= a[i];

            if(ldup[a[i]]) ldcnt++;
            ldup[a[i]]++;
            rdup[a[i]]--;
            if(rdup[a[i]]) rdcnt--;
            if(lcnt == (ll)(1+i)*(ll)i/2 && rcnt == (ll)(1+(n-i))*(ll)(n-i)/2 && !ldcnt && !rdcnt){
                v.emplace_back(i, n-i);
            }
        }
        printf("%d\n", (int)v.size());
        for(auto i : v){
            printf("%d %d\n", i.first, i.second);
        }
    }
    
    return 0;
}
