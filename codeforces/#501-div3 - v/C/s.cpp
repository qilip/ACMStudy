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

    int n, m;
    ll sum = 0;
    vector<int> v;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        sum += a;
        v.push_back(a-b);
    }
    sort(v.begin(), v.end(), greater<int>());
    int cnt = 0;
    if(sum <= m){
        printf("%d", cnt);
        return 0;
    }
    for(auto i : v){
        sum -= i;
        cnt++;
        if(sum <= m){
            printf("%d", cnt);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
