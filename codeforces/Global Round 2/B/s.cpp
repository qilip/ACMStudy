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

    int n, h;
    int a[1010];
    vector<int> v;
    scanf("%d %d", &n, &h);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        v.push_back(a[i]);
        sort(v.begin(), v.end(), greater<int>());
        int h2 = h;
        for(int j=0;j<v.size();j+=2){
            h2 -= v[j];
        }
        if(h2>=0) ans = v.size();
        else break;
    }
    printf("%d", ans);
    return 0;
}
