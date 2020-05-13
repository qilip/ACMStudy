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

ll lev(int l){
    ll r = 0;
    r += (1+l)*l;
    r += l*(l-1)/2;
    return r;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int t;
    scanf("%d", &t);

    int arr[30010] = {0};
    for(int i=1;i<=30000;i++){
        ll r = lev(i);
        if(r<=20'0000'0000) arr[i] = r;
        else{
            break;
        }
    }
    while(t--){
        int n;
        scanf("%d", &n);
        int cnt = 0;
        while(n>1){
            int c = lower_bound(arr, arr+25821, n) - arr;
            if(arr[c]>n) c--;
            if(!arr[c]) break;
            cnt += n/arr[c];
            n -= arr[c] * (n/arr[c]);
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
