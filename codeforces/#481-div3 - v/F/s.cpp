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
ll k;
vector<pair<int, int> > v;
int cnt[200010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d %lld", &n, &k);
    for(int i=1;i<=n;i++){
        int r;
        scanf("%d", &r);
        v.emplace_back(r, i);
    }
    for(ll i=0;i<k;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if(v[x-1].first > v[y-1].first) cnt[x]--;
        if(v[x-1].first < v[y-1].first) cnt[y]--;
    }
    sort(v.begin(), v.end());
    int bef = 0;
    int bcnt = 0;
    int scnt = 0;
    for(auto i : v){
        if(bef < i.first){
            bcnt = scnt;
            bef = i.first;
        }
        scnt++;
        cnt[i.second] += bcnt;
    }
    for(int i=1;i<=n;i++){
        printf("%d ", cnt[i]);
    }
    return 0;
}
