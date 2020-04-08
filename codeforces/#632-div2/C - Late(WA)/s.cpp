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

int n;
int a[200010] = {0};
ll psum[200010] = {0};
int st[200010] = {0};
int ed[200010] = {0};
int eds[200010] = {0};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    vector<pair<ll, int>> vp;
    vp.emplace_back(0, 0);
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        psum[i] = a[i] + psum[i-1];
        vp.emplace_back(psum[i], i);
    }
    sort(vp.begin(), vp.end());
    vector<pair<int, int>> v;

    int cnt = 0;
    for(auto i = vp.begin()+1; i<vp.end(); i++){
        if((i-1)->first == i->first){
            v.emplace_back((i-1)->second+1, i->second);
            st[(i-1)->second+1] = ++cnt;
            ed[i->second] = cnt;
            eds[cnt] = (i-1)->second+1;
        }
    }

    ll ans = 0;
    
    bool *cur = (bool*) calloc(n+10, sizeof(bool));
    int start = 1;
    for(int i=1;i<=n;i++){
        if(cur[ed[i]]){
            int ch = (i-1)-start+1;
            ans += (1+ch)*ch/2;
            int ich = i-eds[ed[i]]-1;
            ans -= (1+ich)*ich/2;
            free(cur);
            cur = (bool*) calloc(n+10, sizeof(bool));
            i = eds[ed[i]]+1;
            start = i;
        }
        if(st[i]) cur[i] = true;
    }
    int ach = n-start+1;
    ans += (1+ach)*ach/2;


    // for(auto i : vp) printf("%lld(%d)\n", i.first, i.second);
    // for(auto i : v) printf("%d~%d\n", i.first, i.second);

    printf("%lld", ans);    
    return 0;
}
