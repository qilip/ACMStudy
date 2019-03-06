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

    int n, q;
    int ql[5010];
    int qr[5010];
    int cnt[5010] = {0};
    int ans = 0;
    scanf("%d %d", &n, &q);
    for(int i=0;i<q;i++){
        scanf("%d %d", &ql[i], &qr[i]);
        for(int j=ql[i];j<=qr[i];j++){
            cnt[j]++;
        }
    }
    int usej = n+2;
    for(int i=0;i<2;i++){
        int maxj = -1;
        int maxc = -1;
        int maxmin = -1;
        for(int j=0;j<n;j++){
            if(j==usej) continue;
            int curmin = 99999999;
            int mincnt = 1;
            for(int k=ql[j];k<=qr[j];k++){
                if(curmin > cnt[k]){
                    curmin = cnt[k];
                    mincnt = 1;
                }
                if(curmin == cnt[k]) mincnt++;
            }
            if(maxc < curmin || (maxc == curmin && maxmin > mincnt)){
                maxc = curmin;
                maxj = j;
                maxmin = mincnt;
            }
        }
        usej = maxj;
        for(int j=ql[maxj];j<=qr[maxj];j++){
            cnt[j]--;
        }
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]) ans++;
    }
    printf("%d", ans);
    return 0;
}
