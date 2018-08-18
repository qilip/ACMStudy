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
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <tuple>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n, m, q;
    char s[1010], t[1010];
    vector<pair<int, int>> v;
    scanf("%d %d %d", &n, &m, &q);
    scanf("%s", s);
    scanf("%s", t);
    int s_cur = 0;
    while(s_cur<n-m+1){
        int pt = s_cur;
        bool flg = true;
        for(int i=0;i<m;i++){
            if(s[s_cur+i]!=t[i]){
                flg = false;
                break;
            }
        }
        if(flg) v.emplace_back(pt, pt+m-1);
        s_cur++;
    }
    for(int i=0;i<q;i++){
        int a, b;
        int cnt = 0;
        scanf("%d %d", &a, &b);
        for(auto vv : v){
            if(vv.first >= a-1 && vv.second <= b-1){
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }    
    return 0;
}
