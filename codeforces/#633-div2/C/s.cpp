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
        int a[100010] = {0};
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        int ans = 0;
        int cnt[32] = {0};
        int befm = a[0];
        for(int i=1;i<n;i++){
            if(befm > a[i]){
                int diff = a[i] - befm;
                int c = 0;
                while(diff){
                    cnt[c] = 1;
                    diff /= 2;
                    c++;
                }
            }
            if(befm < a[i]) befm = a[i];
        }
        for(int i=0;i<31;i++){
            if(cnt[i]) ans++;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
