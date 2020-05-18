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

int n, q;
int tree[100'0006];

void update(int i, int diff){
    while(i <= n){
        tree[i] += diff;
        i += (i & -i);
    }
}

int query(int i){
    int ans = 0;
    while(i){
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d %d", &n, &q);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d", &t);
        update(t, 1);        
    }
    for(int i=0;i<q;i++){
        int t;
        scanf("%d", &t);
        if(t>0) update(t, 1);
        else{
            t = -t;
            int mid = n/2;
            int l = 1;
            int r = n;
            while(l<=r){
                mid = (l+r)/2;
                int q = query(mid);
                if(q > t){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }
    }
    
    return 0;
}
