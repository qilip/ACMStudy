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
int a[300010];
int m;
ll dis_sum[300010];
ll ori_sum[300010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n, greater<int>());
    for(int i=1;i<=n;i++){
        dis_sum[i] = dis_sum[i-1] + a[i-1];
    }
    for(int i=n-1;i>=0;i--){
        ori_sum[i] = ori_sum[i+1] + a[i];
    }
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        int q;
        scanf("%d", &q);
        printf("%lld\n", dis_sum[q-1] + ori_sum[q]);
    }
    return 0;
}
