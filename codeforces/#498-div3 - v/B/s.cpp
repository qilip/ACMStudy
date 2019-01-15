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
    vector<pair<int, int>> e;
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d", &a);
        v.emplace_back(a, i);
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int sum = 0;
    for(int i=0;i<k;i++){
        sum += v[i].first;
        e.emplace_back(v[i].second, 1);
    }
    for(int i=k;i<n;i++){
        e.emplace_back(v[i].second, 0);
    }
    sort(e.begin(), e.end());

    printf("%d\n", sum);
    int cnt = 0;
    int cnk = 0;
    for(auto i : e){
        if(!i.second){
            cnt++;
        }else if(cnk<k-1){
            cnt++;
            printf("%d ", cnt);
            cnt = 0;
            cnk++;
        }else{
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
