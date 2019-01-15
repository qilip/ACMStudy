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
pair<int, int> a[200010];
ll sum;
vector<int> v;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int s;
        scanf("%d", &s);
        a[i].first = s;
        a[i].second = i;
        sum += s;
    }
    sort(a+1, a+n+1, greater<pair<int, int>>());
    for(int i=1;i<=n;i++){
        int max;
        if(i==1) max = a[2].first;
        else max = a[1].first;
        if(sum-a[i].first == max*2) v.push_back(a[i].second);
    }
    printf("%d\n", v.size());
    for(auto i : v){
        printf("%d ", i);
    }
    
    return 0;
}
