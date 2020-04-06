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
    ll sl = 0;
    int l[10'0010] = {0};
    int imp = 0;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;i++){
        scanf("%d", &l[i]);
        if(l[i]+i-1 > n) imp = 1;
        sl += l[i];
    }
    if(sl < n || imp){
        printf("-1");
        return 0;
    }
    printf("%d ", 1);
    sl -= n;
    int lastp = l[1];
    for(int i=2;i<=m;i++){
        if(sl>=l[i-1]-1){
            printf("%d ", lastp-(l[i-1]-1)+1);
            sl -= l[i-1]-1;
            lastp = lastp-(l[i-1]-1)+l[i];
        }else{
            printf("%d ", lastp-sl+1);
            lastp = lastp-sl+l[i];
            sl -= sl;
        }
    }

    return 0;
}
