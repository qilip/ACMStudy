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
    bool ar[110] = {false};
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;i++){
        ar[i] = true;
    }
    for(int i=0;i<n;i++){
        int l, r;
        scanf("%d %d", &l, &r);
        for(int i=l;i<=r;i++){
            ar[i] = false;
        }
    }
    int cnt = 0;
    for(int i=1;i<=m;i++){
        if(ar[i]) cnt++;
    }    
    printf("%d\n", cnt);
    if(cnt){
        for(int i=1;i<=m;i++){
            if(ar[i]) printf("%d ", i);
        }
    }
    return 0;
}
