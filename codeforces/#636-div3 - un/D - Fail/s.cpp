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

int a[200010];
int in[400010] = {0};
int out[400010] = {0};
int sum[400010] = {0};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
        }
        for(int i=0;i<=2*k;i++){
            in[i] = out[i] = sum[i] = 0;
        }
        int ans = 0;
        for(int i=1;i<=n/2;i++){
            if(a[i] > a[n-i+1]) swap(a[i], a[n-i+1]);
            in[a[i]+1]++;
            out[k+a[n-i+1]]++;
            sum[a[i]+a[n-i+1]]++;
        }
        int mi = 0;
        int msum = 0;
        int mcnt = 0;
        for(int i=0;i<=2*k;i++){
            if(msum < sum[i]){
                msum = sum[i];
                mi = i;
            }
        }
        int cnt = 0;
        vector<int> v;
        for(int i=0;i<=2*k;i++){
            if(i == mi) mcnt = cnt;
            cnt += in[i];
            if(cnt > ans){
                ans = cnt;
                // printf("<%d,%d>", cnt, i);
                v.clear();
                v.push_back(i);
            }else if(cnt == ans){
                v.push_back(i);
            }
            cnt -= out[i];
        }
        ans += (n/2 - ans)*2;
        int zero = 0;
        for(auto i : v){
            if(zero < sum[i]){
                zero = sum[i];
                // printf("[%d:%d]", i, sum[i]);
            }
        }
        ans -= zero;
        // printf("(%d:%d)", mcnt, msum);
        if(ans > mcnt - msum + (n/2-mcnt)*2) ans = mcnt - msum + (n/2-mcnt)*2;
        printf("%d\n", ans);
    }    
    return 0;
}
