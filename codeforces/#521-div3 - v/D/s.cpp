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

int s[200010];
int off[200010];
vector<pair<int, int>> v;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d", &tmp);
        s[tmp]++;
    }
    for(int i=1;i<=20'0000;i++){
        if(s[i]) v.emplace_back(s[i], i);
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    
    int flg = 1;
    int cnt = 1;
    while(flg){
        flg = 0;
        memset(off, 0, k * sizeof (int));
        int ptr = 0;
        int c = 0;
        while(ptr<k && ptr < v.end() - v.begin()){
            if( v[ptr].first-off[ptr]>=cnt+1 ){
                off[ptr] += cnt+1;
                c++;
            }
            else ptr++;
            if(c>=k) break;
        }
        if(c>=k){
            flg = 1;
            cnt++;
        }
    }
    int pt = 0;
    memset(off, 0, k * sizeof (int));
    int cc = 0;
    while(pt<k && pt < v.end() - v.begin()){
        if( v[pt].first-off[pt]>=cnt ){
            off[pt] += cnt;
            cc++;
            printf("%d ", v[pt].second);
        }
        else pt++;
        if(cc>=k) break;
    }

    return 0;
}
