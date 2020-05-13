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

int p[100010] = {0};
int cnt[100010];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        priority_queue<pair<int, int>> pq;
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            int pos;
            scanf("%d", &pos);
            p[pos] = i;
            cnt[i] = 1;
            pq.emplace(1, i);
        }
        bool ans = true;
        for(int i=1;i<=n;i++){
            while(cnt[pq.top().second]==0) pq.pop();
            if(cnt[p[i]] == pq.top().first){
                if(cnt[p[i]+1]){
                    cnt[p[i]+1] = cnt[p[i]]+1;
                    if(p[i]+1<=n)
                        pq.emplace(cnt[p[i]+1], p[i]+1);
                }
                cnt[p[i]] = 0;
                // printf("pq:%d,%d| ", pq.top().first, pq.top().second);
                // for(int q=1;q<=n;q++){
                //     printf("%d ", cnt[q]);
                // }
                // printf("\n");
            }else{
                // printf("[%d:%d=%d]", i, cnt[p[i]], pq.top().first);
                ans = false;
                break;
            }
        }

        if(ans) printf("Yes\n");
        else printf("No\n");
    }
    
    return 0;
}
