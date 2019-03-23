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

    int n, k;
    vector<pair<int, int>> v;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        int t, b;
        scanf("%d %d", &t, &b);
        v.emplace_back(b, t);
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    ll mb = 0;
    ll sum = 0;
    ll max = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        mb = v[i].first;
        sum += v[i].second;
        pq.push(v[i].second);
        if(i>=k){
            sum -= pq.top();
            pq.pop();
        }
        ll cur = mb * sum;
        max = max > cur ? max : cur ;
    }
    printf("%lld", max);
    return 0;
}
