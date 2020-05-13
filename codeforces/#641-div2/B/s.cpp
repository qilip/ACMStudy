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
#include <bitset>

using namespace std;

typedef long long ll;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        int s[100010] = {0};
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d", &s[i]);
        }
        int c[100010] = {0};
        int maxc = 1;
        queue<tuple<int, int, int>> q; // cur, before, count
        for(int i=1;i<=n;i++){
            if(c[i] > 0) continue;
            q.emplace(i, s[i], 1);
            while(!q.empty()){
                int cur, bef, cnt;
                tie(cur, bef, cnt) = q.front();
                // printf("(%d,%d,%d)", cur, bef, cnt);
                q.pop();
                c[cur] = cnt;
                if(cnt > maxc) maxc = cnt;
                for(int j=2, nxt = cur*2; cur*j<=n; j++){
                    nxt = cur*j;
                    if(s[nxt] > bef && c[nxt] < cnt+1){
                        q.emplace(nxt, s[nxt], cnt+1);
                        // printf("[%d,%d:%d,%d]", nxt, bef, s[nxt], cnt+1);
                    }
                }
            }
        }
        printf("%d\n", maxc);
    }
    
    return 0;
}
